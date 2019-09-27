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

/* Mr. Miku, I would love to know what miku means... let me know! -D */

// Adds a new node given a specific location in the list, returns 1 if successful, -1 if not.
int insertNodeBasedOnIndex(Node** list, int location)
{
    Node* node = malloc(sizeof(Node));
    Tri* tri = malloc(sizeof(Tri));
    Node* hold = *list;

    // Error check.
    if(node == NULL)
    {
        printf("Error allocating memory in function addNodeByLocation.\n");
        return(-1);
    }

    if(*list == NULL && location > 0)
    {
        printf("Invalid position to input a node.\n");
        return(-1);
    }

    // Filling the node.
    tri->base = rand() % 10 + 1;
    tri->height = rand() % 10 + 1;

    node->r = tri;

    if(*list == NULL)
    {
        node->next = NULL;
        *list = node;

        return(1);
    }

    else
    {
        for(int i = 0; i < location - 1; i++)
        {
            hold = hold->next;
        }

        node->next = hold->next;
        hold->next = node;

        return(1);
    }
}

// Deletes the first occurence of a node given it's item, returns 1 if successful, -1 if not.
int removeNodeBasedOnValue(Node** list,int key)
{
    Node* hold = *list;
    Node* previous;

    if(hold == NULL)
    {
        printf("No list exists.\n");
        return(-1);
    }

    while(hold != NULL && hold->r->base != key)
    {
        if(hold->next != NULL)
        {
            previous = hold;
            hold = hold->next;
        }

        else
            break;
    }

    if(hold->r->base == key)
    {
        previous->next = hold->next;
        free(hold);

        printf("Deleted the first node with item %d.\n", key);

        return(1);
    }

    else
    {
        printf("No node with item %d exists.\n", key);
        return(-1);
    }
}

// Prints the list backwards.
void printReverseList(Node* list)
{
    Node* hold = list;

    if (hold == NULL)
        return;

    printReverseList(hold->next);

    // Format is a little weird, but I have never had to work with recursion before. You said this was okay, so I left it.
    printf("%d, ", hold->r->base);
}
