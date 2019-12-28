#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodestruct {
    int item;
    struct nodestruct* next;
}Node;

Node * initIntegerList(void);
int insertDescend(Node*,int);
int insertAtTail(Node*,int);
void printList(Node*);
void freeList(Node*);
int computeOdd(Node*);

int main(void)
{
    Node*head;
    head=initIntegerList();
    printList(head);
    srand(time(NULL)); // for random integer generator
    int upperValue=10;
    int lowerValue=1;
    int randInt1 = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    int randInt2 = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    int randInt3 = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    int randInt4 = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    int randInt5 = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    int randInt6 = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    int randInt7 = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    int randInt8 = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    int randInt9 = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    int randInt10 = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
    
    int count;
    insertDescend(head,randInt1);
    printList(head);
    count=computeOdd(head);
       printf("\nThe number of Odd numbers is %d\n",count);
    insertDescend(head,randInt2);
    printList(head);
    count=computeOdd(head);
       printf("\nThe number of Odd numbers is %d\n",count);
    insertDescend(head,randInt3);
    printList(head);
    count=computeOdd(head);
       printf("\nThe number of Odd numbers is %d\n",count);
    insertDescend(head,randInt4);
    printList(head);
    count=computeOdd(head);
       printf("\nThe number of Odd numbers is %d\n",count);
    insertDescend(head,randInt5);
    printList(head);
    count=computeOdd(head);
        printf("\nThe number of Odd numbers is %d\n",count);
    insertAtTail(head,randInt6);
    printList(head);
       count=computeOdd(head);
          printf("\nThe number of Odd numbers is %d\n",count);
    insertAtTail(head,randInt7);
    printList(head);
       count=computeOdd(head);
          printf("\nThe number of Odd numbers is %d\n",count);
    insertAtTail(head,randInt8);
    printList(head);
       count=computeOdd(head);
          printf("\nThe number of Odd numbers is %d\n",count);
    insertAtTail(head,randInt9);
    printList(head);
       count=computeOdd(head);
          printf("\nThe number of Odd numbers is %d\n",count);
    insertAtTail(head,randInt10);
    printList(head);
       count=computeOdd(head);
          printf("\nThe number of Odd numbers is %d\n",count);
    freeList(head);
    return 0;

}
Node * initIntegerList()
{
    Node* dum1;
    Node* dum2;
    dum1=malloc(sizeof(Node));
    dum2=malloc(sizeof(Node));
    dum1->next=dum2;
    dum2->next=NULL;
    dum1->item = -9000;
    dum2->item = -9000;
    return dum1;
}
int insertDescend(Node* head,int k) // takes in head pointer and adds new node to linked list in a descending order
{
    Node* temp, *prev;
    temp=head->next;
    prev=head;
    Node* newNode = malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("malloc failed in descending fuction");
    }
    newNode->item=k;
    while(temp!= NULL && temp->item >= k)
    {
        prev = temp;
        temp = temp->next;
    }
    newNode->next = temp;
    prev->next = newNode;
    return 0;
}
int insertAtTail(Node* head, int k)// takes in head pointer and adds to the tail end of linked list
{
    Node* nodeToInsert = malloc(sizeof(Node));
    if(nodeToInsert==NULL)
    {
        printf("Malloc failed in tail function");
    }
    nodeToInsert->item = k;
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = nodeToInsert;
    head->next->next = NULL;
    return 0;
}
void printList(Node* head) // takes head pointer and prints list
{
    Node * temp=head->next;
    if(head->next->item==-9000)
    {
        printf("Linked List is empty\n");
    }
    printf("linked list contains: ");
       while(temp->next != NULL)
       {
           printf("%d,",temp->item);
           temp=temp->next;
       }
}
void freeList(Node* head) // takes in head pointer and frees memory in linked list
{
    Node* temp = malloc(sizeof(Node));
       
       while(head != NULL)
       {
           temp = head;
           head = head->next;
           free(temp);
       }
       printf("linked list has been freed \n");
}
int computeOdd(Node* head) //takes in head pointer counter how many odd numbers there are in the linked list
{
    int count=0;
    Node * temp=head->next;
    while(head->next != NULL)
    {
    if(temp->item %2 !=0)
           {
               count++;
               temp=temp->next;
           }
        break;
    }
    return count;
}
