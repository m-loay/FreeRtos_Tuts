/*
 * usart.c
 *
 *  Created on: Jan 3, 2014
 *      Author: mody
 */

#include"usart.h"

/*Init the UART module*/
void USART_Init(void)
{
	/*set the value of UBRR according the frequency of crystal*/
	UBRRH = (unsigned char)(UBRR_VALUE>>8);
	UBRRL = (unsigned char)(UBRR_VALUE);
	/*set 8bit mode data , 2 stop bit*/
	UCSRC |= (1<<UCSZ1)|(1<<UCSZ0)|(1<<USBS);
	/*Enable transmitting and receiving data*/
	UCSRB|=(1<<RXEN)|(1<<TXEN);
}

/*Function to transmit a char*/
void USART_Transmit( unsigned char data )
{
	xSemaphoreTake( xMutex, portMAX_DELAY );
	{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
		;
	/* Put data into buffer, sends the data */
	UDR = data;
	}
	xSemaphoreGive( xMutex );
}

/*Function to receive a char*/
unsigned char USART_Receive( void )
{
	unsigned char data;
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
		;
	/* Get and return received data from buffer */
	data=UDR;
	return data;
}

/*Function to transmit a whole string*/
void USART_putstring(char* StringPtr)
{

	xSemaphoreTake( xMutex, portMAX_DELAY );
	{
	unsigned char i=0;
	while (StringPtr[i] !=0)
	{
		USART_Transmit(StringPtr[i]);
		i++;
	}
	}
	xSemaphoreGive( xMutex );
}



