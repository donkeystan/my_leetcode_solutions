#include<stdio.h>
#include<stdlib.h>
#define NEWLINE printf("\n")

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode*);
void preorder(struct TreeNode*);
struct TreeNode* get_node(int);
struct TreeNode* insert_node(struct TreeNode *, int);
void pointerSwap(struct TreeNode **, struct TreeNode **);

void pointerSwap(struct TreeNode **left, struct TreeNode **right)
{
    struct TreeNode *ptr = NULL;
    ptr = *left;
    *left = *right;
    *right = ptr;
}

struct TreeNode* invertTree(struct TreeNode* root)
{    
    if (NULL == root)
    {
        return root;
    }

    if (NULL == root->left && NULL == root->right)
    {
        return root;
    }
    else
    {
        pointerSwap(&(root->left), &(root->right));
        invertTree((struct TreeNode *)root->left);
        invertTree((struct TreeNode *)root->right);
    }
    
    return root;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {4,2,7,1,3,6,9};
    int nums[] = {6, 3, 8, 2, 5, 7, 9, 1, 4, 10};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    struct TreeNode *root = NULL;
    int i;

    for (i=0; i<nums_size; i++)
    {
        root = insert_node(root, nums[i]);
    }

    printf("<---- inorder ----->\n");
    inorder(root);
    NEWLINE;
    printf("<---- preorder ----->\n");
    preorder(root);

    root = invertTree(root);
    
    NEWLINE;
    printf("After Invert");
    NEWLINE;
    printf("<---- inorder ----->\n");
    inorder(root);
    NEWLINE;
    printf("<---- preorder ----->\n");
    preorder(root);



    return 0;
}

struct TreeNode* insert_node(struct TreeNode *root, int value)
{
    struct TreeNode *ptr = NULL;
    ptr = root;

    if (NULL == root)
    {
        ptr = get_node(value);
        root = ptr;
        return root;
    }

    if (value == ptr->val)
    {
        return ptr;
    }

    if (value < ptr->val)
    {
        ptr->left = insert_node(ptr->left, value);
    }
    
    if (value > ptr->val)
    {
        ptr->right = insert_node(ptr->right, value);
    }
    return ptr;
}

struct TreeNode* get_node(int value)
{
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;
}

void inorder(struct TreeNode* root)
{
    if (NULL != root)
    {
        inorder(root->left);
        printf("%d ",root->val);
        inorder(root->right);
    }
}

void preorder(struct TreeNode* root)
{
    if (NULL != root)
    {
        printf("%d ",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

/*
226. Invert Binary Tree

Share
Given the root of a binary tree, invert the tree, and return its root.
Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []


Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/