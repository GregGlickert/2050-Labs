#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void * createArray(int n, int elemsize);
int getArraySize(void *array);
void freeArray(void *array);

int main(void){

    srand(time(NULL)); // for random integers

    int n = 10; // size of array

    int* array = (int*)createArray(n, sizeof(int));
    if (array == NULL){
        printf("Allocation failed\n");
        return 0;
    }

    printf("Elements in array are: "); // print out all kinds of information
    for (int i = 0; i < n; i++){
        printf("%d, ", array[i]);
    }
    printf("\nArray size is %d, and the maximum value in array is %d\n", getArraySize((void*)array), array[-1]);

    freeArray((void*)array); // free array

    return 0;
}

void * createArray(int n, int elemsize){

    int* array = (int*)malloc(elemsize*n+sizeof(int)*2); // allocate memory for array and other two parameters.

    if (array == NULL){ // error checking
        printf("Allocation failed\n");
        return NULL;
    }

    *(array) = n;
    array += 2;

    int max = 0;
    for (int i = 0; i < n; i++){
        array[i] = rand() % 10 + 1;
        if (max < array[i]){
            max = array[i];
        }
    }

    array[-1] = max;

    return (void*)array;
}

int getArraySize(void* array){
    return *((int*)array-2);
}

void freeArray(void* array){
    array = ((int*)array-2);
    free (array);
}
