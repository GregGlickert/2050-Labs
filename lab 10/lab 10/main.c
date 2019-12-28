#include <stdio.h>
#include <stdlib.h>
typedef struct nodestruct
{
    int key;
    float priority;
    struct nodestruct *next;
}Node;
typedef struct
{
    int size;
    Node *rear, *front;
}PQueue;

PQueue * initPQ(void);
int insertPQ(int,float,PQueue*);
int deleteMinPQ(PQueue*,int*);
void reInitPQ(PQueue*);
void freePQ(PQueue*);
void printPQ(PQueue*);

PQueue * initPQ()//makes a PQ and return it as an empty PQ
{
    PQueue * queue;
    queue=malloc(sizeof(PQueue));
    queue->front=NULL;
    queue->rear=NULL;
    return queue;
}

int insertPQ(int k, float p, PQueue *queue)//takes in the key and priority of a new node in the PQ. Then searches for where to put in and inserts it based on its priority. smallest priority in the front biggest priority in the rear. Also increases the size counter by 1. error code of -1.
{
    Node * newNode;
    newNode=malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("malloc has failed");//test for malloc
        return -1;
    }
    newNode->priority=p;
    newNode->key=k;
    Node* start=queue->front;
    
   if(queue->front==NULL && queue->rear==NULL)//puts first node into the PQ
           {
               newNode->next=queue->front;
               queue->front=newNode;
           }
    else
    {
      if (newNode->priority < queue->front->priority)//inserts based on priority
        {
            newNode->next=queue->front;
            queue->front=newNode;
           
        }
      else
      {
           while(start->next != NULL && newNode->priority > start->next->priority)//inserts based on priority
            {
                start=start->next;
            }
          newNode->next=start->next;
          start->next=newNode;
    }
    }
     queue->size+=1;
    return 0;
}

int deleteMinPQ(PQueue*queue, int* MinPQ)//removes the min value priority node and stores its key in a pointer.Then frees the node and decreases the size counter by one.Error code of -1.
{
    if(queue->front==NULL && queue->rear==NULL)
           {
               printf("nothing to delete\n");//if PQ is empty
               return -1;
           }
    *MinPQ=queue->front->key;
    Node*temp;
    temp=queue->front;
    queue->front=queue->front->next;
    free(temp);
    queue->size-=1;
    return 0;
}

void reInitPQ(PQueue*queue)//takes in the PQ and then reinitalizes it to an empty PQ with the same address as the first PQ
{
    int MinPQ;
    while(queue->front != queue->rear)
    {
        deleteMinPQ(queue,&MinPQ);
    }
    queue->rear=NULL;
}
void freePQ(PQueue*queue)//takes in the PQ and then frees everything in the PQ and sets the queue to NULL
{
    int MinPQ;
    while(queue->front != queue->rear)
    {
        deleteMinPQ(queue,&MinPQ);
    }
    free(queue);
    queue=NULL;
}

void printPQ(PQueue * queue)//takes in the PQ and prints both the key and priority value
{
    Node*currentNode=queue->front;
    if(queue->front == NULL)
    {
        printf("PQ is empty\n");
    }
    else
    {
    printf("The Current PQ is: ");
    while(currentNode != NULL)
    {
        printf("Key %d ",currentNode->key);
        printf("with priority %.2f -> ",currentNode->priority);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
    }
}


