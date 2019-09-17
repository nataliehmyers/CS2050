#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void * createArray(int n, int elemsize);
int getArraySize(void *array);
void freeArray(void *array);

int main(void){
    /* Function defines variables and array, calls createArray function, calls getArraySize function,
     * then calls freeArray function.*/
    srand(time(NULL));

    int i;
    int size;
    int n = rand() % 10;
    int elemsize = 4;
    printf("Randomized Size = %d\n", n);
    int *array;

    array = createArray(n, elemsize);

    size = getArraySize(array);
    printf("Size from getArraySize = %d", size);

    freeArray(array);
}

void* createArray(int n, int elemsize){
    /* Function receives two integers to specify array size and size of the data type,
     * then allocates the appropriate amount from memory for that array and returns it.
     * Function stores size of array as -1 element; allocated memory accordingly.*/
    int *array;
    int i;
    array = malloc((n * elemsize) + sizeof(int));
    if (array == NULL){
        printf("Malloc failed.");
    }
    array = array + 1;
    for (i = 0; i < n; i++){
        array[i] = rand() % 10;
    }
    array[-1] = n;

    return array;
}

int getArraySize(void *array){
    /* Function receives array by reference and returns -1 element. */
    return *((int*)array - 1);
}

void freeArray(void *array){
    /* Function receives array by reference, typecasts it as new array to access int element,
     * and frees array*/
    int* temp = array;
    free(temp-1);
}
