// #define _CRT_SECURE_NO_DEPRECATE // uncomment this line if you are going to use Visual Studio for this lab
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID, age, ssn;
    float salary;
} Record;

int readRecordFile(char *filename, Record ***array);
void freeRecordArray(Record ***array, int numElems);
void adjustSalaries(Record **array, int age, float x, int size);

int main(void){

    char* filename = "employee.csv";
    Record **empArray;

    int size = readRecordFile(filename,&empArray);
    if (size == 0){
        printf("Allocation failed\n");
        return -1;
    } else if (size == -1){
        printf("File does not exist\n");
        return -1;
    } else {
        printf("Data has been read into the array, there're %d employees in the record file\n",size);
    }

    adjustSalaries(empArray, 30, 1.05, size);

    freeRecordArray(&empArray, size);
    empArray = NULL;

    return 0;

}

int readRecordFile(char *filename, Record ***array){

    FILE *fp;
    fp = fopen(filename, "r");

    int size;
    if (fp){

        fscanf(fp,"%d\n", &size);
        (*array) = malloc(sizeof(Record*)*size);

        if ((*array) == NULL){
            fclose(fp);
            return 0;
        }

        for (int i = 0; i < size; i++){

            *(*array + i) = malloc(sizeof(Record));
            if (*(*array + i) == NULL){
                fclose(fp);

                // free all previously allocated memories
                for (int j = 0; j < i; j++){
                    free(*(*array + j));
                    *(*array + j) = NULL;
                }
                free(*array);
                *array = NULL;

                return 0;
            }

            fscanf(fp, "%f,%d,%d,%d\n", &((*(*array+i))->salary), &((*(*array+i))->age), &((*(*array+i))->empID), &((*(*array+i))->ssn));
        }

        fclose(fp);
        return size;

    } else {
        return -1;
    }

}

void freeRecordArray(Record ***array, int numElems){

    for (int i = 0; i < numElems; i++){

        free (*(*array+i));
        *(*array+i) = NULL;

    }

    free(*array);
    *array = NULL;
}

void adjustSalaries(Record **array, int age, float x, int size){

    for (int i = 0; i < size; i++){

        if (array[i]->age == age){
            array[i]->salary *= x;
        }

    }
}
