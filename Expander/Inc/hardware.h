#include "main.h"
#include "stm32f1xx_hal.h"

#define OWL_EXPANDER
#define HARDWARE_ID                  EXPANDER_HARDWARE
#define HARDWARE_VERSION             "Expander"

#define USE_DIGITALBUS
#define BUS_HUART                    huart1
#define BUS_UART_BAUDRATE            115200
#define DIGITAL_BUS_ENABLED          1
#define DIGITAL_BUS_FORWARD_MIDI     0

#define USE_TLC
#define TLC_CONTINUOUS
#define TLC_DEVICES 	             1
#define TLC5946_CHANNELS             16
#define TLC5946_SPI                  hspi2

#define USE_MAX
/* #define USE_MAX_DMA */
// #define MAX_CONTINUOUS
#define MAX11300_SPI                 hspi1
#define MAX11300_CHANNELS            20

/* Adds extra variables for UART DMA that don't get canceled */
#define NO_DMA_STREAMS
