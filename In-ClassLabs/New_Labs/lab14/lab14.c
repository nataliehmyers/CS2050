#include "lab14.h"

treeNode* insertBT(treeNode* tree, int key){
    /* This function receives the current tree and an integer number. It creates a tree node with the integer and inserts
     * it into the current tree randomly: 50% chance it will be inserted left and 50% chance it will be inserted right.
     * It returns the updated tree. It is assumed the treeNode pointer is NULL before the first insertion. O(N) complexity. */

    int side = rand() % 2;
    if (tree == NULL){
        treeNode* newNode = malloc(sizeof(treeNode));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (side == 0){
        if (tree->left == NULL) {
            treeNode* newNode = malloc(sizeof(treeNode));
            newNode->data = key;
            newNode->left = NULL;
            newNode->right = NULL;
            tree->left = newNode;
        } else {
            insertBT(tree->left, key);
        }
    } else {
        if (tree->right == NULL) {
            treeNode* newNode = malloc(sizeof(treeNode));
            newNode->data = key;
            newNode->left = NULL;
            newNode->right = NULL;
            tree->right = newNode;
        } else {
            insertBT(tree->right, key);
        }
    }
    return tree;
}

void printBT(treeNode* tree){
    /* This function receives the current binary tree and prints out all the integer values in the tree. Returns void.
     * O(N) complexity. */

    if (tree == NULL){
        return;
    }
    printf("%d\n", tree->data);
    printBT(tree->left);
    printBT(tree->right);
}

void countOddKey(treeNode* tree, int* value){
    /* This function receives the current binary tree and an integer pointer. It counts the number of odd integers in
     * the binary tree and stores the value into the integer pointer. It is assumed the value in the integer pointer
     * has been initialized to 0 before being passed into the function. Returns void. */

    if (tree == NULL) {
        return;
    }
    if (tree->data % 2 == 1) {
        (*value)++;
    }
    countOddKey(tree->left, value);
    countOddKey(tree->right, value);
}

void freeTree(treeNode* tree){
    /* This function receives the current binary tree and frees all the allocated memory. Returns void. O(N) complexity.*/

    if (tree == NULL){
        return;
    }
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}
