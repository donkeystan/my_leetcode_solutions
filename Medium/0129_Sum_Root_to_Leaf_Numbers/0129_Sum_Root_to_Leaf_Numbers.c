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

void print_array(int *nums, int nums_size);

int nums_to_int(int *nums, int nums_size)
{
    int i;
    long long int sum = 0;
    long long int base = 1;
    for (i=nums_size-1; i>=0; i--)
    {
        sum += ( nums[i] * base);
        base *= 10;
    }
    return sum;
}


// Use Pre Order Traversal to get the numbers in an array
// when seeing a node with both left and right being null, calculate the sum
void inorder_sum(struct TreeNode *root, int *temp, int level, int *sum)
{
    if (NULL != root)
    {
        temp[level] = root->val;
        if (NULL == root->left && NULL == root->right)
        {
            print_array(temp, level+1);
            (*sum) += nums_to_int(temp, level+1);
            return;
        }
        inorder_sum(root->left, temp, level+1, sum);
        inorder_sum(root->right, temp, level+1, sum);
    }
}

int sumNumbers(struct TreeNode* root)
{
    int sum = 0;
    int temp[1000];
    int level = 0;
    inorder_sum(root, temp, level, &sum);
    return sum;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {5, 2, 8, 1, 3, 6, 9, 4, 7};
    int nums[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};

    int nums_size = sizeof(nums) / sizeof(nums[0]);
    struct TreeNode *root = NULL;

    // root = create_tree(root, nums, nums_size);
    root = create_left_skew_tree(root, nums, nums_size);

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
    
    printf("Sum of Root to Leaf Nums ---> [ %d ]\n", sumNumbers(root));
   
    return EXIT_SUCCESS;
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

129. Sum Root to Leaf Numbers
Medium
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
A leaf node is a node with no children.

Example 1:
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 
Constraints:
The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.

*/