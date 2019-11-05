#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float* createIntArray(int);
int getArraySize(float*);
int getArrayIndex(float*);
void freeArray(float*);
void printArray(float*);

int main(void){
    srand(time(NULL));

    int size = 10;
    createIntArray(size);
}

float* createIntArray(int size){
    int max_index = 0;
    int max = 0;
    float* array = malloc((2 * sizeof(int)) + (size * sizeof(float)));
    *((int*)array) = size;
    array = (float*)((int*)array+1);
    *((int*)array) = max_index;
    array = (float*)((int*)array+1);
    double n = 0;
    for(int i = 0; i < size; i++){
        n = (float)(rand() % 100)/(float)10;
        array[i] = n;
    }
    for(int i = 0; i < size; i++){
        if (array[i] > max){
            max = array[i];
            max_index = i;
        }
    }
    *((int*)array - 1) = max_index;

    printArray(array);
    return array;
}

void printArray(float* array){
    int size = getArraySize(array);
    int max_index = getArrayIndex(array);
    printf("Elements in array are: ");
    for(int i = 0; i < size; i++){
        printf("%.2f ", array[i]);
    }
    printf("\nArray availableIdx is %d, Index of largest value is %d\n", size, max_index);
}

int getArraySize(float* array){
    return *((int*)array-2);
}

int getArrayIndex(float* array){
    return *((int*)array-1);
}

void freeArray(float* array){
    free ((int*)array-2);
}
