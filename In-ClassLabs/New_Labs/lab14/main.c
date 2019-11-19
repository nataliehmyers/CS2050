#include "lab14.h"

int main(void){
    treeNode* node = NULL;
    int oddCount = 0;

    for(int i = 0; i < 10; i++){
        node = insertBT(node, i);
        printBT(node);
        countOddKey(node, &oddCount);
        printf("Odd: %d\n", oddCount);
        oddCount = 0;
        printf("-----------------\n");
    }
    freeTree(node);
    return 0;
}

