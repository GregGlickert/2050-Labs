#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodestruct {
    int item;
    struct nodestruct *next;
} Node;

typedef struct {
    int size;
    Node *head, *tail;
} List;

// no dummy nodes should be used in this lab assignment
List *initIntegerList();
int insertAtTail(int, List*);
int removeTail(List*);
void emptyList(List*);
void freeList(List**);
void printList(List*);

Node *createNode(int);

int main(void){

    srand(time(NULL)); // for random integer generator

    List* myList = initIntegerList();
    if (myList == NULL){
        return -1;
    }

    printList(myList);

    for (int i = 0; i < 5; i++){
        if (insertAtTail((rand()%10+1), myList) == 0){
            printf("Tail insertion: ");
            printList(myList);
        } else {
            return -1;
        }
    }

    if (removeTail(myList) != -1){
        printf("Tail deletion: ");
        printList(myList);
    } else {
        printf("No node to remove\n");
    }
    if (removeTail(myList) != -1){
        printf("Tail deletion: ");
        printList(myList);
    } else {
        printf("No node to remove\n");
    }

    emptyList(myList);
    if (insertAtTail((rand()%10+1), myList) == 0){
        printf("Tail insertion: ");
        printList(myList);
    } else {
        return -1;
    }

    freeList(&myList);

    return 0;

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

/* this function creates an empty list. It returns NULL if malloc fails, otherwise returns the empty list*/
List *initIntegerList(){

    List *myList = malloc(sizeof(List));
    if (myList == NULL){
        return NULL;
    }

    myList->size = 0;
    myList->head = myList->tail = NULL;

    return myList;

}

/* this function creates a new node with the key value, then inserts the new node into linked list at head. It receives the key value and current linked list, returns an error code: 0 if successful, -1 otherwise*/
int insertAtHead(int key, List* myList){

    Node *newNode = createNode(key);
    if (newNode == NULL){
        return -1;
    }

    if (myList->size == 0){
        myList->head = myList->tail = newNode;
    } else {
        newNode->next = myList->head;
        myList->head = newNode;
    }

    myList->size ++;

    return 0;

}

/* this function creates a new node with the key value, then inserts the new node into linked list at tail. It receives the key value and current linked list, returns an error code: 0 if successful, -1 otherwise*/
int insertAtTail(int key, List* myList){

    Node *newNode = createNode(key);
    if (newNode == NULL){
        return -1;
    }

    if (myList->size == 0){
        myList->head = myList->tail = newNode;
    } else {
        myList->tail->next = newNode;
        myList->tail = newNode;
    }

    myList->size ++;

    return 0;

}

/* this function receives the current linked list, frees the node at head, and returns the key value inside this node.*/
int removeHead(List* myList){

    if (myList->size == 0){
        return -1;
    }

    Node *temp = myList->head;
    int returnValue = myList->head->item;

    myList->head = myList->head->next;
    myList->size --;

    if (myList->size == 0){
        // we just removed the very last Node
        myList->tail = NULL;
    }

    free(temp);
    temp = NULL;

    return returnValue;
}

/* this function receives the current linked list, and returns the size of the list as an integer*/
int getListSize(List* myList){
    return myList->size;
}

/* this function prints the value inside the current linked list. It receives the current linked list. It doesn't have a return value.*/
void printHead(List* myList){
    if (myList->size == 0){
        printf("List is empty, cannot print the head value\n");
    } else {
        printf("Head value of list is %d\n",myList->head->item);
    }
}

/* this function receives the current linked list, and moves the head node to the tail. It doesn't have a return value*/
void moveHeadToTail(List* myList){
    // there're many ways to do it, here I'll just use the easiest way: remove from head then insert at tail
    if (myList->size == 0){
        printf("List is empty, cannot move head to tail\n");
    } else {
        int key = removeHead(myList);
        insertAtTail(key, myList);
    }
}

/* this function receives the current linked list and removes the node at tail. It returns the integer value stored in the orignal tail node.*/
int removeTail(List* myList){
    if (myList->size == 0){
        return -1;
    }

    int returnValue = myList->tail->item;

    if (myList->size == 1){
        // only one node, kinda special
        Node *temp = myList->head;
        myList->head = myList->tail = NULL;

        free(temp);
        temp = NULL;

        myList->size = 0;
        return returnValue;
    }

    Node *temp = myList->head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }

    // now temp is second to the last, which will become the new last node
    free(myList->tail);
    myList->tail = NULL;

    temp->next = NULL;
    myList->tail = temp;

    myList->size --;

    return returnValue;
}

/* this function receives the current linked list, and clears all the nodes inside this linked list. It doesn't have a return value.*/
void emptyList(List* myList){
    // well I'll just call remove from head multiple times
    int flag = removeHead(myList);
    while (flag != -1){
        flag = removeHead(myList);
    }

    myList->head = myList->tail = NULL;
    printf("List has been emptied\n");
}

/* this function receives the current linked list, and frees all the nodes and the list. It doesn't have a return value.*/
void freeList(List** myListPtr){
    // just call emptyList function, then free the List pointer
    emptyList(*myListPtr);
    free(*myListPtr);
    *myListPtr = NULL;
    printf("List has been freed\n");
}

/* this function receives the current linked list, and prints out all the integers in this linked list. It doesn't have a return value*/
void printList(List* myList){
    if (myList->size == 0){
        printf("List is empty\n");
    } else {
        Node *temp = myList->head;
        printf("List is: ");
        while (temp != NULL){
            printf("%d ",temp->item);
            temp = temp->next;
        }
        printf("\n");
    }
}
