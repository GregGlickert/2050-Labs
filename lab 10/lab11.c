#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodestruct {
    int key;
    float priority;
    struct nodestruct *next;
} Node;

typedef struct {
    int size;
    Node *front, *rear;
} PQueue;

PQueue* initPQ();
int insertPQ(int,float,PQueue*);
int deleteMinPQ(PQueue*, int*);
void reInitPQ(PQueue*);
void freePQ(PQueue*);
void printPQ(PQueue*);
Node* createNode(int key, float priority);

int main(void){

    srand(time(NULL));
    PQueue *PQ = initPQ();

    if (PQ == NULL){
        printf("Malloc failed\n");
        return -1;
    }
    printPQ(PQ);

    int returnValue;
    for (int i = 0; i < 3; i++){
        if (insertPQ(rand()%10+1, (float)rand()/(float)RAND_MAX*10.0, PQ) == 0){
            printf("\nInsertion:\n");
            printPQ(PQ);
        } else {
            printf("Insertion failed\n");
            freePQ(PQ);
            return -1;
        }
    }
    for (int i = 0; i < 2; i++){
        // test deletion
        if (deleteMinPQ(PQ, &returnValue) == 0){
            printf("\nDeletion: Removed value %d.\n", returnValue);
            printPQ(PQ);
        } else {
            printf("\nDeletion: empty queue, cannot remove.\n");
        }
    }

    // now test reInitPQ
    printf("\nBefore reInitPQ, address of PQ is %p\n", PQ);
    reInitPQ(PQ);
    printf("\nAfter  reInitPQ, address of PQ is %p, if the two addresses are different, deduct points\n", PQ);

    for (int i = 0; i < 3; i++){
        if (insertPQ(rand()%10+1, (float)rand()/(float)RAND_MAX*10.0, PQ) == 0){
            printf("\nInsertion:\n");
            printPQ(PQ);
        } else {
            printf("Insertion failed\n");
            freePQ(PQ);
            return -1;
        }
    }
    for (int i = 0; i < 2; i++){
        // test deletion
        if (deleteMinPQ(PQ, &returnValue) == 0){
            printf("\nDeletion: Removed value %d.\n", returnValue);
            printPQ(PQ);
        } else {
            printf("\nDeletion: empty queue, cannot remove.\n");
        }
    }

    freePQ(PQ);
    return 0;

}

/* This function receives a key value and a priority value, then creates a node with the two values and returns the new Node*/
Node* createNode(int key, float priority){
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        return NULL;
    } else {
        newNode->key = key;
        newNode->priority = priority;
        newNode->next = NULL;
        return newNode;
    }
}

/* this function an empty queue and returns it. This function has no input, and returns a pointer of the priority queue*/
PQueue* initPQ(){

    PQueue *PQ = malloc(sizeof(PQueue));

    if (PQ == NULL){
        return NULL;
    } else {
        PQ->size = 0;

        Node* front = createNode(0, 0.0); // dummy front
        Node* rear = createNode(0, 0.0); // dummy rear

        if (front == NULL || rear == NULL){
            free (front);
            free(rear);
            return NULL;
        } else {
            PQ->front = front;
            PQ->rear = rear;
            PQ->front->next = PQ->rear;
            return PQ;
        }

    }
}

/* This functions receives an integer key value, a corresponding float priority value, and the current priority queue pointer. It then creates a new node with the key and priority values, insert it into the PQ based on priority value in ascending order, then returns an error code, where 0 is successful, and -1 is unsuccessful. This operation is in O(n) time.*/
int insertPQ(int key, float priority, PQueue* PQ){

    Node *newNode = createNode(key, priority);

    if (newNode == NULL){
        return -1;
    } else {
        // ascending insertion
        if (PQ->size == 0){
            PQ->front->next = newNode;
            newNode->next = PQ->rear;
        } else {
            Node *temp = PQ->front->next;

            if (priority < temp->priority){
                newNode->next = PQ->front->next;
                PQ->front->next = newNode;
            } else {
                while (temp->next->next != NULL && priority > temp->next->priority){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
        PQ->size ++;

        return 0;
    }
}

/* This function receives the current PQ, and an integer pointer as inputs. It removed the node with the minimum priority value, and stores the removed key value into the integer pointer. It returns an integer error code, where 0 represents successful and -1 represents unsuccessful. This operation is in O(1) time.*/
int deleteMinPQ(PQueue* PQ, int* returnKey){
    if (PQ->size == 0){
        return -1;
    } else {
        *returnKey = PQ->front->next->key;
        Node *temp = PQ->front->next;
        PQ->front->next = PQ->front->next->next;
        free(temp);
        temp = NULL;
        PQ->size --;
        return 0;
    }
}

/* This function receives the current PQ, reinitializes the PQ to an empty PQ without changing the PQ address. It doesn't have an output.*/
void reInitPQ(PQueue* PQ){
    Node *temp = PQ->front->next;
    while (temp->next != NULL){
        PQ->front->next = PQ->front->next->next;
        free(temp);
        temp = NULL;
        temp = PQ->front->next;
    }

    PQ->size = 0;
}

/* This function receives the current PQ, and frees all the memories that have been previously allocated.*/
void freePQ(PQueue* PQ){
    Node *temp = PQ->front;
    while (temp != NULL){
        PQ->front = PQ->front->next;
        free(temp);
        temp = NULL;
        temp = PQ->front;
    }

    PQ->front = PQ->rear = NULL;
    free(PQ);
    PQ = NULL;
}

/* This function receives the current PQ, then prints out the key values on each node together with their priority values. It doesn't return an output.*/
void printPQ(PQueue* PQ){
    if (PQ->size == 0){
        printf("PQ is empty.\n");
    } else {
        Node *temp = PQ->front->next;
        printf("Current PQ is: ");
        while (temp->next != NULL){
            printf("key %d with priority %.2f --> ", temp->key, temp->priority);
            temp = temp->next;
        }
        printf("NULL\n");
    }

}
