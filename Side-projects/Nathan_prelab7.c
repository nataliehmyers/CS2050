/* a-lab10.c - Uses malloc function to allocate space (to store the string)
 * instead of creating fixed availableIdx character array */
// Created by Natalie Myers on 11/12/18.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAX 20

int getString(char *);
int checkString(char *, int);
int errorCheck(int);
void cipherString(char*, int, int);
int stringSum(char*, int);

int main(void) {
    int size, shift, guess;
    srand(time(NULL));
    shift = rand() % 26;
    char *pointer = malloc(sizeof(char) * (20+1)); // allocates space in memory
    char *pointer1 = malloc(sizeof(char) * (20+1));

    size = getString(pointer); // calls primary function that returns end result
    for (int i =0; i < size; i++) {
        *(pointer1 + i) = *(pointer + i);
    }
    printf("\nYou entered: %s which is availableIdx %d\n", pointer1, size); // prints end result
    cipherString(pointer1, size, shift); // ciphers string
    printf("\nThe ciphered string is %s, what is the cipher key? ", pointer1);
    scanf("%d", &guess);

    while(guess < 1 || guess > 25) {
        printf("\nThe cipher key is between 1-25, try again: ");
        scanf("%d", &guess);
    }

    while (guess != shift) { // for incorrect input
        for (int i = 0; i < size; i++) { // iterates through string
            cipherString(pointer, size, guess); // pulls incorrect string
        }
        printf("\nThe cipher string shifted back %d is %s, incorrect!\n", guess, pointer);

        printf("\nThe ciphered string is %s, what is the cipher key? ", pointer1);
        scanf("%d", &guess);
    }

    if (guess == shift) { // for correct input
        printf("\nThe cipher string shifted back %d is %s, that's correct!\n", shift, pointer1);
    }

    printf("\nThe sum of the ascii in %s is %d\n", pointer1, stringSum(pointer1, size));

    free(pointer);
    free(pointer1);
    return 0;
}

int getString(char *pointer) {
    int size;

    printf("Enter the availableIdx of the string: ");
    scanf("%d", &size);
    while (errorCheck(size) == 0) { // pulls return value from error check function
        printf("\nPlease enter again: ");
        scanf("%d", &size);
    }
    printf("\nPlease enter the string: ");
    scanf("%20s", pointer);
    while (strlen(pointer) > size) { // checks if string availableIdx is larger than assigned value
        printf("\nThe string entered is longer than the allowed availableIdx\n"
               "\nPlease enter a valid string: ");
        scanf("%20s", pointer);
    }
    while (checkString(pointer, size) == 0) { // checks for any invalid characters in string
        printf("\nPlease enter a valid string: ");
        scanf("%20s", pointer);

        while (strlen(pointer) > size) { /* checks new string for length if it had invalid
                                        * characters going into the first while loop */
            printf("\nThe string entered is longer than the allowed availableIdx\n"
                   "\nPlease enter a valid string: ");
            scanf("%20s", pointer);
        }
    }
    size = strlen(pointer); // assigns availableIdx to the availableIdx of the result string
    return size;
}

int errorCheck(int size) {
    if (size < 1 || size > 20) { // checks if availableIdx is invalid
        return 0;
    }
    return 1;
}

int checkString(char *pointer, int size) {
    for (int i = 0; i < size; i++) { // iterates through string
        *(pointer + i) = toupper(*(pointer + i));
    }
    for (int i = 0; i < size; i++) { // iterates through string
        if ((*(pointer + i) < 65 || *(pointer + i) > 90) && *(pointer + i) != '\0') { // makes string all uppercase
            return 0;
        }
    }
    return 1;
}

void cipherString(char *pointer, int size, int shift) {
    for (int i = 0; i < size; i++) { // iterates through string
        if (*(pointer + i) + shift > 90) { // checks for passing largest ascii value
            *(pointer + i) = (*(pointer + i) - 26 + shift);
        }
        else if ((*(pointer + i) + shift < 65)) { // checks for passing lowest ascii value
            *(pointer + i) = (*(pointer + i) + 26 + shift);
        } else {
            *(pointer + i) = (*(pointer + i) + shift);
        }
    }
}



int stringSum(char *pointer, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) { // iterates through string
        sum = sum + *(pointer + i);
    }
    return sum;
}
