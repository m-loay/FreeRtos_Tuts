/*
 * usart_CFG.h
 *
 *  Created on: Jan 3, 2014
 *      Author: mody
 */

#ifndef USART_CFG_H_
#define USART_CFG_H_
/*Select the baude rate and the target frequency*/
#define USART_BAUDRATE 9600
#define F_CLK 8000000UL
#define UBRR_VALUE (((F_CLK / (USART_BAUDRATE * 16UL))) - 1)


#endif /* USART_CFG_H_ */
