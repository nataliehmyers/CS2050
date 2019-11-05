#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct {
    float key;
} Node;
typedef struct {
    int size;
    int capacity;
    Node *array; // ascending priority
} PQueue;

PQueue* initPQ(int);
int insertPQ(float, PQueue*);
int DeQueue(PQueue *, float *); // O(1)
int deleteMinPQ(PQueue*, float*);
int getSizePQ(PQueue*); // O(1)
int findIdx(float, PQueue *); // O(log(N)) so must use array for binary search; N is number os objects currently in the queue
void freePQ(PQueue*);

int insertAtIndex(PQueue*, float, int);
void printPQ(PQueue*);

int main(void){
    PQueue* queue = initPQ(7);
    printPQ(queue);
    insertPQ(5.6, queue);
    printPQ(queue);
    insertPQ(3.1, queue);
    printPQ(queue);
    insertPQ(12.8, queue);
    printPQ(queue);
    insertPQ(4.1, queue);
    printPQ(queue);
    findIdx(0, queue);

    float key = 0;
    DeQueue(queue, &key);
    printPQ(queue);
    findIdx(3.1, queue);
    DeQueue(queue, &key);
    printPQ(queue);
    DeQueue(queue, &key);
    printPQ(queue);
    DeQueue(queue, &key);
    printPQ(queue);

    return 0;
}

PQueue* initPQ(int capacity){
    PQueue* queue = malloc(sizeof(PQueue));
    queue->array = malloc(capacity * sizeof(Node));
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

int insertPQ(float key, PQueue* queue){
    if(queue == NULL || queue->size >= queue->capacity){
        return -1;
    }

    // Array is empty
    if(queue->size == 0){
        insertAtIndex(queue, key, 0);
        return 0;
    }

    // Insert in the middle
    for(int i = 0; i < queue->size; i++){
        if(queue->array[i].key >= key){
            insertAtIndex(queue, key, i);
            return 0;
        }
    }

    // Insert at the end
    insertAtIndex(queue, key, queue->size);
}

int insertAtIndex(PQueue* queue, float key, int index){
    for(int i = queue->size+1; i > index; i--){
        queue->array[i].key = queue->array[i-1].key;
    }
    queue->array[index].key = key;
    queue->size++;
}

int DeQueue(PQueue *queue, float *key){
    *key = queue->array[queue->size].key;
    queue->size--;
}

int findIdx(float search, PQueue *queue){
    int first = 0;
    int last = getSizePQ(queue) - 1;
    int middle = (first + last) / 2;

    while(first <= last){
        if(queue->array[middle].key == search){
            printf("Key found\n");
            return 1;
        }
        if(queue->array[middle].key < search){
            first = middle + 1;
            middle = (first + last) / 2;
        } else {
            last = middle - 1;
            middle = (first + last) / 2;
        }
    }
    printf("Key not found\n");
    return 0;
}

int getSizePQ(PQueue* queue){
    return queue->size;
}

void printPQ(PQueue* queue){
    if (queue == NULL){
        return;
    }
    printf("Size: %d: ", queue->size);
    for(int i = 0; i < queue->size; i++){
        printf("%.2f ", queue->array[i].key);
    }
    printf("\n");
}

void freePQ(PQueue* queue){
    free(queue->array);
    free(queue);
}
