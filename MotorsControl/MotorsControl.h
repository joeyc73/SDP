/* MotorsControl.h
Declares values and functions used in MotorsControl.c
Uses pigpio library to control PWM signals to motor ESCs 

Version 1.0  -  Joseph Carlos  2/12/2017	*/


#ifndef MOTORS_CONTROL
#define MOTORS_CONTROL

#include "pigpio/pigpio.h"

//Define PWM range for ESC
#define FORWARD_MAX 255
#define STOP 127
#define REVERSE_MAX 0

//Define GPIO pins used for motors
#define TOP_LEFT 10
#define TOP_RIGHT 11
#define TOP_FRONT 12
#define SIDE_LEFT 13
#define SIDE_RIGHT 14

//Init GPIO Library and Set Motor Pins
//Returns 0 for OK and 1 on failure
int MotorsInit(void);

//Sets the specified PWM pin to the given duty cycle (0 - 255)
//Returns 0 for OK and 1 on failure
int MotorsSetSpeed(unsigned motorPin, unsigned dutyCycle);

//Returns the PMW of the given pin (0 - 255)
int MotorsGetSpeed(unsigned motorPin);

//Sets all 3 top motors to full speed (downwards)
void MotorsDive(void);

//Sets all 3 top motors to full speed (upwards)
void MotorsRise(void);

//Sets both side motors to full speed (fowards)
void MotorsDriveForward(void);

//Sets both side motors to full speed (backwards)
void MotorsDriveReverse(void);

//Sets side motors to spin right
void MotorsSpinRight(void);

//Sets side motors to spin left
void MotorsSpinLeft(void);

//Sets side motors to arc right
void MotorsArcRight(void);

//Sets side motors to arc left
void MotorsArcLeft(void);














#endif //MOTORS_CONTROL
