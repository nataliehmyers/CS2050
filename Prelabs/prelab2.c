// prelab2.c - An exercise with a generalization to work with any datatype.
// Created by Natalie Myers on 1/31/19.

#include <stdio.h>
#include <stdlib.h>

void* createArray(int numElements, int dataTypeSize);
void freeArray(void *numArray);

int main(void){
     int numElements, dataTypeSize;
    void *numArray;

    printf("Enter the size of the data type you would like to use: "); // prompts user for size of data type
    scanf("%d", &dataTypeSize); // assigns input to variable

    printf("\nEnter the size of the array you want to create: "); // prompts user for size of array
    scanf("%d", &numElements); // assigns input to variable


    numArray = createArray(numElements, dataTypeSize); // calls createArray function to essentially malloc array

    freeArray(numArray); // frees memory

    return 0;
}


void* createArray(int numElements, int dataTypeSize) { // malloc with size of array stored as an element in the array
    int *array;
    array = malloc(sizeof(int) + numElements*dataTypeSize); // malloc size of array and size of int (for integer of elements)
    if (array == NULL) { // checks if malloc failed
        printf("\nMalloc failed. Cannot recover. Exiting...\n");
        exit(1);
    }
    array[0] = numElements; // assigns number of elements to first element of array
    array++; // increments through the array to offset indexes
    return (void *)(array);
}

void freeArray(void * numArray) {
    free(numArray-(sizeof(int))); // frees original array
}
