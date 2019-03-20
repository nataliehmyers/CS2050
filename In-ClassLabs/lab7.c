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
    printf("Base values are:");
    Node * temp = head;
    while (temp){
        printf(" %d,",temp->r->base);
        temp = temp->next;
    }
    printf("\n");
}

// Please do not change the code above -- points will be deducted if you do.

int insertNodeBasedOnIndex(Node** head, int index){ // inserts a node in the passed index place
    int count = 0;

    Node* node = malloc(sizeof(Node));
    Tri* r = malloc(sizeof(Tri));
    Node* cur = *head;

    cur->r = malloc(sizeof(Tri));
    cur->next = NULL;
    if(((void*)head) == NULL){ // checks if reached end of list
        return -1;
    }
    while(head){ // while true statement to iterate through
        (*head)->next;
        count++; // count to track indexes
        if(count == index){ // conditional for index found
            cur->next = (*head)->next;
            (*head)->next = cur;
            return 0;
        }
    }
}

int removeNodeBasedOnValue(Node** head, int value){ // removes a node based on a random int for a value
    Node* cur = *head;
    Node* prev = NULL;
    int found = 0;
    if(head != NULL && (*head)->r->height == value) { // if the first node is what we're looking for
        // first, check if there's a next node
        if((*head)->next != NULL) {// if there is, assign the value to next then free head
            Node* next = (*head)->next;
            free(head);
            return 0;
        }
        else {
            free(head);
            return -1;
        }
    }
    prev = cur;
    cur = cur->next;
    while(cur->next != NULL){ // conditional for reaching end of list
        if(cur->r->height == value){ // conditional for value found in list
            prev->next = cur->next;
            free(cur);
            return 0;
        }
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    free(cur);
    if (found == 0) { // conditional for value not stored in list
        printf("Value not found in list. Nothing removed.\n");
    }
}

void printReverseList(Node* head){ // reverses list and calls print function
    Node* cur = head;
    Node* prev = NULL;
    if(head->next == NULL) // conditional for reaching end of list
        exit;
    prev = cur;
    cur = cur->next;
    prev->next = NULL;//the head now is the new tail
    Node* next = cur->next;
    cur->next = prev;//now the first two nodes are reversed
    while (next != NULL) { // conditional for reaching end of list
        prev = cur;
        cur = next;
        next = next->next;
        cur->next = prev;
    }
    printList(cur); // calls print function
}
