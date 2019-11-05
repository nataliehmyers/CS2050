# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct {
    int height;
    int base;
} Tri;

typedef struct node {
    Tri* r;
    struct node *next;
} Node;

int insertNodeBasedOnIndex(Node**,int);
int removeNodeBasedOnValue(Node**,int);
void printList(Node*);
void printReverseList(Node*);
Node* freeList(Node *);

int main(void){

    srand(time(NULL));
    Node *head = NULL;
    int check;

    for (int i = 0; i < 10; i++){
        check = insertNodeBasedOnIndex(&head, i);
        if (check == -1){
            printf("Insufficient memory\n");
            return -1;
        }
    }
    printList(head);

    check = insertNodeBasedOnIndex(&head, 7);
    printList(head);

    check = removeNodeBasedOnValue(&head, rand()%10+1);
    printList(head);
    printReverseList(head);

    freeList(head);

    return 0;
}

Node* freeList(Node *head){
    Node* temp = head;
    while (head){
        temp = head->next;
        free(head->r);
        free(head);
        head = temp;
    }
    return NULL;
}

void printList(Node* head){
    Node * temp = head;
    while (temp){
        printf(" %d,",temp->r->base);
        temp = temp->next;
    }
    printf("\n");
}

// Please do not change the code above -- points will be deducted if you do.

int insertNodeBasedOnIndex(Node** head, int index){ // inserts a node in the passed availableIdx place
    if (head == NULL){ // checks if reached end of List
        return -1;
    }
    Node* node = malloc(sizeof(Node));
    if (node == NULL){
        return -1;
    }

    Tri* tri = malloc(sizeof(Tri));
    if (tri == NULL){
        return -1;
    }


    tri->height = rand() % 10 + 1;
    tri->base = rand() % 10 + 1;

    node->r = tri;

    if ((*head) == NULL){
        return -1;
    }

    if (index == 0){
        node->next = (*head);
        (*head) = node;
        return 1;
    } else {
        Node* cur = (*head);

        for (int i = 0; i < index - 1; i++){
            cur = cur->next;

            if (cur == NULL) {
                return -1;
            }
        }

        Node* temp = cur->next;
        cur->next = node;
        node->next = temp;
        return 1;
    }
}

int removeNodeBasedOnValue(Node** list, int value){
    if (list == NULL){
        return -1;
    }
    Node* cur = (*list);
    Node* prev = NULL;
    while (cur != NULL && cur->r->base != value){
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL){
        return -1;
    }

    if (prev == NULL){
        Node* next = cur->next;
        (*list) = next;
        free(cur->r);
        free(cur);
        return 1;
    } else {
        prev->next = cur->next;
        free(cur->r);
        free(cur);
        return 1;
    }
}

void printReverseList(Node* head){
    if (head == NULL){
        return;
    }
    printReverseList(head->next);
    printf("%d, ", head->r->base);
}

