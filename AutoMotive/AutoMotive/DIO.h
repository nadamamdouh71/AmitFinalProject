/*
 * DIO.h
 *
 * Created: 28/02/2022 10:15:10 PM
 *  Author: eng_s
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "STD_types.h"
#include "Atmega32PortsRegister.h"
#include "Giop.h"

#define  DIO_PORTA					0
#define  DIO_PORTB					1
#define  DIO_PORTC					2
#define  DIO_PORTD					3

#define  DIO_PIN_0					0
#define  DIO_PIN_1					1
#define  DIO_PIN_2					2
#define  DIO_PIN_3					3
#define  DIO_PIN_4					4
#define  DIO_PIN_5					5
#define  DIO_PIN_6					6
#define  DIO_PIN_7					7

#define  DIO_PIN_DIR_INPUT			0
#define  DIO_PIN_DIR_OUTPUT			1

#define  DIO_PORT_DIR_INPUT			0X00
#define  DIO_PORT_DIR_OUTPUT		0XFF

#define  DIO_PIN_LOW				0
#define  DIO_PIN_HIGH				1

#define  DIO_PORT_LOW				0X00
#define  DIO_PORT_HIGH				0XFF

void DIO_SetPortDir(Uint8 Port,Uint8 Dir);
void DIO_SetPinDir(Uint8 Port,Uint8 Pin,Uint8 Dir);

void DIO_SetPortVal(Uint8 Port,Uint8 Val);
void DIO_SetPinVal(Uint8 Port,Uint8 Pin,Uint8 Val);

Uint8 DIO_ReadPortVal(Uint8 Port);
Uint8 DIO_ReadPinVal(Uint8 Port,Uint8 Pin);

void DIO_SetPullUp(Uint8 Port,Uint8 Pin);

void DIO_TogglePin(Uint8 Port,Uint8 Pin);



#endif /* DIO_H_ */