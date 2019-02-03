
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void* createArray(int numElements, int dataTypeSize);
void freeArray(void *numArray);


int main(void){
    int *practiceArray;

    practiceArray = createArray(MAX, sizeof(int));

    for (int i = 0; i < MAX; i++) {
        practiceArray[i] = MAX-i;
    }

    for (int i = 0; i < MAX; i++) {
        printf("%d ", practiceArray[i]);
    }

    freeArray(practiceArray);
}


void* createArray(int numElements, int dataTypeSize) {
    int *array;
    array = malloc(sizeof(int) + numElements*dataTypeSize);
    if (array == NULL) {
        printf("\nMalloc failed. Cannot recover. Exiting...\n");
        exit(1);
    }
    array[0] = numElements;
    array++;
    return (void *)(array);
}

void freeArray(void * numArray) {
    free(numArray-(sizeof(int)));
}
