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
#define Task1_PRIORITY1  2
#define Task2_PRIORITY2  1


/*Declaring the prototypes of functions*/
void uart_print_Task1 ( void * pvParameters );
void uart_print_Task2 ( void * pvParameters );
/*Declare the handle for task 2*/
xTaskHandle xTask2Handle;

/*The main*/
int main (void)
{
	/*The cont Tasks*/
	xTaskCreate(uart_print_Task1, ( signed char * ) "Task1",
			configMINIMAL_STACK_SIZE,NULL,
			Task1_PRIORITY1,NULL);

	/*Start scheduler function*/
	vTaskStartScheduler();

	while(1)
	{

	}
	return(0);
}

/*Function of Tasks*/
void uart_print_Task1 ( void * pvParameters )
{


	USART_Init();
	while(1)
	{
		USART_putstring("Task 1 is running \r\n");
		xTaskCreate(uart_print_Task2, ( signed char * ) "Task2",
				configMINIMAL_STACK_SIZE,NULL,
				Task2_PRIORITY2, NULL );
		vTaskDelay(100);
	}
}

void uart_print_Task2 ( void * pvParameters )
{
	USART_Init();
	while(1)
	{
		USART_putstring("Task 2 is running \r\n");
		USART_putstring("Task 2 is deleting itself \r\n");
		vTaskDelete(NULL);
	}
}
