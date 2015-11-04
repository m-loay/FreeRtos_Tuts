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
#define LED_BLINK_PRIORITY2 ( tskIDLE_PRIORITY + 1 )

/*Vtask delay values*/
const int _delay_1= 1000;
const int _delay_2 =40;


/*Declaring the prototypes of functions*/
 void led_blink( void * pvParameters );


 /*The main*/
int main (void)
{
	/*The Tasks*/
	xTaskCreate( led_blink, ( signed char * ) "blink",
				configMINIMAL_STACK_SIZE,(void *)_delay_1,
				LED_BLINK_PRIORITY, NULL );
	xTaskCreate( led_blink, ( signed char * ) "blink2",
					configMINIMAL_STACK_SIZE,(void *)_delay_2,
					LED_BLINK_PRIORITY2, NULL );

	vTaskStartScheduler();

	while(1)
	{

	}
	return(0);
}

/*Function of Tasks*/
void led_blink( void * pvParameters )
{
	int delay;
	delay=(int *)pvParameters;
	led_toggle_Init();
	while(1)
	{
		if(delay==1000)
		{
		toggle_led();
		vTaskDelay(delay);
		}
		else
		{
		toggle_led2();
		vTaskDelay(delay);
		}
	}
}


