// #define _CRT_SECURE_NO_DEPRECATE // uncomment this line if you are going to use Visual Studio for this lab
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID, age, ssn;
    float salary;
} Record;

int readRecordFile(char *filename, Record ***array);
void freeRecordArray(Record ***array, int numElems);
int findAge(Record **array, int ageLow, int ageHigh, int size);

int main(void){
    /* Function creates a Record pointer, calls readRecordFile to open and initialize array,
     * receives size in return, declares parameters for search function, calls findAge and gets
     * number of employees in set interval in return, prints results and frees array. */
    Record ***array = malloc(sizeof(int));
    char filename[100] = "//Users/natalie/Documents/CLionProjects/CS2050/Prelabs/employee.csv";
    int size = readRecordFile(filename, array);
    int ageLow = 25;
    int ageHigh = 35;
    int total = findAge(*array, ageLow, ageHigh, size);
    printf("The number of employees between the ages %d and %d is: %d", ageLow, ageHigh, total);
    freeRecordArray(array, size);
    array = NULL;
    return 0;
}

int readRecordFile(char *filename, Record ***array){
    /* Function receives a filename by reference and a double pointer by reference,
     * opens file using filename variable, scans in size, error checks for opening file,
     * mallocs for array elements, assigns values by scanning in values from file, closes
     * file and returns size. */
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

int findAge(Record **array, int ageLow, int ageHigh, int size){
    /* Function receives array by reverence, search parameters, and number of elements,
     * iterates through elements for ones that satisfy conditions and tallies number of occurrences,
     * and returns value. */
    int total = 0;
    for(int i = 0; i < size; i++) {
        if (array[i]->age > ageLow && array[i]->age < ageHigh){
            total++;
        }
    }
    return total;
}

void freeRecordArray(Record ***array, int numElems){
    /* Function receives double pointer by reference and number of elements, iterates through array,
     * freeing each element, then frees pointer to array, and then frees original struct pointer. */
    for(int i = 0; i < numElems; i++) {
        free((*array)[i]);
    }
    free(*array);
    free(array);
    array = NULL;
}
