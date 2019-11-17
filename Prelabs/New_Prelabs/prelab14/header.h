#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct _Node {
    int key;
    struct _Node* left;
    struct _Node* right;
} Node;


Node* initTree(int);
int insertTree(Node*, int);
int depthOfTree(Node*);
int nodesInTree(Node*);
int max(int, int);
int nodesOfValueInTree(Node*, int);
