/*
 * led_7segment.h
 *
 *  Created on: Oct 27, 2024
 *      Author: admin
 */

#ifndef INC_LED_7SEGMENT_H_
#define INC_LED_7SEGMENT_H_

#include "main.h"
#include "global.h"
#define MAX_MATRIX 10
#define MAX_BUFF 4

//void display7SEG2(int number);
void display7SEG1(int number);
void updateClockBuffer(int, int);
void scanLed();

#endif /* INC_LED_7SEGMENT_H_ */
