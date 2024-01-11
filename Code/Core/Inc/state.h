/*
 * state.h
 *
 *  Created on: Nov 29, 2022
 *      Author: ADMIN
 */

#ifndef INC_STATE_H_
#define INC_STATE_H_

typedef enum {
	READER_INIT,
	READER_WAITING,
	READER_READING
} sensorReaderState;

typedef enum {
	START_MODE,
	PRINT_MODE,
	WAIT_MODE,
} systemState;

typedef enum {
	LED_INIT,
	LED_BLINKING,
} ledBlinkyState;

#endif /* INC_STATE_H_ */
