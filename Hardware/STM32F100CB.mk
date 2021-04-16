# Debug / Release
CONFIG ?= Release
ifeq ($(CONFIG),Debug)
  CPPFLAGS = -g3 -Wall -Wcpp -Wunused-function -DDEBUG # -DUSE_FULL_ASSERT
  ASFLAGS  = -g3
  CFLAGS   = -g3
endif
ifeq ($(CONFIG),Release)
  CPPFLAGS = -O2
  ASFLAGS  = -O2
  CFLAGS   = -O2
endif

# compile with semihosting if Debug is selected
ifeq ($(CONFIG),Debug)
  LDLIBS += -lrdimon
  LDFLAGS += -specs=rdimon.specs
else
  CPPFLAGS += -nostdlib -nostartfiles -fno-builtin -ffreestanding
  C_SRC += libnosys_gnu.c
  LDFLAGS += --specs=nano.specs
endif

# Compilation Flags
LDFLAGS += -Wl,--gc-sections
LDSCRIPT = $(OPENWARE)/Hardware/STM32F100CB_FLASH.ld
CPPFLAGS += --specs=nano.specs
CPPFLAGS += -DEXTERNAL_SRAM -DARM_CORTEX
# CPPFLAGS += -fpic -fpie
CPPFLAGS += -fdata-sections
CPPFLAGS += -ffunction-sections
#CPPFLAGS +=  -mno-unaligned-access
#CPPFLAGS  += -fno-omit-frame-pointer
CPPFLAGS += -nostdlib -nostartfiles -fno-builtin -ffreestanding
CXXFLAGS = -fno-rtti -fno-exceptions -std=gnu++11
CFLAGS  += -std=gnu99
ARCH_FLAGS = -mcpu=cortex-m3 -mthumb -mfloat-abi=soft
ARCH_FLAGS += -fsingle-precision-constant
DEF_FLAGS = -DSTM32F100xB -DARM_MATH_CM3
DEF_FLAGS += -D__FPU_PRESENT=0U
S_SRC = $(BUILDROOT)/Src/startup_stm32f100xb.s
