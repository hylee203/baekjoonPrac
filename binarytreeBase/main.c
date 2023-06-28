// base code to build and traverse a binary tree
// Youngmin Oh
// 2022. 3. 23
// (modified by JaKeoung Koo 2022. 3. 15.)

#include <stdio.h>
#include <stdlib.h>


// Node structure
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};


// function to make a new node and assign an integer value to it
// argument: int data
// return: a pointer to the node
struct Node* newnode(int data)
{
    // dynamic memory allocation and check memory assignment
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // node initialization
    node->key = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}


// function to traverse inorder
// when visiting a node, print its key
// argument: a pointer to a node
void inorder(struct Node* node)
{
    if (node) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}


// function to free tree nodes allocated in memory
// using postorder traversal
void free_tree(struct Node* node)
{
    if (node) {
        free_tree(node->left);
        free_tree(node->right);
        // printf("free %d, ", node->key);
        free(node);
    }
}


int main() {

    // manual insertion of nodes to the tree
    // same tree as p.38 of the lecture slides "1-trees.pdf"

    // level 1: root
    struct Node* root = newnode(100);
    printf("pointer size: %d byte, *root size: %d byte\n", sizeof(root), sizeof(*root));

    // level 2
    root->left = newnode(75);
    root->right = newnode(150);

    // level 3
    root->left->left = newnode(50);
    root->left->right = newnode(90);
    root->right->left = newnode(120);
    root->right->right = newnode(490);

    // level 4
    root->right->right->left = newnode(160);

    // inorder traversal 
    printf("inorder traversal: ");
    inorder(root);
    printf("\n");

    // free all tree nodes
    free_tree(root);
    printf("\n");

    return 0;
}