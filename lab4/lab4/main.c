#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void * createArray(int n, int elemsize);
int getArraySize(void *array);
void freeArray(void *array);

int main(void)
{
    
    srand(time(NULL)); // for random integers
    int n = 10; // size of array
    int* array=createArray(n,sizeof(int));
    printf("Array is: ");
    for(int i=0;i<n;i++)
    {
        printf("%d,",array[i]);
    }
    printf("\nArray size is: %d and the max value of the array is ",getarraySize(array));
    printf("%d\n",array[-2]);
    freeArray(array);
    return 0;
}
void * createArray(int n, int elemsize) //function takes in the number of elements and the size of the data type and makes an array
{
    int upperValue=10;
    int lowerValue=1;
    void *Array1 = malloc(n * elemsize + sizeof(int) +sizeof(int));
    if(Array1==NULL)//if malloc failed then the program will tell the user
    {
        printf("malloc failed");
        return NULL;
    }
   
   for(int i=0;i<n;i++)//fills array with random numbers between 1 and 10
    {
        int randInt = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
        ((int *)Array1)[i]=randInt;
    }
  
    int* max= ((int *)Array1); //takes in the array and finds the max
    for(int i=0;i<n;i++)
    {
        if (((int *)Array1)[i] > *max)
            *max = ((int *)Array1)[i];
    }
    ((int *)Array1)[0] = n;
    ((int *)Array1)[1]=*max;
    Array1=(int *)Array1+2;//hides both the size of the array and the max
    return Array1;
}
int getarraySize(void* array)//takes in the array and outputs the hidden size
{
    int size;
    size=*(((int *)array-2));
    return size;
}
void freeArray(void* array)//takes in the array and frees the memory
{
    void*addressToBeFreed=((int *)array-2);
    free(addressToBeFreed);
}
