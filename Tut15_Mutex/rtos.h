/*
 * rtos.h
 *
 *  Created on: Feb 11, 2014
 *      Author: mody
 */

#ifndef RTOS_H_
#define RTOS_H_
/* Scheduler include files. */
#include "FreeRTOS.h"
#include"FreeRTOSConfig.h"
#include "task.h"
#include "semphr.h"

/*Create the handle*/
xSemaphoreHandle xMutex;


#endif /* RTOS_H_ */
