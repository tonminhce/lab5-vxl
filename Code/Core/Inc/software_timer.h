/*
 * software_timer.h
 *
 *  Created on: Nov 29, 2022
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define SYSTEM_DELAY 	10 // 10ms

extern int traffic_timer_flag;
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

void setTrafficTimer(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
