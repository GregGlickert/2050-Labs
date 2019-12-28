#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node{
    int data;
    struct node *left, *right;
}treeNode;

treeNode* insertBT(treeNode*,int);
void printBT(treeNode*);
void freeTree(treeNode*);
void countLeafNode(treeNode*,int*);

