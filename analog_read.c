#ifndef _MAIN_ANALOG_READ_H
#define _MAIN_ANALOG_READ_H
#include "analog_read.h"
#endif

//adc1 characteristics 
static esp_adc_cal_characteristics_t adc1_chars;

//keep track of status as to avoid redundancy
static uint32_t configured=0;

/**
*@brief configures the adc1 unit, mostly defaults with an attenuation of 11 decibels
*/
static void configure(void)
{
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_DEFAULT, 0, &adc1_chars);
    ESP_ERROR_CHECK(adc1_config_width(ADC_WIDTH_BIT_DEFAULT));
    configured = 1;
}

/**
*@brief reads the current value (in millivolts) from chosen ADC1 channel
*@param channel adc1 channel to read from (see analog_read.h for details)
*/
uint32_t read_analog_voltage(int channel)
{
    if(!configured) configure();
    int voltage = 0;
    ESP_ERROR_CHECK(adc1_config_channel_atten(channel, ADC_ATTEN_DB_11));
    voltage = esp_adc_cal_raw_to_voltage(adc1_get_raw(channel), &adc1_chars);
    return voltage;
}

/**
*@brief reads the current value (raw) from chosen ADC1 channel
*@param channel adc1 channel to read from (ADC1_CHANNEL_0 to ADC1_CHANNEL_6)
*/
uint32_t read_analog_raw(int channel)
{
    if(!configured) configure();
    int voltage = 0;
    ESP_ERROR_CHECK(adc1_config_channel_atten(channel, ADC_ATTEN_DB_11));
    voltage = adc1_get_raw(channel);
    return voltage;
}
