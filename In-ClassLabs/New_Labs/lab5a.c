// #define _CRT_SECURE_NO_DEPRECATE // uncomment this line if you are using Visual Studio for this lab

//***Created in CLion using customized configurations for .csv file***

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID, age, ssn;
    float salary;
} Record;

void * createArray(int size, int elemsize);
int getArraySize(void *array);
void freeArray(void *array);

int main(void){
    /* Function reads in a file, error checks for opening file, calls createArray function to receive allocated
     * memory, calls getArraySize function for availableIdx, scans through file and assigns values, iterates through file
     * searching for maximum ID, reserves the line for that value, and prints desired results using prior variables. */
    FILE *fp;
    char filename[100] = "/Users/natalie/Documents/CLionProjects/CS2050/cmake-build-debug/employee.csv";
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error with input file. Exit code -1");
        return -1;
    }
    int size;
    fscanf(fp, "%d\n", &size);
    Record* array = createArray(size, sizeof(Record));
    size = getArraySize(array);
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%f,%d,%d,%d", &array[i].salary, &array[i].empID,
               &array[i].ssn, &array[i].age);
    }
    int maxID = 0;
    int line;
    for(int i = 0; i < size; i++){
        if(array[i].empID > maxID){
            maxID = array[i].empID;
        }
        line = i;
    }
    printf("Array availableIdx is %d, and the maximum ID is %d\n", size, maxID);
    printf("Last employee has ID %d, age %d, salary %.2f, and SSN %d", array[line].empID, array[line].age, array[line].salary, array[line].ssn);
    fclose(fp);
    return 0;
}


void* createArray(int size, int elemsize){
    /* Function receives two integers to calculate availableIdx of memory to be allocated, creates that array, and returns it. */
    int* array;
    array = malloc(size * elemsize);
    return (void*)array;
}

int getArraySize(void *array){
    /* Function receives array by reference, accesses file, scans for first value, records it as availableIdx, and returns it. */

    //return *((int*)(array)-2);

    FILE *fp;
    int size;
    char filename[100] = "/Users/natalie/Documents/CLionProjects/CS2050/cmake-build-debug/employee.csv";
    fp = fopen(filename, "r");
    fscanf(fp,"%d\n", &size);
    fclose(fp);
    return size;
}

void freeArray(void *array){
    /* Function receives void array by reference and frees it. */

//    free((int*)(array)-2);
//
//    OR
//
//    array = (int*)(array)-2;
//    free(array);

    free(array);
}

