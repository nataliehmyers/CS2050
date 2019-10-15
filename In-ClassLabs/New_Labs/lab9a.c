#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodestruct {
    int item;
    struct nodestruct *next;
} Node;

typedef struct {
    int size;
    Node *head, *tail;
} List;

// no dummy nodes should be used in this lab assignment
List *initIntegerList();
int insertAtHead(int, List*);
int removeTail(List*);
void emptyList(List*);
void freeList(List**);
void printList(List*);

int main(void){
    /* Function creates a list, fills it with 5 integers with insertAtHead function, then removes 2 integers with
     * removeTail function, then empties list by calling emptyList function, then inserts a random integer with
     * insertAtHead function, then frees the linked list by calling freeList function. Function prints list with
     * every modification made to it. */

    srand(time(NULL)); // for random integer generator
    List* listPtr = initIntegerList();
    int k = (rand() % 10) + 1;
    printList(listPtr);
    printf("\n");
    for(int i = 0; i < 5; i++){
        int check = insertAtHead(k, listPtr);
        k = (rand() % 10) + 1;
        if(check == -1){
            printf("Insertion failed.\n");
        }
        printf("Head insertion: List is: ");
        printList(listPtr);
        printf("\n");
    }
    for(int i = 0; i < 2; i++){
        int key = removeTail(listPtr);
        printf("Tail deletion: List is: ");
        printList(listPtr);
        printf("\n");
    }
    emptyList(listPtr);
    k = (rand() % 10) + 1;
    insertAtHead(k, listPtr);
    printf("\nHead insertion: List is: ");
    printList(listPtr);
    printf("\n");
    freeList(&listPtr);
    return 0;
}

List* initIntegerList(){
    /* Function creates an empty linked list. Function receives void and returns the linked list. */

    List* listPtr = malloc(sizeof(List));
    listPtr->head = NULL;
    listPtr->tail = NULL;
    listPtr->size = 0;
    return listPtr;
}

int insertAtHead(int k, List* listPtr){
    /* Function inserts a new key at head. Function receives an integer and list pointer and returns an integer. */

    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        return -1;
    }
    newNode->item = k;
    listPtr->size++;
    if(listPtr->head == NULL){
        listPtr->head = newNode;
        newNode->next = NULL;
        listPtr->tail = newNode;
    } else {
        newNode->next = listPtr->head;
        listPtr->head = newNode;
    }
    return 0;
}

int removeTail(List* listPtr){
    /* Function removes the tail node from the list and returns its key. Function receives a list pointer and returns
     * an integer. */

    if(listPtr->head == NULL){
        printf("Cannot remove element from empty list.\n");
        return 0;
    }
    if(listPtr->head->next == NULL){
        int key = listPtr->head->item;
        free(listPtr->head);
        listPtr->size--;
        listPtr->head = NULL;
        return key;
    }
    Node* currentPtr = listPtr->head;
    while(currentPtr->next->next != NULL){
        currentPtr = currentPtr->next;
    }
    Node *removeNode = currentPtr->next;
    int key = removeNode->item;
    currentPtr->next = NULL;
    listPtr->size--;
    free(removeNode);
    return key;
}

void emptyList(List* listPtr){
    /* Function receives a linked list and removes all nodes in this list such that the list is empty. Function returns
     * void. */

    while(listPtr->size != 0){
        removeTail(listPtr);
    }
    printf("List has been emptied\n");
}

void printList(List* listPtr){
    /* Function prints out the current linked list. Function receives a list pointer and returns void. */

    Node* currentPtr = listPtr->head;
    if(currentPtr == NULL){
        printf("List is empty.\n");
        return;
    }
    while(currentPtr != NULL){
        printf("%d ", currentPtr->item);
        currentPtr = currentPtr->next;
    }
    printf("\n");
}

void freeList(List **listPtr){
    /* Function receives the reference of the current linked list, frees all previously allocated memories in the
     * linked list and set the list pointer to NULL. Function returns void. */

    while((*listPtr)->size != 0){
        removeTail(*listPtr);
    }
    free(*listPtr);
    listPtr = NULL;
    printf("List has been freed.\n");
}
