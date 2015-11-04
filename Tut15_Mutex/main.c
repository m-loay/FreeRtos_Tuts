/*
 * main.c
 *
 *  Created on: Jan 22, 2014
 *      Author: mody
 */


#include <stdlib.h>
#include <string.h>

#include <avr/io.h>
#include"usart.h"
#include"rtos.h"


/*Set the priorties*/
#define LED_BLINK_PRIORITY1 ( tskIDLE_PRIORITY + 1 )
#define LED_BLINK_PRIORITY2 ( tskIDLE_PRIORITY + 2 )

/*flage to choose f1 or f2*/
static const  char *f1="Task1 is runining \r\n";
static const  char *f2="Task2 is runining \r\n";



/*Declaring the prototypes of functions*/
void uart_print( void * pvParameters );
void uart_print2( void * pvParameters );

/*Create the handle*/
xSemaphoreHandle xMutex;


/*The main*/
int main (void)
{
	/*Init USART*/
	USART_Init();

	/*Create the Mutex*/
	xMutex=xSemaphoreCreateMutex();

	/*The cont Tasks*/
	xTaskCreate( uart_print, ( signed char * ) "blink",
			configMINIMAL_STACK_SIZE,(void*)f1,
			LED_BLINK_PRIORITY1, NULL );

	xTaskCreate( uart_print2, ( signed char * ) "blink2",
			configMINIMAL_STACK_SIZE,(void*)f2,
			LED_BLINK_PRIORITY2, NULL );


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
	while(1)
	{
		USART_putstring(taskname);
		vTaskDelay(100);
		//_delay_ms(1000);
	}
}

void uart_print2 ( void * pvParameters )
{
	char *taskname;
	taskname=(char*)pvParameters;
	while(1)
	{
		USART_putstring(taskname);
		vTaskDelay(100);
		//_delay_ms(1000);
	}
}
