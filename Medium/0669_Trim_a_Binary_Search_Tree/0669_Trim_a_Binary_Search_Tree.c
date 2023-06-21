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

// During trim low, we will encounter three condition
//      1. root->val == low
//          just eliminate all its left tree
//      2. root->val > low
//          since still higher than low boundary, we keep search from the left tree to look for smaller than/equal to low one
//      3. root->val < low
//          when a node with value lower than low, we have to eliminate it and search for other possible smaller than/equal to low ones from its right tree.
//      4. than set up a base case when we meet a NULL, just return it since its the end, and nothing can be smaller.
//
struct TreeNode *trim_low(struct TreeNode *root, int low)
{
    if (NULL == root)
    {
        return root;
    }

    if (root->val == low)
    {
        root->left = NULL;
        return root;
    }

    else if (root->val > low)
    {
        root->left = trim_low(root->left, low);
        return root;
    }

    else
    {
        return trim_low(root->right, low);
    }
}

// Same process as trim low function but in different search direction.
struct TreeNode *trim_high(struct TreeNode *root, int high)
{
    if (NULL == root)
    {
        return root;
    }

    if (root->val == high)
    {
        root->right = NULL;
        return root;
    }
    else if (root->val < high)
    {
        root->right = trim_high(root->right, high);
        return root;
    }
    else
    {
        return trim_high(root->left, high);
    }
}

// 1 create two functions to trim those nodes lower then low and higher than high separately.
struct TreeNode* trimBST(struct TreeNode* root, int low, int high)
{
    root = trim_low(root, low);
    root = trim_high(root, high);
    return root;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {3, 0, 4, 2, 1};
    int nums[] = {100, 50, 120, 45, 54, 110, 132, 40, 48, 52, 60, 105, 112, 122, 134, 30, 46, 51, 59, 101, 107, 114, 121, 125, 133, 135};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    struct TreeNode *root = NULL;
    root = create_tree(root, nums, nums_size);


    printf("< --- Pre Order --- >\n");
    preorder_search(root);

    printf("\n< --- In Order --- >\n");
    inorder_search(root);

    NEWLINE
    NEWLINE
    // int low   = 1;
    // int high = 3;
    int low  = 55;
    int high = 124;
    root = trimBST(root, low, high);

    printf("< --- Pre Order --- >\n");
    preorder_search(root);

    printf("\n< --- In Order --- >\n");
    inorder_search(root);

    return 0;
}


/*

669. Trim a Binary Search Tree
Medium
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high].
Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant).
It can be proven that there is a unique answer.
Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

Example 1:
Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]

Example 2:
Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
0 <= Node.val <= 10^4
The value of each node in the tree is unique.
root is guaranteed to be a valid binary search tree.
0 <= low <= high <= 10^4

*/