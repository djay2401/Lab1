/*
 * global.h
 *
 *  Created on: Oct 27, 2024
 *      Author: admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "traffic_light.h"
#include "input_reading_processing.h"

extern int timeRed;
extern int timeGreen;
extern int timeYellow;
extern int olderTimeRed;
extern int olderTimeYellow;
extern int olderTimeGreen;
extern int tempRed;
extern int tempGreen;
extern int tempYellow;

extern int defaultTimeRed;
extern int defaultTimeGreen;
extern int defaultTimeYellow;

#define INIT 1
#define AUTO_RED_GREEN 	2
#define AUTO_RED_YELLOW 3
#define AUTO_GREEN_RED 	4
#define AUTO_YELLOW_RED 5

#define MAN_MODE1 10
#define MAN_MODE2 11
#define MAN_MODE3 12
#define MAN_MODE4 13


extern int status;



#endif /* INC_GLOBAL_H_ */
