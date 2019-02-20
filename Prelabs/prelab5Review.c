// Created by Natalie Myers on 2/17/19.

#include <stdio.h>
#include <stdlib.h>

typedef struct emp {
    int ID;
    float salary;
    int age;
    float SSN;
} Employee;

typedef struct new_{
    int ID;
    float salary;
    int age;
    float SSN;
} new;

int getSize(Employee**);
Employee ** createEmployeeArray(int);
int addNewEmployee(Employee *, Employee**);
int getIndex(Employee **array);
void* freeEmployeeArray(Employee**);
Employee** fillArray(char*);
void printArray(Employee**);
int findAge(int, Employee**);
int addUserEmployee(Employee**);
void printUserArray(int, new*);

int main(int argc, char *argv[]){
//    if (argc != 2) { // checks for appropriate number of command line arguments
//        printf("Insufficient arguments! Load the correct number of input arguments!\n");
//        return 1;
//    }

    char *filename = "employeeFile";
    Employee **array = fillArray(filename);

//    printArray(array);

    int search;
    printf("\nEnter an age to search for: ");
    scanf("%d", &search);

    int ageCount = findAge(search , array);
    printf("\nThe number of instances of age %d is %d\n", search, ageCount);

    addUserEmployee(array);

    array = freeEmployeeArray(array);
    if (array != NULL) {
        printf("Free failed, program exiting...");
        return -1;
    }
    return 0;
}

Employee** createEmployeeArray(int maxLength) {
    void* vp = malloc(maxLength*(sizeof(Employee*))+2*sizeof(int)); // allocates memory for void pointer
    int* ip = vp; // creates integer pointer to void pointer
    *ip = maxLength; // assigns maxLength to first element of integer array
    ip+=1; // iterates through integer pointer to set maxLength to index -1
    *ip = 0; // assigns index number 0 to new first element of integer array
    ip+=1; // iterates through integer pointer
    vp = ip;
    Employee** array = vp;

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
    int size = getSize(array);
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    printf("%d size\n", size);

    free((int*)array - 2);
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
        if(fscanf(fp, "%d%*c%f%*c%d%*c%f", &p->ID, &p->salary, &p->age, &p->SSN) <= 0){
            free(p);
        }
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

int findAge(int search, Employee** array){
    int count = 0;
    int index = getIndex(array);
    for (int i = 0; i < index; i++){
        if (array[i]->age == search){
            count++;
        }
    }
    return count;
}

int addUserEmployee(Employee** array){
    int index;
    printf("\nEnter the number of new employees: ");
    scanf("%d", &index);
    new* p = malloc(index * sizeof(new));

    for (int i = 0; i < index; i++) {
        printf("\nEnter employee ID: ");
        scanf("%d", &p[i].ID);

        printf("\nEnter employee salary: ");
        scanf("%f", &p[i].salary);
        printf("\nEnter employee age: ");
        scanf("%d", &p[i].age);
        printf("\nEnter employee SSN: ");
        scanf("%f", &p[i].SSN);
    }
    printUserArray(index, p);
    free(p);


    //freeUserArray(index, p);
    //int index = getIndex(array);
    //int maxLength = getSize(array);
    /*
    if (index <= maxLength) {
        *((new*)array + index) = *p;
        incrementIndex(array);
        return index;
    } else {
        return -1;
    } */

}

void printUserArray(int index, new* p) {
    printf("\n");
    for (int i = 0; i < index; i++) {
        printf("ID: %d\tSalary: %.2f\tAge: %d\tSSN: %.2f\n", p[i].ID, p[i].salary, p[i].age, p[i].SSN);
    }
}
