// prelab1.c - Implements a function that will search for a given integer in an array of integers.
// Created by Natalie Myers on 1/24/19.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int integer_search(int, int, int*);
int size_check(int);
int target_check(int);

int main(void){
    int size, target;
    srand(time(NULL)); // imports random from time.h

    printf("Please enter size of array as an integer: "); // prompts user for size of array
    scanf("%d", &size); // assigns input to variable
    size = size_check(size); // sends variable to check function and redefines it if needed

    int array[size]; // creates array with variable as parameter
    int *pointer = array; // creates pointer for above array

    for (int i = 0; i < size; i++){ // iterates through array
        array[i] = rand() % 11; // assigns random integers
    }

    printf("\nPlease enter an target from 0-10 to search for: "); // prompts user for integer to search for
    scanf("%d", &target); // assigns input to variable
    target = target_check(target); // sends variable to check function and redefines it if needed

    // test for proper initialization of array
    /*printf("\nGenerated array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }*/

    int count = integer_search(size, target, pointer); // calls search function and assigns its return to variable count
    printf("\nThe number of occurrences of integer %d is %d\n", target, count);
    if (count == 0) { // conditional for if target integer is not found in array
        printf("\nInteger %d has no index\n", target);
    }
    return 0;
}

// function that locates and counts instances of target integer
int integer_search(int size, int target, int *arrayPtr){
    int count = 0;
    int index = -1;

    for (int i = 0; i < size; i++){ // iterates through array
        if (target == *(arrayPtr+i)){ // integer matching
            count++;

            if (count == 1) { // locates first instance of target integer
                index = i; // stores its index in new variable
            }
        }
    }
    if (index != -1) { // conditional for if instance not stored in index variable
        printf("\nThe first occurrence of integer %d is at index %d", target, index);
    }
    return count;
}

int size_check(int size){ // checks size for viable input
    while (size <= 0) { // checks for negative integers
        printf("\nChoose an integer greater than or equal to 1. Try again: ");
        scanf("%d", &size);
    }
    return size;
}

int target_check(int target){ // checks target for viable input
    while (target > 10 || target < 0){ // conditional for if input is outside specified parameters
        printf("\nInvalid search; integer must be from 0-10. Try again: ");
        scanf("%d", &target);
    }
    return target;
}
