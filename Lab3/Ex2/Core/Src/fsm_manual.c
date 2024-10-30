/*
 * fsm_manual.c
 *
 *  Created on: Oct 27, 2024
 *      Author: admin
 */


#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_MODE1:
		// return INIT status AUTO_RED_GREEN
		setTimer1(defaultTimeGreen*1000);
		setTimer2(1000);
		timeRed = defaultTimeRed;
		timeGreen = defaultTimeGreen;
		tempYellow = defaultTimeYellow;
		updateClockBuffer(timeRed--, timeGreen--);
		status = AUTO_RED_GREEN;
		break;
	case MAN_MODE2:
		// only red leds in both road1 and road2 are ON, other leds are OFF

		// if button0 is pressed, status will move to MAN_MODE3
		if(is_button_pressed(0) == 1){
			status = MAN_MODE3;
			setTrafficYellowBlink();
			setTimer1(500);
		}
		//blinking red led
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			setTimer1(500); //2Hz
		}
		//if button is pressed, tempRed value'll increase 1 unit
		//if value overcome 99, it'll return 1
		if(is_button_pressed(1) == 1){
			tempRed++;
			if(tempRed >99) tempRed = 1;
		}
		//if button3 is pressed, tempRed is assign for dedefaultTimeRed
		if(is_button_pressed(2) == 1){
			defaultTimeRed = tempRed ;
		}
		updateClockBuffer(2, defaultTimeRed);
		break;
	case MAN_MODE3:
		// only yellow led in both road1 and road2 are ON, other led are OFF

		// if button0 is pressed, status will move to MAN_MODE4
		if(is_button_pressed(0) == 1){
			status = MAN_MODE4;
			setTrafficGreenBlink();
			setTimer1(500);
		}
		//blinking yellow led
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			setTimer1(500);
		}
		//if button is pressed, tempYellow value'll increase 1 unit
		//if value overcome 99, it'll return 1
		if(is_button_pressed(1) == 1){
			tempYellow++;
			if(tempYellow > 99) tempYellow = 1;
		}
		//if button3 is pressed, tempYellow is assign for dedefaultTimeYelow
		if(is_button_pressed(2) == 1){
			defaultTimeYellow = tempYellow ;
		}
		updateClockBuffer(3, defaultTimeYellow);
		break;
	case MAN_MODE4:
		// if button0 is pressed, status will move to MAN_MODE1
		if(is_button_pressed(0) == 1)
		{
			if (defaultTimeRed < (defaultTimeGreen + defaultTimeYellow))
				{
				defaultTimeRed = olderTimeRed;
				defaultTimeYellow = olderTimeYellow;
				defaultTimeGreen = olderTimeGreen;
				}
			else
				{
				olderTimeRed = defaultTimeRed;
				olderTimeYellow = defaultTimeYellow;
				olderTimeGreen = defaultTimeGreen;
				}

			status = MAN_MODE1;
			setTimer1(500);
		}
		// only green led in both road1 and road2 are ON, other led are OFF
		//blinking Green Led
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			setTimer1(500);
		}
		//if button is pressed, tempGreen value 'll increase 1 unit
		//if value overcome 99, it'll return 1
			if(is_button_pressed(1) == 1){
				tempGreen++;
				if(tempGreen > 99) tempGreen = 1;
			}
		//if button3 is pressed, tempGreen is assign for dedefaultTimeGreen
			if(is_button_pressed(2) == 1){
				defaultTimeGreen = tempGreen ;
			}
		updateClockBuffer(4, defaultTimeGreen);
		break;
	default:
		break;
	}
}

