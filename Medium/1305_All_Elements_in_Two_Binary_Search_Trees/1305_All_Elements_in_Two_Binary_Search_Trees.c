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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void print_array(int *nums, int nums_size);

void inorder_to_array(struct TreeNode *root, int *nums, int *level)
{
    if (NULL != root)
    {
        inorder_to_array(root->left, nums, level);
        nums[(*level)++] = root->val;
        inorder_to_array(root->right, nums, level);
    }
}

int * merge_arrays(int *nums1, int nums_size1, int *nums2, int nums_size2)
{   
    int *result = (int *)malloc(sizeof(int) * (nums_size1 + nums_size2));
    int i, j, k;
    for (i=0, j=0, k=0; i<nums_size1 && j<nums_size2; k++)
    {
        if (nums1[i] <= nums2[j])
        {
            result[k] = nums1[i++];
        }
        else
        {
            result[k] = nums2[j++];
        }
    }
    
    while (i < nums_size1)
    {
        result[k++] = nums1[i++];
    }

    while (j < nums_size2)
    {
        result[k++] = nums2[j++];
    }
    return result;
}


int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize)
{
    (*returnSize) = 0;
    int nums_size = 0;
    int nums1[5001];
    int nums2[5001];
    int nums_size1 = 0;
    int nums_size2 = 0;
    inorder_to_array(root1, nums1, returnSize);
    nums_size1 = (*returnSize);
    (*returnSize) = 0;
    inorder_to_array(root2, nums2, returnSize);
    nums_size2 = (*returnSize);
    (*returnSize) = 0;
    int *result = merge_arrays(nums1, nums_size1, nums2, nums_size2);
    (*returnSize) = nums_size1 + nums_size2;
    return result;
}


int main(int argc, char const *argv[])
{
    int nums1[] = {2,1,4};
    int nums_size1 = sizeof(nums1)/sizeof(nums1[0]);

    int nums2[] = {1,0,3};
    int nums_size2 = sizeof(nums1)/sizeof(nums1[0]);

    struct TreeNode *root1 = NULL;
    struct TreeNode *root2 = NULL;

    root1 = create_tree(root1, nums1, nums_size1);
    root2 = create_tree(root2, nums2, nums_size2);

    printf("< --- Tree1 Preorder --> \n");
    preorder_search(root1);
    NEWLINE
    printf("< --- Tree1 In order --> \n");
    inorder_search(root1);
    
    NEWLINE
    NEWLINE

    printf("< --- Tree2 Preorder --> \n");
    preorder_search(root2);
    NEWLINE

    printf("< --- Tree2 In order --> \n");
    inorder_search(root2);
    NEWLINE

    NEWLINE
    int result_size;
    printf("< ---- Get All Element from Two Trees in Sorted Array --->\n ");
    int *result = getAllElements(root1, root2, &result_size);
    print_array(result, result_size);
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
    printf(" \n");
}

/*

1305. All Elements in Two Binary Search Trees
Medium
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

Example 1:
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
Constraints:

The number of nodes in each tree is in the range [0, 5000].
-105 <= Node.val <= 105

*/
