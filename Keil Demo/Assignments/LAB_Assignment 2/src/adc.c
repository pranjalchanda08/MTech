/**
 * @file        adc.c
 * @brief       File containing definations for ADC Driver
 * @author      Pranjal Chanda (2022HT01011)
 */

#include "adc.h"

/**
 * @brief   Initialise ADC ADC0.0 P0[21]
 */
void adc_init(void)
{
    /* Pin Select */
    PINSEL1 |= (1 << 14); 	    // Set P0.23 in ADC0.0 mode.

    /* Enable ADC Power */
    PCONP |= (1 << 12);		    // Enable PCADC

    /* Configure ADC0 */
    AD0CR |= (1 << 0) | (1 << 9) | (1 << 16) | (1 << 21);
}

/**
 * @brief   Read ADC0.0
 * @param[out]  adc_val     ADC Converted Value
 */
int adc_read( unsigned int *adc_val )
{

    if (( AD0DR0 &  ADC_DONE_MASK ) != ADC_RESET )
    {
        if (( AD0DR0 &  ADC_OVERRUN_MASK ) != ADC_RESET )
        {
            /* Check for Over-Run Error */
            return ADC_ERROR;
        }
        *adc_val   = (AD0DR0 & ADC_READ_MASK) >> ADC_READ_SHIFT;
    }
    else
    {
        return ADC_ERROR;
    }
    return ADC_RESET;
}
