/* 
 * File:   QueueArray.C
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 30, 2023, 12:46 AM
 */
#include "QueueArray.h"

static uint8_t QueueIsFull(Queue_t *queue_obj);
static uint8_t QueueIsEmpty(Queue_t *queue_obj);

/**
 * @brief CreateQueue function
 * 
 * Creates a queue object in the heap to hold queue information.
 * 
 * @param queue_obj Pointer to a pointer of Queue_t structure to store the created queue
 * @param maxSize Maximum size of the queue to be created
 * @return QueueStatus_t Status of the queue creation operation
 *         Possible values: QUEUE_OK if queue created successfully,
 *                          QUEUE_NULL_POINTER if queue_obj is NULL,
 *                          QUEUE_NOK if queue creation failed
 */
QueueStatus_t CreateQueue(Queue_t **queue_obj, uint32_t maxSize){
    QueueStatus_t status = QUEUE_NOK;
    /* Check for NULL pointers in the input parameters */
    if(NULL == queue_obj){
        status = QUEUE_NULL_POINTER;
    }
    else{
        /* Create queue object in the heap to hold the queue information */
        *queue_obj = (Queue_t *)malloc(sizeof(Queue_t));
        if(NULL == *queue_obj){
            status = QUEUE_NOK; /* Queue not created successfully */
        }
        else{
            (*queue_obj)->ElementCount = 0;
            (*queue_obj)->QueueFront = -1;
            (*queue_obj)->QueueRear = -1;
            (*queue_obj)->QueueMaxSize = maxSize;
            /* Create array of <void *> to hold the addresses of the Queue elements */
            (*queue_obj)->QueueArray = (void **)calloc(maxSize, sizeof(void *));
            if(NULL == ((*queue_obj)->QueueArray)){
                free(*queue_obj); /* Free the Queue object as the Array not created successfully */
                *queue_obj = NULL;
                status = QUEUE_NOK; /* Queue not created successfully */
            }
            else{
                status = QUEUE_OK; /* Queue created successfully */
            }
        }
    }
    return status;
}

/**
 * @brief EnqueueElement function
 * 
 * Inserts an element into the queue.
 * 
 * @param queue_obj Pointer to the Queue_t structure representing the queue
 * @param item_ptr Pointer to the element to be enqueued
 * @return QueueStatus_t Status of the enqueue operation
 *         Possible values: QUEUE_OK if successful,
 *                          QUEUE_NULL_POINTER if queue_obj or item_ptr is NULL,
 *                          QUEUE_FULL if the queue is full and cannot enqueue,
 *                          QUEUE_NOK if enqueue operation failed
 */
QueueStatus_t EnqueueElement(Queue_t *queue_obj, void *item_ptr){
    QueueStatus_t status = QUEUE_NOK;
    /* Check for NULL pointers in the input parameters */
    if((NULL == queue_obj)||(NULL == item_ptr)){
        status = QUEUE_NULL_POINTER;
    }
    else{
        /* Validate if the queue is not full */
        if(QueueIsFull(queue_obj)){
            status = QUEUE_FULL; /* Queue is full, can't enqueue new element */
        }
        else{
            /* Increment Queue Rear Index */
            (queue_obj->QueueRear)++;
            /* Queue wraps to element 0 (Circular Queue) */
            if((queue_obj->QueueRear) == (queue_obj->QueueMaxSize)){
                queue_obj->QueueRear = 0;
            }
            else{ /*Nothing */ }
            /* Insert the input data in to the rear position */
            queue_obj->QueueArray[queue_obj->QueueRear] = item_ptr;
            /* validate if the queue was empty, (front and rear points to the first element) */
            if(QueueIsEmpty(queue_obj)){
                queue_obj->QueueFront = 0;
                queue_obj->ElementCount = 1;
            }
            else{
                (queue_obj->ElementCount)++;  /* New element has been added to the Queue */
            }
            status = QUEUE_OK;
        }
    }
    return status;
}

/**
 * @brief DequeueElement function
 * 
 * Removes an element from the front of the queue and retrieves it via Element_ptr.
 * 
 * @param queue_obj Pointer to the Queue_t structure representing the queue
 * @param Element_ptr Pointer to a pointer where the dequeued element will be stored (output parameter)
 * @return QueueStatus_t Status of the dequeue operation
 *         Possible values: QUEUE_OK if successful,
 *                          QUEUE_NULL_POINTER if queue_obj or Element_ptr is NULL,
 *                          QUEUE_EMPTY if the queue is empty and cannot dequeue,
 *                          QUEUE_NOK if dequeue operation failed
 */
QueueStatus_t DequeueElement(Queue_t *queue_obj, void **Element_ptr){
    QueueStatus_t status = QUEUE_NOK;
    /* Check for NULL pointers in the input parameters */
    if((NULL == queue_obj)||(NULL == Element_ptr)){
        status = QUEUE_NULL_POINTER;
    }
    else{
        /* Check if the queue is empty */
        if(QueueIsEmpty(queue_obj)){
            status = QUEUE_EMPTY; /* Queue is empty */
        }
        else{
            *Element_ptr = queue_obj->QueueArray[queue_obj->QueueFront];
            /* Increment Queue Front Index */
            (queue_obj->QueueFront)++;
            /* Queue front has wrapped to element 0 (Circular Queue) */
            if((queue_obj->QueueFront )== (queue_obj->QueueMaxSize)){
                queue_obj->QueueFront = 0;
            }
            else{ /* Nothing */ }
            /* Check if the element is the last element in the Queue */
            if(1 == queue_obj->ElementCount){
                queue_obj->QueueFront = -1; /* Queue is empty */
                queue_obj->QueueRear = -1;  /* Queue is empty */
            }
            else{ /* Nothing */ }
            (queue_obj->ElementCount)--; /* Element has been deleted from the Queue */
            status = QUEUE_OK;
        }
    }
    return status;
}

/**
 * @brief QueueFront function
 * 
 * Retrieves the element at the front of the queue without removing it.
 * 
 * @param queue_obj Pointer to the Queue_t structure representing the queue
 * @param Element_ptr Pointer to a pointer where the front element will be stored (output parameter)
 * @return QueueStatus_t Status of the operation
 *         Possible values: QUEUE_OK if successful,
 *                          QUEUE_NULL_POINTER if queue_obj or Element_ptr is NULL,
 *                          QUEUE_EMPTY if the queue is empty,
 *                          QUEUE_NOK if operation failed
 */
QueueStatus_t QueueFront(Queue_t *queue_obj, void **Element_ptr){
    QueueStatus_t status = QUEUE_NOK;
    /* Check for NULL pointers in the input parameters */
    if((NULL == queue_obj)||(NULL == Element_ptr)){
        status = QUEUE_NULL_POINTER;
    }
    else{
        /* Check if the queue is empty */
        if(QueueIsEmpty(queue_obj)){
            status = QUEUE_EMPTY; /* Queue is empty */
        }
        else{ 
            *Element_ptr = queue_obj->QueueArray[queue_obj->QueueFront];
            status = QUEUE_OK; /* Successfully retrieved the front element */
        }
    }
    return status;
}

/**
 * @brief QueueRear function
 * 
 * Retrieves the element at the rear of the queue without removing it.
 * 
 * @param queue_obj Pointer to the Queue_t structure representing the queue
 * @param Element_ptr Pointer to a pointer where the rear element will be stored
 * @return QueueStatus_t Status of the operation
 *         Possible values: QUEUE_OK if successful,
 *                          QUEUE_NULL_POINTER if queue_obj or Element_ptr is NULL,
 *                          QUEUE_EMPTY if the queue is empty,
 *                          QUEUE_NOK if operation failed
 */
QueueStatus_t QueueRear(Queue_t *queue_obj, void **Element_ptr){
    QueueStatus_t status = QUEUE_NOK;
    /* Check for NULL pointers in the input parameters */
    if((NULL == queue_obj)||(NULL == Element_ptr)){
        status = QUEUE_NULL_POINTER;
    }
    else{
        /* Check if the queue is empty */
        if(QueueIsEmpty(queue_obj)){
            status = QUEUE_EMPTY; /* Queue is empty */
        }
        else{
            *Element_ptr = queue_obj->QueueArray[queue_obj->QueueRear];
            status = QUEUE_OK; /* Successfully retrieved the rear element */
        }
    }
    return status;
}

/**
 * @brief GetQueueCount function
 * 
 * Retrieves the current count of elements in the queue.
 * 
 * @param queue_obj Pointer to the Queue_t structure representing the queue
 * @param QueueCount Pointer to an unsigned integer where the queue count will be stored
 * @return QueueStatus_t Status of the operation
 *         Possible values: QUEUE_OK if successful,
 *                          QUEUE_NULL_POINTER if queue_obj or QueueCount is NULL,
 *                          QUEUE_NOK if operation failed
 */
QueueStatus_t GetQueueCount(Queue_t *queue_obj, uint32_t *QueueCount){
    QueueStatus_t status = QUEUE_NOK;
    /* Check for NULL pointers in the input parameters */
    if((NULL == queue_obj)||(NULL == QueueCount)){
        status = QUEUE_NULL_POINTER;
    }
    else{
        /* Check if the queue is empty */
        if(QueueIsEmpty(queue_obj)){
            *QueueCount = 0;  /* Queue is empty */
        }
        else{
            *QueueCount = queue_obj->ElementCount; /* Retrieve the count of elements in the queue */
        }
        status = QUEUE_OK;
    }
    return status;
}

/**
 * @brief DestroyQueue function
 * 
 * Frees memory associated with the queue and destroys the queue object.
 * 
 * @param queue_obj Pointer to the Queue_t structure representing the queue
 * @return QueueStatus_t Status of the operation
 *         Possible values: QUEUE_OK if successful,
 *                          QUEUE_NULL_POINTER if queue_obj is NULL
 */
QueueStatus_t DestroyQueue(Queue_t *queue_obj){
    QueueStatus_t status = QUEUE_NOK;
    /* Check for NULL pointers in the input parameters */
    if(NULL == queue_obj){
        status = QUEUE_NULL_POINTER;
    }
    else{
        /* Free memory allocated for the QueueArray (elements array) */
        free(queue_obj->QueueArray);
        queue_obj->QueueArray = NULL;
        /* Free memory allocated for the queue object itself */
        free(queue_obj);
        queue_obj = NULL;
        status = QUEUE_OK;
    }
    return status;
}

/**
 * @brief QueueIsFull function
 * 
 * Checks if the queue is full based on the current number of elements and the maximum queue size.
 * 
 * @param queue_obj Pointer to the Queue_t structure representing the queue
 * @return uint8_t Returns 1 (true) if the queue is full, otherwise returns 0 (false)
 */
static uint8_t QueueIsFull(Queue_t *queue_obj){
    return (queue_obj->ElementCount == queue_obj->QueueMaxSize);
}

/**
 * @brief QueueIsEmpty function
 * 
 * Checks if the queue is empty based on the current number of elements.
 * 
 * @param queue_obj Pointer to the Queue_t structure representing the queue
 * @return uint8_t Returns 1 (true) if the queue is empty, otherwise returns 0 (false)
 */
static uint8_t QueueIsEmpty(Queue_t *queue_obj){
    return (0 == queue_obj->ElementCount);
}