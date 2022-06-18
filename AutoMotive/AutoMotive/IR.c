/*
 * IR.c
 *
 * Created: 6/11/2022 4:01:26 PM
 *  Author: eng_s
 */
#include "IR.h"
void IRInit(void)
{
	DIO_SetPinDir(IR_PORT,FRONT_IR_PIN,DIO_PIN_DIR_INPUT);
	DIO_SetPinDir(IR_PORT,BACK_IR_PIN,DIO_PIN_DIR_INPUT);
	GICR  = 1<<INT0_EN  | 1<<INT1_EN;		/* Enable INT0 & INT1*/
	MCUCR = 1<<INT0_RISINGEDGE_EN0 | 1<<INT0_RISINGEDGE_EN1 | 1<<INT1_RISINGEDGE_EN0 | 1<<INT1_RISINGEDGE_EN1;  // Trigger INT0 & INT1 on rising edge */
	
}