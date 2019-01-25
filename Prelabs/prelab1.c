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
    srand(time(NULL));

    printf("Please enter size of array as an integer: ");
    scanf("%d", &size);
    size = size_check(size);

    int array[size];
    int *pointer = array;

    for (int i = 0; i < size; i++){
        array[i] = rand() % 11;
    }

    printf("\nPlease enter an target from 0-10 to search for: ");
    scanf("%d", &target);
    target = target_check(target);

    // test for proper initialization of array
    /*printf("\nGenerated array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }*/

    int count = integer_search(size, target, pointer);
    printf("\nThe number of occurrences of integer %d in the array is %d", target, count);
    if (count == 0) {
        printf("\nInteger %d has no index", target);
    }
    return 0;
}

int integer_search(int size, int target, int *arrayPtr){
    int count = 0;
    int index = -1;

    for (int i = 0; i < size; i++){
        if (target == *(arrayPtr+i)){
            count++;

            if (count == 1) {
                index = i;
            }
        }
    }
    if (index != -1) {
        printf("\nThe first occurrence of integer %d is at index %d", target, index);
    }
    return count;
}

int size_check(int size){
    while (size <= 0) {
        printf("\nChoose an integer greater than or equal to 1. Try again: ");
        scanf("%d", &size);
    }
    return size;
}

int target_check(int target){
    while (target > 10 || target < 0){
        printf("\nInvalid search; integer must be from 0-10. Try again: ");
        scanf("%d", &target);
    }
    return target;
}
