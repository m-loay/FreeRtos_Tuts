/*
 * main.c
 *
 *  Created on: Jan 22, 2014
 *      Author: mody
 */


#include <stdlib.h>
#include <string.h>

#include <avr/io.h>
#include<util/delay.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include"FreeRTOSConfig.h"
#include "task.h"
#include "queue.h"


/*Set the priorties*/
#define Task1_PRIORITY1  ( tskIDLE_PRIORITY + 1 )
#define Task2_PRIORITY2  ( tskIDLE_PRIORITY + 1 )
#define Task3_PRIORITY3  ( tskIDLE_PRIORITY + 2 )

/*create the quee handel for the quee*/
xQueueHandle xQueue;



/*Declaring the prototypes of functions*/
void uart_print_sender ( void * pvParameters );
void uart_print_receiver ( void * pvParameters );
/*define the structure of data of sender 1 and 2*/
typedef struct
{
	char msg[20];
    char sender;
}xdata;

static const xdata xStructsToSend[ 2 ] =
{
		{ "100", 'a' }, /* Used by Sender1. */
		{ "50", 'b'} /* Used by Sender2. */
};


/*The main*/
int main (void)
{
	/*Iniiatlize the function*/
	USART_Init();
	/*creat the details of quee*/
	xQueue = xQueueCreate( 3, sizeof( xdata ) );

	/*The cont Tasks*/
	/*Ther sender tasks*/
	xTaskCreate( uart_print_sender, ( signed char * ) "Task1",
			configMINIMAL_STACK_SIZE, &( xStructsToSend[ 0 ] ),Task1_PRIORITY1, NULL );

	xTaskCreate( uart_print_sender, ( signed char * ) "Task2",
			configMINIMAL_STACK_SIZE, &( xStructsToSend[ 1 ] ), Task2_PRIORITY2, NULL );


	/*The receiver task*/
	xTaskCreate(uart_print_receiver, ( signed char * ) "Task3",
			configMINIMAL_STACK_SIZE,NULL,Task3_PRIORITY3, NULL );



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
	xdata xSenderStructure;
	xdata *pxMessage;
	while(1)
	{

		xQueueSend(xQueue,&xSenderStructure,portMAX_DELAY);
		vTaskDelay(100);
		taskYIELD();
	}
}

void uart_print_receiver ( void * pvParameters )
{
	xdata xReceivedStructure;
	portBASE_TYPE xStatus;
	while(1)
	{

		xStatus = xQueueReceive( xQueue, &xReceivedStructure, 1000 );
		if (xStatus==pdPASS)
		{
			if ( xReceivedStructure.sender == 'a')
			{
				USART_putstring("\r\n Receiving Successful from 1 \r\n");
				USART_putstring(xReceivedStructure.msg);
				vTaskDelay(100);
			}
			else
			{
				USART_putstring("\r\n Receiving Successful from 2 \r\n");
				USART_putstring(xReceivedStructure.msg);
				vTaskDelay(100);
			}
		}
		else
		{
			USART_putstring("\r\n fail \r\n");
		}
	}
}


