/*
 * global.h
 *
 *  Created on: Nov 29, 2022
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "software_timer.h"
#include "state.h"

#define LED_PERIOD				500
#define PARSER_TIMEOUT			3000
#define SENSOR_READ_PERIOD		500

#define MAX_BUFFER_SIZE			30

extern systemState sysState;
extern sensorReaderState readerState;
extern ledBlinkyState ledState;

extern uint8_t temp;
extern uint32_t ADC_value;
extern uint8_t buffer_flag;

extern uint8_t printData;

#endif /* INC_GLOBAL_H_ */
