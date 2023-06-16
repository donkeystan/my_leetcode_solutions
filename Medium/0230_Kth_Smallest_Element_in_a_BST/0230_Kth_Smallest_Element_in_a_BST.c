#include<stdio.h>
#include<stdlib.h>
#define NEWLINE printf("\n");

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorder_print(struct TreeNode *root);
void inorder_print(struct TreeNode *root);
void postorder_print(struct TreeNode *root);
struct TreeNode *get_node(int key);
struct TreeNode *insert_node(struct TreeNode *root, int key);
struct TreeNode *make_bst(struct TreeNode *root, int *nums, int nums_size);
void devide_insert(int *nums, int strt, int end, struct TreeNode **root);
struct TreeNode *delete_node(struct TreeNode *root, int key);
struct TreeNode *find_minimum_node(struct TreeNode *root);

void inorder(struct TreeNode *root, int *count, int *k_smallest_val, int k)
{
    if (NULL != root)
    {
        inorder(root->left, count, k_smallest_val, k);
        (*count) ++;
        if ((*count) == k)
        {
            (*k_smallest_val) = root->val;
            return;
        }
        inorder(root->right, count, k_smallest_val, k);
    }
}

int kthSmallest(struct TreeNode* root, int k)
{
    int count = 0;
    int k_smallest_val = -1;
    inorder(root, &count, &k_smallest_val, k);
    return k_smallest_val;
}

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    // int nums[] = {8826, 6557, 1622, 6881, 989, 1885, 265};
    int nums_size = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode *root = NULL;
    root = make_bst(root, nums, nums_size);

    printf("< --- Pre Order --- >\n");
    preorder_print(root);
    NEWLINE
    
    printf("< --- In Order --- >\n");
    inorder_print(root);
    NEWLINE

    printf("< --- Post Order --- >\n");
    postorder_print(root);
    NEWLINE

    int k = 10;
    printf("[%d] th smallest val in bst --> [ %d ]\n", k, kthSmallest(root, k));

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

void preorder_print(struct TreeNode *root)
{
    if (NULL != root)
    {
        printf("%d ", root->val);
        preorder_print(root->left);
        preorder_print(root->right);
    }
}

void inorder_print(struct TreeNode *root)
{
    if (NULL != root)
    {
        inorder_print(root->left);
        printf("%d ", root->val);
        inorder_print(root->right);
    }
}

void postorder_print(struct TreeNode *root)
{
    if (NULL != root)
    {
        postorder_print(root->left);
        postorder_print(root->right);
        printf("%d ", root->val);
    }
}