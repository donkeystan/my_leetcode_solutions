#include<stdio.h>
#include<stdlib.h>
#define NEWLINE printf("\n");
int COUNT = 0;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode *);
void preorder(struct TreeNode *);
void print_tree(struct TreeNode *);
struct TreeNode *get_node(int);
struct TreeNode *insert_node(struct TreeNode *, int);
void print_array(int *, int);
int inorder_gen(struct TreeNode *, int *, int *);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int nums[100];
    int count = 0;
    int i;
    *returnSize = inorder_gen(root, nums, &count);
    printf("returnSize ---> %d\n", *returnSize);

    int *returnNums = (int *)malloc(*returnSize * sizeof(int));
    for (i=0; i<*returnSize; i++)
    {
        returnNums[i] = nums[i];
    }


    return returnNums;
}

int inorder_gen(struct TreeNode *root, int *nums, int *count)
{
    if (NULL != root)
    {
        inorder_gen(root->left, nums, count);
        nums[(*count)++] = root->val;
        printf("%d ",*count);
        inorder_gen(root->right, nums, count);
    }
    return *count;
}



int main(int argc, char const *argv[])
{
    int nums[] = {6, 3, 8, 2, 5, 7, 9, 1, 4, 10};
    int nums_size = sizeof(nums)/sizeof(nums[0]);
    int i;
    struct TreeNode *root = NULL;
    int returnSize = 0;
    int *return_nums;

    for (i=0; i<nums_size; i++)
    {
        root = insert_node(root, nums[i]);
    }

    print_tree(root);

    return_nums = inorderTraversal(root, &returnSize);
    printf("<--- Inorder traversal --->");
    print_array(return_nums, returnSize);

    return EXIT_SUCCESS;
}

void print_array(int *nums, int nums_size)
{
    int i;
    for (i=0; i<nums_size; i++)
    {
        printf("%d ",nums[i]);
    }
    NEWLINE;
}


struct TreeNode *insert_node(struct TreeNode *root, int value)
{
    if(NULL == root)
    {
        root = get_node(value);
        return root;
    }

    if (value == root->val)
    {
        return root;
    }

    if (value < root->val)
    {
        root->left = insert_node(root->left, value);
    }
    else
    {
        root->right = insert_node(root->right, value);
    }
    return root;
}


struct TreeNode *get_node(int value)
{
    struct TreeNode *new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void print_tree(struct TreeNode * root)
{
    printf("<--- Inorder --->\n");
    inorder(root);
    NEWLINE;
    printf("<--- Preorder --->\n");
    preorder(root);
    NEWLINE;
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


/*
94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.


Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
 

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?
*/