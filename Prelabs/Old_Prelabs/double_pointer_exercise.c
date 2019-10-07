#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int occurrence(int**, int, int);

int main(void) {
    srand(time(NULL));
//    int search = rand() % 10;
    int search = 2;
    int size = 8;
    int *array;
    array = malloc(size * sizeof(int));
    int** p = &array;
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % 10;
    }

    printf("array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }

    int count = occurrence(p, size, search);
    printf("\n\n%d", count);

    return 0;
}

int occurrence(int** p, int size, int search){
    int count = 0;
    for (int i = 0; i < size; i++) {
        if ((*p)[i] == search){
            count++;
        }
    }
    if (count != 0) {
        return count;
    } else {
        return 1;
    }
}
