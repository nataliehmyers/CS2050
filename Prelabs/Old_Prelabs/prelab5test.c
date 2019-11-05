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
Employee** fillArray(char*);
void printArray(Employee**);

int main(int argc, char *argv[]){
    if (argc != 2) { // checks for appropriate number of command line arguments
        printf("Insufficient arguments! Load the correct number of input arguments!\n");
        return 1;
    }

    char *filename = argv[1];
    Employee **array = fillArray(filename);

    printArray(array);

    array = freeEmployeeArray(array);
    if (array != NULL) {
        printf("Free failed, program exiting...");
        return -1;
    }
    return 0;
}

Employee ** createEmployeeArray(int maxLength) {
    void* vp = malloc(maxLength*(sizeof(Employee*))+2*sizeof(int)); // allocates memory for void pointer
    int* ip = vp; // creates integer pointer to void pointer
    *ip = maxLength; // assigns maxLength to first element of integer array
    ip+=1; // iterates through integer pointer to set maxLength to availableIdx -1
    *ip = 0; // assigns availableIdx number 0 to new first element of integer array
    ip+=1; // iterates through integer pointer
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
    int maxLength = ip[-2];
    return maxLength;
}

int getIndex(Employee** array) {
    void* vp = array;
    int* ip = vp;
    int index = ip[-1];
    return index;
}

void incrementIndex(Employee** array) {
    void* vp = array;
    int* ip = vp;
    ip[-1]++;
}

int addNewEmployee(Employee* p, Employee** array) {
    int maxLength = getSize(array);
    int index = getIndex(array);
    if (index <= maxLength) {
        array[index] = p;
        incrementIndex(array);
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

Employee** fillArray(char* filename) {
    int maxLength;

    FILE *fp; // defines a FILE pointer
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable

    fscanf(fp, "%d", &maxLength);
    Employee** array = createEmployeeArray(maxLength);
    for (int i = 0; i < maxLength; i++) {
        Employee* p = malloc(sizeof(Employee));
        fscanf(fp, "%d%*c%f%*c%d%*c%f", &p->ID, &p->salary, &p->age, &p->SSN);
        addNewEmployee(p, array);
    }
    fclose(fp);
    return array;
}

void printArray(Employee** array) {
    int maxLength = getSize(array);
    for (int i = 0; i < maxLength; i++) {
        printf("ID: %d\tSalary: %.2f\tAge: %d\tSSN: %.2f\n", array[i]->ID, array[i]->salary, array[i]->age, array[i]->SSN);
    }
}
