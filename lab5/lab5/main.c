#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID, age, ssn;
    float salary;
} Record;

void * createArray(int n, int elemsize);
int getArraySize(void *array);
void freeArray(void *array);

int main(void)
{
    int n=0;
    int elemsize;
    FILE *fp=fopen("employee.csv","r");
    if(!fp)//error checking for opening the file
    {
        printf("file error");
        return NULL;
    }
    fscanf(fp,"%d", &n);
    elemsize=sizeof(Record);
    int*array=createArray(n,elemsize);
    for(int i=0;i<n;i++)
    {
        Record record;
        fscanf(fp,"%f%*c %d%*c %d%*c %d",&(record.salary), &(record.age), &(record.empID), &(record.ssn));
        ((Record*)array)[i]=record;
        
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < ((Record*)array)[i].ssn)
        {
            max = ((Record*)array)[i].ssn;
        }
    }
    
    array[-1] = max;
    printf("Array size is %d and the maximum SSN is %d\n",getArraySize(array), array[-1]);
    printf("Last employee had ID %d, age %d, salary %.2f, and SSN %d\n",((Record*)array)[9999].empID,((Record*)array)[9999].age,((Record*)array)[9999].salary,((Record*)array)[9999].ssn);
    
    freeArray((void*)array);
    fclose(fp);
    return 0;
}
void * createArray(int n, int elemsize)
{
    int*Array1 = malloc(n * elemsize + sizeof(int)*2);
    if(Array1==NULL)//test if malloc worked
    {
        printf("malloc failed");
        return NULL;
    }
    *((int *)Array1) = n;
    Array1=(int *)Array1+1;
    
    *(Array1) = n;
    Array1 += 2;
    
   /* int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < ((Record*)Array1)[i].ssn)
        {
            max = ((Record*)Array1)[i].ssn;
        }
    }
    
    Array1[-1] = max; */
    
    return (void*)Array1;
}
int getArraySize(void *array)
{
    int size;
    size=*((int *)array-2);
    return size;
}
void freeArray(void *array)
{
    void*addressToBeFreed=((int *)array-2);
    free(addressToBeFreed);
}
