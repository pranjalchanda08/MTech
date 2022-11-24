/**
 * @file        adc.h
 * @brief       A File to be included for ADC functionalities
 * @author      Pranjal Chanda (2022HT01011)
 */

#ifndef _ADC_H_
#define _ADC_H_

#include <LPC23xx.h>

#define ADC_RESET           (0)
#define ADC_ERROR           (1)
#define ADC_READ_SHIFT      (6)
#define ADC_DONE_MASK       (0x80000000)
#define ADC_OVERRUN_MASK    (0x40000000)
#define ADC_READ_MASK       (0x0000FFC0)

void adc_init(void);
int adc_read(unsigned int *adc_val);

#endif /* _ADC_H_ */
