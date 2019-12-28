# include <stdlib.h>
# include <stdio.h>

void computeInOut(int arr[], int size, int lowBoundary, int highBoundary, int* inPtr, int* outPtr); // function prototype

int main(void) {

    int size = 10, lowBoundary = -5, highBoundary = 5;
    int array[10] = {5,-9,8,2,-7,10,12,-9,3,-6};

    int inlier,outlier;
    computeInOut(array, size, lowBoundary, highBoundary, &inlier, &outlier);

    printf("Array is: ");
    for (size_t i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
    printf("\nArray has %d inliers and %d outliers\n",inlier,outlier);

    return 0;
}

void computeInOut(int arr[], int size, int lowBoundary, int highBoundary, int* inPtr, int* outPtr){

    *inPtr = 0;
    *outPtr = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] > lowBoundary && arr[i] < highBoundary){
            (*inPtr) ++;
        } else {
            (*outPtr) ++;
        }
    }

}
