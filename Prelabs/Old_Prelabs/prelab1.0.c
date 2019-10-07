#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void count_integers(int array[], int, int, int*, int*);

int main(void){
    srand(time(NULL)); // import rand
    int lesser = 0; // initialized to be passed by reference
    int greater = 0; // initialized to be passed by reference
    int target; // initialized by user
    int size = rand() % 10; // creates a random size for the array
    int array[size]; // creates array of random size

    printf("Enter an integer: "); // prompts user for target int
    scanf("%d", &target); // assigns input to target variable

    printf("Size: %d\n", size); // array check

    for(int i = 0; i < size; i++) { // iterates through array
        array[i] = rand() % 10; // assigns random ints to each element
    }

    for(int i = 0; i < size; i++){ // array check
        printf("%d\n", array[i]);
    }

    count_integers(array, size, target, &lesser, &greater); // calls function for greater/lesser ints

    printf("There are %d integers greater than %d\n", greater, target); // prints results from count_integers
    printf("There are %d integers less than %d", lesser, target); // prints results from count_integers

    return 0;
}

void count_integers(int array[], int size, int target, int* lesser, int* greater) {
    for(int i = 0; i < size; i++) { // iterates through array
        if(array[i] > target) { // conditional for greater ints
            *greater = *greater + 1; // tallies greater ints
        }
        if(array[i] < target) { // conditional for lesser ints
            *lesser = *lesser + 1; // tallies lesser ints
        }
    }
}
