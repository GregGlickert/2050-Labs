#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// circular linked list
typedef struct nodestruct {
    int item;
    struct nodestruct *next;
} Node;

typedef struct {
    int size, sum;
    Node *rear;
} Queue;

Queue* initQueue();
int enqueue(int, Queue*);
int dequeue(Queue*, int*);
float getAverage(Queue*);
void freeQueue(Queue*);
Node *createNode(int);
void printQueue(Queue*);

/* test program */
int main(void){

    srand(time(NULL));

    Queue* myQueue = initQueue();
    printQueue(myQueue);

    int returnValue;
    for (int i = 0; i < 10; i++){
        enqueue(rand()%10+1, myQueue);
        printQueue(myQueue);
        printf("Average is %.2f\n",getAverage(myQueue));
    }
    for (int i = 0; i < 5; i ++){
        dequeue(myQueue, &returnValue);
        // printf("Removed %d\n",returnValue);
        printQueue(myQueue);
        printf("Average is %.2f\n",getAverage(myQueue));
    }

    freeQueue(myQueue);
    return 0;
}

/* this function initializes the circular linked list, and returns the empty queue*/
Queue* initQueue(){
    Queue* myQueue = malloc(sizeof(Queue)*1);

    if (myQueue == NULL){
        return NULL;
    } else {

        myQueue->size = 0;
        myQueue->sum = 0;
        myQueue->rear = NULL;

        return myQueue;
    }
}

/* this function receives the circular queue, creates a new node with the input integer value, inserts the new node in queue, and returns an error code. Error code: 0 successful, -1 failed.*/
int enqueue(int keyValue, Queue* myQueue){

    Node* newNode = createNode(keyValue);
    if (newNode == NULL){
        return -1;
    }

    if (myQueue->size == 0){
        // empty queue
        myQueue->rear = newNode;
        newNode->next = myQueue->rear;

    } else {
        // not empty queue
        newNode->next = myQueue->rear->next;
        myQueue->rear->next = newNode;
        myQueue->rear = newNode;
    }

    myQueue->size ++;
    myQueue->sum += keyValue;

    return 0;

}

/* this function receives the circular queue, removes the oldest node, and returns the value in this node through the integer pointer. This functions returns 0 is deletion was successful and -1 if it failed*/
int dequeue(Queue* myQueue, int* returnValuePtr){

    if (myQueue->size == 0){

        return -1;

    } else if (myQueue->size == 1){

        *returnValuePtr = myQueue->rear->item;

        free(myQueue->rear);
        myQueue->rear = NULL;

        myQueue->size = 0;
        myQueue->sum = 0;

        return 0;

    } else {

        Node* temp = myQueue->rear->next;
        myQueue->rear->next = temp->next;

        *returnValuePtr = temp->item;
        free(temp);
        temp = NULL;

        myQueue->size --;
        myQueue->sum -= (*returnValuePtr);

        return 0;

    }

}

/* this function receives the current circular linked queue, and returns the number of odd integers on this linked list. O(1) complexity.*/
float getAverage(Queue* myQueue){
    return (float)myQueue->sum / (float)myQueue->size;
}

/* this function receives the current circular linked queue, and frees ALL space. This function doesn't have a return value.*/
void freeQueue(Queue* myQueue){
    if (myQueue->size == 0){
        free(myQueue);
        myQueue = NULL;
    } else {

        // just call dequeue till end....
        int test = 0, returnValue;
        while (test == 0){
            test = dequeue(myQueue, &returnValue);
        }

        free(myQueue);
        myQueue = NULL;

    }
}

/* this function receives the current queue, and prints it out. */
void printQueue(Queue* myQueue){
    if (myQueue->size == 0){
        printf("Empty queue\n");
    } else {
        Node *temp = myQueue->rear->next;
        printf("Queue is: ");
        for (int i = 0; i < myQueue->size; i ++){
            printf("%d ",temp->item);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* this functions creates a new Node with keyValue stored in it. It returns NULL if malloc fails, otherwise returns the address of the new Node*/
Node *createNode(int keyValue){
    Node *n = malloc(sizeof(Node));

    if (n != NULL){
        n->item = keyValue;
        n->next = NULL;
    }

    return n;
}
