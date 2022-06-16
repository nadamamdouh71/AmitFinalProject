/*
 * AutoMotive.c
 *
 * Created: 6/11/2022 12:01:23 PM
 * Author : eng_s
 */
#ifndef F_CPU
#define F_CPU 16000000UL // 8 MHz clock speed
#endif
#include "DIO.h"
#include "Giop.h"
#include "Atmega32PortsRegister.h" 
#include "LCD4bit_8bit.h"
#include "UltraSonic.h"
#include "Servo.h"
#include "IR.h"
#include <avr/interrupt.h>
#include <util/delay.h>

void SystemInit(void)
{
	LCD Lcd1;
	Lcd1.mode = LCD_4BIT_MODE;
	Lcd1.controlPort = DIO_PORTB;
	Lcd1.RSPin = DIO_PIN_1;
	Lcd1.RWPin = DIO_PIN_2;
	Lcd1.ENPin = DIO_PIN_3;
	Lcd1.dataPort = DIO_PORTA;
	Lcd1.D4Pin = DIO_PIN_4;
	Lcd1.D5Pin = DIO_PIN_5;
	Lcd1.D6Pin = DIO_PIN_6;
	Lcd1.D7Pin = DIO_PIN_7;
	LCDInit(&Lcd1);
	IRInit();
	GICR  = 1<<INT0  | 1<<INT1;		/* Enable INT0*/
	MCUCR = 1<<ISC01 | 1<<ISC00;  /* Trigger INT0 on rising edge */
	sei();
}

int main(void)
{
    /* Replace with your application code */
	SystemInit();
	
    while (1) 
    {
		
    }
}

ISR(INT0_vect)
{
	
}
ISR(INT1_vect)
{
	
}