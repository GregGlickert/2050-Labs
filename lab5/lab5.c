#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID, age, ssn;
    float salary;
} Record;

void * createArray(int n, int elemsize);
int getArraySize(void *array);
void freeArray(void *array);

int main(void){

    FILE *fp;
    fp = fopen("employee.csv", "r");

    int size;
    Record *empArray;

    if (fp){

        fscanf(fp,"%d\n", &size); // get size of array from the first line of file
        empArray = createArray(size, sizeof(Record));

        if (empArray == NULL){ // error check for malloc
            printf("Allocating memory failed\n");
            return -1;
        }
    }
    else {
        printf("Cannot find the file\n"); // error checking
        return -1;
    }

    int maxSSN = 0;
    for (int i = 0; i < size; i++){
        fscanf(fp, "%f,%d,%d,%d\n", &empArray[i].salary, &empArray[i].age, &empArray[i].empID, &empArray[i].ssn);
        if (maxSSN < empArray[i].ssn){
            maxSSN = empArray[i].ssn;
        }
    }

    *((int*)empArray-1) = maxSSN;

    printf("Array size is %d, and the maximum SSN is %d\nLast employee has ID %d, age %d, salary %.2f, and SSN %d\n", getArraySize((void*)empArray), *((int*)empArray-1), empArray[size-1].empID, empArray[size-1].age, empArray[size-1].salary, empArray[size-1].ssn);

    freeArray((void*)empArray);

    return 0;
}

void * createArray(int n, int elemsize){

    int* array = (int*)malloc(elemsize*n + sizeof(int)*2);

    if (array == NULL){ // error checking
        printf("Allocation failed\n");
        return NULL;
    }

    *(array) = n;
    array += 2;

    return (void*)array;
}

int getArraySize(void* array){
    return *((int*)array-2);
}

void freeArray(void* array){
    array = ((int*)array-2);
    free (array);
}
