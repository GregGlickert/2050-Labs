#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int arraySize;
    int availableIdx;
    int *sortedArray;
}PQueue;

PQueue* initPQ(int);
int InsertPQ(PQueue*,int);
int DeQueue(PQueue*,int*);
int findIdx(PQueue*,int);
void freePQ(PQueue*);
void printPQ(PQueue*);

PQueue* initPQ(int size)//makes an empty PQ with data type of array then returns the pointer to the front of the array
{
    PQueue*queue;
    queue=malloc(sizeof(PQueue));
    queue->sortedArray=malloc(sizeof(size));
    queue->arraySize=size;
    queue->availableIdx=0;
    return queue;
}

int InsertPQ(PQueue* queue,int k)//takes in an int and inserts in ascending order into PQ error code of -1
{
    int i = 0;
    int TempForSizePlusOne = ((queue->availableIdx-1)+1);
    int tempForSize = (queue->availableIdx-1);
    if(queue->arraySize==queue->availableIdx)
    {
        printf("insert function failed no more space in array\n");
        return -1;
    }
    while(queue->sortedArray[i] < k && i < queue->availableIdx)
    {
        i++;
    }
    while(TempForSizePlusOne > i)
    {
        queue->sortedArray[TempForSizePlusOne] = queue->sortedArray[tempForSize];
        TempForSizePlusOne--;
        tempForSize--;
    }
    queue->sortedArray[i] = k;
    queue->availableIdx = queue->availableIdx+1;
    return 0;
}
int DeQueue(PQueue* queue,int* deletedValue)// takes in the PQ and removes the max int from the PQ in O(1) time then sets an int* to the value of the deleted int error code of -1
{
    int temp;
       if(queue->availableIdx==0)
       {
           printf("Nothing to delete in the PQ\n");
           return -1;
       }
    temp=queue->availableIdx-1;
    queue->availableIdx -= 1;
    *deletedValue=queue->sortedArray[temp];
    return 0;
}
int findIdx(PQueue* queue,int x)//performs binary search and tells the user if the value is in the array and at which index the value is in in O(log(n)) if number not found returns -1
{
    int left = 0;
    int  right = queue->availableIdx-1;
    while (left <= right)
    {
            int middle = left + (right - left) / 2;
         
            // Check if x is present at mid
            if (queue->sortedArray[middle] == x)
            {
                printf("Element is present at index %d\n",middle);
                return middle;
            }
         
            // If x greater, ignore left half
            if (queue->sortedArray[middle] < x)
            {
                left = middle + 1;
            }
         
            // If x is smaller, ignore right half
            else
            {
                right = middle - 1;
            }
    }
           // if we reach here, then element was
           // not present
           printf("Number not in the PQ\n");
           return -1;
}
void freePQ(PQueue* queue)// takes in the PQ and frees the PQ
{
    free(queue->sortedArray);
    free(queue);
}

void printPQ(PQueue* queue)//takes in the PQ and prints off the values
{
    if(queue->availableIdx==0)
    {
        printf("No data inside PQ\n");
    }
    else
    {
    int i=0;
       printf("PQ holds the values\n");
       while(i <= queue->availableIdx-1)
       {
           printf("%d\n",queue->sortedArray[i]);
           i++;
           
       }
    }
}
