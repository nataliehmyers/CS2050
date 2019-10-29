#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct {
    int key;
    float priority;
    struct nodestruct *next;
} Node;
typedef struct {
    int size;
    Node *front, *rear;
} PQueue;

PQueue* initPQ();
int insertPQ(int, float, PQueue*);
int deleteMinPQ(PQueue*, int*);
void reInitPQ(PQueue*);
void freePQ(PQueue*);
void printPQ(PQueue*);

int main(void){
    PQueue* queue = initPQ();
    insertPQ(1, 0, queue);
    insertPQ(2, 99, queue);
    insertPQ(3, 50, queue);
    printPQ(queue);
    printf("\n");

    int removedItem = 0;
    int* key = &removedItem;
    deleteMinPQ(queue, key);
    printPQ(queue);
    printf("\n");
    deleteMinPQ(queue, key);
    printPQ(queue);

    freePQ(queue);

    return 0;
}

PQueue* initPQ(){

    PQueue* queue = malloc(sizeof(PQueue));
    if(queue == NULL){
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

int insertPQ(int key, float priority, PQueue* queue){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return -1;
    }
    newNode->key = key;
    newNode->priority = priority;
    queue->size++;
    if(queue->rear == NULL){
        queue->rear = newNode;
        queue->front = newNode;
        newNode->next = newNode;
    } else if (priority > queue->rear->priority) {
        newNode->next = queue->rear->next;
        queue->front = queue->rear->next;
        queue->rear->next = newNode;
        queue->rear = newNode;
    } else {
        Node* currentNode = queue->rear;
        while (priority > currentNode->next->priority) {
            currentNode = currentNode->next;
        }
        queue->front = queue->rear->next;
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    return 0;
}

int deleteMinPQ(PQueue* queue, int* key){
    if(queue->rear == NULL){
        return -1;
    }
    if(key == NULL){
        return -1;
    }
    if(queue->size == 1){
        *key = queue->rear->next->key;
        free(queue->rear->next);
        queue->size--;
        queue->rear = NULL;
        return 0;
    }
    Node *removeNode = queue->rear->next;
    *key = removeNode->key;
    queue->rear->next = removeNode->next;
    queue->front = queue->rear->next;
    queue->size--;
    free(removeNode);
    return 0;
}

void reInitPQ(PQueue* queue){
    while(queue->size > 0){
        int poppedValue = 0;
        deleteMinPQ(queue, &poppedValue);
    }
}

void printPQ(PQueue* queue){
    if (queue == NULL){
        return;
    }
    if(queue->rear == NULL){
        return;
    }
    Node* currentPtr = queue->rear->next;
    printf("Current PQ is: ");
    while(currentPtr->next != queue->rear->next){
        printf("key %d with priority %.2f --> ", currentPtr->key, currentPtr->priority);
        currentPtr = currentPtr->next;
    }
    printf("key %d with priority %.2f --> NULL", currentPtr->key, currentPtr->priority);
}

void freePQ(PQueue* queue){
    reInitPQ(queue);
    free(queue);
    queue = NULL;
}
