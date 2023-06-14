#include<stdio.h>
#include<stdlib.h>
#define NEWLINE printf("\n");

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorder(struct TreeNode *root);
void inorder(struct TreeNode *root);
void postorder(struct TreeNode *root);
struct TreeNode *get_node(int key);
struct TreeNode *insert_node(struct TreeNode *root, int key);
struct TreeNode *make_bst(struct TreeNode *root, int *nums, int nums_size);
void devide_insert(int *nums, int strt, int end, struct TreeNode **root);

struct TreeNode *replace_by_left_rightmost(struct TreeNode *root)
{
    struct TreeNode *prev = root;
    struct TreeNode *curr = root->left;
    while (NULL != root && NULL != curr->right)
    {
        prev = curr;
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

struct TreeNode *replace_by_right_leftmost(struct TreeNode *root)
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
    free(curr);
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    // 1. Base Case for recursion call if the key cannot be found or the tree is empty
    if (NULL == root)
    {
        return root;
    }

    // 2. Search Key by recursion, 
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }

    if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }


    // 3. Process when Key Found

    // 3.1 If the node found happens to be lack of left tree, return the right tree;
    //     If the node found happens to be lack of right tree, return the left tree;
    //     if the node found still with left and right tree, we can either
    //          1. Take the rightmost node of current node's left tree, and swap with current node
    //          2. Take the leftmost node of current node's right tree, and swap with current node
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
        // 3.1.2 The function that takes care of finding the rightmost node of the left tree or leftmost node of righttree
        // root = replace_by_left_rightmost(root);
        root = replace_by_right_leftmost(root);
        return root;
    }
}

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    // int nums[] = {8826, 6557, 1622, 6881, 989, 1885, 265};
    int nums_size = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode *root = NULL;
    root = make_bst(root, nums, nums_size);

    printf("< --- Pre Order --- >\n");
    preorder(root);
    NEWLINE
    
    printf("< --- In Order --- >\n");
    inorder(root);
    NEWLINE

    printf("< --- Post Order --- >\n");
    postorder(root);
    NEWLINE

    NEWLINE
    int key = 5;
    printf("< --- On Delete [ %d ] --- >\n", key);
    root = deleteNode(root, key);

    printf("< --- Pre Order --- >\n");
    preorder(root);
    NEWLINE
    
    printf("< --- In Order --- >\n");
    inorder(root);
    NEWLINE

    printf("< --- Post Order --- >\n");
    postorder(root);
    NEWLINE
    

    return EXIT_SUCCESS;
}


void devide_insert(int *nums, int start, int end, struct TreeNode **root)
{
    int mid;
    if (start <= end)
    {
        mid = (start + end) / 2;
        (*root) = insert_node((*root), nums[mid]);
        devide_insert(nums, start, mid-1, root);
        devide_insert(nums, mid+1, end, root);
    }
}

struct TreeNode *make_bst(struct TreeNode *root, int *nums, int nums_size)
{
    if (NULL == root)
    {
        devide_insert(nums, 0, nums_size-1, &root);
    }
    return root;
}

struct TreeNode *insert_node(struct TreeNode *root, int key)
{
    if (NULL != root)
    {
        if (key == root->val)
        {
            return root;
        }
        
        if (key < root->val)
        {
            root->left = insert_node(root->left, key);
        }

        if (key > root->val)
        {
            root->right = insert_node(root->right, key);
        }
    }
    else
    {
        root = get_node(key);
        return root;
    }
    return root;
}

struct TreeNode *get_node(int key)
{
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->val = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void preorder(struct TreeNode *root)
{
    if (NULL != root)
    {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct TreeNode *root)
{
    if (NULL != root)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void postorder(struct TreeNode *root)
{
    if (NULL != root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}

/*

450. Delete Node in a BST
Medium
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
Each node has a unique value.
root is a valid binary search tree.
-10^5 <= key <= 10^5

Follow up: Could you solve it with time complexity O(height of tree)?
*/
