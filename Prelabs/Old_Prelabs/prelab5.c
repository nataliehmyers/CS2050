//
// Created by Natalie Myers on 2/14/19.

#include <stdio.h>
#include <stdlib.h>

typedef struct emp {
    int ID;
    float salary;
    int age;
    float SSN;
} Employee;


Employee** createEmployeeArray(int);
int addNewEmployee(Employee *, Employee **);
void *freeEmployeeArray(Employee **);

int main(int argc, char *argv[]){
    int maxLength = 0;
    int i, j, empArray, newIndex;

    if (argc != 2) { // checks for appropriate number of command line arguments
        printf("Insufficient arguments! Load the correct number of input arguments!\n");
        return 1;
    }

    FILE *fp; // defines a FILE pointer
    char *filename = argv[1];
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable

    Employee **array;

    fscanf(fp, "%d", &maxLength);

    array = createEmployeeArray(maxLength);
    for(i = 0; i < maxLength; i++){
        for(j = 0; j < maxLength; j++){
            fscanf(fp, "%d%*c%f%*c%d%*c%f\n", &array[i][j].ID, &array[i][j].salary, &array[i][j].age, &array[i][j].SSN);
        }
    }
    for(i = 0; i < 2; i++){
        for(j = 0; j < maxLength; j++){
            printf("ID %d\tsalary %.2f\n", array[i][j].ID, array[i][j].salary);
        }
    }

    Employee new;
    new.SSN = 1234;
    new.age = 11;
    new.salary = 888888;
    new.ID = 12;

    newIndex = addNewEmployee(&new, array);


    if (freeEmployeeArray(array) != NULL) {
        return -1;
    }

}

Employee** createEmployeeArray(int maxLength) {
    Employee** array = NULL;
    int i;
    array = malloc(sizeof(Employee*) * maxLength);
    for(i = 0; i < maxLength; i++){
        array[i] = malloc(sizeof(Employee) * maxLength);
    }
    return array;
}
/*
 * Node* current = array;
 * while(current != null){
 *      length++;
 *      current = current -> next;
 * }
 */
int addNewEmployee(Employee *p, Employee **array) {

}

void *freeEmployeeArray(Employee ** array) {

//    int i;
//    for(i = 0; i < availableIdx; i++) {
//        free(array[i]);
//    }
    free(array);
}
