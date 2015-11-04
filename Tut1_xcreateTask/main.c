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
#include"led_blink.h"

/*Set the priorties*/
#define LED_BLINK_PRIORITY ( tskIDLE_PRIORITY + 1 )
#define LED_Toggle_PRIORITY ( tskIDLE_PRIORITY + 2 )

/*Declaring the prototypes of functions*/
 void led_blink( void * pvParameters );
 void led_toggle( void * pvParameters );

 /*The main*/
int main (void)
{
	xTaskCreate( led_blink, ( signed char * ) "blink",
				configMINIMAL_STACK_SIZE, NULL,
				LED_BLINK_PRIORITY, NULL );
	vTaskStartScheduler();

	while(1)
	{

	}
	return(0);
}

void led_blink( void * pvParameters )
{
	xTaskCreate(led_toggle,"Led toggle",configMINIMAL_STACK_SIZE,NULL,
				LED_Toggle_PRIORITY,NULL);


	led_toggle_Init();
	while(1)
	{
		toggle_led();
		vTaskDelay(1000);

	}
}

void led_toggle( void * pvParameters )
{
	led_toggle_Init();
	while(1)
	{

		toggle_led2();
		vTaskDelay(40);
	}
}
