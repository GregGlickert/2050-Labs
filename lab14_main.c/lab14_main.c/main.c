#include "lab14.h"

int main(void)
{
    srand(time(NULL));
    treeNode*root;
    //int BTHeight;
    int leafCount;
    root=NULL;
    for(int i=0; i<10;i++)
    {
        root=insertBT(root, 9);
    }
    printBT(root);
    countLeafNode(root, &leafCount);
    printf("Amount of leafs is %d\n",leafCount);
    freeTree(root);
}

