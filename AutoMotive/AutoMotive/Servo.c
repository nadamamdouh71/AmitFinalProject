/*
 * Servo.c
 *
 * Created: 6/11/2022 3:11:20 PM
 *  Author: nada
 */ 
#include "Servo.h"

void ServoInit(void)
{
  DDRC = 0x01; //RC0 output pin
  PORTC = 0x00;
}
void ServoGoToAngle(Sint8 Angle)
{
	if (Angle == 90)
	{
		PORTC = 0x01;         //Rotation to 0 degree
		_delay_us(1000);      //Rotation to 0 degree
		PORTC = 0x00;         //Rotation to 0 degree
		_delay_ms(500);
	} 
	else if (Angle == 0)
	{
		PORTC = 0x01;         //Rotation to 90 degree
		_delay_us(1500);      //Rotation to 90 degree
		PORTC = 0x00;         //Rotation to 90 degree
		_delay_ms(500);
	}
	else if (Angle == -90)
	{
		PORTC = 0x01;         //Rotation to 180 degree
		_delay_us(2000);      //Rotation to 180 degree
		PORTC = 0x00;         //Rotation to 180 degree
		_delay_ms(500);
	}  
}
