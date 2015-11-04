/*
 * led_blink.c
 *
 *  Created on: Jan 23, 2014
 *      Author: mody
 */

#include"led_blink.h"


void led_toggle_Init(void)
{
	/*Set as an output*/
	LED_DDR_TOG=0xFF;
}

void toggle_led (unsigned char x)
{
	LED_PORT_TOG^=(1<<x);
}

void led_toggle_Init2(void)
{
	/*Set as an output*/
	LED_DDR_TOG2=0xFF;
}
void toggle_led2 (unsigned char x)
{
	LED_PORT_TOG2 ^=(1<<x);
}
