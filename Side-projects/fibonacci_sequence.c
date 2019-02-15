// fibonacci_sequence - Calculates the sequence up to a given number.
// Created by Natalie Myers on 2/14/19.

#include <math.h>
#include <stdio.h>

int getTarget(int);

int main(void){
    int fx, fy, sum, target;

    getTarget(target);

    fx = 0;
    fy = 1;

    for (int i = 0; i < target; i++) {
        sum = fx + fy;
        fx = sum;
        sum = fy + fx;
        printf("%d ", sum);
    }
    return 0;
}

int getTarget(int target) {
    printf("Enter how many numbers of the Fibonacci Sequence you want: ");
    scanf("%d", target);
    return target;
}
