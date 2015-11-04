/*
 * io.h
 *
 *  Created on: Feb 1, 2014
 *      Author: mody
 */

#ifndef IO_H_
#define IO_H_
#include<avr/io.h>
void Init_io (void);
unsigned char input(void);
void output (unsigned char write);

#endif /* IO_H_ */
