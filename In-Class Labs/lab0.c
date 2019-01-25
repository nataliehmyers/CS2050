// lab0.c - Review exercise with pointers.
// Created by Natalie Myers on 1/23/19.

#include <stdio.h>
#include <stdlib.h>

void addition(int, int, int*);

int main(void){

    int integer1, integer2, sum;
    integer1 = 1;
    integer2 = 2;
    printf("The first and second numbers are %d and %d.\n", integer1, integer2);
    addition(integer1, integer2, &sum);
    printf("The third number is %d.", sum);
}

void addition(int integer1, int integer2, int *sum){
    *sum = integer1 + integer2;
}

/*
#include <stdlib.h>
#include <stdio.h>

void addition(int integer1,int integer2,int* sumPtr); // function prototype

int main(void) {


    int integer1 = 1, integer2 = 2, sum;

    // prints out the value of the first two integers
    printf("First integer is %d, and second integer is %d\n",integer1,integer2);

    // computes the sum by calling your addition function
    addition(integer1, integer2, &sum);

    // prints out the value in the third integer
    printf("The third integer is %d\n", sum);
    return 0;
}

void addition(int integer1,int integer2,int* sumPtr){
    // adds passed integers
    *sumPtr = integer1 + integer2;
}
*/
