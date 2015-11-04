/*
 * led_blink.c
 *
 *  Created on: Jan 23, 2014
 *      Author: mody
 */

#include"led_blink.h"


void led_toggle_Init(void)
{
	LED_DDR_TOG|=(1<<LED1_TOG);

}

void toggle_led (void)
{
	LED_PORT_TOG^=(1<<LED1_TOG);

}
void toggle_led2 (void)
{
	LED_PORT_TOG^=(1<<LED2_TOG);

}
