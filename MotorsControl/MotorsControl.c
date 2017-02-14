/* MotorsControl.c
Defines functions used to control PWM signals to ESCs
Uses pigpio library 

Version 1.0  -  Joseph Carlos  2/12/2017	*/

#include "MotorsControl.h"

//Init GPIO Library and Set Motor Pins
//Returns 0 for OK and 1 on failure
int MotorsInit(void){
   if (gpioInitialise() < 0){
      return 1;
   }
   gpioSetMode(TOP_LEFT, PI_OUTPUT);
   gpioSetMode(TOP_RIGHT, PI_OUTPUT);
   gpioSetMode(TOP_FRONT, PI_OUTPUT);
   gpioSetMode(SIDE_LEFT, PI_OUTPUT);
   gpioSetMode(SIDE_RIGHT, PI_OUTPUT);
   return 0;
}

//Sets the specified PWM pin to the given duty cycle (0 - 255)
//Returns 0 for OK and 1 on failure
int MotorsSetSpeed(unsigned motorPin, unsigned dutyCycle){
   if (dutyCycle < 0 || dutyCycle > 255){
      return 1;
   }
   return gpioPWM(motorPin, dutyCycle);
}

//Returns the PMW of the given pin (0 - 255)
int MotorsGetSpeed(unsigned motorPin){
   return gpioGetPWMdutycycle(motorPin);
}

//Sets all 3 top motors to full speed (downwards)
void MotorsDive(void){
	gpioPWM(TOP_LEFT, FORWARD_MAX);
	gpioPWM(TOP_RIGHT, FORWARD_MAX);
	gpioPWM(TOP_FRONT, FORWARD_MAX);
}

//Sets all 3 top motors to full speed (upwards)
void MotorsRise(void){
	gpioPWM(TOP_LEFT, REVERSE_MAX);
	gpioPWM(TOP_RIGHT, REVERSE_MAX);
	gpioPWM(TOP_FRONT, REVERSE_MAX);
}

//Sets both side motors to full speed (fowards)
void MotorsDriveForward(void){
	gpioPWM(SIDE_RIGHT, FORWARD_MAX);
	gpioPWM(SIDE_LEFT, FORWARD_MAX);
}

//Sets both side motors to full speed (backwards)
void MotorsDriveReverse(void){
	gpioPWM(SIDE_RIGHT, REVERSE_MAX);
	gpioPWM(SIDE_LEFT, REVERSE_MAX);
}

//Sets side motors to spin right
void MotorsSpinRight(void){
	gpioPWM(SIDE_RIGHT, REVERSE_MAX);
	gpioPWM(SIDE_LEFT, FORWARD_MAX);
}

//Sets side motors to spin left
void MotorsSpinLeft(void){
	gpioPWM(SIDE_RIGHT, FORWARD_MAX);
	gpioPWM(SIDE_LEFT, REVERSE_MAX);
}


//Sets side motors to arc right
void MotorsArcRight(void){
	gpioPWM(SIDE_RIGHT, STOP);
	gpioPWM(SIDE_LEFT, FORWARD_MAX);
}

//Sets side motors to arc left
void MotorsArcLeft(void){
	gpioPWM(SIDE_RIGHT, FORWARD_MAX);
	gpioPWM(SIDE_LEFT, STOP);
}

