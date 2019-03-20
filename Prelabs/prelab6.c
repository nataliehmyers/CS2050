#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node_ {
    int key;
    struct Node_* next;
} List;

List* initIntegerList();
List* insertInteger(List*, int);
List* insertAtEnd(List*, int );
void printList(List*);
List* insertInOrder(List*, int);
void freeList(List*);
List* removeKey(List*, int);
List* reverseList(List*);

int main(void){
    srand(time(NULL));
    List *head;
    head = initIntegerList();
    int arr[10];
    int value = rand() % 10;
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 10;   //I'm gonna assign random numbers to an array
    }
    printf("Original array: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\nRemoving %d\n", value);
    for(int i = 0; i < 10; i++){
        head = insertInOrder(head, arr[i]);
    }

    //    printf("Remove int %d\n", value);
    printf("Before remove: ");
    printList(head);


//    printf("freeing %d\n", value);
    head = removeKey(head, value);


    printf("Removed list: ");
    printList(head);
    head = reverseList(head);
    printf("Reversed list: ");
    printList(head);
    freeList(head);
}

List* initIntegerList(){
    return NULL;
}

List* insertInteger(List* head, int value){
    List* new = malloc(sizeof(List));
    new->key = value;
    new->next = head;

    return new;
}

List* insertAtEnd(List* head, int value){

    List* new = malloc(sizeof(List));
    new->key = value;
    new->next = NULL;

    if(head == NULL)
        return new;

    List* cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }

    cur->next = new;
    return head;
}


List* insertInOrder(List* head, int value) {
    List* insert = malloc(sizeof(List));
    insert->key = value;
    insert->next = NULL;


    if(head == NULL)
        return insert;
    if(head->key > value){//if the head is greater than what we're inserting
        insert->next = head; //make the new node connect to the head then return the new node
        return insert;
    }
    List* cur = head;
    while(cur->next != NULL){
        if(cur->next->key < value){//if next node is smaller, we move to the next
            cur = cur->next;
        }
        else{
            //for example: 1->3->4->6,  we're 5, current is 4 so we should insert
            break;
        }

    }
    insert->next = cur->next;
    cur->next = insert;
    return head;
}

List* removeKey(List* head, int value) {
    List* cur = head;
    List* prev = NULL;
    int found = 0;
    if(head != NULL && head->key == value) { // if the first node is what we're looking for
        // first, check if there's a next node
        if(head->next != NULL) {// if there is, assign the value to next then free head
            List* next = head->next;
            free(head);
            return next;
        }
        else {// else, there's only one node, free it and return NULL
            free(head);
            return NULL;
        }
    }
    // at this point it's save to move our current pointer
    prev = cur;
    cur = cur->next;

    while(cur->next != NULL){
        if(cur->key == value){
            prev->next = cur->next;
            free(cur);
//          found = 1;
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
//    printf("prev %d cur %d\n", prev->key, cur->key);
    //handle the special edge cases, the last node
    prev->next = NULL;
    free(cur);
//    found = 1;
    // handle
    //    ToDo: Add in conditionals for head and tail removal
    if (found == 0) {
        printf("Key not found in list. Nothing removed.\n");
        //        printList(head);
    }
// ToDo: Add message for remove int not in list.
// ToDo: Remove all instances of int if it appears more than once.
    return head;
}

void printList(List* head) {
    if(head == NULL){
        printf("The list is empty!\n");
        return;
    }
    List* cur = head;
//    printf("The list is:\n");
    while(cur->next != NULL) {
        printf("%d ", cur->key);
        cur = cur->next;
    }
    printf("%d\n", cur->key);
}

void freeList(List* head) {
    List* cur = head;
    if(head == NULL)
        return;
    while(cur->next != NULL) {
        head = head->next;
        free(cur);
        cur = head;
    }
    free(head);
}

// ToDo: Make circular?
// ToDo: Dummy nodes?

List* reverseList(List* head) {
    List* cur = head;
    List* prev = NULL;
    if(head->next == NULL)
        return head;

    prev = cur;
    cur = cur->next;
    prev->next = NULL;//the head now is the new tail
    List* next = cur->next;
    cur->next = prev;//now the first two nodes are reversed
    while (next != NULL) {
        prev = cur;
        cur = next;
        next = next->next;
        cur->next = prev;
    }
    return cur;
}
