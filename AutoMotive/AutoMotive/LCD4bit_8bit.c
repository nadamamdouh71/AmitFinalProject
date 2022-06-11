/*
 * LCD4bit.c
 *
 * Created: 11/3/2021 11:07:20 AM
 *  Author: eng_s
 */ 
#include "LCD4bit_8bit.h"



void LCDEN (LCD *lcd){
	DIO_SetPinVal(lcd->controlPort,lcd->ENPin,DIO_PIN_HIGH);
	_delay_us(100);
	DIO_SetPinVal(lcd->controlPort,lcd->ENPin,DIO_PIN_LOW);
	_delay_us(100);
}
void PortWrite(LCD *lcd,Uint8 Data){
	
	if (lcd->mode == LCD_4BIT_MODE)
	{
		if ((Data & 1))
		{
			DIO_SetPinVal(lcd->dataPort,lcd->D4Pin,DIO_PIN_HIGH);
		} 
		else
		{
			DIO_SetPinVal(lcd->dataPort,lcd->D4Pin,DIO_PIN_LOW);
		}
		if ((Data & 2))
		{
			DIO_SetPinVal(lcd->dataPort,lcd->D5Pin,DIO_PIN_HIGH);
		}
		else
		{
			DIO_SetPinVal(lcd->dataPort,lcd->D5Pin,DIO_PIN_LOW);
		}
		if ((Data & 4))
		{
			DIO_SetPinVal(lcd->dataPort,lcd->D6Pin,DIO_PIN_HIGH);
		}
		else
		{
			DIO_SetPinVal(lcd->dataPort,lcd->D6Pin,DIO_PIN_LOW);
		}
		if ((Data & 8))
		{
			DIO_SetPinVal(lcd->dataPort,lcd->D7Pin,DIO_PIN_HIGH);
		}
		else
		{
			DIO_SetPinVal(lcd->dataPort,lcd->D7Pin,DIO_PIN_LOW);
		}

	} 
	else
	{
		DIO_SetPortVal(lcd->dataPort,Data);
	}


	
}
void cmd (LCD *lcd,Uint8 command){
	
	DIO_SetPinVal(lcd->controlPort,lcd->RSPin,DIO_PIN_LOW);
	if (lcd->mode == LCD_4BIT_MODE)
	{
		PortWrite(lcd,(command>>4));
		LCDEN (lcd);
		PortWrite(lcd,command & 0x0F);
		LCDEN (lcd);
	}
	else
	{
		PortWrite(lcd,command);
		LCDEN (lcd);
	}
	
}
void LCDInit(LCD *lcd)
{
	DIO_SetPinDir(lcd->controlPort,lcd->RSPin,DIO_PIN_DIR_OUTPUT);
	DIO_SetPinDir(lcd->controlPort,lcd->RWPin,DIO_PIN_DIR_OUTPUT);
	DIO_SetPinDir(lcd->controlPort,lcd->ENPin,DIO_PIN_DIR_OUTPUT);
	DIO_SetPinVal(lcd->controlPort,lcd->RWPin,DIO_PIN_LOW);
	if (lcd->mode == LCD_4BIT_MODE)
	{
		DIO_SetPinDir(lcd->dataPort,lcd->D4Pin,DIO_PIN_DIR_OUTPUT);
		DIO_SetPinDir(lcd->dataPort,lcd->D5Pin,DIO_PIN_DIR_OUTPUT);
		DIO_SetPinDir(lcd->dataPort,lcd->D6Pin,DIO_PIN_DIR_OUTPUT);
		DIO_SetPinDir(lcd->dataPort,lcd->D7Pin,DIO_PIN_DIR_OUTPUT);
		_delay_ms(20);
		
		///////////////////LCD 4 BIT MODE/////////////////////
		cmd(lcd,0x33);
		_delay_ms(1);
		cmd(lcd,0x32);
		_delay_ms(1);
		cmd(lcd,0x28);
		_delay_ms(1);
	} 
	else
	{
		DIO_SetPortDir(lcd->dataPort,DIO_PORT_DIR_OUTPUT);
		_delay_ms(20);
		///////////////////LCD 8 BIT MODE/////////////////////
		cmd(lcd,0x38);
		_delay_ms(1);
	}
	///////////// Reset process from datasheet /////////
	cmd(lcd,0x03);
	_delay_ms(5);
	cmd(lcd,0x03);
	_delay_ms(11);
	cmd(lcd,0x03);
	
	cmd(lcd,0x06); // clear LCD
	_delay_ms(1);
	
	cmd(lcd,0x0C); // cursor OFF
	_delay_ms(1);
	
	cmd(lcd,0x80); // ---8 go to first line and --0 is for 0th position
	_delay_ms(1);
}
void writeData(LCD *lcd,Uint8 Data){
	
	DIO_SetPinVal(lcd->controlPort,lcd->RSPin,DIO_PIN_HIGH);
	if (lcd->mode == LCD_4BIT_MODE)
	{
		PortWrite(lcd,(Data>>4));
		LCDEN (lcd);
		PortWrite(lcd,(Data & 0x0F));
		LCDEN (lcd);
	}
	else
	{
		PortWrite(lcd,Data);
		LCDEN (lcd);
	}
}
void LcdSetCursor(LCD *lcd,Uint8 row, Uint8 cloumn)
{
	cmd(lcd,(0x80 | ((row * 0x40) + cloumn) ));
}
void Clear(LCD *lcd){
	cmd(lcd,0x01);
}
void CursorOn(LCD *lcd){
	cmd(lcd,0x0E);
	_delay_ms(1);
}
void CursorOff(LCD *lcd){
	cmd(lcd,0x0C);
	_delay_ms(1);
}
void CursorBlank(LCD *lcd){
	cmd(lcd,0x0F);
	_delay_ms(1);
}
void LCDShift(LCD *lcd,Uint8 RightLeft){
	if (RightLeft)
	{
		cmd(lcd,0x1C);
		_delay_ms(1);
	} 
	else
	{
		cmd(lcd,0x18);
		_delay_ms(1);
	}
}
void CursorShift(LCD *lcd,Uint8 RightLeft){
	if (RightLeft)
	{
		cmd(lcd,0x14);
		_delay_ms(1);
	}
	else
	{
		cmd(lcd,0x10);
		_delay_ms(1);
	}
}
void writeString(LCD *lcd,char *LINE){
	int i;
	for (i = 0 ; LINE[i] != '\0' ; i++)
	{
		writeData(lcd,LINE[i]);
	}
}
void writeIntager(LCD * lcd,Sint32 Number)
{
	Uint32 temp = 1;
	if (Number < 0)
	{
		writeData(lcd,'-');
		Number *= -1;
	} 
	while(Number > 0)
	{
		temp = (temp * 10) + Number % 10;
		Number /=10;
	}
	while (temp > 1)
	{
		writeData(lcd,((temp%10) + 48));
		temp /= 10;
	}
}
void LCDCastumCharacter (LCD *lcd,Uint8 Character[8],Uint8 MemoryLocation){ //get your graph decimal from https://www.quinapalus.com/hd44780udg.html
	cmd(lcd,(64+(8*MemoryLocation)));		//call the CGRAM to create the character ant store it on memory location (0(0x40) -> 7(0x78))
	_delay_ms(1);
	for (int count = 0;count <=7;count++)	//create the character on GCRAM 
	{
		writeData(lcd,Character[count]);
	}
	cmd(lcd,0x0E);
	_delay_ms(1);
	cmd(lcd,0x0C);
	_delay_ms(1);
	/* 
	*	After finish creation of character just call LcdSetCursor(&LCD_NAME,row, column) to chose the position
	*	that the character will write in and call writeData(&LCD_NAME, MemoryLocation that the character stored in
	*/
}