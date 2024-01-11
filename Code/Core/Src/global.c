/*
 * global.c
 *
 *  Created on: Nov 29, 2022
 *      Author: ADMIN
 */


#include "global.h"

systemState sysState = START_MODE;
sensorReaderState readerState = READER_INIT;
ledBlinkyState ledState = LED_INIT;

uint8_t temp = 0;
uint32_t ADC_value = 0;
uint8_t buffer_flag = 0;

uint8_t printData = 0;
