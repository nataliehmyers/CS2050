#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct {
    int key;
    float priority;
    struct nodestruct *next;
} Node;

typedef struct {
    int size, sum;
    Node *rear;
} PQueue;


PQueue* initPQ(); // Return empty priority queue
int insertPQ(int, float, PQueue *); // int key, float priority
int deleteMaxPQ(PQueue *, int *);
int deleteMinPQ(PQueue *, int *);
int getSizePQ(PQueue *); // returns # of items
void reInitPQ(PQueue *); /* Re-initialize an existing priority queue as an empty priority queue. */
void freePQ(PQueue *); // Free all priority-queue memory
void printPQueue(PQueue*); // to test functions

int main(void){
    PQueue* queue = initPQ();
    insertPQ(1, 91.3, queue);
    printPQueue(queue);
    insertPQ(2, 91.3, queue);
    printPQueue(queue);
    insertPQ(3, 74.2, queue);
    printPQueue(queue);
    insertPQ(4, 101.7, queue);
    printPQueue(queue);

    int removedItem = 0;
    int* key = &removedItem;
    deleteMinPQ(queue, key);
    printPQueue(queue);
    deleteMinPQ(queue, key);
    printPQueue(queue);
    deleteMinPQ(queue, key);
    printPQueue(queue);
    deleteMinPQ(queue, key);
    printPQueue(queue);
    deleteMinPQ(queue, key);
    printPQueue(queue);

    freePQ(queue);
    printPQueue(queue);


    return 0;
}

PQueue* initPQ(){
    PQueue* queue = malloc(sizeof(PQueue));
    if(queue == NULL){
        return NULL;
    }
    queue->rear = NULL;
    queue->size = 0;
    queue->sum = 0;
    return queue;
}

int insertPQ(int key, float priority, PQueue* queue){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return -1;
    }
    newNode->key = key;
    newNode->priority = priority;
    queue->sum = queue->sum + key;
    queue->size++;
    if(queue->rear == NULL){
        queue->rear = newNode;
        newNode->next = newNode;
    } else if (priority < queue->rear->priority) {
        newNode->next = queue->rear->next;
        queue->rear->next = newNode;
        queue->rear = newNode;
    } else {
        Node* currentNode = queue->rear;
        while (priority < currentNode->next->priority) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    return 0;
}

int deleteMaxPQ(PQueue* queue, int* key){
    if(queue->rear == NULL){
        return -1;
    }
    if(key == NULL){
        return -2;
    }
    if(queue->size == 1){
        *key = queue->rear->next->key;
        free(queue->rear->next);
        queue->size--;
        queue->sum = queue->sum - *key;
        queue->rear = NULL;
        return 0;
    }
    Node *removeNode = queue->rear->next;
    *key = removeNode->key;
    queue->rear->next = removeNode->next;
    queue->sum = queue->sum - *key;
    queue->size--;
    free(removeNode);
    return 0;
}

int deleteMinPQ(PQueue *queue, int *key){
    if(queue->rear == NULL){
        return -1;
    }
    if(key == NULL){
        return -2;
    }
    if(queue->size == 1){
        *key = queue->rear->next->key;
        free(queue->rear->next);
        queue->size--;
        queue->sum = queue->sum - *key;
        queue->rear = NULL;
        return 0;
    }
    Node *removeNode = queue->rear;
    Node *currentNode = queue->rear->next;
    *key = removeNode->key;
    while(currentNode->next != queue->rear){
        currentNode = currentNode->next;
    }
    currentNode->next = removeNode->next;
    queue->rear = currentNode;
    queue->sum = queue->sum - *key;
    queue->size--;
    free(removeNode);
    return 0;
}

int getSizePQ(PQueue* queue){
    return queue->size;
}

void reInitPQ(PQueue* queue){
    while(queue->size > 0){
        int poppedValue = 0;
        deleteMaxPQ(queue, &poppedValue);
    }
}

void printPQueue(PQueue* queue){
    if (queue == NULL){
        return;
    }
    if(queue->rear == NULL){
        return;
    }
    Node* currentPtr = queue->rear->next;
    while(currentPtr->next != queue->rear->next){
        printf("Key: %d\tPriority: %.2f\n", currentPtr->key, currentPtr->priority);
        currentPtr = currentPtr->next;
    }
    printf("Key: %d\tPriority: %.2f", currentPtr->key, currentPtr->priority);
    printf("\n");
    printf("----------------------------------\n");
}

void freePQ(PQueue* queue){
    reInitPQ(queue);
    free(queue);
    queue = NULL;
}
