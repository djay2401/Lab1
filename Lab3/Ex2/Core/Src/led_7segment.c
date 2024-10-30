/*
 * led_7segment.c
 *
 *  Created on: Oct 27, 2024
 *      Author: admin
 */

#include "led_7segment.h"

uint16_t led_matrix[MAX_MATRIX] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7D, 0x07, 0x7F, 0x6f};
int index_led = 0;
int led_buffer[MAX_BUFF] = {0,0,0,0};
//display LED 7 segment
void display7SEG1(int number){
	uint16_t bit_var = led_matrix[number];
	HAL_GPIO_WritePin(GPIOB, bit_var, RESET);
	HAL_GPIO_WritePin(GPIOB, ~bit_var, SET);
}

//void display7SEG2(int number){
//	uint16_t bit_var = led_matrix[number];
//	HAL_GPIO_WritePin(GPIOB, bit_var, RESET);
//	HAL_GPIO_WritePin(GPIOB, ~bit_var, SET);
//}

//if counter1 < 10, example value = 2, led7 1 display 0 and led 7 segment 2 display 2
//if counter1 > 10, ex value = 12, led7 1 display 1 and led 7 segment 2 display 2
void updateClockBuffer(int counter1, int counter2){
	    led_buffer[0] = counter1 / 10;
		led_buffer[1] = counter1 % 10;
		led_buffer[2] = counter2 / 10;
		led_buffer[3] = counter2 % 10;
 }
// show which led 7 segment is ON and the value it display
void update7SEG1(int index){
	switch(index){
	case 0:
		// Display the first 7 SEG with led_buffer [0]
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		display7SEG1(led_buffer[0]);
		break;
	case 1:
		// Display the second 7 SEG with led_buffer [1]
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
		display7SEG1(led_buffer[1]);
		break;
	case 2:
		// Display the third 7 SEG with led_buffer [2]
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
		display7SEG1(led_buffer[2]);
		break;
	case 3:
		// Display the forth 7 SEG with led_buffer [3]
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin| EN1_Pin | EN2_Pin , SET);
		display7SEG1(led_buffer[3]);
		break;
	default:
		break;
	}
}


// display time value in LED 7 SEGMENT
void scanLed(){
	if(timer3_flag == 1){
		update7SEG1(index_led++);
		if(index_led > 3) index_led = 0;
		setTimer3(250);
	}
}



