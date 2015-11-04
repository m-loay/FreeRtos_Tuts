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
#define Task1_PRIORITY1  ( tskIDLE_PRIORITY+2  )
#define Task2_PRIORITY2  ( tskIDLE_PRIORITY+2  )




/*Declaring the prototypes of functions*/
void uart_print ( void * pvParameters );

/*Strings to send*/
static const  char *f1="100\r\n";
static const  char *f2="200\r\n";


/*The main*/
int main (void)
{
	/*Iniiatlize the function*/
	USART_Init();

	/*The cont Tasks*/
	xTaskCreate(uart_print, ( signed char * ) "Task1",
			configMINIMAL_STACK_SIZE,(void*)f1,
			Task1_PRIORITY1, NULL );

	xTaskCreate(uart_print, ( signed char * ) "Task2",
			configMINIMAL_STACK_SIZE,(void*)f2,
			Task2_PRIORITY2, NULL );



	/*Start scheduler function*/
	vTaskStartScheduler();

	while(1)
	{

	}
	return(0);
}

/*Function of Tasks*/
void uart_print ( void * pvParameters )
{
	char *taskname;
	taskname=(char*)pvParameters;
	USART_Init();
	while(1)
	{
		USART_putstring(taskname);
		//vTaskDelay(1000);
		//_delay_ms(1000);
	}
}
