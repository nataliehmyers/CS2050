#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID, age, ssn;
    float salary;
} Record;

int readRecordFile(char *filename, Record ***array);
void adjustSalaries(Record **employees, int position, float x, int size);
void freeRecordArray(Record ***array, int numElems);


int main(void){
    Record ***array = malloc(sizeof(int));
    char filename[100] = "/Users/natalie/Documents/CLionProjects/CS2050/Prelabs/employee.csv";
    int size = readRecordFile(filename, array);
    int position;
    float x;
    position, x = 0;
    adjustSalaries(*array, position, x, size);
    freeRecordArray(array, size);
    array = NULL;
    return 0;
}

int readRecordFile(char *filename, Record ***array){
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL){
        return -1;
    }
    int size;
    fscanf(fp, "%d\n", &size);
    Record** temp_array = malloc(size * sizeof(*array));
    if (temp_array == NULL){
        return 0;
    }
    for(int i = 0; i < size; i++){
        Record* address = malloc(sizeof(Record));
        if(address == NULL){
            return 0;
        }
        temp_array[i] = address;
        fscanf(fp, "%f,%d,%d,%d\n", &address->salary, &address->empID, &address->ssn, &address->age);
    }
    *array = temp_array;
    fclose(fp);
    return size;
}

void adjustSalaries(Record **employees, int position, float x, int size){
    for(int i = 0; i < size; i++){
        if(employees[i]->empID == position){
            employees[i]->salary = employees[i]->salary * x;
        }
    }
}

void freeRecordArray(Record ***array, int numElems){
    for(int i = 0; i < numElems; i++) {
        free((*array)[i]);
    }
    free(*array);
    free(array);
}
