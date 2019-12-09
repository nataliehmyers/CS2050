/* Implement a C function that takes a null-terminated string and returns
 * a new heap-allocated null-terminated string containing every other character
 * from original string (e.g., “house” -> “hue”). char* strdup_every_other_char(const char* s) { */

#include <stdio.h>
#include <stdlib.h>

char* strdup_every_other_char(const char* s);

int main(void){

    const char string[] = {'h', 'o', 'u', 's', 'e', '\0'};
    printf("Original string: %s\n", string);

    char* new_string = strdup_every_other_char(string);
    printf("String returned to main: %s\n", new_string);


    return 0;
}

char* strdup_every_other_char(const char* s){

    char* new_string = malloc(sizeof(s));
    int i = 0, j = 0;
    while(*(s + i) != '\0'){
        if(i % 2 == 0){
            *(new_string + j) = *(s + i);
            j++;
        }
        i++;
    }
    return new_string;
}
