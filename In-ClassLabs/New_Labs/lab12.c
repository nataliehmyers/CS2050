#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arraySize; // next available availableIdx in the sorted array
    int availableIdx; // the arraySize of the sorted array
    int *sortedArray;  // the sorted array
} PQueue;

PQueue* initPQ(int);
int insertPQ(PQueue*, int);
int DeQueue(PQueue *, int*);
int findIdx(PQueue*, int);
void printPQ(PQueue*);
void freePQ(PQueue*);

int getSizePQ(PQueue*);
void insertAtIndex(PQueue*, int, int);



int getSizePQ(PQueue* queue){
    /* Function receives the current priority queue and returns its size. 0(1) complexity. */

    return queue->availableIdx;
}

void insertAtIndex(PQueue* queue, int key, int index){
    /* Function receives the current priority queue, the insert element's key, and the index integer to perform the
     * insertion of the new key at the index's location in the priority queue. Function returns void. 0(1) complexity. */

    for(int i = queue->availableIdx+1; i > index; i--){
        queue->sortedArray[i] = queue->sortedArray[i-1];
    }
    queue->sortedArray[index] = key;
    queue->availableIdx++;
}

PQueue* initPQ(int capacity){
    /* Function initializes a PQueue struct with availableIdx = 0, arraySize = the input integer, and creates an integer array
     * with length = the input integer. It returns the initialed PQueue pointer. 0(1) complexity. */

    PQueue* queue = malloc(sizeof(PQueue));
    queue->sortedArray = malloc(capacity * sizeof(int));
    queue->availableIdx = 0;
    queue->arraySize = capacity;
    return queue;
}

int insertPQ(PQueue* queue, int key){
    /* This function receives the current priority queue and a new integer value, then insets the new integer into the
     * sorted array in ascending order. It returns an error code 0 in insertions was successful, -1 if insertion failed.
     * 0(N) complexity. */

    if(queue == NULL || queue->availableIdx >= queue->arraySize){
        return -1;
    }

    // Array is empty
    if(queue->availableIdx == 0){
        insertAtIndex(queue, key, 0);
        return 0;
    }

    // Insert in the middle
    for(int i = 0; i < queue->availableIdx; i++){
        if(queue->sortedArray[i] >= key){
            insertAtIndex(queue, key, i);
            return 0;
        }
    }

    // Insert at the end
    insertAtIndex(queue, key, queue->availableIdx);
    return 0;
}


int DeQueue(PQueue *queue, int *key){
    /* This function receives the current priority queue and an integer pointer. It removes the maximum integer from the
     * sorted array, stores the removed value into the integer pointer, then returns error code 0 if deletion was
     * successful, -1 if deletion failed. 0(1) complexity. */

    if(queue == NULL){
        return -1;
    }
    *key = queue->sortedArray[queue->availableIdx];
    queue->availableIdx--;
    return 0;
}

int findIdx(PQueue* queue, int search){
    /* This function receives the current priority queue and a query integer for searching. Then it searches this query
     * integer in the sorted array and returns the index of the query integer if it exists, or -1 if it does not exist.
     * 0(log(N)) complexity. */

    int first = 0;
    int last = getSizePQ(queue) - 1;
    int middle = (first + last) / 2;

    while(first <= last){
        if(queue->sortedArray[middle] == search){
            return middle;
        }
        if(queue->sortedArray[middle] < search){
            first = middle + 1;
            middle = (first + last) / 2;
        } else {
            last = middle - 1;
            middle = (first + last) / 2;
        }
    }
    return -1;
}

void printPQ(PQueue* queue){
    /* Function prints the current sorted array. */

    if (queue == NULL){
        return;
    }
    for(int i = 0; i < queue->availableIdx; i++){
        printf("%d ", queue->sortedArray[i]);
    }
    printf("\n");
}

void freePQ(PQueue* queue){
    /* Function frees all the allocated memory. */

    free(queue->sortedArray);
    free(queue);
}
