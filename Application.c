/* 
 * File:   Application.C
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 30, 2023, 12:46 AM
 */

#include "Application.h"

int main(){
    printf("==============CreateQueue===========\n");
    ReturnQueueStatus = CreateQueue(&Queue1, 4);
    printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);
    if(NULL == Queue1){
        printf("Queue not created successfully\n");
    }
    else{
        printf("Queue created successfully\n");
        printf("==============EnqueueElement===========\n");
        ReturnQueueStatus = EnqueueElement(Queue1, &Number1);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);

        printf("==============EnqueueElement===========\n");
        ReturnQueueStatus = EnqueueElement(Queue1, &Number2);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);

        printf("==============EnqueueElement===========\n");
        ReturnQueueStatus = EnqueueElement(Queue1, &Number3);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);

        printf("==============EnqueueElement===========\n");
        ReturnQueueStatus = EnqueueElement(Queue1, &Number4);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);

        printf("==============EnqueueElement===========\n");
        ReturnQueueStatus = EnqueueElement(Queue1, &Number5);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);
        
        printf("==============GetQueueCount===========\n");
        ReturnQueueStatus = GetQueueCount(Queue1, &QueueCount);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);
        printf("QueueCount = %i\n", QueueCount);

        printf("==============QueueFront===========\n");
        ReturnQueueStatus = QueueFront(Queue1, &QueueRetVal);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);
        printf("*((uint32_t *)QueueRetVal) = 0x%X\n", *((uint32_t *)QueueRetVal));

        printf("==============QueueFront===========\n");
        ReturnQueueStatus = QueueRear(Queue1, &QueueRetVal);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);
        printf("*((uint32_t *)QueueRetVal) = 0x%X\n", *((uint32_t *)QueueRetVal));

        printf("==============DequeueElement===========\n");
        ReturnQueueStatus = DequeueElement(Queue1, &QueueRetVal);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);
        printf("*((uint32_t *)QueueRetVal) = 0x%X\n", *((uint32_t *)QueueRetVal));

        printf("==============GetQueueCount===========\n");
        ReturnQueueStatus = GetQueueCount(Queue1, &QueueCount);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);
        printf("QueueCount = %i\n", QueueCount);
        
        printf("==============DestroyQueue===========\n");
        ReturnQueueStatus = DestroyQueue(Queue1);
        printf("ReturnQueueStatus = %i\n", ReturnQueueStatus);
    }
    printf("The End\n");
    return 0;
}