/**
* ADC1_CHANNEL_0 <=> GPIO36 <=> VP
* ADC1_CHANNEL_3 <=> GPIO39 <=> VN
* ADC1_CHANNEL_4 <=> GPIO32 <=> D32
* ADC1_CHANNEL_5 <=> GPIO33 <=> D33
* ADC1_CHANNEL_6 <=> GPIO34 <=> D34
* ADC1_CHANNEL_7 <=> GPIO35 <=> D35
*/
#ifndef _MAIN_READ_ANALOG_H
#include "driver/adc.h"
#define _MAIN_READ_ANALOG_H
#endif

/**
*@brief reads raw analog input using the ADC1 unit
*@param channel channel number from available channels
*@return raw analog input value
*/
int read_analog_raw(int channel);
