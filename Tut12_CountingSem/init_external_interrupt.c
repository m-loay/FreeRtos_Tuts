/*
 * init_external_interrupt.c
 *
 *  Created on: Feb 11, 2014
 *      Author: mody
 */

#include "init_external_interrupt.h"
void Init_External_Interrupt (void)
{
	DDRC=0xFF;// o/p
	DDRD =0x00;//input
	DDRB =0x00;//input

	GICR=((1<<INT0)|(1<<INT1)|(1<<INT2));
	MCUCR=((1<<ISC01)|(1<ISC11));

	sei();
}
