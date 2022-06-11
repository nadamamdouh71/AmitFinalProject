/*
 * DIO.c
 *
 * Created: 28/02/2022 10:15:28 PM
 *  Author: eng_s
 */ 
#include "DIO.h"

void DIO_SetPortDir(Uint8 Port,Uint8 Dir)
{
	switch(Dir)
	{
		case DIO_PORT_DIR_INPUT:
			switch(Port)
			{
				case DIO_PORTA:
					DDRA = 0X00;
				break;
				case DIO_PORTB:
					DDRB = 0X00;
				break;
				case DIO_PORTC:
					DDRC = 0X00;
				break;
				case DIO_PORTD:
					DDRD = 0X00;
				break;
			}
		break;
		case DIO_PORT_DIR_OUTPUT:
			switch(Port)
			{
				case DIO_PORTA:
					DDRA = 0XFF;
				break;
				case DIO_PORTB:
					DDRB = 0XFF;
				break;
				case DIO_PORTC:
					DDRC = 0XFF;
				break;
				case DIO_PORTD:
					DDRD = 0XFF;
				break;
			}
		break;
	}
	
}
void DIO_SetPinDir(Uint8 Port,Uint8 Pin,Uint8 Dir)
{
	switch(Dir)
	{
		case DIO_PIN_DIR_OUTPUT:
			switch(Port)
			{
				case DIO_PORTA:
					set_bit(DDRA,Pin);
				break;
				case DIO_PORTB:
					set_bit(DDRB,Pin);
				break;
				case DIO_PORTC:
					set_bit(DDRC,Pin);
				break;
				case DIO_PORTD:
					set_bit(DDRD,Pin);
				break;
			}
		break;
		case DIO_PIN_DIR_INPUT:
			switch(Port)
			{
				case DIO_PORTA:
					clr_bit(DDRA,Pin);
				break;
				case DIO_PORTB:
					clr_bit(DDRB,Pin);
				break;
				case DIO_PORTC:
					clr_bit(DDRC,Pin);
				break;
				case DIO_PORTD:
					clr_bit(DDRD,Pin);
				break;
			}
		break;
	}
	
}

void DIO_SetPortVal(Uint8 Port,Uint8 Val)
{
	switch(Port)
	{
		case DIO_PORTA:
			PORTA = Val;
		break;
		case DIO_PORTB:
			PORTB = Val;
		break;
		case DIO_PORTC:
			PORTC = Val;
		break;
		case DIO_PORTD:
			PORTD = Val;
		break;
	}
}
void DIO_SetPinVal(Uint8 Port,Uint8 Pin,Uint8 Val)
{
	switch(Val)
	{
		case DIO_PIN_HIGH:
		switch(Port)
		{
			case DIO_PORTA:
			set_bit(PORTA,Pin);
			break;
			case DIO_PORTB:
			set_bit(PORTB,Pin);
			break;
			case DIO_PORTC:
			set_bit(PORTC,Pin);
			break;
			case DIO_PORTD:
			set_bit(PORTD,Pin);
			break;
		}
		break;
		case DIO_PIN_LOW:
		switch(Port)
		{
			case DIO_PORTA:
			clr_bit(PORTA,Pin);
			break;
			case DIO_PORTB:
			clr_bit(PORTB,Pin);
			break;
			case DIO_PORTC:
			clr_bit(PORTC,Pin);
			break;
			case DIO_PORTD:
			clr_bit(PORTD,Pin);
			break;
		}
		break;
	}
}

Uint8 DIO_ReadPortVal(Uint8 Port)
{
	Uint8 value = 0;
	switch (Port)
	{
		case DIO_PORTA:
		value = PINA;
		break;
		case DIO_PORTB:
		value = PINB;
		break;
		case DIO_PORTC:
		value = PINC;
		break;
		case DIO_PORTD:
		value = PIND;
		break;
	}
	return value;
}
Uint8 DIO_ReadPinVal(Uint8 Port,Uint8 Pin)
{
	Uint8 value = 0;
	switch (Port)
	{
		case DIO_PORTA:
		value = get_bit(PINA,Pin);
		break;
		case DIO_PORTB:
		value = get_bit(PINB,Pin);
		break;
		case DIO_PORTC:
		value = get_bit(PINC,Pin);
		break;
		case DIO_PORTD:
		value = get_bit(PIND,Pin);
		break;
	}
	return value;
}

void DIO_SetPullUp(Uint8 Port,Uint8 Pin)
{
	switch(Port)
	{
		case DIO_PORTA:
		clr_bit(DDRA,Pin);
		set_bit(PORTA,Pin);
		break;
		case DIO_PORTB:
		clr_bit(DDRB,Pin);
		set_bit(PORTB,Pin);
		break;
		case DIO_PORTC:
		clr_bit(DDRC,Pin);
		set_bit(PORTC,Pin);
		break;
		case DIO_PORTD:
		clr_bit(DDRD,Pin);
		set_bit(PORTD,Pin);
		break;
	}
}

void DIO_TogglePin(Uint8 Port,Uint8 Pin)
{
	switch(Port)
	{
		case DIO_PORTA:
		toggle_bit(PORTA,Pin);
		break;
		case DIO_PORTB:
		toggle_bit(PORTB,Pin);
		break;
		case DIO_PORTC:
		toggle_bit(PORTC,Pin);
		break;
		case DIO_PORTD:
		toggle_bit(PORTD,Pin);
		break;
	}
}
