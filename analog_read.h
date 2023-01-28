/**
* ADC1_CHANNEL_0 <=> GPIO36 <=> VP
* ADC1_CHANNEL_3 <=> GPIO39 <=> VN
* ADC1_CHANNEL_4 <=> GPIO32 <=> D32
* ADC1_CHANNEL_5 <=> GPIO33 <=> D33
* ADC1_CHANNEL_6 <=> GPIO34 <=> D34
* ADC1_CHANNEL_7 <=> GPIO35 <=> D35
*/
#include "driver/adc.h"
#include "esp_adc/deprecated/esp_adc_cal.h"
#define _MAIN_READ_ANALOG_H
/*
* reads analog values as voltages takes ADC1_CHANNEL_{channel number} as an argument
*/
uint read_analog_voltage(uint8_t channel);
/*
* reads raw analog takes ADC1_CHANNEL_{channel number} as an argument
*/
int read_analog_raw(uint8_t channel);