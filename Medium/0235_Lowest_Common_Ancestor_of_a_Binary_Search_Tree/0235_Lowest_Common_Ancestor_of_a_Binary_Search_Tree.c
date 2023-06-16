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

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (NULL != root)
    {
        if (p->val == root->val || q->val == root->val)
        {
            return root;
        }

        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        if ( (p->val < root->val && q->val > root->val) || (q->val < root->val && p->val > root->val) )
        {
            return root;
        }
    }
    return root;   
}

int main(int argc, char const *argv[])
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int nums_size = sizeof(nums)/sizeof(nums[0]);
    int set[2] = {6, 10};
    struct TreeNode *root = NULL;
    struct TreeNode *p = NULL;
    struct TreeNode *q =NULL;
    
    root = make_bst(root, nums, nums_size);

    printf("< --- Pre Order --- >\n");
    preorder_search(root);
    NEWLINE
    printf("< --- In Order --- >\n");
    inorder_search(root);
    NEWLINE
    
    p = find_node(root, set[0]);
    q = find_node(root, set[1]);

    printf("Node p --> [ %d ]\n", p->val);
    printf("Node q --> [ %d ]\n", q->val);

    printf("Lowest Common Ancestor --> [ %d ]\n", lowestCommonAncestor(root, p, q)->val);
    
    return 0;
}


/*

235. Lowest Common Ancestor of a Binary Search Tree
Medium

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T
that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2

Constraints:

The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the BST.

*/