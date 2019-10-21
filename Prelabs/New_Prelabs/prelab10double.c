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
void verify(Queue *);

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
    if(getQsize(queuePtr) == 0){
        queuePtr->headPtr = newNode;
        queuePtr->tailPtr = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else if(getQsize(queuePtr) == 1) {
        newNode->next = queuePtr->tailPtr;
        newNode->prev = queuePtr->tailPtr;
        queuePtr->headPtr = newNode;
        queuePtr->tailPtr->next = newNode;
        queuePtr->tailPtr->prev = newNode;
    }
    else if(getQsize(queuePtr) > 1) {
        newNode->next = queuePtr->headPtr;
        newNode->prev = queuePtr->tailPtr;
        queuePtr->tailPtr->next = newNode;
        queuePtr->headPtr->prev = newNode;
        queuePtr->headPtr = newNode;
    }
    queuePtr->size++;
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
    Node* secondToLastNode = queuePtr->tailPtr->prev;
    Node *removeNode = queuePtr->tailPtr;
    int key = removeNode->key;
    secondToLastNode->next = queuePtr->headPtr;
    queuePtr->tailPtr = secondToLastNode;
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

void verify(Queue* queue) {
    if (queue->size == 0) {
        if (queue->headPtr != NULL) {
            printf("size=0 head should be null");
            exit(1);
        }
        if (queue->tailPtr != NULL) {
            printf("size=0 tail should be null");
            exit(1);
        }
    }

    else if (queue->size == 1) {
        if (queue->headPtr->next != queue->tailPtr) {
            printf("size=1 head->next should be tail");
            exit(1);
        }
        if (queue->tailPtr->next != queue->headPtr) {
            printf("size=1 tail->next should be head");
            exit(1);
        }
        if (queue->headPtr->prev != queue->tailPtr) {
            printf("size=1 head->prev should be tail");
            exit(1);
        }
        if (queue->tailPtr->prev != queue->headPtr) {
            printf("size=1 tail->prev should be tail");
            exit(1);
        }
    }

    else if (queue->size > 1) {
        if (queue->headPtr->prev != queue->tailPtr) {
            printf("size=1+ head->prev should be tail");
            exit(1);
        }
        if (queue->tailPtr->next != queue->headPtr) {
            printf("size=1+ tail->next should be head");
            exit(1);
        }

        {
            Node* n = queue->headPtr;
            int moved = 0;
            while (n != queue->tailPtr) {
                n = n->next;
                moved++;
                if (moved > queue->size) {
                    printf("size=1+ should have found tail by now");
                    exit(1);
                };
            }
        }
        {
            Node* n = queue->tailPtr;
            int moved = 0;
            while (n != queue->headPtr) {
                n = n->prev;
                moved++;
                if (moved > queue->size) {
                    printf("size=1+ should have found head by now");
                    exit(1);
                };
            }
        }
    }
}
