#include <stdio.h>
#include <stdlib.h>

int main(void){
    char string1[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char replace[4] = {'e', 'l', 'l', '\0'};
    char new[4] = {'a', 'l', 'l', '\0'};
    printf("Original: %s\n", string1);
    printf("Replace this: %s\n", replace);
    printf("With this: %s\n", new);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++) {
            if (*(string1 + i) == *(replace + j)) {
                *(string1+i) = *(new+j);
            }
        }
    }
    printf("Final string: %s", string1);

    return 0;
}
