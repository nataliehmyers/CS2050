// prelab4.c - Takes a file, reads in the number of structs, and creates that many structs.
// Created by Natalie Myers on 2/10/19.

#include <stdio.h>
#include <stdlib.h>

int get_size(char *);

struct example {
    char name[20];
    int age;
};

int main(int argc, char *argv[]){
    int size;
    if (argc != 2) { // checks for appropriate number of command line arguments
        printf("Insufficient arguments! Load the correct number of input arguments!\n");
        return 1;
    }
    char *filename = argv[1];
    size = get_size(filename);
    struct example array_example_structs[size];
}

int get_size(char *filename) {
    int size;
    FILE *fp; // defines a FILE pointer
    fp = fopen(filename, "r"); // opens a file in read mode and sets the command to a variable
    fscanf(fp, "%d", &size);
    return size;
}

// incomplete, go to prelab4test.c to see full version
