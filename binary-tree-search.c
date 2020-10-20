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

int main (void) {
    node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    bool result = search(root, 8);
    if(result){
        printf("Achou!\n");
    } else {
        printf("Nao achou!\n");
    }
}