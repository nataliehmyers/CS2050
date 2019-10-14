#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node_ {
    int key;
    struct Node_* next;
} List;

void initIntegerList(List**);
void printList(List*);
int insertInOrder(List*, int);
int removeKey(List*, int);
void freeList(List*);

int main(void){
    srand(time(NULL));
    List** ptr = 0;
    initIntegerList(ptr);



    return 0;
}

int insertInOrder(List** ptr) {
    List* insert = malloc(sizeof(List));
    insert->key = rand() % 10;
    insert->next = NULL;


    if(*ptr == NULL)
        return 1;
    if(head->key > value){//if the headPtr is greater than what we're inserting
        insert->next = head; //make the new node connect to the headPtr then return the new node
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

void printList(List* head) {
    if(head == NULL){
        printf("The List is empty!\n");
        return;
    }
    List* cur = head;
//    printf("The List is:\n");
    while(cur->next != NULL) {
        printf("%d ", cur->key);
        cur = cur->next;
    }
    printf("%d\n", cur->key);
}

void initIntegerList(List** ptr){
    List* head = NULL;
    *ptr = head;
}

int removeKey(List** ptr) {
    List* cur = head;
    List* prev = NULL;
    int found = 0;
    if(head != NULL && head->key == value) { // if the first node is what we're looking for
        // first, check if there's a next node
        if(head->next != NULL) {// if there is, assign the value to next then free headPtr
            List* next = head->next;
            free(head);
            return next;
        }
        else {// else, there's only one node, free it and return NULL
            free(head);
            return NULL;
        }
    }
    prev = cur;
    cur = cur->next;
    while(cur->next != NULL){
        if(cur->key == value){
            prev->next = cur->next;
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    free(cur);
    if (found == 0) {
        printf("Key not found in List. Nothing removed.\n");
        //        printList(headPtr);
    }
    return head;
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
