#include <stdio.h>
#include <stdlib.h>

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




int main(void){
    List *head;
    head = initIntegerList();
//    head = insertInteger(head, 1);
//    head = insertInteger(head, 2);
//    head = insertInteger(head, 3);
//    head = insertInteger(head, 4);
//    head = insertInteger(head, 5);

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);

    //head = insertInOrder(head, 4);
    //head = insertInOrder(head, 1);
    //head = insertInOrder(head, 3);
    //head = insertInOrder(head, 5);
    //head = insertInOrder(head, 2);

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
    List* cur = head;

    while (cur->next != NULL && cur->next->key > value) {
        printf("cur->key = %d\n", cur->key);
//        insert->next = cur->next;
//        cur->next = insert;

        insert->next = head;
//        head = insert;
    }
    return head;
}

void printList(List* head) {
    List* cur = head;
    while(cur != NULL) {
        printf("key: %d\n", cur->key);
        cur = cur->next;
    }
}

void freeList(List* head) {
    List* cur = head;
    while(cur->next != NULL) {
        head = head->next;
        free(cur);
        cur = head;
    }
    free(head);
}
