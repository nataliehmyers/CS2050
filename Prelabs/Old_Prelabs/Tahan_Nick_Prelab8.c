#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct queue{
    Node *first, *last;
} Queue;

void createQueue(Queue**);
void createQueueWithDummy(Queue**);
void dequeue(Queue**);
void enqueue(Queue**, Node*);
void enqueueDummy(Queue**, Node*);
void dequeueDummy(Queue**);
int findSizeOfQueue(Queue**);
int findSizeOfQueueDummy(Queue**);
void printQueueDummy(Queue**);
void printQueue(Queue**);
void freeQueue(Queue**);

int main(void){
    Queue * ptr;
    createQueue(&ptr);

    Node* int1 = (Node*)malloc(sizeof(Node));
    Node* int2 = (Node*)malloc(sizeof(Node));
    Node* int3 = (Node*)malloc(sizeof(Node));
    Node* int4 = (Node*)malloc(sizeof(Node));

    int1->data = 34;
    int2->data = 7;
    int3->data = 87;
    int4->data = 14;

    enqueue(&ptr, int1);
    enqueue(&ptr, int2);
    printQueue(&ptr);
    enqueue(&ptr, int3);
    dequeue(&ptr);
    enqueue(&ptr, int4);
    printQueue(&ptr);

    printf("Dummy Node!\n");

    Queue* ptr2;
    createQueueWithDummy(&ptr2);
    enqueueDummy(&ptr2, int1);
    enqueueDummy(&ptr2, int2);
    printQueueDummy(&ptr2);
    enqueueDummy(&ptr2, int3);
    dequeueDummy(&ptr2);
    enqueueDummy(&ptr2, int4);
    printQueueDummy(&ptr2);
}

void freeQueue(Queue** ptr){
    Node* q = (*ptr)->first;
    Node* holder;
    while(q != NULL){
        holder = q->next;
        free(q);
        q = holder;
    }
    free(*ptr);
    *ptr = NULL;
}

void printQueueDummy(Queue** ptr){
    Node* q = (*ptr)->first->next;
    while(q != (*ptr)->last){
        printf("%d\n",q->data);
        q = q->next;
    }
    printf("Size of Queue:%d\n",findSizeOfQueueDummy(ptr));
    printf("\n");
}

void printQueue(Queue** ptr){
    Node* q = (*ptr)->first;
    while(q != NULL){
        printf("%d\n",q->data);
        q = q->next;
    }
    printf("Size of Queue:%d\n",findSizeOfQueue(ptr));
    printf("\n");
}

int findSizeOfQueueDummy(Queue** ptr){
    int counter = 0;
    Queue* list = *ptr;
    Node* q;
    if(list->first->next == list->last){
        return counter;
    } else {
        q = list->first->next;
        while(q!=list->last){
            q=q->next;
            counter++;
        }
        return counter;
    }
    return counter;
}

int findSizeOfQueue(Queue** ptr){
    int counter = 0;
    Queue* list = *ptr;
    Node* q;
    if(list->first == NULL){
        return counter;
    } else {
        q = list->first;
        while(q!=NULL){
            q = q->next;
            counter++;
        }
        return counter;
    }
    return counter;
}

void enqueueDummy(Queue** ptr, Node* obj){
    if((*ptr)->first->next == (*ptr)->last){
        (*ptr)->first->next = obj;
        obj->next = (*ptr)->last;
    } else {
        Node* prev = (*ptr)->first;
        Node* q = (*ptr)->first->next;
        while(q!=(*ptr)->last){
            prev = q;
            q=q->next;
        }
        prev->next = obj;
        obj->next = q;
    }
}

void dequeueDummy(Queue** ptr){
    if((*ptr)->first->next == (*ptr)->last){
        printf("Dequeue failed. No node in queue\n");
    } else {
        (*ptr)->first->next= (*ptr)->first->next->next;
    }
}

void dequeue(Queue** ptr){
    if((*ptr)->first == NULL){
        printf("Dequeue failed. No node in queue\n");
    } else {
        (*ptr)->first = (*ptr)->first->next;
    }
}

void enqueue(Queue** ptr, Node* obj){
    if((*ptr)->last == NULL){
        (*ptr)->last = obj;
        (*ptr)->first = obj;
        obj->next = NULL;
    } else {
        (*ptr)->last->next = obj;
        (*ptr)->last = obj;
    }
}


void createQueueWithDummy(Queue** ptr){
    *ptr = (Queue*)malloc(sizeof(Queue));
    Node* top = (Node*)malloc(sizeof(Node));
    Node* bot = (Node*)malloc(sizeof(Node));

    if(*ptr == NULL || top == NULL || bot == NULL){
        printf("Failed to allocate memory for Queue\n");
    } else {
        (*ptr)->first = top;
        (*ptr)->last = bot;
        (*ptr)->first->next = bot;
        bot->next = NULL;
    }
}

void createQueue(Queue** head) {
    *head = (Queue*)malloc(sizeof(Queue));

    if(*head == NULL){
        printf("Failed to allocate memory for Queue\n");
    } else {
        (*head)->first = NULL;
        (*head)->last = NULL;
    }
}
