#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int width;
    int height;
}Rect;

typedef struct node {
    Rect* r;
    struct node* next;
}Node;

typedef struct {
    Node* head;
    Node* tail;
}Queue;

Queue* createQueue(void);
void enQueue(Queue*);
void* deQueue(Queue*);
int deQueueAll(Queue*);
void printQueue(Queue*);
void freeQueue(Queue*);

int main(void){

    srand(time(NULL));

    Queue* queue = createQueue();
    if (queue == NULL){
        return -1;
    }
    int check = 1;;

    for (int i = 0; i < 10; i++){
        check = enQueue(queue);
        if (check == -1){
            return -1;
        }
    }
    printf("(printQueue)");
    printQueue(queue);

    Rect *r = NULL;
    for (int i = 0; i < 2; i++){
        r = (Rect*)deQueue(queue);
        if (r != NULL){
            printf("(deQueue)");
            printf("Rectangle with area %d has been dequeued\n",r->height*r->width);
        }
    }
    printf("(printQueue)");
    printQueue(queue);

    printf("(deQueueAll)");
    check = deQueueAll(queue);
    printf("(printQueue)");
    printQueue(queue);

    // final test for deQueue
    printf("(deQueue)");
    r = deQueue(queue);

    printf("(freeQueue)");
    freeQueue(queue);
    queue = NULL;

    return 0;
}

Queue* createQueue(void) {
    Queue* queue = malloc(sizeof(Queue));
    return queue;
}

void enqueue(Queue* Rect){
    if(Rect->tail == NULL){
        Rect->width = rand() % 10;
        Rect->height = rand() % 10;
        Rect->next = NULL;
    } else {
        Rect->tail->next = rand() % 10;
        Rect->tail = rand() % 10;
    }
}

void* dequeue(Queue* queue){
    // tried and failed
}

int deQueueAll(Queue* queue){
    // could not complete previous function
}

void printQueue(Queue* queue){
    Node* p = queue->;
    while(p != NULL){
        printf("%d\n", p->);
        p = p->next;
    }
    printf("\n");
}

void freeQueue(Queue* queue){
    Node* q = queue->;
    Node* placeholder;
    while(q != NULL){
        placeholder = q->next;
        free(q);
        q = placeholder;
    }
    free(queue);
    queue = NULL;
}
