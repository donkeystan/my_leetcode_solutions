#include<stdlib.h>
#include<stdio.h>
#include"bst_mod\bst.h"
#define NEWLINE printf("\n");
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *get_node(int val)
{
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct TreeNode *insert_node(struct TreeNode *root, int val)
{
    if (NULL != root)
    {
        if (val == root->val)
        {
            return root;
        }
        
        if (val < root->val)
        {
            root->left = insert_node(root->left, val);
        }

        if (val > root->val)
        {
            root->right = insert_node(root->right, val);
        }
    }
    else
    {
        root = get_node(val);
        return root;
    }
    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{
    struct TreeNode *root = NULL;
    int i;
    for (i=0; i<preorderSize; i++)
    {
        root = insert_node(root, preorder[i]);
    }
    return root;
}

void print_array(int *nums, int nums_size);

int main(int argc, char const *argv[])
{
    int preorder[] = {50,25,12,6,3,1,2,4,5,9,7,10,11,18,15,13,14,16,17,21,19,20,23,22,24,37,31,28,26,27,29,30,34,32,33,35,36,43,40,38,39,41,42,46,44,45,48,47,49,75,62,56,53,51,52,54,55,59,57,58,60,61,68,65,63,64,66,67,71,69,70,73,72,74,88,81,78,76,77,79,80,84,82,83,86,85,87,94,91,89,90,92,93,97,95,96,99,98,100};
    int preorderSize = sizeof(preorder)/sizeof(preorder[0]);

    struct TreeNode *root = NULL;
    root = bstFromPreorder(preorder, preorderSize);
    
    printf("< --- Pre Order Search --- >\n");
    preorder_search(root);
    NEWLINE
    printf("< --- In Order Search --->\n");
    inorder_search(root);
    
    return 0;
}

void print_array(int *nums, int nums_size)
{
    int i;
    printf("[ ");
    for (i=0; i<nums_size; i++)
    {
        printf("%d", nums[i]);
        if (i < nums_size-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

/*

1008. Construct Binary Search Tree from Preorder Traversal
Medium
5.3K
69
Companies
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.


Example 1:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:
Input: preorder = [1,3]
Output: [1,null,3]
 
Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.

*/