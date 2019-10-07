#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node* next;
} List;

List* initIntegerList();
int insertAtHead(int k, List *);
int insertAtTail(int k, List *);
void printList(List *);
void freeList(List *);

List* initIntegerListNoDummy();
List* insertAtHeadNoDummy(int k, List *);
List* insertAtTailNoDummy(int k, List *);
void printNoDummyList(List *);
void freeNoDummyList(List *);

int main(void){
    srand(time(NULL));
    List *listPtr = initIntegerListNoDummy();
    int k = rand() % 10;
    listPtr = insertAtHeadNoDummy(k, listPtr);
    k = rand() % 10;
    listPtr = insertAtTailNoDummy(k, listPtr);
    printNoDummyList(listPtr);
    freeNoDummyList(listPtr);

    List *dummyListPtr = initIntegerList();
    k = rand() % 10;
    insertAtHead(k, dummyListPtr);
    k = rand() % 10;
    insertAtTail(k, dummyListPtr);
    printList(dummyListPtr);
    freeList(dummyListPtr);
    return 0;
}

List* initIntegerListNoDummy(){
    return NULL;
}

List* insertAtHeadNoDummy(int k, List *listPtr){
    List* new = malloc(sizeof(List));
    new->key = k;
    new->next = listPtr;
    return new;
}

List* insertAtTailNoDummy(int k, List *listPtr){
    List* newNode = malloc(sizeof(List));
    newNode->key = k;
    newNode->next = NULL;
    if(listPtr == NULL){
        return newNode;
    }
    List* i = listPtr;
    while(i->next != NULL){
        i = i->next;
    }
    i->next = newNode;
    return listPtr;
}

void printNoDummyList(List *listPtr){
    while(listPtr != NULL){
        printf("%d\n", listPtr->key);
        listPtr = listPtr->next;
    }
}

void freeNoDummyList(List *nextNode){
    if(nextNode == NULL){
        return;
    }
    while(nextNode->next != NULL){
        List* previousNode = nextNode;
        nextNode = previousNode->next;
        free(previousNode);
    }
    free(nextNode);
}

List* initIntegerList(){
    List* head = malloc(sizeof(List));
    List* tail = malloc(sizeof(List));
    head->next = tail;
    tail->next = NULL;
    return head;
}

int insertAtHead(int k, List *listPtr){
    List* newNode = malloc(sizeof(List));
    if(newNode == NULL){
        return -1;
    }
    newNode->key = k;
    newNode->next = listPtr->next;
    listPtr->next = newNode;
    return 0;
}

int insertAtTail(int k, List *listPtr){
    List* newNode = malloc(sizeof(List));
    if(newNode == NULL){
        return -1;
    }
    newNode->key = k;
    while(listPtr->next->next != NULL){
        listPtr = listPtr->next;
    }
    newNode->next = listPtr->next;
    listPtr->next = newNode;
    return 0;
}

void printList(List *listPtr){
    listPtr = listPtr->next;
    while(listPtr->next != NULL){
        printf("%d\n", listPtr->key);
        listPtr = listPtr->next;
    }
}

void freeList(List *nextNode){
    while(nextNode->next != NULL){
        List* previousNode = nextNode;
        nextNode = previousNode->next;
        free(previousNode);
    }
    free(nextNode);
}
