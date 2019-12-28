#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID, age, ssn;
    float salary;
} Record;

int readRecordFile(char *filename, Record ***array);
void freeRecordArray(Record ***array, int numElems);
void adjustSalaries(Record **array, int age, float x, int size);

int main(void)
{
    Record**array;
    int size;
  //  printf("main test");
    size = readRecordFile("employee.csv",&array);
    adjustSalaries(array,30,1.05,size);
    freeRecordArray(&array,size);
    return 0;
}
int readRecordFile(char *filename, Record ***array) //takes in the array and then open and reads the file. Then mallocs and fills the array and outputs the size of the array and array of pointers.
{
    int size;
    FILE *fp=fopen("employee.csv","r");
       if(!fp)//error checking
       {
           printf("file error");
           return -1;
       }
    fscanf(fp,"%d", &size);
    *array=malloc(size * sizeof(Record*));
    for(int i=0; i<size;i++)
    {
        Record*temp=malloc(sizeof(Record));
        if (temp==NULL)
        {
            printf("malloc error");
            return 0;
        }
        fscanf(fp,"%f%*c %d%*c %d%*c %d",&temp-> salary,&temp -> age, &temp -> empID, &temp -> ssn);
        //printf("%d\n",temp->empID);
        (*array)[i]=temp;
    }
    
  //  printf("Record File");
    return size;
    
}
void adjustSalaries(Record **array, int age, float x, int size) //takes the info and searches for people who are 30 and then multiples there salary by 1.05 and outputs the changed infomation
{
  // printf("adjust salary");
    for(int i=0;i<size;i++)
    {
        if(array[i]->age==age)
        {
            array[i]->salary=array[i]->salary*x;
      // printf("%d %f\n",array[i]->age,array[i]->salary);
        }
    }
}
void freeRecordArray(Record ***array, int numElmes) //takes in the size and frees everything that was malloced
{
    for(int i=0;i<numElmes;i++)
    {
        free((*array)[i]);
    }
    free(*array);
}
