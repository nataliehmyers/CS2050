// fibonacci_sequence - Calculates the sequence up to a given number.
// Created by Natalie Myers on 2/14/19.

#include <math.h>
#include <stdio.h>

int getTarget();

int main(void){
    int first, second, sum, target;

    target = getTarget();

    first = 0;
    second = 1;
    sum = 0;

    for (int i = 0; i < target; i++) {
        printf("%d ", sum);
        sum = first + second;
        second = first;
        first = sum;
    }
    return 0;
}

int getTarget(){
    int target;
    printf("Enter how many numbers of the Fibonacci Sequence you want: ");
    scanf("%d", &target);
    return target;
}
