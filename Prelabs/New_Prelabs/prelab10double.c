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
    queuePtr->headPtr = NULL;
    queuePtr->tailPtr = NULL;
    queuePtr->size = 0;
    return queuePtr;
}

int enqueue(int k, Queue *queuePtr){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return -1;
    }
    newNode->key = k;
    queuePtr->size++;
    if(queuePtr->headPtr == NULL){
        queuePtr->headPtr = newNode;
        newNode->next = NULL;
        queuePtr->tailPtr = newNode;
    } else {
        newNode->next = queuePtr->headPtr;
        queuePtr->headPtr = newNode;
    }
    return 0;
}
