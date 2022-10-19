#include<stdlib.h>
#include<stdio.h>
#define NEWLINE printf("\n");

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *get_node(int);
struct TreeNode *insert(struct TreeNode*, int);
void inorder(struct TreeNode*);
void preorder(struct TreeNode*);
void postorder(struct TreeNode*);


void counting(struct TreeNode *root, int *count);

int countNodes(struct TreeNode* root)
{
    int count = 0;
    
    if (NULL != root)
    {
        counting(root, &count);    
    }
    return count;
}

void counting(struct TreeNode *root, int *count)
{
    if (NULL != root)
    {
        (*count) ++;
        counting(root->left, count);
        counting(root->right, count);
    }
}



int main(int argc, char const *argv[])
{
    
    int nums[] = {11, 5, 16, 2, 8, 13, 18, 1, 4, 6, 10, 12, 15, 17, 20};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int i;

    struct TreeNode *root = NULL;

    for (i=0; i<numsSize; i++)
    {
        root = insert(root, nums[i]);
    }
    
    printf("<--- Inorder --->\n");
    inorder(root);
    NEWLINE

    printf("<--- Pre order --->\n");
    preorder(root);
    NEWLINE

    int rc = countNodes(root);
    printf("Node Count ---> %d\n", rc);


    return EXIT_FAILURE;


    return EXIT_SUCCESS;
}


void inorder(struct TreeNode *root)
{
    if (NULL != root)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void preorder(struct TreeNode *root)
{
    if (NULL != root)
    {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

struct TreeNode *insert(struct TreeNode *root, int val)
{
    if (NULL != root)
    {
        if (val == root->val)
        {
            return root;
        }

        if (val < root->val)
        {
            root->left = insert(root->left, val);
        }

        if (val > root->val)
        {
            root->right = insert(root->right, val);
        }
    }
    else
    {
        root = get_node(val);
        return root;
    }
    return root;
}


struct TreeNode *get_node(int val)
{
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node -> val = val;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}



/*
222. Count Complete Tree Nodes
Medium

Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last,
is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1

Constraints:
The number of nodes in the tree is in the range [0, 5 * 10^4].
0 <= Node.val <= 5 * 10^4
The tree is guaranteed to be complete.

*/