//
//  BinaryTree.c
//  DataStructures
//
//  Created by Brett Fazio on 5/5/18.
//  Copyright © 2018 Brett Fazio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

void insert(int value, Node **node);
Node* search(int value, Node *current);
Node* newNode(int value);
int depth(Node *root);
int size(Node *root);
int minValue(Node *root);
void printOrderedValues(Node *root);

struct Node {
    int value;
    
    Node *left;
    Node *right;
};

void insert(int value, Node **node) {
    if ((*node) == NULL) {
        (*node) = newNode(value);
        return;
    }
    
    if (value > (*node)->value) {
        insert(value, &(*node)->right);
    }else {
        insert(value, &(*node)->left);
    }
}

Node* search(int value, Node *current) {
    
    if (current->value == value) {
        return current;
    }else if (current->value > value) {
        return search(value, current->right);
    }else {
        return search(value, current->left);
    }
    
    return NULL;
}

Node* newNode(int value) {
    Node * node = (Node*)malloc(sizeof(Node));
    
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

int depth(Node *root) {
    
    int max = 1;
    
    if (root->left != NULL) {
        int dl = depth(root->left)+1;
        if (dl > max) {
            max = dl;
        }
    }
    if (root->right != NULL) {
        int dr = depth(root->right)+1;
        if (dr > max) {
            max = dr;
        }
    }
    
    return max;
}

int size(Node *root) {
    if (root == NULL) {
        return 0;
    }
    
    return 1 + size(root->left) + size(root->right);
}

int minValue(Node *root) {
    if (root->left == NULL) {
        return root->value;
    }else {
        return minValue(root->left);
    }
}

void printOrderedValues(Node *root) {
    if (root->left != NULL) {
        printOrderedValues(root->left);
    }
    printf("%d ", root->value);
    
    if (root->right != NULL) {
        printOrderedValues(root->right);
    }
}

int main(int argc, const char * argv[]) {
    
    Node *root = newNode(0);
    
    insert(-50, &root);
    
    insert(50, &root);
    
    insert(100, &root);
    
    
    
    printf("Depth = %d\n", depth(root));
    printf("Size = %d\n", size(root));
    printf("Min Value = %d\n", minValue(root));
    
    printOrderedValues(root);
    
    return 0;
    
}
