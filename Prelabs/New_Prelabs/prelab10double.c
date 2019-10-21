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
    Queue* queuePtr = initQueue();
    int check = -2;
    int k = (rand() % 10) + 1;
    for(int i = 0; i < 5; i++){
        check = enqueue(k, queuePtr);
        printQueue(queuePtr);
        k = (rand() % 10) + 1;
        if(check != 0){
            printf("Failed to create a new node\n");
        }
    }
    int removedKey = 0;
    int* keyPtr = &removedKey;
    for(int i = 0; i < 5; i++){
        check = dequeue(queuePtr, keyPtr);
        printQueue(queuePtr);
        if(check != 0){
            printf("Cannot remove node from an empty list\n");
        }
    }
    int size = getQsize(queuePtr);
    freeQueue(queuePtr);
    return 0;
}

Queue* initQueue(){
    Queue* queuePtr = malloc(sizeof(Queue));
    queuePtr->headPtr = NULL;
    queuePtr->tailPtr = NULL;
    queuePtr->size = 0;
    return queuePtr;
}

int enqueue(int k, Queue* queuePtr){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return -1;
    }
    newNode->key = k;
    queuePtr->size++;
    if(queuePtr->headPtr == NULL){
        queuePtr->headPtr = newNode;
        queuePtr->tailPtr = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = queuePtr->headPtr;
        queuePtr->headPtr = newNode;
        queuePtr->tailPtr->next = newNode;
        newNode->prev = queuePtr->tailPtr;
    }
    return 0;
}

int dequeue(Queue* queuePtr, int* keyPtr){
    if(queuePtr->headPtr == NULL){
        return -1;
    }
    if(getQsize(queuePtr) == 1){
        int key = queuePtr->headPtr->key;
        free(queuePtr->headPtr);
        queuePtr->size--;
        queuePtr->headPtr = NULL;
        queuePtr->tailPtr = NULL;
        *keyPtr = key;
        return 0;
    }
    Node* currentPtr = queuePtr->headPtr;
    while(currentPtr->next->next != queuePtr->headPtr){
        currentPtr = currentPtr->next;
    }
    Node *removeNode = currentPtr->next;
    int key = removeNode->key;
    currentPtr->next = queuePtr->headPtr;
    queuePtr->tailPtr = currentPtr;
    queuePtr->headPtr->prev = queuePtr->tailPtr;
    queuePtr->size--;
    *keyPtr = key;
    free(removeNode);
    return 0;
}

int getQsize(Queue* queuePtr){
    return queuePtr->size;
}

void printQueue(Queue* queuePtr){
    Node* currentPtr = queuePtr->headPtr;
    if(currentPtr == NULL){
        return;
    }
    while(currentPtr->next != queuePtr->headPtr){
        printf("%d ", currentPtr->key);
        currentPtr = currentPtr->next;
    }
    printf("%d ", queuePtr->tailPtr->key);
    printf("\n");
}

void freeQueue(Queue* queuePtr){
    while(getQsize(queuePtr) > 0){
        int poppedValue = 0;
        dequeue(queuePtr, &poppedValue);
    }
    free(queuePtr);
    queuePtr = NULL;
    printf("Queue has been freed.\n");
}
