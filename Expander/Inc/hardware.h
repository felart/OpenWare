#include "main.h"
#include "stm32f1xx_hal.h"

#define OWL_EXPANDER
#define HARDWARE_ID                  EXPANDER_HARDWARE
#define HARDWARE_VERSION             "Expander"

#define USE_DIGITALBUS
#define USE_MAX
/* #define USE_MAX_DMA */
#define USE_TLC
#define TLC_CONTINUOUS
// #define MAX_CONTINUOUS

#define BUS_HUART huart1
#define MAX11300_SPI hspi1
#define TLC5946_SPI hspi2

#define PIXI_nCS_GPIO_Port MAX_nCS_GPIO_Port
#define PIXI_nCS_Pin MAX_nCS_Pin

#define TLC_DEVICES 	1
