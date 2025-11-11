#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int val)
{
    TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
    if (!node)
    {
        printf("Error to alocate");
    }
    else
    {
        node->val = val;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

int* inorderTraversal(TreeNode* node, int *returnSize)
{
    
    
}


int main(){

    TreeNode *node = createNode(1);
    int *returnSize;
}                   
