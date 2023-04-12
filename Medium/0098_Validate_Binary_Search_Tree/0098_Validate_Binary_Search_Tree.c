#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void search(struct TreeNode *root, int *isValid, int *key_box, int *idx)
{
    if (NULL != root)
    {
        search(root->left, isValid, key_box, idx);
        key_box[(*idx)] = root->val;
        if ((*idx) > 0)
        {
            if ( key_box[(*idx)-1] >= key_box[(*idx)]) 
            {
                (*isValid) = 0;
                return;
            }
        }
        (*idx) ++;
        search(root->right, isValid, key_box, idx);
    }
}

bool isValidBST(struct TreeNode* root)
{
    int idx = 0;
    int key_box[40000];
    int isValid = 1;
    search(root, &isValid, key_box, &idx);
    return isValid;
}

/*
98. Validate Binary Search Tree
Medium
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1

*/