#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int* createIntArray(int);
void* createArray(int numElems, int elemSize);

int main(void){
    /* Function creates an array, calls createIntArray to allocate memory,
     * then creates variables to be passed to openArray to allocate memory
     * for a general data type array. Function frees both arrays and exits. */
    srand(time(NULL));
    int size = rand() % 10;
    int *array;

    array = createIntArray(size);
    if(array == NULL){
        printf("Error: no memory allocated. Try again.\n");
        return -1;
    } else {
        printf("Memory successfully allocated for integer array.\n");
    }
    free(array);

    int numElements = rand() % 10;
    int elemSize = 4;

    void* openArray = createArray(numElements, elemSize);
    if (openArray == NULL) {
        printf("Error: no memory allocated. Try again.\n");
        return -1;
    } else {
        printf("Memory successfully allocated for general data type array.\n");
    }
    free(openArray);
    return 0;
}

int* createIntArray(size){
    /* Function takes in size of array and returns an array with
     * appropriate amount of memory allocated. */
    int *array = (int*) malloc(size * sizeof(int));
    return array;
}

void* createArray(int numElems, int elemSize){
    /* Function receives number of elements in an array and the number
     * of bits for that data type. Function returns a type void array
     * with the appropriate amount of memory allocated. */
    void* array = malloc(numElems * elemSize);
    return array;
}
