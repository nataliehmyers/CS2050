#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID, ssn, position;
    float salary;
} Record;

int get_size(char *filename);
Record* allocate_struct(int size);
Record* load_data(char *filename, int size, Record*);
void print_data(Record*, int);
void free_struct(Record*);

int main(void){
    FILE *fp;
    char filename[100] = "/Users/natalie/Documents/CLionProjects/CS2050/Prelabs/exampleFile4.txt";
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error with input file. Exit code -1");
        return -1;
    }
    int size = get_size(filename);
    printf("Size: %d\n", size);
    Record* record;
    record = allocate_struct(size);
    record = load_data(filename, size, record);
    print_data(record, size);
    free_struct(record);
    return 0;
}

int get_size(char *filename){
    int size;
    FILE *fp;
    fp = fopen(filename, "r");
    fscanf(fp, "%d ", &size);
    fclose(fp);
    return size;
}

Record* allocate_struct(int size){
    Record* array;
    array = malloc(size*sizeof(Record));
    return array;
}

Record* load_data(char *filename, int size, Record* record){
    FILE *fp;
    fp = fopen(filename, "r");
    fscanf(fp, "%d", &size);
    for (int i = 0; i < size; i++){
        fscanf(fp, "%d %d %d %f", &record[i].empID, &record[i].ssn,
               &record[i].position, &record[i].salary);
    }
    fclose(fp);
    return record;
}

void print_data(Record* record, int size){
    int i;
    for(i = 0; i < size; i++){
            printf("empID:%d\tssn:%d\tposition:%d\tsalary:%.2f\n", record[i].empID, record[i].ssn, record[i].position, record[i].salary);
    }
}

void free_struct(Record* record){
    free(record);
}
