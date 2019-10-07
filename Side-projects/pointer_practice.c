#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int square_function(int*);
void* double_pointer(int**);

int main(void){
    srand(time(NULL));
    int x;
    int y;
    int* ptr;
    int array[10];
    x = 5;
    y = 2;
    ptr = &x;
    printf("*ptr = %d\t x = %d\n", *ptr, x);
    *ptr = y;
    printf("*ptr = %d\t y = %d\n", *ptr, y);
    for(int i = 0; i < 10; i++){
        array[i] = rand() % 10;
        printf("array[%d] = %d\n", i, *(array+i));
    }

    *ptr = square_function(ptr);
    int** dp_ptr = &ptr;
     = double_pointer(dp_ptr);

    return 0;
}

int square_function(int* ptr){
    printf("ptr received in square_function: %d\n", *ptr);
    *ptr = ((*ptr) * (*ptr));
    printf("ptr returned by square_function: %d\n", *ptr);
    return *ptr;
}

void* double_pointer(int** ptr){

}
