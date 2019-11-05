#include <stdio.h>
#include <stdlib.h>

/* Headers do not match prototypes exactly*/

typedef struct emp {
    int ID;
    double salary;
    int age;
} Employee;

/*
Employee** createArray(void);
int addEmployee(Employee**, double, int);
void freeArray(Employee**);
*/

int countSalary(Employee**, double);
int getSize(Employee**);
Employee ** createEmployeeArray(int);
int addNewEmployee(Employee *, Employee**);
int getIndex(Employee **array);
void* freeEmployeeArray(Employee**);
Employee** fillArray(char*);
void printArray(Employee**);
void addEmployee(Employee**);


int main(int argc, char *argv[]){

    char *filename = "employee.csv"; // calls in text file
    Employee **array = fillArray(filename); // fills array with the called function

    float search = 12346; // given search number
    int count = countSalary(array, search); // calls search function to find number of instances of given salary
    printf("There are %d employees with salary %f\n", count, search);

//    printArray(array);

    addEmployee(array); // add employee array to attempt to add two given employees

    array = freeEmployeeArray(array); // frees array struct
    if (array == NULL) { // conditional for freed array
        printf("Array freed!\n");
        return 0;
    }
    return -1; // contingency for failure to free
}

Employee ** createEmployeeArray(int maxLength) { // pass it maxLength and recieve double pointer
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

int getSize(Employee** array) { // pass it the double pointer and recieve maxLength as an int
    void* vp = array; // defines void pointer
    int* ip = vp; // creates integer pointer to void pointer
    int maxLength = ip[-2]; // assigns maxLength to hidden availableIdx -2
    return maxLength;
}

int getIndex(Employee** array) { // pass it the double pointer and recieve the next available availableIdx
    void* vp = array; // defines void pointer
    int* ip = vp; // creates integer pointer to void pointer
    int index = ip[-1]; // assigns next available availableIdx to hidden availableIdx -1
    return index;
}

void incrementIndex(Employee** array) { // pass it the array and it will incrememnt the availableIdx without returning
    void* vp = array; // defines void pointer
    int* ip = vp; // creates integer pointer to void pointer
    ip[-1]++; // iterates through elements
}

int addNewEmployee(Employee* p, Employee** array) { // pass it a single employee pointer and the double pointer, recieve the next available availableIdx if it passes
    int maxLength = getSize(array); // calls getSize to find maxLength
    int index = getIndex(array); // calls getIndex to find availableIdx
    if (index <= maxLength) { // conditional to see if availableIdx has reached largest element
        array[index] = p; // assigns open element to pointer p
        incrementIndex(array); // increments availableIdx to next element
        return index;
    } else {
        return -1;
    }
}

void *freeEmployeeArray(Employee** array) { // pass it double pointer
    free(*array);
    array = NULL;
    return array;
}

Employee** fillArray(char* filename) { // passes the text filename and recieves back the double pointer
    int maxLength;

    FILE *fp; // defines a FILE pointer
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable
    fscanf(fp, "%d", &maxLength); // scans text file for length
    Employee** array = createEmployeeArray(maxLength);
    for (int i = 0; i < maxLength; i++) {
        Employee* p = malloc(sizeof(Employee)); // allocates memory for a struct
        fscanf(fp, "%d%*c%lf%*c%d\n", &p->ID, &p->salary, &p->age);
        addNewEmployee(p, array);
    }
    fclose(fp);
    return array;
}

void printArray(Employee** array) { // pass it the double pointer
    int maxLength = getSize(array); // calls getSize function to get maxLength
    for (int i = 0; i < maxLength; i++) { // iterates through the array
        printf("ID: %d\tSalary: %.2f\tAge: %d\n", array[i]->ID, array[i]->salary, array[i]->age);
    }
}

int countSalary(Employee** array, double search){ // pass it the doubple pointer and double to search for, recieve back the number of instances in the array
    int count = 0;
    int index = getIndex(array); // calls getindex to get the next available element in the array
    for (int i = 0; i < index; i++) { // checks for while in initialized array
        if (array[i]->salary == search) { // checks for matching salaries
            count++; // if a matching salary is found, 1 gets added to count each time 
        }
    }
    return count;
}

void addEmployee(Employee** array) { // pass it the double pointer

    typedef struct new_{ // struct definition for new employee
        int ID;
        float salary;
        int age;
        float SSN;
    } new;

    int index = getIndex(array);
    int maxLength = getSize(array);

    new* p = malloc(index * sizeof(new)); // allocates memory for availableIdx of a new employee struct

    if (index <= maxLength) { // conditional for if availableIdx has reached the end of the array
        p->ID = index;
        p->salary = 12345;
        p->age = 34;
        printf("Added employee %d with age %d and salary %.2f\n", index, p->age, p->salary);
        incrementIndex(array);
    } else {
        printf("The employee can not be added. Array full!\n");
    }

    if (index <= maxLength) { // conditional for if availableIdx has reached the end of the array
        p->ID = index++;
        p->salary = 31236;
        p->age = 64;
        incrementIndex(array);
        printf("Added employee %d with age %d and salary %.2f\n", index, p->age, p->salary);
    } else {
        printf("The employee can not be added. Array full!\n");
    }
    free(p); // frees new employee struct
}
