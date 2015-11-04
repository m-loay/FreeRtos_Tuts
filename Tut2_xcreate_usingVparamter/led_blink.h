/*
 * led_blink.h
 *
 *  Created on: Jan 23, 2014
 *      Author: mody
 */

#ifndef LED_BLINK_H_
#define LED_BLINK_H_

#include<avr/io.h>

#define LED_PORT_TOG PORTC
#define LED_DDR_TOG  DDRC
#define LED1_TOG 0
#define LED2_TOG 1

void led_toggle_Init(void);
void toggle_led (void);
void toggle_led2 (void);
#endif /* LED_BLINK_H_ */
