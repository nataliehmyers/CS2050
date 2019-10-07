//
// Created by Natalie Myers on 2/17/19.

#include <stdio.h>
#include <stdlib.h>

typedef struct emp {
    int ID;
    float salary;
    int age;
    float SSN;
} Employee;

int getSize(Employee**);
Employee ** createEmployeeArray(int);
int addNewEmployee(Employee *, Employee**);
int getIndex(Employee **array);
void* freeEmployeeArray(Employee**);

int main(int argc, char *argv[]){
    if (argc != 2) { // checks for appropriate number of command line arguments
        printf("Insufficient arguments! Load the correct number of input arguments!\n");
        return 1;
    }
    Employee** array = createEmployeeArray(500);
    getSize(array);
    getIndex(array);

    Employee* p = malloc(sizeof(Employee));

    p->ID = 12;
    p->salary = 888888;
    p->age = 11;
    p->SSN = 1234;

    addNewEmployee(p, array);

    array = freeEmployeeArray(array);
    if (array != NULL) {
        printf("Free failed, program exiting...");
        return -1;
    }
    return 0;
}

Employee ** createEmployeeArray(int maxLength) {
    void* vp = malloc(maxLength*(sizeof(Employee))+2*sizeof(int));
    int* ip = vp;
    *ip = maxLength;
    ip+=1;
    *ip = 0;
    ip+=1;
    vp = ip;
    Employee** array = vp;
    for (int i = 0; i < maxLength; i++) {
        array[i] = malloc(sizeof(Employee));
    }
    return array;
}

int getSize(Employee** array) {
    void* vp = array;
    int* ip = vp;
    int index = ip[-2];
    return index;
}

int getIndex(Employee** array) {
    void* vp = array;
    int* ip = vp;
    int index = ip[-1];
    return index;
}

int addNewEmployee(Employee* p, Employee** array) {
    int maxLength = getSize(array);
    int index = getIndex(array);
    if (index <= maxLength) {
        array[index] = p;
        return index;
    } else {
        return -1;
    }
}

void *freeEmployeeArray(Employee** array) {
    for (int i = 0; i < 0; i++) {
        free(array[i]);
    }
    free(*array);
    array = NULL;
    return array;
}

//int getSize(char* filename) {
//    int maxLength;
//    FILE *fp; // defines a FILE pointer
//    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable
//    fscanf(fp, "%d", &maxLength);
//    fclose(fp);
//    return maxLength;
//}
