/*
 * Giop.h
 *
 * Created: 25/02/2022 10:07:26 PM
 *  Author: eng_s
 */ 


#ifndef GIOP_H_
#define GIOP_H_

#define set_bit(reg,bit)		(reg |=(1<<bit))
#define clr_bit(reg,bit)		(reg &=~(1<<bit))
#define toggle_bit(reg,bit)		(reg ^=(1<<bit))
#define get_bit(reg,bit)		((reg >>bit)&1)



#endif /* GIOP_H_ */