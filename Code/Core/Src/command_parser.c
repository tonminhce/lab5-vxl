/*
 * command_parser.c
 *
 *  Created on: Nov 29, 2022
 *      Author: ADMIN
 */


#include "command_parser.h"

uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t buffer_index = 0;

char * string_buffer;

uint8_t isRST = 0;
uint8_t isOK = 0;

uint8_t isRSTCmd(void);
uint8_t isOKCmd(void);

void command_parser_fsm(void) {
	switch(sysState) {
	case START_MODE:
		if(isRST == 1) {
			setTimer3(0);
			isRST = 0;
			printData = 1;
			sysState = PRINT_MODE;
		}
		break;

	case PRINT_MODE:
		setTimer3(PARSER_TIMEOUT);
		printData = 0;
		sysState = WAIT_MODE;
		break;

	case WAIT_MODE:
		if(isRST == 1) {
			setTimer3(0);
			isRST = 0;
			printData = 1;
			sysState = PRINT_MODE;
			break;
		}

		if(isOK == 1) {
			setTimer3(0);
			isOK = 0;
			printData = 0;
			sysState = START_MODE;
			break;
		}

		if(timer3_flag == 1) {
			setTimer3(0);
			clearBuffer();
			printData = 1;
			sysState = PRINT_MODE;
			break;
		}

		setTimer3(PARSER_TIMEOUT);
		break;
	}
}

void updateBuffer(uint8_t updated) {
	uint8_t * newLine = (uint8_t *)"\r\n";
	if(updated == *newLine) {
		isRST = isRSTCmd();
		isOK = isOKCmd();
		clearBuffer();
	}
	else {
		buffer[buffer_index] = updated;
		buffer_index = (buffer_index + 1) % MAX_BUFFER_SIZE;
	}
	string_buffer = (char *)buffer;
}

void clearBuffer(void) {
	for(uint8_t index = 0; index < buffer_index; index++) {
		buffer[index] = 0;
	}
	buffer_index = 0;
}

uint8_t isRSTCmd(void) {
	char * requestCmd = (char *)"!RST#";
	if(strcmp(string_buffer, requestCmd) == 0) {
		return 1;
	}
	return 0;
}

uint8_t isOKCmd(void) {
	char * stopCmd = (char *)"!OK#";
	if(strcmp(string_buffer, stopCmd) == 0) {
		return 1;
	}
	return 0;
}
