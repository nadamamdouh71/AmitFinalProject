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


void IRInit(void);




#endif /* IR_H_ */