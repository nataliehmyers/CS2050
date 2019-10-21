#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Queue {
    struct Node* headPtr;
    struct Node* tailPtr;
    int size;
} Queue;

Queue * initQueue();
int enqueue(int, Queue *);
int dequeue(Queue *, int *);
int getQsize(Queue *);
void printQueue(Queue*); // required to test functions
void freeQueue(Queue *);

int main(void){
    srand(time(NULL));

    return 0;
}

Queue * initQueue(void){
    Queue* queuePtr = malloc(sizeof(Queue));
    listPtr->headPtr = NULL;
    listPtr->tailPtr = NULL;
    listPtr->size = 0;
}
