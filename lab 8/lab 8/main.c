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
List *initIntegerList(void);
int insertAtTail(int, List*);
int removeTail(List*);
void emptyList(List*);
void freeList(List**);
void printList(List*);

int main(void){

    srand(time(NULL)); // for random integer generator
    List*p;
    p=initIntegerList();
    if (p ==NULL)
    {
        printf("Malloc failed");
        return -1;
    }
    printList(p);
    for (int i = 0; i < 5; i++)
    {
        insertAtTail((rand()%10)+1, p);
        printf("tail Insertion: ");
        printList(p);
    }
    removeTail(p);
    printf("tail deletion: ");
        printList(p);
    removeTail(p);
    printf("tail deletion: ");
        printList(p);
    emptyList(p);
     printf("List has been emptied\n");
    insertAtTail((rand()%10)+1, p);
    printf("tail Insertion: ");
        printList(p);
    freeList(&p);
    }
List * initIntegerList()
    {
        List * list;
        list=malloc(sizeof(List));
        if(list==NULL)
        {
            printf("Malloc failed inside initIntegerList");
        }
        list -> head=NULL;
        list -> tail=NULL;
        list->size=0;
        return list;
    }
int insertAtTail(int k, List*list)
    {
        if(list->head==NULL||list->tail==NULL)
        {
            Node* nodeToInsert = malloc(sizeof(Node));
              if(nodeToInsert==NULL)
              {
                  printf("Malloc failed in tail function");
              }
            nodeToInsert->item = k;
            nodeToInsert->next=NULL;
            list->head=nodeToInsert;
            list->tail=nodeToInsert;
            
            return 0;
        }
        Node* nodeToInsert = malloc(sizeof(Node));
          if(nodeToInsert==NULL)
          {
              printf("Malloc failed in tail function");
          }
        nodeToInsert->item = k;
        nodeToInsert->next=NULL;
        list->tail->next=nodeToInsert;
        list->tail=nodeToInsert;
        
        
        return 0;
       
    }
int removeTail(List * list)
    {
        if(list->head==NULL||list->tail==NULL)
        {
            printf("remove tail failed");
            return  0;
        }
        Node*newTail;
        for(newTail= list->head; newTail->next != list->tail; newTail= newTail->next);
       // printf("%d\n",newTail->item);
        Node*temp;
        temp=newTail->next;
      //  printf("%d\n",temp->item);
        list->tail=newTail;
     //   printf("%d\n",list->tail->item);
        newTail->next=NULL;
        free(temp);
        return 0;
    }

void printList(List * list) // needs to work without any nodes and print message when no nodes
    {
        Node*currentNode=list->head;
        if (list->head == NULL)
        {
            printf("Linked list is empty.\n");
            return;
        }
        printf("List is: ");
        while(currentNode != NULL)
        {
            printf("%d ",currentNode->item);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
void emptyList(List * list)
    {
        Node*temp=NULL;
        while(list->head != NULL)
            {
                temp=list->head;
                list->head=list->head->next;
                free(temp);
            }
       // printf("List has been emptied\n");
    }
void freeList(List ** p)
    {
        emptyList(*p);
        free(*p);
        printf("list has been freed\n");
    }
