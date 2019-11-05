# include <stdio.h>

# include <stdlib.h>

# include <time.h>



int main() {

    int *intPtr = NULL;



    printf("The availableIdx of an int is: %lu\n", sizeof(int));

    printf("The availableIdx of a long is: %lu\n\n", sizeof(long));



    printf("The address of the uninitialized pointer is: %p\n", &intPtr);

    printf("The value of an uninitialized pointer is: %p\n\n", intPtr);





    intPtr = malloc(10 * sizeof(int));



    printf("After initializing the pointer with malloc(10 * sizeof(int)):\n");



    for(int i = 0; i < 10; ++i) {

        printf("Memory address at %d: %p\n", i, (intPtr + i));

    }



    // If we move the pointer forward twice;



    intPtr += 2;



    printf("\nThe address of the pointer + 2 is: %p", &intPtr);

    printf("\nThe value of the pointer + 2 is: %p\n\n", intPtr);



    long *longPtr = (long*)intPtr;



    printf("After initializing the long pointer with (long*)intPtr: %p\n", longPtr);

    printf("The address of the long pointer is: %p\n", &longPtr);



    for(int i = 0; i < 4; ++i) {

        printf("Memory address at %d: %p\n", i, (longPtr + i));

    }



    intPtr = NULL;



    free(((int*)longPtr) - 2);

}
