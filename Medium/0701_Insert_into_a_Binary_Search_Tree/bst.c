#include<stdlib.h>
#include<stdio.h>
#include"bst.h"
#define NEWLINE printf("\n");

struct TreeNode *get_node(int key)
{
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->val = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct TreeNode *insert_node(struct TreeNode *root, int key)
{
    if (NULL != root)
    {
        if (key == root->val)
        {
            return root;
        }

        else if (key < root->val)
        {
            root->left = insert_node(root->left, key);
        }
        else
        {
            root->right = insert_node(root->right, key);
        }
    }
    else
    {
        root = get_node(key);
        return  root;
    }
    return root;
}

struct TreeNode *left_skew_insert(struct TreeNode *root, int key)
{
    if (NULL != root)
    {
        root->left = left_skew_insert(root->left, key);
    }
    else
    {
        root = get_node(key);
        return root;
    }
    return root;
}

struct TreeNode *create_left_skew_tree(struct TreeNode *root, int *nums, int nums_size)
{
    int i;
    for (i=0; i<nums_size; i++)
    {
        root = left_skew_insert(root, nums[i]);
    }
    return root;
}

void divide_insert(int *nums, int start, int end, struct TreeNode **root)
{
    int mid;
    if (start <= end)
    {
        mid = (start + end) / 2;
        (*root) = insert_node((*root), nums[mid]);
        divide_insert(nums, start, mid-1, root);
        divide_insert(nums, mid+1, end, root);
    }
}

struct TreeNode *create_tree(struct TreeNode *root, int *nums, int nums_size)
{
    int i;
    for (i=0; i<nums_size; i++)
    {
        root = insert_node(root, nums[i]);
    }
    return root;
}

struct TreeNode *make_bst(struct TreeNode *root, int *nums, int nums_size)
{
    if (NULL == root)
    {
        divide_insert(nums, 0, nums_size-1, &root);
    }
    return root;
}

struct TreeNode *replace_by_right_leftmost(struct TreeNode *root, int key)
{
    struct TreeNode *prev = root;
    struct TreeNode *curr = root->right;

    while (NULL != curr->left)
    {
        prev = curr;
        curr = curr->left;
    }

    if (prev == root)
    {
        prev->right = curr->right;
    }
    else
    {
        prev->left = curr->right;
    }

    root->val = curr->val;
    free(root);
    return root;
}

struct TreeNode *replace_by_left_rightmost(struct TreeNode *root, int key)
{
    struct TreeNode *prev = root;
    struct TreeNode *curr = root->left;

    while (NULL != curr->right)
    {
        prev= curr;
        curr = curr->right;
    }

    if (prev == root)
    {
        prev->left = curr->left;
    }
    else
    {
        prev->right = curr->left;
    }

    root->val = curr->val;
    free(curr);
    return root;
}

struct TreeNode *delete_node(struct TreeNode *root, int key)
{
    if (NULL == root)
    {
        return root;
    }

    if (key < root->val)
    {
        root->left = delete_node(root->left, key);
        return root;
    }

    if (key > root->val)
    {
        root->right = delete_node(root->right, key);
        return root;
    }

    if (NULL == root->left)
    {
        struct TreeNode *right_tree = root->right;
        free(root);
        return right_tree;
    }
    else if (NULL == root->right)
    {
        struct TreeNode *left_tree = root->left;
        free(root);
        return left_tree;
    }
    else
    {
        // root = replace_by_left_rightmost(root, key);   
        root = replace_by_right_leftmost(root, key);
        return root;
    }
}

void inorder_search(struct TreeNode *root)
{
    if (NULL != root)
    {
        inorder_search(root->left);
        printf("%d ", root->val);
        inorder_search(root->right);
    }
}

void preorder_search(struct TreeNode *root)
{
    if (NULL != root)
    {
        printf("%d ", root->val);
        preorder_search(root->left);
        preorder_search(root->right);
    }
}

void postorder_search(struct TreeNode *root)
{
    if (NULL != root)
    {
        postorder_search(root->left);
        postorder_search(root->right);
        printf("%d ", root->val);
    }
}