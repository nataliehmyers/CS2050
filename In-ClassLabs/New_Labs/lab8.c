#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodestruct {
    int item;
    struct nodestruct *next;
} Node;


Node *initIntegerList();
int insertAscend(Node*,int);
int insertAtTail(Node*,int);
void printList(Node*);
void freeList(Node*);
int computeEven(Node*);


int main(void) {
    /* Function creates a list, fills it with 5 integers using insert Ascend, then inserts 5 integers with insertAtTail,
     * then frees the function. Between each insertion, the full list is printed and computeEven is called, with results printed. */

    srand(time(NULL)); // for random integer generator
    Node *listPtr = initIntegerList();
    printList(listPtr);
    int k = (rand() % 10) + 1;
    for(int i = 0; i < 5; i++){
        int check = insertAscend(listPtr, k);
        k = (rand() % 10) + 1;
        if(check == -1){
            printf("Insertion failed.\n");
        }
        printf("Ascending insertion: Linked list is: ");
        int evens = computeEven(listPtr);
        printList(listPtr);
        printf("\n%d even numbers in this linked list\n", evens);
        printf("\n");
    }
    for(int i = 0; i < 5; i++){
        k = (rand() % 10) + 1;
        int check = insertAtTail(listPtr, k);
        if(check == -1){
            printf("Insertion failed.\n");
        }
        printf("Tail insertion: Linked list is: ");
        int evens = computeEven(listPtr);
        printList(listPtr);
        printf("\n%d even numbers in this linked list\n", evens);
        printf("\n");
    }
    freeList(listPtr);
    return 0;
}

Node* initIntegerList(){
    /* Function created a linked lists with dummy nodes by allocating memory for the head and tail, error checking,
     * then assigning them into a list. Function recieves NULL and returns the empty dummy list.  */
    Node* head = malloc(sizeof(Node));
    if(head == NULL){
        free(head);
        printf("Malloc failed.");
    }
    Node* tail = malloc(sizeof(Node));
    if(tail == NULL){
        free(head);
        printf("Malloc failed.");
    }
    head->next = tail;
    tail->next = NULL;
    return head;
}

int insertAscend(Node* listPtr,int k) {
    /* Function iterates through a linked list and inserts new value before the next highest element in the list. Function
     * receives a node pointer to the list and the value to insert and returns an error numbers. */
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        free(newNode);
        printf("Malloc failed.");
        return -1;
    }
    Node *currentNode = listPtr;
    newNode->item = k;
    while(currentNode->next->next != NULL){
        if(k <= currentNode->next->item){
            break;
        }
        currentNode = currentNode->next;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return 0;
}

int insertAtTail(Node *listPtr, int k){
    /* Function inserts a new value at the end of the linked list. Function receives a node pointer to the list and the
     * value to insert and returns an error numbers. */
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        free(newNode);
        printf("Malloc failed.");
        return -1;
    }
    newNode->item = k;
    while(listPtr->next->next != NULL){
        listPtr = listPtr->next;
    }
    newNode->next = listPtr->next;
    listPtr->next = newNode;
    return 0;
}

int computeEven(Node* listPtr){
    /* Function iterates through linked list and counts the number of even elements. Function receives a node pointer
     * and returns an integer for the number of evens in the list. */
    int count = 0;
    while(listPtr->next->next != NULL){
        if(((listPtr->next->item) % 2) == 0){
            count++;
        }
        listPtr = listPtr->next;
    }
    return count;
}

void printList(Node *listPtr){
    /* Function prints all the elements in a linked list. Function receives a node pointer and returns void. */
    if(listPtr->next->next == NULL){
        printf("Linked list is empty.\n");
    }
    listPtr = listPtr->next;
    while(listPtr->next != NULL){
        printf("%d ", listPtr->item);
        listPtr = listPtr->next;
    }
    printf("\n");
}

void freeList(Node *nextNode){
    /* Function frees a linked list. Function receives a node pointer and returns void. */
    while(nextNode->next != NULL){
        Node* previousNode = nextNode;
        nextNode = previousNode->next;
        free(previousNode);
    }
    free(nextNode);
    nextNode = NULL;
    printf("Linked list has been freed.\n");
}
