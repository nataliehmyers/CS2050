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

    if (argc != 2) { // checks for appropriate number of command line arguments
        printf("Insufficient arguments! Load the correct number of input arguments!\n");
        return 1;
    }

    FILE *fp; // defines a FILE pointer
    char *filename = argv[1];
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable

    Employee *array;



    createEmployeeArray();

}
