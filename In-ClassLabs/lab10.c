#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {

    int ID;
    float salary;
    int age;

} Employee;

Employee** createArray(void);
int binarySearch(Employee**, int, int, int);

int main(void) {

    return 0;
}

Employee** createArray(void){
    int max = 0;

    FILE *fp;
    if((fp = fopen("employee.csv", "r")) == NULL){
        printf("Error file could not be opened.\n");
    } else {
        fscanf(fp, "%d", &max);
        void * ptr;
        ptr = malloc(sizeof(Employee*) * max + sizeof(int));
        if(ptr){
            int* temp;
            temp = ptr;
            *temp = max;
            temp++;
            ptr = temp;
            Employee** array = ptr;
            for(int i = 0; i < max; i++){
                array[i] = malloc(sizeof(Employee));
            }

            for(int i=0; i<max; i++){
                fscanf(fp, "%d,%f,%d", &((*array[i]).ID), &((*array[i]).salary), &((*array[i]).age));
            }
            fclose(fp);

            return array;
        } else {
            printf("Malloc failed\n");
            return NULL;
        }
    }
    return NULL;
}
