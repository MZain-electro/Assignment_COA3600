#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// Recursive function to construct a binary tree from a given
// inorder and preorder sequence
struct Node* construct(char In_Order[], int start, int end,
                char Pre_Order[], int *pIndex)
{
    if (start > end) 
    {
        return NULL;
    }

    struct Node* node = newNode(Pre_Order[(*pIndex)++]);
    int i;
    for (i = start; i <= end; i++)
    {
        if (In_Order[i] == node->data)
         break;
    }
    node->left = construct(In_Order, start, i - 1, Pre_Order, pIndex);
    node->right = construct(In_Order, i + 1, end, Pre_Order, pIndex);
    return node;
}

void traversal_in_order(struct Node* root)
{
    if (root == NULL) 
        return;

    traversal_in_order(root->left);
    printf(" %d ", root->data);//print value of the data
    traversal_in_order(root->right);
}

void traversal_in_pre_order(struct Node* root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    traversal_in_pre_order(root->left);
    traversal_in_pre_order(root->right);
}

 
struct Node* constructTree(char In_Order[], char Pre_Order[], int n)
{
    int pIndex = 0;// pIndex stores the index of the next unprocessed node in preorder;
    return construct(In_Order, 0, n - 1, Pre_Order, &pIndex);
}
//Main Code
int main()
{
    char In_Order[] = {'F','A','E','K','C','D','H','G','B'};
    char Pre_Order[] = {'E','A','C','K','F','H','D','B','G'};

    int number_of_characters = sizeof(In_Order)/sizeof(In_Order[0]);

    struct Node* root = constructTree(In_Order, Pre_Order, number_of_characters);
// traverse the constructed tree
    printf("Traversing the tree in order \n");
    traversal_in_order(root);
    printf("\n");
    printf("Traversing the tree in pre order \n"); 
    traversal_in_pre_order(root);
}
