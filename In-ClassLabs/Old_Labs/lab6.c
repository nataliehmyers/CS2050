# include <stdio.h>
# include <stdlib.h>
# include <time.h>

/*
    Please do not change the fct prototypes.
    Please use descriptive variable names and appropriate spacing!
    Please leave appropriate comments where necessary but do not remove the ones provided.
    Please remember to answer the questions at the end, if any.
    Compilation command: gcc lab6.c -Werror -Wall
*/

// Function prototypes

typedef struct {

    float height;
    float base;

} Tri;

typedef struct list {

    Tri* r;
    struct list* next;

} List;

List* initList();
int insertList(List**);
void printList(List*);
List* freeList(List*);
float averageArea(List*);

int main(){

    srand(time(NULL));

    List* list = initList();

    int check = 0;

    for (int i = 0; i < 10; i++) {

        check = insertList(&list);

        if (check == -1) {

            printf("Insufficient memory\n");
            return -1;
        }
    }

    printList(list);

    float avgArea = averageArea(list);
    printf("Average area is %.2f\n",avgArea);

    list = freeList(list);

    return 0;
}

// Do not change anything in the code above

// NOTE: You may comment out parts of the code in main to test your code, but your submission should have the main function exactly as it is given.

List* initList(){
    List* node = malloc(sizeof(List));
    return node;
}

int insertList(List** head){
    float height, base;
    height = rand() % 10;
    base = rand() % 10;
    List* node = malloc(sizeof(List));
    Tri* r = malloc(sizeof(Tri));
    r->height = height;
    r->base = base;

    node->r = r;
    (*head)->next = node;

    if (head == NULL) {
        return -1;
    }
    printf("made it here");
    return 0;
}

void printList(List* head){
    if(head == NULL){
        printf("The list is empty!\n");
        return;
    }
    List* cur = head;
    while(cur->next != NULL) {
        printf("%.2f ", cur->r->base);
        cur = cur->next;
    }
    printf("%.2f\n", cur->r->base);
}

List* freeList(List* head){
    List* cur = head;
    if(head == NULL)
        return 0;
    while(cur->next != NULL) {
        head = head->next;
        free(cur);
        cur = head;
    }
    free(head);
}

float averageArea(List* head){

}
