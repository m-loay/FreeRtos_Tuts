/*
 * usart.h
 *
 *  Created on: Jan 3, 2014
 *      Author: mody
 */

#ifndef USART_H_
#define USART_H_
#include<avr/io.h>
#include "usart_CFG.h"

void USART_Init(void);
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );
void USART_putstring(char* StringPtr);

#endif /* USART_H_ */
