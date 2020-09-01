#include "FlashStorage.h"
#include "FlashStorageBlock.hpp"
#include "device.h"
#include "eepromcontrol.h"
#include "message.h"
#include <string.h>

#ifndef DAISY
// Most devices need a single flash storage
extern char _FLASH_STORAGE_BEGIN;
extern char _FLASH_STORAGE_END;
#define EEPROM_PAGE_BEGIN ((uint32_t)&_FLASH_STORAGE_BEGIN)
#define EEPROM_PAGE_END ((uint32_t)&_FLASH_STORAGE_END)
#else
// Daisy uses separate storages for settings and patches
extern char _SETTINGS_STORAGE_BEGIN;
extern char _SETTINGS_STORAGE_END;
#define SETTINGS_EEPROM_PAGE_BEGIN ((uint32_t)&_SETTINGS_STORAGE_BEGIN)
#define SETTINGS_EEPROM_PAGE_END ((uint32_t)&_SETTINGS_STORAGE_END)
extern char _PATCH_STORAGE_BEGIN;
extern char _PATCH_STORAGE_END;
#define PATCH_EEPROM_PAGE_BEGIN ((uint32_t)&_PATCH_STORAGE_BEGIN)
#define PATCH_EEPROM_PAGE_END ((uint32_t)&_PATCH_STORAGE_END)
#endif

#define EEPROM_PAGE_SIZE (128 * 1024)


#if 0
// This probably belongs to BaseStorages template, however we must not run it in some
// cases (i.e. for readonly Qspi). We might add something like .isWritable() method
// to storage for such cases.
template<>
void FlashStorage::recover(){
  StorageBlock block = getLastBlock();
  if(!block.isFree() && !block.isValidSize()){
    // count backwards to see how much free space (0xff words) there is
    uint32_t* top = (uint32_t*)block.getData();
    uint32_t* ptr = (uint32_t*)(end_page);
    uint32_t free = 0;
    while(--ptr > top && *ptr == 0xffffffff)
      free += 4;
    uint32_t size = (ptr-top)*4;
    // write size to last block, and update magick to deleted
    block.setSize(size);
    block.setDeleted();
    // add empty block to end
    if(count+1 < max_blocks)
      blocks[count++] = createBlock(ptr, 4); // createBlock(ptr+4);
  }
}
#endif


// erase entire allocated FLASH memory
template<>
void FlashStorage::erase() {
  uint32_t page = start_page;
  eeprom_unlock();
  while (page < end_page) {
    eeprom_erase(page);
    page += EEPROM_PAGE_SIZE;
  }
  eeprom_lock();
  init();
}

template<>
void FlashStorage::defrag(void *buffer, uint32_t size) {
  // ASSERT(size >= getWrittenSize(), "Insufficient space for full defrag");
  uint8_t *ptr = (uint8_t *)buffer;
  if (getDeletedSize() > 0 && getWrittenSize() > 0) {
    uint32_t offset = 0;
    for (uint8_t i = 0; i < count && offset < size; ++i) {
      if (blocks[i].verify()) {
        memcpy(ptr + offset, blocks[i].getBlock(), blocks[i].getBlockSize());
        offset += blocks[i].getBlockSize();
      }
    }
    erase();
    eeprom_unlock();
    eeprom_write_block(start_page, buffer, offset);
    eeprom_lock();
    init();
  }
}

#ifndef DAISY
FlashStorage storage(EEPROM_PAGE_BEGIN, EEPROM_PAGE_END);
#else
FlashStorage settings_storage(SETTINGS_EEPROM_PAGE_BEGIN, SETTINGS_EEPROM_PAGE_END);
PatchStorage patch_storage(PATCH_EEPROM_PAGE_BEGIN, PATCH_EEPROM_PAGE_END);
#endif

