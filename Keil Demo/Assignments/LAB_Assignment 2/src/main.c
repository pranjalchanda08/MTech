/**
 * @file        main.c
 * @brief       File containing main application code.
 * @author      Pranjal Chanda (2022HT01011)
 */
#include <lpc23xx.h>
#include "adc.h"
#include "LCD.h"
#include "stdio.h"

#define MAX_BUFF_LEN                    32
#define SIMULATION_RUN                  0

static void nop_delay(int cycles);
static void get_voltage(float *volt, const unsigned int adc_val);
static void main_init(void);

static const unsigned char buff[MAX_BUFF_LEN];

/**
 * @brief Application Main Entry
 */
int main(void)
{
    unsigned int adc_val = ADC_RESET;
    int err = ADC_RESET;
    float volt = ADC_RESET;
    main_init();

    while (1)
    {
        err = adc_read(&adc_val);
        if (!err)
        {
            get_voltage(&volt, adc_val);
            snprintf((char *)buff, MAX_BUFF_LEN, "Volt: %.2f", volt);
#if SIMULATION_RUN == 0
            lcd_print(buff);
#endif
            nop_delay(2000);
        }
    }
}

/**
 * @brief Initialise Main
 */
static void main_init(void)
{
#if SIMULATION_RUN == 0
    lcd_init();
    lcd_clear();
    set_cursor(0, 0);
#endif
    adc_init();
}

/**
 * @brief Convert ADC Value to Voltage
 * @param[out]  volt        Converted voltage
 * @param[in]   adc_val     Current ADC value
 */
static void get_voltage(float *volt, const unsigned int adc_val)
{
    *volt = (((float)adc_val / 1023.0) * 3.3);
}

/**
 * @brief Single instruction NOP delay
 * @param[in]   cycles    Number of Delay cycles
 */
static void nop_delay(int cycles)
{
    for (volatile size_t i = 0; i < cycles; i++)
    {
        __asm__ __volatile__("nop \n");
    }
}
