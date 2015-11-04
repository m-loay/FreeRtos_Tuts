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

#define LED_PORT_TOG2 PORTD
#define LED_DDR_TOG2  DDRD

void led_toggle_Init(void);
void toggle_led (unsigned char x);
void led_toggle_Init2(void);
void toggle_led2 (unsigned char x);
#endif /* LED_BLINK_H_ */
