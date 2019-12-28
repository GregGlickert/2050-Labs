#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int info;
    int size;
    struct Queue *next;
}Queue;

Queue* initQueue(void);
int enqueue(int,Queue*);
int dequeue(Queue*,int*);
int getQsize(Queue*);
void freeQueue(Queue*);
int display(Queue*);
int main(void)
{
    Queue*p;
    int d;
    p=initQueue();
    display(p);
    enqueue(4,p);
    enqueue(5,p);
    dequeue(p,&d);
   // dequeue(p,&d);
    display(p);
}
Queue* initQueue()
{
    Queue * rear;
    rear=malloc(sizeof(Queue));
    rear->next=NULL;
    rear->size=0;
    
    return rear;
}
int enqueue(int k, Queue* rear)
{
    Queue * newNode;
    newNode=malloc(sizeof(Queue));
    //newNode->next=NULL;
    newNode->info=k;
    if(rear->next==NULL)
    {
      //  printf("if statement test\n");
        rear->next=newNode;
        rear=newNode;
        rear->size+=1;
      //  printf("%d\n",rear->info);
    }
    else
    {
        newNode->next=rear->next;
        rear->next=newNode;
        rear=newNode;
        rear->size+=1;
     //   printf("Else statement test\n");
      //  printf("%d\n",rear->info);
    }
    
    
    return 0;
}
int dequeue(Queue* rear,int * d)
{
    Queue * temp;
    temp=malloc(sizeof(Queue));
    temp=rear->next;
    rear->next=temp->next;
    //printf("temp info at deq %d",temp->info);
    free(temp);
    return 0;;
}
int getQsize(Queue* rear)
{
    return 0;
}
void freeQueue(Queue* rear)
{
    
}

int display(Queue* rear)
{
    Queue*temp = rear;
   // temp=malloc(sizeof(Queue));
    if(rear->next==NULL)
    {
       printf("List is empty\n");
    }
    else
    {
        while(temp->next != temp)
           {
             printf("%d\n",temp->next->info);
             temp = temp->next;
               break;
           }
    }
    return 0;
}
