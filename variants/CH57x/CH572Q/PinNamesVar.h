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

#ifndef _PINNAMES_VAR_H
#define _PINNAMES_VAR_H

#ifdef __cplusplus
extern "C" {
#endif

/* If this file is edited, please ensure that Z_STARTUP_FILE is updated */
/* to include the correct objects for the variant */

// Default pin names for CH572 32-pin package
// Digital PinName array
extern const PinName digitalPin[];

// ADC PinName array
extern const PinName analogInputPin[];

// Analog PinName array (for analogWrite)
extern const PinName analogOutputPin[];

#ifdef __cplusplus
}
#endif

#endif /* _PINNAMES_VAR_H */
