#include <string.h>
#include <stdlib.h>
#include "device.h"
#include "Owl.h"
#include "errorhandlers.h"
#include "message.h"
#include "ProgramManager.h"
#include "PatchRegistry.h"
#include "OpenWareMidiControl.h"

#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif
#ifndef abs
#define abs(x) ((x)>0?(x):-(x))
#endif

#define SEG_DISPLAY_BLANK 10
#define SEG_DISPLAY_E     11
#define SEG_DISPLAY_U     12
const uint8_t seg_bits[] =
  {
/*    0,    1,    2,    3,    4,    5,    6,    7,    8,    9 */
   0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67,
/*      blank,         E,          U */
   0b00000000, 0b01111001, 0b00111110
   // E: A D E F G: 1 0 0 1 1 1 1
   // U: B C D E F: 0 1 1 1 1 1 0
  };
GPIO_TypeDef* seg_ports[8] =
  {
   DISPLAY_A_GPIO_Port,
   DISPLAY_B_GPIO_Port,
   DISPLAY_C_GPIO_Port,
   DISPLAY_D_GPIO_Port,
   DISPLAY_E_GPIO_Port,
   DISPLAY_F_GPIO_Port,
   DISPLAY_G_GPIO_Port,
   DISPLAY_DP_GPIO_Port
  };
const uint16_t seg_pins[8] =
  {
   DISPLAY_A_Pin,
   DISPLAY_B_Pin,
   DISPLAY_C_Pin,
   DISPLAY_D_Pin,
   DISPLAY_E_Pin,
   DISPLAY_F_Pin,
   DISPLAY_G_Pin,
   DISPLAY_DP_Pin
  };

// set value to 10 for no display
static void setSegmentDisplay(int value, bool dot=false){
  HAL_GPIO_WritePin(seg_ports[7], seg_pins[7], dot ? GPIO_PIN_RESET : GPIO_PIN_SET);
  uint8_t bits = seg_bits[value % sizeof(seg_bits)];
  for(int i=0; i<7; ++i)
    HAL_GPIO_WritePin(seg_ports[i], seg_pins[i], (bits & (1<<i)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void setGateValue(uint8_t ch, int16_t value){
  if(ch == PUSHBUTTON)
    HAL_GPIO_WritePin(GATE_OUT_GPIO_Port, GATE_OUT_Pin, value ? GPIO_PIN_RESET :  GPIO_PIN_SET);
}

void setup(){
  extern TIM_HandleTypeDef htim2;
  // __HAL_TIM_SET_COUNTER(&htim2, INT16_MAX/2);
  HAL_TIM_Encoder_Start_IT(&htim2, TIM_CHANNEL_ALL);
  setSegmentDisplay(11, true);
  HAL_GPIO_WritePin(GATE_OUT_GPIO_Port, GATE_OUT_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_SW1_GPIO_Port, LED_SW1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_SW2_GPIO_Port, LED_SW2_Pin, GPIO_PIN_SET);
  owl_setup();
}

bool isModeButtonPressed(){
  return HAL_GPIO_ReadPin(ENC_SW_GPIO_Port, ENC_SW_Pin) == GPIO_PIN_RESET;
}

int getEncoderValue(){
  extern TIM_HandleTypeDef htim2;
  return __HAL_TIM_GET_COUNTER(&htim2)>>2;
}

void setEncoderValue(int value){
  extern TIM_HandleTypeDef htim2;
  __HAL_TIM_SET_COUNTER(&htim2, value<<2);
}

#define PATCH_RESET_COUNTER 5000
static void update_preset(){
  int patchselect = getEncoderValue();
  patchselect = max(1, min((int)registry.getNumberOfPatches()-1, patchselect + 1));  
  switch(getOperationMode()){
  case STARTUP_MODE:
    setOperationMode(RUN_MODE);
    break;
  case LOAD_MODE:
    setSegmentDisplay(SEG_DISPLAY_U);
    break;
  case RUN_MODE:
    if(isModeButtonPressed()){
      // switch patches
      if(program.getProgramIndex() != patchselect){
	program.loadProgram(patchselect);
	program.resetProgram(false);
      }
      setSegmentDisplay(patchselect, true);
    }else if(patchselect != program.getProgramIndex()){
      setSegmentDisplay(patchselect, false);
      static uint32_t counter = PATCH_RESET_COUNTER;
      if(--counter == 0){
	counter = PATCH_RESET_COUNTER;
	patchselect = program.getProgramIndex();
	setEncoderValue(patchselect);
      }
    }else if(getErrorStatus() != NO_ERROR){
      setOperationMode(ERROR_MODE);
    }else{
      setSegmentDisplay(patchselect, true);
    }
    break;
  case CONFIGURE_MODE:
    setOperationMode(RUN_MODE);
    break;
  case ERROR_MODE:
    if(isModeButtonPressed())
      program.resetProgram(false); // runAudioTask() changes to RUN_MODE
    static uint32_t counter = PATCH_RESET_COUNTER;
    setSegmentDisplay(SEG_DISPLAY_E, counter > PATCH_RESET_COUNTER/2);
    if(--counter == 0)
      counter = PATCH_RESET_COUNTER;
    break;
  }
}

void loop(void){
  MX_USB_HOST_Process(); // todo: enable PWR management
  update_preset();
  owl_loop();
}
