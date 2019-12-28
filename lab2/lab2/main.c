# include <stdlib.h>
# include <stdio.h>

void computeInOut(int array[], int size, int lowBoundary, int highBoundary, int* inPtr, int* outPtr); // function prototype

int main(void)
{
    int i;
    int size = 10, lowBoundary = -5, highBoundary = 5;
    int inPrt=0;
    int outPtr=0;
    int array[10] = {6,-9,8,2,-7,10,12,-9,3,-6};
    printf("Array is:");
    for(i=0;i<size;i++)
    {
        printf("%d, ",array[i]); //prints out array
    }
    computeInOut(array,size,lowBoundary,highBoundary,&inPrt,&outPtr); //runs function
    printf("\nArray has %d inliers and %d outliers\n",inPrt,outPtr); // prints out whats in and outside the bounds
    
    return 0;
}

void computeInOut(int array[],int size,int lowBoundary,int highBoundary,int* inPtr,int* outPtr)
{
    * inPtr=0;
    * outPtr=0;// points needed because its a void function
    for(size_t i=0;i<size;i++)
    {
        if (array[i] > lowBoundary && array[i] < highBoundary) // checks if array value is between the high and low boundary with an AND statement
        {
            *inPtr=*inPtr+1; //adds 1 to the amount of values in between the high and low bounds
        }
        else
        {
            *outPtr=*outPtr+1; // adds 1 to the amount of values outside the bounds
        }
    }
}
