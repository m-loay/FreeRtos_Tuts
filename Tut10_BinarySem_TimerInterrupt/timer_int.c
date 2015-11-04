/*
 * timer_int.c
 *
 *  Created on: Feb 11, 2014
 *      Author: mody
 */
#include"timer_int.h"

void Timer_Init(void)
{
	DDRB|=1<<PINB0;

	TCCR1A=0x00;//normal mode
	TCCR1B=0x04;//normal mode ,prescalar 256

	TCNT1H=0x85;
	TCNT1L=0xEE;

	TIMSK=1<<TOIE1;//unmask the timer interrupt
	sei ();//enable interrupt
}
