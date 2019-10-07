// prelab4.c - Takes a file, reads in the number of structs, and creates that many structs.
// Created by Natalie Myers on 2/10/19.

#include <stdio.h>
#include <stdlib.h>
#include "struct.c"

typedef struct employee_ {
    char name[20];
    int age;
}employee;


int get_size(FILE *);
void get_data(struct Example[], int, FILE *);

int main(int argc, char *argv[]){
    int size;
    if (argc != 2) { // checks for appropriate number of command line arguments
        printf("Insufficient arguments! Load the correct number of input arguments!\n");
        return 1;
    }
    FILE *fp; // defines a FILE pointer
    char *filename = argv[1];
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable
    size = get_size(fp);
    struct Example examples[size]; // creates array of structs
    get_data(examples, size, fp);

    for (int i = 0; i < size; i++) { // prints struct information
        printf("\nname:%s age:%d", examples[i].name, examples[i].age);
    }
    
    
}

int get_size(FILE *fp) {
    int size;
    fscanf(fp, "%d", &size); // scans integer
    printf("%d", size);
    return size;
}

void get_data(struct Example examples[], int size, FILE *fp) {
    for (int i = 0; i < size; i++) { // iterates through file
        //fscanf(fp, "%s %d", examples[i].name, &examples[i].age); // assigns struct information
        fscanf(fp, "%s ", examples[i].name);
    }
}
