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

}

PQueue* initPQ(){
    /* Function creates an empty queue and return it. Function receives no input and returns a pointer */

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
    /* Function inserts an integer key value, a float priority value, and the current priority queue pointer.
     * Function creates a new node with the key and priority values, inserts it into the priority queue
     * in ascending priority value, then returns an error code. */

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
    /* Function receives the current priority queue and an integer pointer as inputs. Function removes the node
     * with the minimum priority value and stores the removed key value into the integer pointer. Function
     * returns an integer error code. */

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
    /* Function receives the current priority queue, reinitializes the priority queue to an empty priority queue
     * without changing the address of the priority queue. */

    while(queue->size > 0){
        int poppedValue = 0;
        deleteMinPQ(queue, &poppedValue);
    }
}

void printPQ(PQueue* queue){
    /* Function receives the current priority queue and prints out the key values of each node with their priority
     * values. */

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
    /* Function receives the current priority queue and frees all the memory that has been previously allocated. */

    reInitPQ(queue);
    free(queue);
    queue = NULL;
}
