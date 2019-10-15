#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct List {
    struct Node* headPtr;
    struct Node* tailPtr;
    int listSize;
} List;

List* initIntegerList(); // Return empty list
int insertAtHead(int k, List*); // Insert k at headPtr
int insertAtTail(int k, List*); // Insert k at tailPtr
int removeHead(List *); // Remove headPtr and return its key
int getListSize(List *); // Return number of elements in list
void printHead(List *); // Print key in headPtr
void moveHeadToTail(List *); // Move key at headPtr to tailPtr

void printList(List *listPtr);
void freeList(List *);

List* initIntegerListNoDummy(); // Return empty list
int insertAtHeadNoDummy(int k, List*); // Insert k at headPtr
int insertAtTailNoDummy(int k, List*); // Insert k at tailPtr
int removeHeadNoDummy(List *); // Remove headPtr and return its key
int getListSizeNoDummy(List *); // Return number of elements in list
void printHeadNoDummy(List *); // Print key in headPtr
void moveHeadToTailNoDummy(List *); // Move key at headPtr to tailPtr
void printListNoDummy(List *listPtr);
void freeListNoDummy(List *);

int main(void){
    srand(time(NULL));
    /*
    List *listPtr = initIntegerList();
    if (listPtr == NULL){
        printf("Initializing failed.");
        return -1;
    }
    int k = rand() % 10;
    printf("insertAtHead:\n");
    for(int i = 0; i < 5; i++){
        int check = insertAtHead(k, listPtr);
        if (check == -1){
            printf("insertion failed\n");
            return -1;
        }
        k = rand() % 10;
        printList(listPtr);
    }
    printHead(listPtr);
    int size = getListSize(listPtr);
    printf("getListSize: %d\n", size);
    printf("insertAtTail:\n");
    for(int i = 0; i < 5; i++){
        int check = insertAtTail(k, listPtr);
        if (check == -1){
            printf("insertion failed\n");
            return -1;
        }
        k = rand() % 10;
        printList(listPtr);
    }
    printHead(listPtr);
    size = getListSize(listPtr);
    printf("getListSize: %d\n", size);
    printf("removeHead:\n");
    for(int i = 0; i < 5; i++){
        int check = removeHead(listPtr);
        if (check == -1){
            printf("insertion failed\n");
            return -1;
        }
        printList(listPtr);
    }
    printHead(listPtr);
    size = getListSize(listPtr);
    printf("getListSize: %d\n", size);
    moveHeadToTail(listPtr);
    printList(listPtr);
    freeList(listPtr);
    */


    List* listPtr = initIntegerListNoDummy();
    insertAtHeadNoDummy(5, listPtr);
    insertAtHeadNoDummy(4, listPtr);
    insertAtHeadNoDummy(3, listPtr);
    insertAtHeadNoDummy(2, listPtr);
    insertAtHeadNoDummy(1, listPtr);
    printListNoDummy(listPtr);
    int size = getListSizeNoDummy(listPtr);
    printf("\nsize: %d\n", size);
    printHeadNoDummy(listPtr);

    insertAtTailNoDummy(6, listPtr);
    insertAtTailNoDummy(7, listPtr);
    insertAtTailNoDummy(8, listPtr);
    insertAtTailNoDummy(9, listPtr);
    insertAtTailNoDummy(10, listPtr);
    printListNoDummy(listPtr);
    size = getListSizeNoDummy(listPtr);
    printf("\nsize: %d\n", size);
    printHeadNoDummy(listPtr);

    removeHeadNoDummy(listPtr);
    removeHeadNoDummy(listPtr);
    removeHeadNoDummy(listPtr);
    removeHeadNoDummy(listPtr);
    removeHeadNoDummy(listPtr);
    printf("removed list: ");
    printListNoDummy(listPtr);
    size = getListSizeNoDummy(listPtr);
    printf("\nsize: %d\n", size);
    printHeadNoDummy(listPtr);
    moveHeadToTailNoDummy(listPtr);
    printListNoDummy(listPtr);
    freeListNoDummy(listPtr);


    return 0;
}

List* initIntegerList(){
    List *listPtr = malloc(sizeof(List));
    Node* head = malloc(sizeof(Node));
    Node* tail = malloc(sizeof(Node));
    listPtr->headPtr = head;
    listPtr->tailPtr = head;
    head->next = tail;
    tail->next = NULL;
    listPtr->listSize = 0;
    return listPtr;
}

int insertAtHead(int k, List* listPtr){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return -1;
    }
    if(listPtr->listSize == 0){
        listPtr->tailPtr = newNode;
    }
    newNode->key = k;
    newNode->next = listPtr->headPtr->next;
    listPtr->headPtr->next = newNode;
    listPtr->listSize++;
    return 0;
}

int insertAtTail(int k, List* listPtr){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return -1;
    }
    newNode->key = k;
    newNode->next = listPtr->tailPtr->next;
    listPtr->tailPtr->next = newNode;
    listPtr->tailPtr = newNode;
    listPtr->listSize++;
    return 0;
}

int removeHead(List *listPtr){
    if(listPtr->listSize == 0){
        return -1;
    }
    Node* removePtr = listPtr->headPtr->next;
    int key = removePtr->key;
    listPtr->headPtr->next = listPtr->headPtr->next->next;
    listPtr->listSize--;
    free(removePtr);
    return key;
}

int getListSize(List *listPtr){
    return listPtr->listSize;
}

void printHead(List *listPtr){
    printf("Head: %d\n", listPtr->headPtr->next->key);
}

void moveHeadToTail(List *listPtr){
    int initHeadKey = listPtr->headPtr->next->key;
    int initTailKey = listPtr->tailPtr->key;
    listPtr->headPtr->next->key = initTailKey;
    int newHeadKey = listPtr->headPtr->next->key;
    listPtr->tailPtr->key = initHeadKey;
    int newTailKey = listPtr->tailPtr->key;
}

void printList(List *listPtr){
    Node* currentNode = listPtr->headPtr;
    currentNode = currentNode->next;
    while(currentNode->next != NULL){
        printf("%d ", currentNode->key);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void freeList(List *listPtr){
    while(listPtr->listSize != 0){
        removeHead(listPtr);
    }
    free(listPtr->tailPtr->next);
    free(listPtr->headPtr);
    free(listPtr);
    listPtr = NULL;
    printf("listPtr freed.\n");
}



List* initIntegerListNoDummy(){
    List* listPtr = malloc(sizeof(List));
    listPtr->headPtr = NULL;
    listPtr->tailPtr = NULL;
    listPtr->listSize = 0;
    return listPtr;
}

int insertAtHeadNoDummy(int k, List* listPtr){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return -1;
    }
    newNode->key = k;
    listPtr->listSize++;
    if(listPtr->headPtr == NULL){
        listPtr->headPtr = newNode;
        newNode->next = NULL;
        listPtr->tailPtr = newNode;
    } else {
        newNode->next = listPtr->headPtr;
        listPtr->headPtr = newNode;
    }
    return 0;
}

int insertAtTailNoDummy(int k, List* listPtr){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return -1;
    }
    newNode->key = k;
    listPtr->listSize++;
    if(listPtr->headPtr == NULL){
        listPtr->headPtr = newNode;
        listPtr->tailPtr = newNode;
        newNode->next = NULL;
    } else {
        newNode->next = NULL;
        listPtr->tailPtr->next = newNode;
        listPtr->tailPtr = newNode;
    }
    return 0;
}

int removeHeadNoDummy(List *listPtr){
    if(listPtr->headPtr == NULL){
        return -1;
    }
    Node* removeNode = listPtr->headPtr;
    int key = listPtr->headPtr->key;
    listPtr->headPtr = listPtr->headPtr->next;
    listPtr->listSize--;
    free(removeNode);
    return key;
}

int getListSizeNoDummy(List *listPtr){
    return(listPtr->listSize);
}

void printHeadNoDummy(List *listPtr){
    printf("Head: %d\n", listPtr->headPtr->key);
}

void moveHeadToTailNoDummy(List *listPtr){
    int initHeadKey = listPtr->headPtr->key;
    int initTailKey = listPtr->tailPtr->key;
    listPtr->headPtr->key = initTailKey;
    listPtr->tailPtr->key = initHeadKey;
    int newHeadKey = listPtr->headPtr->key;
    int newTailKey = listPtr->tailPtr->key;
}

void printListNoDummy(List* listPtr){
    Node* currentPtr = listPtr->headPtr;
    if(currentPtr == NULL){
        return;
    }
    while(currentPtr != NULL){
        printf("%d ", currentPtr->key);
        currentPtr = currentPtr->next;
    }
    printf("\n");
}

void freeListNoDummy(List *listPtr){
    while(listPtr->listSize != 0){
        removeHeadNoDummy(listPtr);
    }
    free(listPtr);
    listPtr = NULL;
    printf("listPtr freed.\n");
}
