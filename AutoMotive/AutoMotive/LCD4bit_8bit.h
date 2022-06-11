/*
 * LCD *4bit.h
 * the model can write on any number of LCD
 * just define the data port & bins (D4,D5,D6,D7) & control port & bins (RS,RW,EN)
 * that connected to micro controller if the module will work in 4 bit mode
 * OR define the data port only & control port & bins (RS,RW,EN)
 * in main.c define the LCD like that
 ******************************************************************************************************************
 * LCD LCD_NAME = {mode(LCD_4BIT_MODE or LCD_8BIT_MODE),connected control port,connected RS pin in control port,
						connected RW pin in control port,connected EN pin in control port,connected data port,
						connected D4 pin in data port,connected D5 pin in data port,connected D6 pin in data port,
						connected D7 pin in data port};define from D4 to D7 if 4 bit mode will be use if 8 bit mode
						define them by zero value.
 *******************************************************************************************************************
 in main function first we initiate the lcd by LCDInit(&LCD_NAME) and use the model functions as needed
 * Created: 11/3/2021 10:55:31 AM
 *  Author: eng_s
 */ 


#ifndef LCD4BIT_H_
#define LCD4BIT_H_

#define F_CPU 16000000UL
#include "STD_types.h"
#include "Atmega32PortsRegister.h"
#include "Giop.h"
#include "DIO.h"
#include <util/delay.h>

#define LCD_4BIT_MODE		0
#define LCD_8BIT_MODE		1
#define SHIFT_RGHIT			1
#define SHIFT_LEFT			0

typedef struct {
//////////////mode////////////
	Uint8 mode;
//////// Control port ////////////
	Uint8 controlPort;
	Uint8 RSPin;
	Uint8 RWPin;
	Uint8 ENPin;
//////// Data port ////////////
	Uint8 dataPort;
	Uint8 D4Pin;
	Uint8 D5Pin;
	Uint8 D6Pin;
	Uint8 D7Pin;
	
}LCD;

void LCDEN (LCD *);								//to create pulse that allow the signal to store in lcd reg from micro controller(working LCD) the pulse width is 100 us
void PortWrite(LCD *,Uint8);					//to convert the data to hexadecimals and out it to the data port (working LCD , data)
void cmd (LCD *,Uint8);							//to out commands on data port (&working LCD , command)
void LCDInit(LCD * );							//to initiate the LCD (&working LCD )
void writeData(LCD * ,Uint8);					//to out character on data port (&working LCD , data)
void LcdSetCursor(LCD *,Uint8, Uint8);			//to set the cursor on LCD (&working LCD ,row(0 -> 1),columne(0 -> 15))
void Clear(LCD * );								//to clear the LCD (&working LCD )
void CursorOn(LCD * );							//to show cursor on LCD (&working LCD )
void CursorOff(LCD * );							//to hide cursor from LCD (&working LCD )
void CursorBlank(LCD * );						//to blank cursor on LCD (&working LCD )
void LCDShift(LCD * ,Uint8);					//to shift all data on LCD (&working LCD,(SHIFT_RGHIT or SHIFT_LEFT)
void CursorShift(LCD * ,Uint8);					//to shift the cursor on LCD (&working LCD,(SHIFT_RGHIT or SHIFT_LEFT)
void writeString(LCD * ,char *);				//to write string on LCD (&working LCD , array of character[] )
void writeIntager(LCD * ,Sint32);				//to write integer on LCD (&working LCD , array of character[] )
void LCDCastumCharacter (LCD *lcd,Uint8 Character[8],Uint8 MemoryLocation);	
												// to write spatial character that created its array of decimals on  https://www.quinapalus.com/hd44780udg.html

											



#endif /* LCD4BIT_H_ */