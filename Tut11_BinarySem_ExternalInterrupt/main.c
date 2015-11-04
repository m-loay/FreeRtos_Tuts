
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "init_external_interrupt.h"

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/*The Priorties of the system*/

#define LED_BLINK			( tskIDLE_PRIORITY + 1 )

/*The Prototypes of functions of tasks*/
static void led_blink( void *pvParameters );

/*Create the semaphore handle*/
xSemaphoreHandle xBinarySemaphore;


int main( void )
{
	/*Function to initialize the external interrupt*/
	Init_External_Interrupt();

	/*The interrupt handler*/
	vSemaphoreCreateBinary( xBinarySemaphore );

	/*The tasks of the system*/
	xTaskCreate( led_blink, ( signed char * ) "input",
			configMINIMAL_STACK_SIZE, NULL,
			LED_BLINK, NULL );

	/*Start the Scheduler*/
	vTaskStartScheduler();
	return 0;
}
/*-----------------------------------------------------------*/

static void led_blink( void *pvParameters)
{
	xSemaphoreTake(xBinarySemaphore, portMAX_DELAY);
	while(1)
	{
		xSemaphoreTake( xBinarySemaphore, portMAX_DELAY );
		PORTC^=(1<<0);
	}
}

ISR (INT0_vect)
{
	signed portBASE_TYPE woken;
	xSemaphoreGiveFromISR(xBinarySemaphore, &woken);
}


