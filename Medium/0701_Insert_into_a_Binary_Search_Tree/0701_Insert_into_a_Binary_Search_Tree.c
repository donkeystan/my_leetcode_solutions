#include<stdlib.h>
#include<stdio.h>
#include"bst.h"
#define NEWLINE printf("\n");
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// struct TreeNode *get_node(int val)
// {
//     struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//     new_node->val = val;
//     new_node->left = NULL;
//     new_node->right = NULL;
//     return new_node;
// }

struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    if (NULL != root)
    {
        if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        if (val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
    }
    else
    {
        root = get_node(val);
        return root;
    }
    return root;
}

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3,4,5,6,8,9,10};
    int nums_size = sizeof(nums)/sizeof(nums[0]);
    struct TreeNode *root = NULL;

    root = make_bst(root, nums, nums_size);
    
    printf("< --- Pre Order Search --->\n");
    preorder_search(root);
    NEWLINE

    printf("< --- In Order Search --->\n");
    inorder_search(root);
    NEWLINE

    printf("< --- Post Order Search --->\n");
    postorder_search(root);
    NEWLINE
    NEWLINE

    int val = 7;
    printf("< --- On Insert Key [ %d ] --> \n", val);
    root = insertIntoBST(root, val);

    printf("< --- Pre Order Search --->\n");
    preorder_search(root);
    NEWLINE

    printf("< --- In Order Search --->\n");
    inorder_search(root);
    NEWLINE

    printf("< --- Post Order Search --->\n");
    postorder_search(root);
    NEWLINE
    NEWLINE
    

    

    
    return EXIT_SUCCESS;
}


/*

701. Insert into a Binary Search Tree

You are given the root node of a binary search tree (BST) and a value to insert into the tree.
Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Example 1:
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:
Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]

Example 3:
Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]

Constraints:

The number of nodes in the tree will be in the range [0, 10^4].
-10^8 <= Node.val <= 10^8
All the values Node.val are unique.
-10^8 <= val <= 10^8
It's guaranteed that val does not exist in the original BST.

*/