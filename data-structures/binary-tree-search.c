#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
        int value;
        struct node *left;
        struct node *right;
} node;

bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->value)
    {
        return search(tree->left, number);
    }
    else if (number > tree->value)
    {
        return search(tree->right, number);
    }
    else if (number == tree->value)
    {
        return true;
    }
}

node* newNode(int nodeValue)
{
    node *tmp = malloc(sizeof(node));
    tmp->value = nodeValue;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

node* insertNode(node *node, int nodeValue) {
    if (node == NULL) return newNode(nodeValue); 
  
    if (nodeValue < node->value) 
        node->left  = insertNode(node->left, nodeValue); 
    else if (nodeValue > node->value) 
        node->right = insertNode(node->right, nodeValue);    
  
    return node; 
}

void printSortedTree(node *node) {
    if (node == NULL) {
      return;
    } 
    printSortedTree(node->left);
    printf("%d\n", node->value);
    printSortedTree(node->right);
}

node* mountTree(node *root, int size) {
    for(int i = 0; i < size; i++){
        if(i == 0) {
            root = insertNode(root, i + 1);
        }
        insertNode(root, i + 1);
    }
    return root;
}

int main (void) {
    node *root = NULL;
    int sizeOfTree = 8;
    int *numbers = malloc(sizeOfTree * sizeof(int));
    root = mountTree(root, sizeOfTree);
    printSortedTree(root);
    bool result = search(root, 11);
    if(result){
        printf("Achou!\n");
    } else {
        printf("Nao achou!\n");
    }
}