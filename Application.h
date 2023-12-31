/* 
 * File:   Application.h
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 30, 2023, 12:46 AM
 */
#ifndef _APPLICATION_H
#define _APPLICATION_H

/* Section : Includes */
#include "QueueArray.h"
/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */


/* Section : Data type Declarations */
uint32_t Queue1MaxElem = 0;
Queue_t *Queue1 = NULL;
void *QueueRetVal = NULL;

uint32_t Number1 = 0x11, Number2 = 0x22, Number3 = 0x33, Number4 = 0x44, Number5 = 0x55;
uint32_t QueueCount;
QueueStatus_t ReturnQueueStatus = QUEUE_NOK;

/* Section : Functions Declaration */


#endif // _APPLICATION_H