/*
 * debug_led.c
 *
 *  Created on: Nov 29, 2022
 *      Author: ADMIN
 */


#include "debug_led.h"

void led_blinky_fsm(void) {
	switch(ledState) {
	case LED_INIT:
		// Initialize timer for led_blinky
		setTimer1(SYSTEM_DELAY);
		ledState = LED_BLINKING;
		break;

	case LED_BLINKING:
		if(timer1_flag == 1) {
			setTimer1(LED_PERIOD);
			HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		}
		break;
	}
}
