# include <stdlib.h>
# include <stdio.h>
# include <time.h>

void computeEvenOdd(int arr[], int size, int* evenPrt, int* oddPtr); // function prototype
void* createArray(int elemSize, int elemNumber);

int main(void) {

    // Use current time as seed for random generator
    srand(time(0));
    int size = 10;

    int* array = (int*)createArray(sizeof(int), size);
    for (int i = 0; i < size; i++){
        array[i] = rand() % 10 + 1;
    }

    int even,odd;
    computeEvenOdd(array, size, &even, &odd);

    printf("Array is: ");
    for (size_t i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
    printf("\nArray has %d even numbers and %d odd numbers\n",even,odd);

    free(array);

    return 0;
}

void computeEvenOdd(int arr[], int size, int* evenPrt, int* oddPtr){

    *evenPrt = 0;
    *oddPtr = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 0){
            (*evenPrt) ++;
        } else {
            (*oddPtr) ++;
        }
    }

}

void* createArray(int elemSize, int elemNumber){
    int* array = (int*)malloc(elemNumber*elemSize);
    if (array == NULL){
        printf("Malloc failed\n");
        return NULL;
    } else {
        return (void*)array;
    }
}
