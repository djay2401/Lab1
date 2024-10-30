/*
 * fsm_automatic.c
 *
 *  Created on: Oct 27, 2024
 *      Author: admin
 */


#include "fsm_automatic.h"


void fsm_automatic_run(){
	switch(status){
	/*in INIT status, it status is assigned AUTO_RED_GREEN
	assign timeRed, timeGreen, timeYellow
	tempRed, tempYellow, tempGreen to corresponding value
	*/
	case INIT:
		status = AUTO_RED_GREEN;
		setTimer1(defaultTimeGreen*1000);
		timeRed = defaultTimeRed;
		timeGreen = defaultTimeGreen;
		tempRed = defaultTimeRed;
		tempYellow = defaultTimeYellow;
		tempGreen = defaultTimeGreen;
		setTimer2(1000);
		updateClockBuffer(timeRed--, timeGreen--);
		break;
	case AUTO_RED_GREEN:
	/*
	 * in this status, red led in road 1 is ON
	 * and green led in road 2 is off
	 * if timer1_flag == 1, status = AUTO_RED_YELLOW
	 * and call updateClockBuffer to update value is displayed in led 7 Segment
	 * with parameter is timeRed-- and timeYellow--
	 * if timer2_flag = 1, update and decrease timeRed and timeGreen
	 * if is_button_pressed(0) = 1, move to MAN_MODE2
	 */
		setTrafficRed();
		setTrafficGreen1();

		if(timer1_flag == 1){
			status = AUTO_RED_YELLOW;
			setTimer1(defaultTimeYellow*1000);
			timeYellow = defaultTimeYellow;
			updateClockBuffer(timeRed--, timeYellow--);
			setTimer2(1000);
		}
		if(timer2_flag == 1){
			updateClockBuffer(timeRed--, timeGreen--);
			setTimer2(1000);
		}
		if(is_button_pressed(0) == 1){
			setTimer1(250);
			status = MAN_MODE2;
			setTrafficRedBlink();

		}
		break;
	case AUTO_RED_YELLOW:
		/*
		 * in this status, red led in road 1 is ON
		 * and Yellow led in road 2 is off
		 * if timer1_flag == 1, status = AUTO_GREEN_RED
		 * and call updateClockBuffer to update value is displayed in led 7 Segment
		 * with parameter is timeGreen-- and timeRed--
		 * if timer2_flag = 1, update and decrease timeRed and timeYelow
		 * if is_button_pressed(0) = 1, move to MAN_MODE2
		 */
		setTrafficRed();
		setTrafficYellow1();

		if(timer1_flag == 1){
			status = AUTO_GREEN_RED;
			setTimer1(defaultTimeGreen*1000);
			timeGreen = defaultTimeGreen;
			timeRed = defaultTimeRed;
			updateClockBuffer(timeGreen--, timeRed--);
			setTimer2(1000);
		}
		if(timer2_flag == 1){
			updateClockBuffer(timeRed--, timeYellow--);
			setTimer2(1000);
		}
		if(is_button_pressed(0) == 1){
			setTimer1(250);
			status = MAN_MODE2;
			setTrafficRedBlink();
		}
		break;
	case AUTO_GREEN_RED:
		/*
		 * in this status, green led in road 1 is ON
		 * and red led in road 2 is off
		 * if timer1_flag == 1, status = AUTO_YELLOW_RED
		 * and call updateClockBuffer to update value is displayed in led 7 Segment
		 * with parameter is timeYelow-- and timeRed--
		 * if timer2_flag = 1, update and decrease timeGreen and timeRed
		 * if is_button_pressed(0) = 1, move to MAN_MODE2
		 */
		setTrafficGreen();
		setTrafficRed1();

		if(timer1_flag == 1){
			status = AUTO_YELLOW_RED;
			setTimer1(defaultTimeYellow*1000);
			timeYellow = defaultTimeYellow;
			updateClockBuffer(timeYellow--, timeRed--);
			setTimer2(1000);
		}
		if(timer2_flag == 1){
			updateClockBuffer(timeGreen--, timeRed--);
			setTimer2(1000);
		}
		if(is_button_pressed(0) == 1){
			setTimer1(250);
			status = MAN_MODE2;
			setTrafficRedBlink();

		}
		break;
	case AUTO_YELLOW_RED:
		/*
		 * in this status, Yellow led in road 1 is ON
		 * and red led in road 2 is off
		 * if timer1_flag == 1, status = AUTO_RED_GREEN
		 * and call updateClockBuffer to update value is displayed in led 7 Segment
		 * with parameter is timeRed-- and timeGreen--
		 * if timer2_flag = 1, update and decrease timeYellow and timeRed
		 *  if is_button_pressed(0) = 1, move to MAN_MODE2
		 */
		setTrafficYellow();
		setTrafficRed1();

		if(timer1_flag == 1){
			status = AUTO_RED_GREEN;
			setTimer1(defaultTimeGreen*1000);
			timeRed = defaultTimeRed;
			timeGreen = defaultTimeGreen;
			updateClockBuffer(timeRed--, timeGreen--);
			setTimer2(1000);
		}
		if(timer2_flag == 1){
			updateClockBuffer(timeYellow--, timeRed--);
			setTimer2(1000);
		}
		if(is_button_pressed(0) == 1){
			setTimer1(250);
			status = MAN_MODE2;
			setTrafficRedBlink();
		}
		break;
	default:
		break;
	}
}
