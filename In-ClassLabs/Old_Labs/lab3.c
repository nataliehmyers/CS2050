#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Please do not change the fct prototypes.
    Please use descriptive variable names and appropriate spacing!
    Please leave appropriate comments where necessary but do not remove the ones provided.
    Please remember to answer the questions at the end, if any.
    Compilation command: gcc lab3.c -Werror -Wall
*/

// Function prototypes
float* createIntArray(int);
int getArraySize(float*);
void freeArray(float*);
void printArray(int, int, float*);
float float_rand(float, float);


int main(void){

    // Your array needs to be filled with 10 randomly generated floating point numbers rounded to two decimal places
    // Your output must EXACTLY MATCH the sample output pattern

    float *array;
    int size = 10;

    array = createIntArray(size);

    getArraySize(array);

    freeArray(array);
}

// Define prototyped functions below here

float* createIntArray(int size) { // creates array
    float *array;
    size = 10;
    int maxIndex = 0;
    array = malloc((2*sizeof(int)) + (size*sizeof(float))); // allocates memory
    if (array == NULL) {
        printf("\nMalloc failed. Cannot recover. Exiting...\n");
        exit(1);
    }
    array = array + 2;
    for (int i = 0; i < size; i++) { // increments through array
//        array[i] = (float)rand()/(float)(RAND_MAX/10);
//        array[i] = float_rand(0, 10);
        array[i] = float_rand(0.0, 10.0);
    }
    float max = -1;
    for (int i = 0; i < size; i++) {
        if (array[i] > max){ // checks for a larger value
            max = array[i];
            maxIndex = i;
        }
    }
    array[-2] = size;
    array[-1] = maxIndex;

    printArray(size, maxIndex, array); // calls to print array

    return array;
}

void freeArray(float * array) { // frees array
    free(array-2);
}

int getArraySize(float* array) { // returns size of array
    return array[-2];
}

void printArray(int size, int maxIndex, float* array){ // prints array, index, and size

    printf("Array size is %d, Index of largest value is %d\n", size, maxIndex);
    printf("Elements in the array are: ");
    for (int i = 0; i < size; i++) { // increments through array
        printf("%.2f ", array[i]);
    }
}

float float_rand(float min, float max) {
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}

/* Questions to answer:
1. Describe any real world example where negative array indices are useful.
 Perhaps in patient medical files or anything encrypted.

2. According to C, what is the result of the computation 5/3 given both 5 and 3 are integers? Why?
 1 because it does not factor in the remainder with integers. A more accurate data type would be floats,
 and if you specifically want the remainder, mod (%) is what you should use.
*/
