#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct
{
    int item;
    struct nodestruct *next;
}Node;
typedef struct
{
    int size;
    int sum;
    Node *rear;
}Queue;

Queue* initQueue(void);
int enqueue(int,Queue*);
int dequeue(Queue*,int*);
float getAverage(Queue*);
void freeQueue(Queue*);

Queue* initQueue() //makes a circle linked list with nothing inside it with error code -1
{
    Queue*queue;
    queue=malloc(sizeof(Queue));
    if(queue==NULL)
    {
        printf("MALLOC Failed");//malloc test
        return 0;
    }
    else
    {
        queue->rear=NULL;
        queue->size=0;
        queue->sum=0;
        return queue;
    }
}
int enqueue(int k,Queue*queue)// takes in a value and inserts it at the start of the list with error code of -1
{
    Node*newNode;
    newNode=malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("Malloc failed");//malloc test
        return -1;
    }
    newNode->item=k;
    if(queue->rear==NULL)//if the list is empty
    {
        queue->rear=newNode;
        newNode->next=newNode;
      //  printf("newNode value %d\n",queue->rear->item);
        queue->size+=1;
        queue->sum=queue->sum+k;
    }
    else // if not empty
    {
        Node*temp = NULL;
        temp=queue->rear;
        queue->rear->next=newNode;
        queue->rear=temp;
        queue->size+=1;
        queue->sum=queue->sum+k;
       // printf("newNode value %d\n",queue->rear->next->item);
        return 0;
    }
    return 0;
    
}
int dequeue(Queue*queue,int *value)//deletes the last item in the queue and then returns the value of the last time with error code -1
{
    Node*deleted;
    if(queue->rear==NULL)//if the list is empty
    {
        printf("nothing to dequeue\n");
        return -1;
    }
   //int * value;
    deleted=queue->rear;
   // printf("deleted item value %d\n",deleted->item);
    value=&queue->rear->item;
  //  printf("Value of dequeue in the fuction %d\n",*value);
    queue->rear=queue->rear->next;
    queue->sum=queue->sum - deleted->item;
    queue->size-=1;
    //printf("deleted item value %d\n",deleted->item);
    free(deleted);
    return *value;
    
}
float getAverage(Queue*queue)// takes in the sum and size from the stuct and takes the average
{
    float Avg;
    Avg=(queue->sum/queue->size);
    printf("The average is %f\n",Avg);
    return 0;
    
}
void freeQueue(Queue*queue)//takes in the queue and frees it ok it doesnt but thats the goal lol
{
    Node*temp;
    temp=queue->rear;
   
    if (queue->rear == NULL)
     {
         free(queue);
         printf("\nQueue was freed\n");//queue freed
          return;
     }
     
}

