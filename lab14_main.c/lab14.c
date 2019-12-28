#include "lab14.h"

treeNode* insertBT(treeNode*root,int k) // function takes in a binary tree and created a new node an inserts it 50% of the time to the left and 50% of the time to the right
{
    int randnumber;
        if(root==NULL) // makes a new node
        {
            //printf("testing\n");
            root=malloc(sizeof(treeNode));
            root->data=k;
            root->left=NULL;
            root->right=NULL;
            return root;
        }
    randnumber=rand()%2; // coin flip
    if (randnumber==0)
    {
        root->left = insertBT(root->left, k);
    }
    if(randnumber==1)
    {
        root->right = insertBT(root->right, k);
    }
    return root;
}
void printBT(treeNode*root)// takes in the tree and prints all values in it
{
    if (root==NULL)
    {

        return;
    }
    printBT(root->left);
    printf("%d\n",root->data);
    printBT(root->right);
}
void freeTree(treeNode*root) // takes in the tree and frees all values in it
{
    if(root == NULL)
       {
           return;
       }
       if(root->left !=NULL)
           freeTree(root->left);
       if(root->right !=NULL)
           freeTree(root->right);
       free(root);
       return;
}

void countLeafNode(treeNode*root,int*leafCount)// takes in the tree counts all leaf nodes then for every leaf node adds 1 to a leaf counter pointer
{
    if(root->left==NULL && root->right==NULL)// checks if node is a leaf node
    {
        (*leafCount)+=1;
    }
    if (root->left !=NULL)
    {
        countLeafNode(root->left, leafCount);
    }
    if(root->right !=NULL)
    {
        countLeafNode(root->right, leafCount);
    }
}

