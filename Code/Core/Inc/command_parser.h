/*
 * command_parser.h
 *
 *  Created on: Nov 29, 2022
 *      Author: ADMIN
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include "global.h"

void command_parser_fsm(void);

void updateBuffer(uint8_t updated);
void clearBuffer(void);

#endif /* INC_COMMAND_PARSER_H_ */
