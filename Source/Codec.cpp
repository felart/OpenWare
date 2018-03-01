#include "device.h"
#include "Codec.h"
#include "errorhandlers.h"
#include "ApplicationSettings.h"

#ifdef __cplusplus
 extern "C" {
#endif
   void codec_init(SPI_HandleTypeDef*);
   void codec_write(uint8_t reg, uint8_t data);
   void codec_bypass(int bypass);
   void codec_mute(bool mute);
   void codec_set_volume(int8_t volume);
#ifdef __cplusplus
}
#endif

static int32_t txbuf[CODEC_BUFFER_SIZE];
static int32_t rxbuf[CODEC_BUFFER_SIZE];
static uint16_t blocksize;

uint16_t Codec::getBlockSize(){
  return blocksize;
}

#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif

void Codec::begin(SPI_HandleTypeDef *spi){
  codec_init(spi);
#ifdef OWL_MICROLAB
  codec_set_volume(127-18); // -18dB
#else
  codec_set_volume(127); // 0dB
#endif
}

void Codec::reset(){
  stop();
  start();
}

void Codec::ramp(uint32_t max){
  uint32_t incr = max/CODEC_BUFFER_SIZE;
  for(int i=0; i<CODEC_BUFFER_SIZE; ++i)
    txbuf[i] = i*incr;
}

void Codec::clear(){
  set(0);
}

int32_t Codec::getMin(){
  int32_t min = txbuf[0];
  for(int i=1; i<CODEC_BUFFER_SIZE; ++i)
    if(txbuf[i] < min)
      min = txbuf[i];
  return min;
}

int32_t Codec::getMax(){
  int32_t max = txbuf[0];
  for(int i=1; i<CODEC_BUFFER_SIZE; ++i)
    if(txbuf[i] > max)
      max = txbuf[i];
  return max;
}

float Codec::getAvg(){
  float avg = 0;
  for(int i=0; i<CODEC_BUFFER_SIZE; ++i)
    avg += txbuf[i];
  return avg / CODEC_BUFFER_SIZE;
}

void Codec::set(uint32_t value){
  for(int i=0; i<CODEC_BUFFER_SIZE; ++i)
    txbuf[i] = value;
}

void Codec::bypass(bool doBypass){
  codec_bypass(doBypass);
}

void Codec::mute(bool doMute){
  codec_mute(doMute);
}

void Codec::setOutputGain(int8_t value){
  codec_set_volume(value);
}

#ifdef USE_WM8731
extern "C" {
  extern I2S_HandleTypeDef hi2s2;
  extern void audioCallback(int32_t* rx, int32_t* tx, uint16_t size);
}

void Codec::stop(){
  HAL_I2S_DMAStop(&hi2s2);
}

// // hacked in to enable half-complete callbacks
// static void I2S_DMARxCplt(DMA_HandleTypeDef *hdma){
//   I2S_HandleTypeDef* hi2s = ( I2S_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
//   HAL_I2SEx_TxRxCpltCallback(hi2s);
// }
// static void I2S_DMARxHalfCplt(DMA_HandleTypeDef *hdma){
//   I2S_HandleTypeDef* hi2s = (I2S_HandleTypeDef*)((DMA_HandleTypeDef*)hdma)->Parent;
//   HAL_I2SEx_TxRxHalfCpltCallback(hi2s);
// }

void Codec::start(){
  blocksize = min(CODEC_BUFFER_SIZE/4, settings.audio_blocksize);
  HAL_StatusTypeDef ret;
  /* See STM32F405 Errata, I2S device limitations */
  /* The I2S peripheral must be enabled when the external master sets the WS line at: */
  while(HAL_GPIO_ReadPin(I2S_LRCK_GPIO_Port, I2S_LRCK_Pin)); // wait for low
  /* High level when the I2S protocol is selected. */
  while(!HAL_GPIO_ReadPin(I2S_LRCK_GPIO_Port, I2S_LRCK_Pin)); // wait for high

  // Ex function doesn't set up a half-complete callback
  // extern DMA_HandleTypeDef hdma_spi2_tx;
  // extern DMA_HandleTypeDef hdma_i2s2_ext_rx;
  // hdma_i2s2_ext_rx.XferHalfCpltCallback = I2S_DMARxHalfCplt;
  // hdma_spi2_tx.XferHalfCpltCallback = I2S_DMARxHalfCplt;
  // when a 24-bit data frame or a 32-bit data frame is selected the Size parameter means the number of 16-bit data length
  ret = HAL_I2SEx_TransmitReceive_DMA(&hi2s2, (uint16_t*)txbuf, (uint16_t*)rxbuf, blocksize*4);
  ASSERT(ret == HAL_OK, "Failed to start I2S DMA");
  // hdma_i2s2_ext_rx.XferCpltCallback = I2S_DMARxCplt;
  // hdma_spi2_tx.XferCpltCallback = I2S_DMARxCplt;
  // hdma_spi2_tx.Instance->CR |= DMA_IT_HT;

  // hdma_i2s2_ext_rx.Instance->CR  |= DMA_IT_TC | DMA_IT_TE | DMA_IT_DME;
  // hdma_i2s2_ext_rx.Instance->FCR |= DMA_IT_FE;
  // hdma_i2s2_ext_rx.Instance->CR  |= DMA_IT_HT;

  // ret = HAL_I2S_Receive(&hi2s2, (uint16_t*)rxbuf, CODEC_BUFFER_SIZE*2, 10000);
  // ASSERT(ret == HAL_OK, "Failed to start I2S RX");

  // ret = HAL_I2S_Receive_IT(&hi2s2, (uint16_t*)rxbuf, CODEC_BUFFER_SIZE*2);
  // ASSERT(ret == HAL_OK, "Failed to start I2S RX IT");

  // ret = HAL_I2S_Receive_DMA(&hi2s2, (uint16_t*)rxbuf, CODEC_BUFFER_SIZE*2);
  // ASSERT(ret == HAL_OK, "Failed to start I2S RX DMA");

  // ret = HAL_I2S_Transmit(&hi2s2, (uint16_t*)txbuf, CODEC_BUFFER_SIZE*2, 10000);
  // ASSERT(ret == HAL_OK, "Failed to perform I2S TX");

  // ret = HAL_I2S_Transmit_IT(&hi2s2, (uint16_t*)txbuf, CODEC_BUFFER_SIZE*2);
  // ASSERT(ret == HAL_OK, "Failed to perform I2S TX");

  // ret = HAL_I2S_Transmit_DMA(&hi2s2, (uint16_t*)txbuf, CODEC_BUFFER_SIZE*2);
  // ASSERT(ret == HAL_OK, "Failed to start I2S TX DMA");

  // ret = HAL_I2SEx_TransmitReceive(&hi2s2, (uint16_t*)txbuf, (uint16_t*)rxbuf, CODEC_BUFFER_SIZE*2, 10000);
  // ASSERT(ret == HAL_OK, "Failed to perform I2S TX/RX");

  // ret = HAL_I2SEx_TransmitReceive_IT(&hi2s2, (uint16_t*)txbuf, (uint16_t*)rxbuf, CODEC_BUFFER_SIZE*2);
  // ASSERT(ret == HAL_OK, "Failed to perform I2S TX/RX");
}

void Codec::pause(){
  HAL_I2S_DMAPause(&hi2s2);
}

void Codec::resume(){
  HAL_I2S_DMAResume(&hi2s2);
}

extern "C"{

  
  void HAL_I2SEx_TxRxHalfCpltCallback(I2S_HandleTypeDef *hi2s){
    audioCallback(rxbuf, txbuf, blocksize);
  }

  void HAL_I2SEx_TxRxCpltCallback(I2S_HandleTypeDef *hi2s){
    audioCallback(rxbuf+blocksize*2, txbuf+blocksize*2, blocksize);
  }

  // void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s){
  //   audioCallback(rxbuf, txbuf, blocksize);
  // }
  // void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s){
  //   audioCallback(rxbuf+blocksize*2, txbuf+blocksize*2, blocksize);
  // }

  // void HAL_I2S_TxHalfCpltCallback(I2S_HandleTypeDef *hi2s){
  //   audioCallback(rxbuf, txbuf, blocksize);
  // }
  // void HAL_I2S_TxCpltCallback(I2S_HandleTypeDef *hi2s){
  //   audioCallback(rxbuf+blocksize*2, txbuf+blocksize*2, blocksize);
  // }

  void HAL_I2S_ErrorCallback(I2S_HandleTypeDef *hi2s){
    error(CONFIG_ERROR, "I2S Error");
  }
}
#endif /* USE_WM8731 */

#ifdef USE_CS4271
extern "C" {
SAI_HandleTypeDef hsai_BlockA1;
SAI_HandleTypeDef hsai_BlockB1;
}

void Codec::txrx(){
  HAL_SAI_DMAStop(&hsai_BlockA1);
  HAL_SAI_Transmit_DMA(&hsai_BlockB1, (uint8_t*)rxbuf, blocksize*4);
}

void Codec::stop(){
  HAL_SAI_DMAStop(&hsai_BlockA1);
  HAL_SAI_DMAStop(&hsai_BlockB1);
}

void Codec::start(){
  blocksize = min(CODEC_BUFFER_SIZE/4, settings.audio_blocksize);
  HAL_StatusTypeDef ret;
  ret = HAL_SAI_Receive_DMA(&hsai_BlockB1, (uint8_t*)rxbuf, blocksize*4);
  ASSERT(ret == HAL_OK, "Failed to start SAI RX DMA");
  ret = HAL_SAI_Transmit_DMA(&hsai_BlockA1, (uint8_t*)txbuf, blocksize*4);
  ASSERT(ret == HAL_OK, "Failed to start SAI TX DMA");
}

void Codec::pause(){
  HAL_SAI_DMAPause(&hsai_BlockB1);
  HAL_SAI_DMAPause(&hsai_BlockA1);
}

void Codec::resume(){
  HAL_SAI_DMAResume(&hsai_BlockB1);
  HAL_SAI_DMAResume(&hsai_BlockA1);
}

extern "C" {

// void HAL_SAI_TxHalfCpltCallback(SAI_HandleTypeDef *hsai){
// }

extern void audioCallback(int32_t* rx, int32_t* tx, uint16_t size);

void HAL_SAI_RxCpltCallback(SAI_HandleTypeDef *hsai){
  audioCallback(rxbuf+blocksize*2, txbuf+blocksize*2, blocksize);
}

void HAL_SAI_RxHalfCpltCallback(SAI_HandleTypeDef *hsai){
  audioCallback(rxbuf, txbuf, blocksize);
}

void HAL_SAI_ErrorCallback(SAI_HandleTypeDef *hsai){
  error(CONFIG_ERROR, "SAI DMA Error");
}

}
#endif /* USE_CS4271 */
