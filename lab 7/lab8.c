#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodestruct {
    int item;
    struct nodestruct *next;
} Node;

Node *initIntegerList();
Node *createNode(int);
int insertDescend(Node*,int);
int insertAtTail(Node*,int);
void printList(Node*);
void freeList(Node*);
int computeOdd(Node*);

int main(void){

    srand(time(NULL));

    Node* list = initIntegerList();
    if (list == NULL){
        printf("Malloc failed\n");
        return -1;
    }

    printList(list);
    printf("%d odd numbers are in this linked list.\n",computeOdd(list));

    for (int i = 0; i < 5; i++){
        if (insertDescend(list, (rand()%10+1)) == 0){
            printf("Descending insertion: ");
            printList(list);
            printf("%d odd numbers are in this linked list.\n",computeOdd(list));
        } else {
            return -1;
        }
    }

    for (int i = 0; i < 5; i++){
        if (insertAtTail(list, (rand()%10+1)) == 0){
            printf("Tail insertion: ");
            printList(list);
            printf("%d odd numbers are in this linked list.\n",computeOdd(list));
        } else {
            return -1;
        }
    }

    freeList(list);

    return 0;

}

Node *createNode(int keyValue){
    Node *n = malloc(sizeof(Node));

    if (n != NULL){
        n->item = keyValue;
        n->next = NULL;
    }

    return n;

}


Node *initIntegerList(){
    Node *dummyHead = malloc(sizeof(Node));
    Node *dummyTail = malloc(sizeof(Node));

    if (dummyHead == NULL || dummyTail == NULL){
        // either of the two failed
        return NULL;
    }

    // otherwise connect head and tail dummy nodes
    dummyHead->next = dummyTail;
    dummyTail->next = NULL;

    return dummyHead;
}

int insertDescend(Node* dummyHead, int keyValue){
    Node *newNode = createNode(keyValue);

    if (newNode == NULL){
        printf("Malloc failed\n");
        return -1;
    }

    Node* temp = dummyHead->next;
    if (temp->next == NULL){
        // no node in list yet
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;

        return 0;
    }

    if (temp->item < keyValue){
        // the first one is smaller than input already
        newNode->next = temp;
        dummyHead->next = newNode;

        return 0;
    }

    while (temp->next->next != NULL && keyValue < temp->next->item){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return 0;

}

int insertAtTail(Node* dummyHead, int keyValue){

    // locate the last real node before dummyTail
    Node* temp = dummyHead;
    while (temp->next->next != NULL){
        temp = temp->next;
    }

    Node *newNode = createNode(keyValue);

    if (newNode == NULL){
        printf("Malloc failed\n");
        return -1;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return 0;

}

void printList(Node* dummyHead){
    Node* temp = dummyHead->next;

    if (temp->next == NULL){
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list is: ");
    while (temp->next != NULL){
        printf("%d ",temp->item);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* dummyHead){
    Node* temp = dummyHead;

    while (temp->next != NULL){
        dummyHead = dummyHead->next;

        free(temp);
        temp = NULL;

        temp = dummyHead;
    }

    // now free the very last dummyTail
    free(temp);
    temp = NULL;
    printf("Linked list has been freed\n");

}

int computeOdd(Node* dummyHead){
    Node* temp = dummyHead->next;

    if (temp->next == NULL){
        return 0; // no nodes, number of odds is 0
    }

    int count = 0;
    while (temp->next != NULL){
        if (temp->item % 2 == 1){
            count ++;
        }
        temp = temp->next;
    }
    return count;
}
