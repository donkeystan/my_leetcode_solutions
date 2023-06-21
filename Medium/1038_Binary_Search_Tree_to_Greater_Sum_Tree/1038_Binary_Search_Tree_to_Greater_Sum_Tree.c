#include<stdio.h>
#include<stdlib.h>
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

int inorder_sum(struct TreeNode *root, int sum)
{
    if (NULL != root)
    {
        sum = inorder_sum(root->left, sum);
        sum += root->val;
        sum = inorder_sum(root->right, sum);
    }
    return sum;
}

int inorder_rewrite(struct TreeNode *root, int curr_total)
{
    if (NULL != root)
    {
        curr_total = inorder_rewrite(root->left, curr_total);
        int curr_node_val = root->val;
        root->val = curr_total;
        curr_total -= curr_node_val;
        curr_total = inorder_rewrite(root->right, curr_total);
    }
    return curr_total;
}

struct TreeNode* bstToGst(struct TreeNode* root)
{
    int sum = 0;
    sum = inorder_sum(root, sum);
    inorder_rewrite(root, sum);
    return root;
}

int main(int argc, char const *argv[])
{
    int nums[] = {4,1,6,0,2,5,7,3,8};
    int nums_size = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode *root = NULL;
    root = create_tree(root, nums, nums_size);

    printf("< --- Pre Order --- >\n");
    preorder_search(root);
    NEWLINE

    printf("< --- In Order --- >\n");
    inorder_search(root);
    NEWLINE

    NEWLINE
    printf(" < -- Convert to Greater Tree -- >\n");
    root = bstToGst(root);

    printf("< --- Pre Order --- >\n");
    preorder_search(root);
    NEWLINE

    printf("< --- In Order --- >\n");
    inorder_search(root);
    NEWLINE

    return EXIT_SUCCESS;
}

/*

1038. Binary Search Tree to Greater Sum Tree
Medium
Given the root of a Binary Search Tree (BST),
onvert it to a Greater Tree
such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Example 2:
Input: root = [0,null,1]
Output: [1,null,1]

Constraints:
The number of nodes in the tree is in the range [1, 100].
0 <= Node.val <= 100
All the values in the tree are unique.
 
Note: This question is the same as 538: https://leetcode.com/problems/convert-bst-to-greater-tree/

*/