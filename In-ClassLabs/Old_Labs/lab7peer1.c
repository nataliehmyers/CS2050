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

/*
 * Inserts a new node into the provided List at the given index.
 * Takes the address of the linkedList and the insertion index.
 * Returns -1 if the insertion failed.
 * Returns 1 if the insertion was successful.
*/
int insertNodeBasedOnIndex(Node **list, int index)
{

    if (list == NULL) // null pointer
    {
        return -1;
    }

    // create the node element and the node
    Tri *tri = malloc(sizeof(Tri));
    if (!tri)
    {
        return -1;
    }

    Node *node = malloc(sizeof(Node));
    if (!node)
    {
        return -1;
    }

    tri->height = rand()%10+1; // populate triangle
    tri->base = rand()%10+1;
    node->r = tri; // point to triangle

    // logic for inserting into List

    if (*list == NULL && index != 0)
    {
        return -1; // always have to insert at 0 for an empty List
    }

    if (index == 0) // inserting at the headPtr of the List
    {
        node->next = *list;
        *list = node;
        return 1;
    }

    else // not inserting at the headPtr of the List
    {
        Node *currentNode = *list;

        for (int i =0; i < index - 1; i++)
        {
            currentNode = currentNode->next;

            if (currentNode == NULL)
            {
                return -1; // out of bounds of List
            }
        }

        Node *tempNode = currentNode->next;
        currentNode->next = node;
        node->next = tempNode;
        return 1;
    }
}

/*
 * Removes the first instance of a node with the given base.
 * Takes the address of the linkedList and the target base.
 * Returns -1 if the removal was not successful.
 * Returns 1 if the removal was successful.
*/
int removeNodeBasedOnValue(Node **list, int base)
{
    if (list == NULL) // null pointer
    {
        return -1;
    }

    Node *currentNode = *list; // start at headPtr of List
    Node *previousNode = NULL;

    while (currentNode != NULL && currentNode->r->base != base)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) // node with base value not found
    {
        return -1;
    }

    if (previousNode == NULL) // node we are removing is the headPtr of the List
    {
        Node *nextNode = currentNode->next;
        *list = nextNode; // set the new headPtr of the List as the node following the current headPtr
        free(currentNode->r);
        free(currentNode);
        return 1;
    }

    else // target node is embedded between node A and B where A != headPtr
    {
        previousNode->next = currentNode->next; // remove references to node from List
        free(currentNode->r);
        free(currentNode);
        return 1;
    }
}

/*
 * Prints the linkedList in reverse order.
 * Takes in the linkedList.
*/
void printReverseList(Node *list)
{
    // recursive solution to printing List backwards
    if (list == NULL) // reached the end of the List
    {
        return;
    }

    printReverseList(list->next);

    printf("%d, ", list->r->base);
}

