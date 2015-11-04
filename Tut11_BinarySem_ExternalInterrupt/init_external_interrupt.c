/*
 * init_external_interrupt.c
 *
 *  Created on: Feb 11, 2014
 *      Author: mody
 */

#include "init_external_interrupt.h"
void Init_External_Interrupt (void)
{
	DDRC|=(1<<0);//set as an o/p
	DDRD &=~(1<<2);//set as an i/p
	PORTD|=(1<<2);//make it high to take low signal
	GICR=1<<INT0;//select the interrupt

	sei();//to enable interrupt
}
