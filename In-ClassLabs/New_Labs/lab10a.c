#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodestruct {
    int item;
    struct nodestruct *next;
} Node;

typedef struct {
    int size, sum;
    Node *rear;
} Queue;

Queue* initQueue();
int enqueue(int, Queue*);
int dequeue(Queue*, int*);
int getSum(Queue*);
void freeQueue(Queue*);
void printQueue(Queue*); // to test functions

int main(void){
    /* Function tests other functions. */


    srand(time(NULL));
    Queue* queue = initQueue();
    int k = (rand() % 10) + 1;
    for(int i = 0; i < 5; i++){
        enqueue(k, queue);
        printQueue(queue);
        k = (rand() % 10) + 1;
    }
    printf("Sum: %d\n", getSum(queue));
    int removedItem = 0;
    int* item = &removedItem;
    dequeue(queue, item);
    printQueue(queue);
    dequeue(queue, item);
    printQueue(queue);
    dequeue(queue, item);
    printQueue(queue);
    dequeue(queue, item);
    printQueue(queue);
    dequeue(queue, item);
    printQueue(queue);
    printf("Sum: %d\n", getSum(queue));
    freeQueue(queue);
    return 0;
}

Queue* initQueue(){
    /* Function returns an empty queue. Function receives void and returns a queue pointer. */
    Queue* queue = malloc(sizeof(Queue));
    if(queue == NULL){
        return NULL;
    }
    queue->rear = NULL;
    queue->size = 0;
    queue->sum = 0;
    return queue;
}

int enqueue(int k, Queue* queue){
    /* Function adds a new node to the queue and returns an error code. Function receives an integer and queue pointer
     * and returns an integer. */
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return -1;
    }
    newNode->item = k;
    queue->sum = queue->sum + k;
    queue->size++;
    if(queue->rear == NULL){
        queue->rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = queue->rear->next;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return 0;
}

int dequeue(Queue* queue, int* item){
    /* Funtion removes a node from the queue, returns the key value in the removed node by integer pointer, and returns
     * an error code. Function receives a queue pointer and integer pointer and returns an integer. */
    if(queue->rear == NULL){
        return -1;
    }
    if(item == NULL){
        return -2;
    }
    if(queue->size == 1){
        *item = queue->rear->next->item;
        free(queue->rear->next);
        queue->size--;
        queue->sum = queue->sum - *item;
        queue->rear = NULL;
        return 0;
    }
    Node *removeNode = queue->rear->next;
    *item = removeNode->item;
    queue->rear->next = removeNode->next;
    queue->rear->next = removeNode->next;
    queue->sum = queue->sum - *item;
    queue->size--;
    free(removeNode);
    return 0;
}

int getSum(Queue* queue){
    /* Function returns the sum value of all integers in the queue. Function receives a queue pointer and returns
     * an integer. */
    return queue->sum;
}

void freeQueue(Queue* queue){
    /* Function frees all space. Function receives a queue pointer and returns void. */
    while(queue->size > 0){
        int poppedValue = 0;
        dequeue(queue, &poppedValue);
    }
    free(queue);
    queue = NULL;
}

void printQueue(Queue* queue){
    /* Function prints all nodes in a queue. Function receives a queue pointer and returns void. Function added for
     * convenience and testing function in development. */
    if(queue->rear == NULL){
        return;
    }
    Node* currentPtr = queue->rear->next;
    while(currentPtr->next != queue->rear->next){
        printf("%d ", currentPtr->item);
        currentPtr = currentPtr->next;
    }
    printf("%d ", queue->rear->item);
    printf("\n");
}
