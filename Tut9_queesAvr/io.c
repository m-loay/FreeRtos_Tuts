/*
 * io.c
 *
 *  Created on: Feb 1, 2014
 *      Author: mody
 */


#include"io.h"
#define DDR_PORT_IN 	DDRB
#define PIN_PORT_IN  	PINB
#define PORT_IN  		PORTB

#define DDR_PORT_OUT 	DDRA
#define PORT_OUT 		PORTA

void Init_io (void)
{
	/*Set Port B as input*/
	DDR_PORT_IN=0x00;
	/*Make it high*/
	PORT_IN=0xFF;
	/*Set PORT A as an output*/
	DDR_PORT_OUT=0xFF;
}

unsigned char input(void)
{
	return PIN_PORT_IN;
}

void output (unsigned char write)
{
	PORT_OUT=write;
}
