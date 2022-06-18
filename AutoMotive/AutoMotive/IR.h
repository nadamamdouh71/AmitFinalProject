/*
 * IR.h
 *
 * Created: 6/11/2022 4:01:40 PM
 *  Author: eng_s
 */
#ifndef IR_H_
#define IR_H_
#include "DIO.h"
#include "Giop.h"
#include "Atmega32PortsRegister.h"
 
#define IR_PORT			DIO_PORTD
#define FRONT_IR_PIN	DIO_PIN_2
#define BACK_IR_PIN		DIO_PIN_3
#define INT0_RISINGEDGE_EN0		0
#define INT0_RISINGEDGE_EN1		1
#define INT1_RISINGEDGE_EN0		2
#define INT1_RISINGEDGE_EN1		3
#define INT0_EN					6
#define INT1_EN					7

void IRInit(void);




#endif /* IR_H_ */