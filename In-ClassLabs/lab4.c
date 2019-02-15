#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes

typedef struct emp {
    int ID;
    float salary;
    int age;
    float SSN;
} Employee;


Employee* createArray(FILE*);
int numOfEmployee(int*);
void freeArray(int*);
void statsAvg(Employee*, int, float*, float*);
int findEmployeeID(Employee*, int, int);

/*
    Please do not change the fct prototypes.
    Please use descriptive variable names and appropriate spacing!
    Please leave appropriate comments where necessary but do not remove the ones provided.
    Please remember to answer the questions at the end, if any.
    Compilation command: gcc lab3.c -Werror -Wall
*/

int main(int argc, char *argv[]) {
    int num, i, SSN1, SSN2;
    int search1 = 323658912;
    int search2 = 563911234;

    if (argc != 2) { // checks for appropriate number of command line arguments
        printf("Insufficient arguments! Load the correct number of input arguments!\n");
        return 1;
    }
    FILE *fp; // defines a FILE pointer
    char *filename = argv[1];
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable



    Employee *array;//void* array
    array = createArray(fp);
    num = numOfEmployee((int*)array);
    for (i = 0; i < num; i++){
        fscanf(fp, "%d%*c%f%*c%d%*c%f\n", &array[i].ID, &array[i].salary, &array[i].age, &array[i].SSN);
    }

    float avgSalary = 0, avgAge = 0;
    statsAvg(array, num, &avgSalary, &avgAge);
    printf("The average salary is: $%.2f and the average age is: %.2f\n", avgSalary, avgAge);

    SSN1 = findEmployeeID(array, num, search1);
    if (SSN1 != -1) {
        printf("Employee ID %d has SSN %d\n", SSN1, search1);
    } else {
        printf("No employee found with SSN %d\n", search1);
    }
    SSN2 = findEmployeeID(array, num, search2);
    if (SSN2 != -1) {
        printf("Employee ID %d has SSN %d\n", SSN2, search2);
    } else {
        printf("No employee found with SSN %d\n", search2);
    }
    freeArray((int*)array);
    fclose(fp);
}

void statsAvg(Employee* array, int size, float* avgSalary, float* avgAge) {

    float totalSalary = 0;
    float totalAge = 0;

    for (int i = 0; i < size; i++){
        totalSalary += array[i].salary;
        totalAge += array[i].age;
    }
    *avgSalary = totalSalary / size;
    *avgAge = totalAge / size;
}

Employee* createArray(FILE* fp){
    int* array = NULL;
    int length = 0;

    fscanf(fp, "%d\n", &length);
    array = malloc(sizeof(int) + sizeof(Employee) * length);
    array[0] = length;
    //array++;
    return (Employee*)(array + 1);
}

int findEmployeeID(Employee* array, int size, int SSN) {
    int i;
    for (i = 0; i < size; i++) {
        if (SSN == array[i].SSN) {
            return array[i].ID;
        }
    }
    return -1;
}

int numOfEmployee(int *array) {

//    --array;// array - 1
//    array--;// array

    //*(array - 1);

    return *(array - 1);
}

void freeArray(int *array){
    free(array - 1);
}

//Employee* createArray(FILE *fp) { // creates array
//    Employee *array;
//    int size;
//    fscanf(fp, "%d", &size); // scans integer
//    printf("size=%d", size); // test - holds correct integer
//    array = malloc(size*sizeof(Employee)+ sizeof(int));
//    array = malloc(sizeof(int) + size*sizeof(Employee));
//    array++;
//    for (int i = 0; i < size; i++){
//        fscanf(fp, "%d%*c%2f%*c%d%*c%2f", &array[i].ID, &array[i].salary, &array[i].age, &array[i].SSN);
//    }
//    array[-1] = size;
//    array[-1] = (void*)size;
//    array[-1] = (Employee)size;
//    array[-1].ID = size;
//    return array;
//}


//void statsAvg(Employee *array, int num){
//    float ages=0;
//    for (int i = 0; i < num; i++) {
//        ages = ages + array[i].SSN;
//    }
//    float avgAge = ages / num;
//    // should calculate average age, salary
//}

//int findEmployeeID(){
//    should search for employee ID
//}
