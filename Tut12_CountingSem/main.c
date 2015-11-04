
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "init_external_interrupt.h"
#include"usart.h"

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/*The Priorties of the system*/

#define LED_BLINK			( tskIDLE_PRIORITY + 1 )


/*The Prototypes of functions of tasks*/
static void led_blink( void *pvParameters );

/*Create the semaphore handle*/
xSemaphoreHandle xCountingSemaphore;


int main( void )
{
	/*Function to initialize the external interrupt*/
	Init_External_Interrupt();
	USART_Init();

	/*The interrupt handler*/
	xCountingSemaphore=xSemaphoreCreateCounting( 2, 0 );

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
	xSemaphoreTake(xCountingSemaphore, portMAX_DELAY);
	while(1)
	{
		xSemaphoreTake(xCountingSemaphore, portMAX_DELAY );
		PORTC^=(1<<0);
		USART_putstring("PUSH\r\n");
	}
}


ISR (INT0_vect)
{
	signed portBASE_TYPE woken;
	xSemaphoreGiveFromISR(xCountingSemaphore, &woken);
}

ISR (INT1_vect)
{
	signed portBASE_TYPE woken;
	xSemaphoreGiveFromISR(xCountingSemaphore, &woken);
}

ISR (INT2_vect)
{
	signed portBASE_TYPE woken;
	xSemaphoreGiveFromISR(xCountingSemaphore, &woken);
}
