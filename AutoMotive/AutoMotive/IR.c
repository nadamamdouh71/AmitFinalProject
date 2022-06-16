/*
 * IR.c
 *
 * Created: 6/11/2022 4:01:26 PM
 *  Author: eng_s
 */
#include "IR.h"
void IRInit(void)
{
	DIO_SetPinDir(IR_PORT,FRONT_IR_PIN,DIO_PIN_DIR_OUTPUT);
	DIO_SetPinDir(IR_PORT,BACK_IR_PIN,DIO_PIN_DIR_OUTPUT);
}