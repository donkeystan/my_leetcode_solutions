#ifndef _BST_H_
#define _BST_H_

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *get_node(int key);
struct TreeNode *insert_node(struct TreeNode *root, int key);
struct TreeNode *make_bst(struct TreeNode *root, int *nums, int nums_size);
struct TreeNode *create_tree(struct TreeNode *root, int *nums, int nums_size);
void divide_insert(int *nums, int start, int end, struct TreeNode **root);
struct TreeNode *replace_by_right_leftmost(struct TreeNode *root, int key);
struct TreeNode *replace_by_left_rightmost(struct TreeNode *root, int key);
struct TreeNode *delete_node(struct TreeNode *root, int key);
struct TreeNode *left_skew_insert(struct TreeNode *root, int key);
struct TreeNode *create_left_skew_tree(struct TreeNode *root, int *nums, int nums_size);
void inorder_search(struct TreeNode *root);
void preorder_search(struct TreeNode *root);
void postorder_search(struct TreeNode *root);
struct TreeNode *find_node(struct TreeNode *root, int key);

#endif