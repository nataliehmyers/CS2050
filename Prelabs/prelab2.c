// prelab2.c - An exercise with a generalization to work with any datatype.
// Created by Natalie Myers on 1/31/19.

#include <stdio.h>
#include <stdlib.h>

void* createArray(int n, int dataTypeSize);


int main(void){
    int n, dataTypeSize;
    float *numarray;

    printf("Enter the size of the data type you would like to use: ");
    scanf("%d", &dataTypeSize);

    printf("\nEnter the size of the array you want to create: ");
    scanf("%d", &n);

    numarray = createArray(n, dataTypeSize);

    for (int i = 0; i < n; i++){
        printf("%.2f ", numarray[i]);
    } // Todo: Fix index offset
}


void* createArray(n, dataTypeSize) {
    int *array;
    array = malloc(n*dataTypeSize + sizeof(int)); // ToDo: Find how to check if malloc worked
    array[0] = n;
    array++;
    // free((void *)(array+1)); ???
    return (void *)(array+1); // ToDo: Ask how to free memory here
}