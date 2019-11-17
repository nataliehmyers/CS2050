#include "header.h"

int main(void){
    srand(time(NULL));
    Node* tree = initTree(99);
    printf("Nodes: %d\tDepth: %d\n", nodesInTree(tree), depthOfTree(tree));
    int key = rand() % 10;
    for(int i = 0; i < 100; i++){
        insertTree(tree, key);
        key = rand() % 10;
        printf("Nodes: %d\tDepth: %d\n", nodesInTree(tree), depthOfTree(tree));
        printf("Number of 3s: %d\n", nodesOfValueInTree(tree, 3));
    }

    return 0;
}
