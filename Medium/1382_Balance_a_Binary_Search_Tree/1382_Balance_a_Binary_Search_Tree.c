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

void divide_insert(struct TreeNode **root, int *nums, int start, int end)
{
    int mid;
    if (start <= end)
    {
        mid = (start + end) / 2;
        (*root) = insert_node((*root), nums[mid]);
        divide_insert(root, nums, start, mid-1);
        divide_insert(root, nums, mid+1, end);
    }
}

struct TreeNode *make_bst(struct TreeNode *root, int *nums, int nums_size)
{
    if (NULL == root)
    {
        divide_insert(&root, nums, 0, nums_size-1);
    }
    return root;
}

void inorder_traversal(struct TreeNode *root, int *nums, int *count)
{
    if (NULL != root)
    {
        inorder_traversal(root->left, nums, count);
        nums[(*count)++] = root->val;
        inorder_traversal(root->right, nums, count);
    }
}

// By Inorder Traversal we can get a sorted array
// and then use make bst method to create a new balanced tree.
struct TreeNode* balanceBST(struct TreeNode* root)
{
    int temp[10000];
    int count = 0;
    inorder_traversal(root, temp, &count);
    root = NULL;
    root = make_bst(root, temp, count);
    return root;
}

int main(int argc, char const *argv[])
{
    int nums[] = {1, 2, 3, 4};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    struct TreeNode *root = NULL;
    root = create_tree(root, nums, nums_size);
    
    printf("< --- Pre Order --->\n");
    preorder_search(root);
    NEWLINE
    printf("< --- In Order --->\n");
    preorder_search(root);
    NEWLINE
    NEWLINE

    printf("< --- After Balance --- >\n");
    root = balanceBST(root);
    printf("< --- Pre Order --->\n");
    preorder_search(root);
    NEWLINE
    printf("< --- In Order --->\n");
    preorder_search(root);
    
    return EXIT_SUCCESS;
}

/*

1382. Balance a Binary Search Tree
Medium
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:
Input: root = [2,1,3]
Output: [2,1,3]
 
Constraints:

The number of nodes in the tree is in the range [1, 10^4].
1 <= Node.val <= 10^5

*/