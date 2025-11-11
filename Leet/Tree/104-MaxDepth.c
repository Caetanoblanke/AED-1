#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode *createNode(){
    int val;
    printf("TYpe the node value:");
    scanf("%d", &val);

    TreeNode *root =(TreeNode*) malloc(sizeof(TreeNode));
    if (!root)
    {
        printf("Error to alocate\n");
    }
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;    
}


int maxDepth(struct TreeNode* root)
{
    if(!root)
    {
        return 0;
    }

    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);

    if (left_depth > right_depth)
    {
        return left_depth + 1;
    }
    else
    {
        return right_depth + 1;
    }
}