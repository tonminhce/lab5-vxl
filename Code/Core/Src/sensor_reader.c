/*
 * sensor_reader.c
 *
 *  Created on: Nov 29, 2022
 *      Author: ADMIN
 */


#include "sensor_reader.h"

void uart_communication_fsm(void) {
	switch(readerState) {
	case READER_INIT:
		// Initialize timer for sensor reader
		setTimer2(SYSTEM_DELAY);
		readerState = READER_READING;
		break;

	case READER_WAITING:
		if(printData) {
			setTimer2(SENSOR_READ_PERIOD);
			readSensor();
			readerState = READER_READING;
		}
		break;

	case READER_READING:
		if(!printData) {
			readerState = READER_WAITING;
		}

		if(timer2_flag == 1) {
			setTimer2(SENSOR_READ_PERIOD);
			readSensor();
		}
		break;
	}
}

void readSensor(void) {
	char str[50];
	ADC_value = HAL_ADC_GetValue(&hadc1);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "!ADC=%ld#\r\n", ADC_value), 1000);
}
