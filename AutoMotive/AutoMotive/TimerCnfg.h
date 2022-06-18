/*
 * TimerCnfg.h
 *
 * Created: 4/1/2022 10:45:32 AM
 *  Author: eng_s
 */ 


#ifndef TIMERCNFG_H_
#define TIMERCNFG_H_

typedef struct{
	Uint8	TimerSelect;
	Uint8	TimerMode;
	Uint16	TimerPrescaler;
	Uint32	TimerDelay;
	Uint8	TimerCompSelect;
	Uint8	TimerCompMode;
	Uint8	TimerInterruptSelect;
}TimerControl;







#endif /* TIMERCNFG_H_ */