#ifndef _MAIN_ANALOG_READ_H
#define _MAIN_ANALOG_READ_H
#include "analog_read.h"
#include <stdint.h>
#endif



//keep track of status as to avoid redundancy
static uint32_t configured=0;

/**
*@brief configures the adc1 unit, mostly defaults with an attenuation of 11 decibels 
* check (https://docs.espressif.com/projects/esp-idf/en/v4.4/esp32/api-reference/peripherals/adc.html)
*/
static void configure(int channel)
{
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(channel,ADC_ATTEN_DB_11);
    configured = 1;
}


/**
*@brief reads the current value (raw) from chosen ADC1 channel
*@param channel adc1 channel to read from (ADC1_CHANNEL_0 to ADC1_CHANNEL_6)
*/
int read_analog_raw(int channel)
{
    
    int val = 0;
    switch(channel)
    {
        case 0:
        if(!configured) configure(ADC1_CHANNEL_0);
        val = adc1_get_raw(ADC1_CHANNEL_0);
        break;
        case 3:
        if(!configured) configure(ADC1_CHANNEL_3);
        val = adc1_get_raw(ADC1_CHANNEL_3);
        break;
        case 4:
        if(!configured) configure(ADC1_CHANNEL_4);
        val = adc1_get_raw(ADC1_CHANNEL_4);
        break;
        case 5:
        if(!configured) configure(ADC1_CHANNEL_5);
        val = adc1_get_raw(ADC1_CHANNEL_5);
        break;
        case 6:
        if(!configured) configure(ADC1_CHANNEL_6);
        val = adc1_get_raw(ADC1_CHANNEL_6);
        break;
        case 7:
        if(!configured) configure(ADC1_CHANNEL_7);
        val = adc1_get_raw(ADC1_CHANNEL_7);
        break;
        default:
        exit(1);
        break;
    }


    return val;
}
