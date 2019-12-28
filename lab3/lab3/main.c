# include <stdlib.h>
# include <stdio.h>
# include <time.h>

void computeEvenOdd(int arr[], int size, int* evenPrt, int* oddPtr); // function prototype
void* createArray(int elemSize, int elemNumber);

int main(void)
{
    
    // Use current time as seed for random generator
    srand(time(0));
    int size = 10;
    int* arr=createArray(size,sizeof(int));//uses malloc to allocated enough space for an array
    int evenPtr=0;
    int oddPtr=0;
    int upperValue=10;
    int lowerValue=1;
    for(int i=0;i<size;i++)//fills array with random numbers between 1 and 10
    {
        int randInt = (rand() % (upperValue - lowerValue + 1)) + lowerValue;
        arr[i]=randInt;
    }
    printf("Array is: ");
    for(int i=0;i<size;i++)
    {
        printf("%d,",arr[i]);
    }
    computeEvenOdd(arr,size,&evenPtr,&oddPtr);//computes how many even and odd numbers the array has
    printf("\nArray has %d even numbers and %d odd numbers",evenPtr,oddPtr);
    free(arr);
    return 0;
}

void* createArray(int numElems,int ElemsSize)//takes in the size of the array and the data type of the array and created an array with enough memory
{
    void*Array1=malloc(numElems*ElemsSize);//allocates enough memory for the array
    return Array1;
}
void computeEvenOdd(int arr[], int size, int* evenPrt, int* oddPtr)// This function takes in the array and outputs the number of even numbers and odd numbers inside the array
{
    * evenPrt=0;
    * oddPtr=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i] % 2 == 0) // calcs if number is even or odd
        {
            * evenPrt=* evenPrt+1;
        }
        else
        {
            * oddPtr=* oddPtr+1;
        }
    }
}
