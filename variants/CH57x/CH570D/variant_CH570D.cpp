/*
 *******************************************************************************
 * Custom implementation for CH570/CH572 microcontroller family
 * Based on the CH570/CH572 datasheet and reference manual
 *
 * Licensed under the BSD 3-Clause License
 * You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

// Digital PinName array
// CH570 has PA0-PA15, PB0-PB15, PC0 pins
const PinName digitalPin[] = {
  // PA0 - PA7
  PA_0,  PA_1,  PA_2,  PA_3,  PA_4,  PA_5,  PA_6,  PA_7,
  // PA8 - PA15
  PA_8,  PA_9,  PA_10, PA_11, PA_12, PA_13, PA_14, PA_15,
  // PB0 - PB7
  PB_0,  PB_1,  PB_2,  PB_3,  PB_4,  PB_5,  PB_6,  PB_7,
  // PB8 - PB15
  PB_8,  PB_9,  PB_10, PB_11, PB_12, PB_13, PB_14, PB_15,
  // PC0
  PC_0
};

// Analog (ADC) PinName array
// CH570 has limited ADC functionality via comparator (4-bit ADC equivalent)
const PinName analogInputPin[] = {
  PA_1,  // A0 - Comparator input
  PA_4,  // A1
  PA_5,  // A2 
  PA_9,  // A3
  PA_12, // A4
  PB_5   // A5
};

// PWM PinName array
const PinName analogOutputPin[] = {
  PA_4,   // PWM0
  PA_5,   // PWM1
  PA_9,   // PWM2
  PA_10,  // PWM3
  PB_0,   // PWM4
  PB_4    // PWM5
};

// System pre-initialization
void pre_init(void) {
  // Enable enhanced Flash read mode for better performance
  // This is specific to CH57x series
  PFIC->CFGR = (PFIC->CFGR & ~(PFIC_CFGR_SYSRST | PFIC_CFGR_IMCFGR)) | PFIC_CFGR_IMCFGR;
  
  // Initialize system clock at startup
  SystemClock_Config();
}

// Serial port initialization
void serialEvent_init(void) {
  // Serial port setup will be handled by Arduino core
}

/**
  * @brief  System Clock Configuration
  * @note   Default clock configuration for CH570 EVT Board
  * @retval None
  */
void SystemClock_Config(void)
{
  // By default, CH570 uses internal HSI at 32MHz as system clock
  // The microcontroller can operate at frequencies up to 100MHz
  // Clock configuration will be handled by Arduino core based on
  // settings in boards.txt
}

#ifdef __cplusplus
}
#endif
