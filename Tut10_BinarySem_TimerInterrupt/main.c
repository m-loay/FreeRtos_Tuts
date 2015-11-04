
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "usart.h"

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/*The Priorties of the system*/
#define LED_BLINK	(tskIDLE_PRIORITY + 1)

/*The Prototypes of functions of tasks*/
static void led_blink( void *pvParameters );

/*Create the semaphore handle*/
xSemaphoreHandle xBinarySemaphore;

int main( void )
{
	/*Function to initialize the i/os and usart*/
	Timer_Init();

	/*The interrupt handler*/
	vSemaphoreCreateBinary( xBinarySemaphore );

	/*The tasks of the system*/
	xTaskCreate( led_blink, ( signed char * ) "input",
			configMINIMAL_STACK_SIZE,
			NULL,
			LED_BLINK,
			NULL );

	/*Start the Scheduler*/
	vTaskStartScheduler();
	return 0;
}

static void led_blink( void *pvParameters)
{
	xSemaphoreTake( xBinarySemaphore, portMAX_DELAY );
	while(1)
	{
		TCNT1H=0x85;
		TCNT1L=0xEE;
		xSemaphoreTake(xBinarySemaphore, portMAX_DELAY);
		PORTB^=(1<<PINB0);//Toggle PORTB.0
	}
}


ISR (TIMER1_OVF_vect)
{
	signed portBASE_TYPE woken;
	xSemaphoreGiveFromISR(xBinarySemaphore, &woken);
}
