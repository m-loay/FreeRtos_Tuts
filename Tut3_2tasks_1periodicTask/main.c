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
#include"usart.h"


/*Set the priorties*/
#define LED_BLINK_PRIORITY1 ( tskIDLE_PRIORITY + 1 )
#define LED_BLINK_PRIORITY2 ( tskIDLE_PRIORITY + 1 )
#define LED_BLINK_PRIORITY3 ( tskIDLE_PRIORITY + 2 )
/*flage to choose f1 or f2*/
static const  char *f1="Task1 is runining \r\n";
static const  char *f2="Task2 is runining \r\n";
static const  char *f3="Task3 Periodic Task \r\n";


/*Declaring the prototypes of functions*/
void uart_print( void * pvParameters );
void uart_print_periodic (void * pvParameters);

/*The main*/
int main (void)
{
	/*The cont Tasks*/
	xTaskCreate( uart_print, ( signed char * ) "blink",
			configMINIMAL_STACK_SIZE,(void*)f1,
			LED_BLINK_PRIORITY1, NULL );

	xTaskCreate( uart_print, ( signed char * ) "blink2",
			configMINIMAL_STACK_SIZE,(void*)f2,
			LED_BLINK_PRIORITY2, NULL );

	/*The periodic Task*/
	xTaskCreate(uart_print_periodic, ( signed char * ) "blink3",
			configMINIMAL_STACK_SIZE,(void*)f3,
			LED_BLINK_PRIORITY3, NULL );


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
		vTaskDelay(100);
		//_delay_ms(1000);
	}
}
void uart_print_periodic (void * pvParameters)
{

	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	char *taskname;
	taskname=(char*)pvParameters;
	USART_Init();
	while(1)
	{

		USART_putstring(taskname);
		vTaskDelayUntil( &xLastWakeTime, 1000 );
	}
}

