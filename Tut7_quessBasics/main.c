/*
 * main.c
 *
 *  Created on: Jan 22, 2014
 *      Author: mody
 */


#include <stdlib.h>
#include <string.h>

#include <avr/io.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include"FreeRTOSConfig.h"
#include "task.h"
#include"queue.h"
#include"usart.h"


/*Set the priorties*/
#define SENDER_1_PRIORITY  1
#define SENDER_2_PRIORITY  1
#define RECEIVER_PRIORITY  2


/*Declaring the prototypes of functions*/
void uart_print_sender ( void * pvParameters );
void uart_print_receiver ( void * pvParameters );

/*vlaues to send*/
static const char *f1="100";
static const char *f2="200";
/*Declare the handle for queue*/
xQueueHandle xQueue;

/*The main*/
int main (void)
{
	/*Create the size of quee*/
	xQueue=xQueueCreate( 5, sizeof(char) );

	/*The sender Tasks*/
	xTaskCreate(uart_print_sender, ( signed char * ) "sender1",
			configMINIMAL_STACK_SIZE,(void *)f1,
			SENDER_1_PRIORITY,NULL);
	xTaskCreate(uart_print_sender, ( signed char * ) "sender2",
			configMINIMAL_STACK_SIZE,(void *)f2,
			SENDER_2_PRIORITY,NULL);

	/*The receiver Task*/
	xTaskCreate(uart_print_receiver, ( signed char * ) "receiver",
			configMINIMAL_STACK_SIZE,NULL,
			RECEIVER_PRIORITY,NULL);

	/*Start scheduler function*/
	vTaskStartScheduler();

	while(1)
	{

	}
	return(0);
}

/*Function of Tasks*/
void uart_print_sender ( void * pvParameters )
{
	char *ValueToSend;
	ValueToSend=(char*)pvParameters;
	portBASE_TYPE xStatus;
	USART_Init();
	while(1)
	{
		xStatus=xQueueSendToBack(xQueue,&ValueToSend,0);
		if (xStatus==pdPASS)
		{
			USART_putstring("\r\nsucced\r\n");
		}

		taskYIELD();

	}
}

void uart_print_receiver ( void * pvParameters )
{
	char *ValueToReceive;
	ValueToReceive=(char*)pvParameters;
	portBASE_TYPE xStatus;
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;
	USART_Init();
	while(1)
	{

		xStatus = xQueueReceive( xQueue, &ValueToReceive, xTicksToWait );
		if( xStatus == pdPASS )
		{

			USART_putstring( "\r\nReceived = \r\n");
			USART_putstring( ValueToReceive);
		}
		else
		{

			USART_putstring( "\r\nCould not receive from the queue.\r\n" );
		}

		vTaskDelay(100);

	}
}
