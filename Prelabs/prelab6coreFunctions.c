#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node_ {
    int key;
    struct Node_* next;
} List;

List* initIntegerList();
void printList(List*);
void freeList(List*);
List* insertInteger(List*, int);


int main(void) {
    int size = 10;
    List* head = initIntegerList();
    head = insertInteger(head, size);
    printList(head);
    freeList(head);
}

List* initIntegerList(){
    return NULL;
}

void printList(List* head) {
    if(head == NULL){
        printf("The list is empty!\n");
        return;
    }
    List* cur = head;
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

List* insertInteger(List* head, int value){
    List* new = malloc(sizeof(List));
    new->key = value;
    new->next = head;
    return new;
}
