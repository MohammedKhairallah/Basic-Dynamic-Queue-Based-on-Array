/* 
 * File:   QueueArray.h
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 30, 2023, 12:46 AM
 */
#ifndef _QUEUEARRAY_H
#define _QUEUEARRAY_H

/* Section : Includes */
#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */


/* Section : Data type Declarations */

typedef enum{
    QUEUE_NOK = 0,     /* Queue operation not performed successfully */
    QUEUE_OK,          /* Queue operation performed successfully  */
    QUEUE_FULL,        /* Queue is full */
    QUEUE_EMPTY,       /* Queue is empty */
    QUEUE_NULL_POINTER /* NULL pointer passed to the Queue */
}QueueStatus_t;

typedef struct{
    void **QueueArray;     /* Pointer to array of void pointers */
    uint32_t QueueMaxSize; /* Maximum elements in the Queue */
    sint32_t ElementCount; /* Number of elements in the Queue */
    sint32_t QueueFront;   /* Index of the front elements */
    sint32_t QueueRear;    /* Index of the rear elements */
}Queue_t;

/* Section : Functions Declaration */

QueueStatus_t CreateQueue(Queue_t **queue_obj, uint32_t maxSize);
QueueStatus_t EnqueueElement(Queue_t *queue_obj, void *item_ptr);
QueueStatus_t DequeueElement(Queue_t *queue_obj, void **Element_ptr);
QueueStatus_t QueueFront(Queue_t *queue_obj, void **Element_ptr);
QueueStatus_t QueueRear(Queue_t *queue_obj, void **Element_ptr);
QueueStatus_t GetQueueCount(Queue_t *queue_obj, uint32_t *QueueCount);
QueueStatus_t DestroyQueue(Queue_t *queue_obj);

#endif // _QUEUEARRAY_H