#include "header.h"

Node* initTree(int key){
    Node* newNode = malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->key = key;
    return newNode;
}

int insertTree(Node* node, int key){
    int side = rand() % 2;
    if (side == 0){
        if (node->left == NULL) {
            Node* newNode = malloc(sizeof(Node));
            newNode->key = key;
            newNode->left = NULL;
            newNode->right = NULL;
            node->left = newNode;
        } else {
            insertTree(node->left, key);
        }
    } else {
        if (node->right == NULL) {
            Node* newNode = malloc(sizeof(Node));
            newNode->key = key;
            newNode->left = NULL;
            newNode->right = NULL;
            node->right = newNode;
        } else {
            insertTree(node->right, key);
        }
    }
}

int depthOfTree(Node* node){
    if (node == NULL) {
        return 0;
    }
    return 1 + max(depthOfTree(node->left), depthOfTree(node->right));
}

int nodesInTree(Node* node){
    if (node == NULL) {
        return 0;
    }
    return 1 + nodesInTree(node->left) + nodesInTree(node->right);
}

int nodesOfValueInTree(Node* node, int value){
    if (node == NULL) {
        return 0;
    }
    int toAdd = 0;
    if (node->key == value) {
        toAdd = 1;
    }
    return toAdd + nodesOfValueInTree(node->left, value) + nodesOfValueInTree(node->right, value);
}

int max(int one, int two) {
    if (one >= two) {
        return one;
    } else {
        return two;
    }
}
