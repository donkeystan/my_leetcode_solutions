#include<stdio.h>
#include<stdlib.h>
#define NEWLINE printf("\n");
#define SIZE 100
int COUNT = 0;
int IDX = -1;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode * STACK[SIZE];

void inorder(struct TreeNode *);
void preorder(struct TreeNode *);
void print_tree(struct TreeNode *);
struct TreeNode *get_node(int);
struct TreeNode *insert_node(struct TreeNode *, int);

struct TreeNode *push(struct TreeNode*);
struct TreeNode *pop();
int isEmpty();
int isFull();


void left_child_push(struct TreeNode*);
void print_array(int *, int);



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int nums[SIZE];
    int i = 0;
    int done = 0;
    int count = 0;
    int *return_nums = NULL;
    

    struct TreeNode *ptr = root;
    struct TreeNode *p_pop = NULL;

    while (!done)
    {
        if(NULL != ptr)
        {
            push(ptr);
            ptr = ptr->left;
        }
        else
        {
            if (!isEmpty())
            {
                p_pop = pop();
                if (NULL != p_pop)
                {
                    printf("%d popped out\n",p_pop->val);
                    nums[i++] = p_pop->val;
                    count++;
                }
                ptr = p_pop->right;
            }
            else
            {
                done = 1;
            }
        }
    }
    return_nums = (int *)malloc(count * sizeof(int));
    
    for (i=0; i<count; i++)
    {
        return_nums[i] = nums[i];
    }

    *returnSize = count;

    return return_nums;
}





int main(int argc, char const *argv[])
{
    int nums[] = {6, 3, 8, 2, 5, 7, 9, 1, 4, 10};
    int nums_size = sizeof(nums)/sizeof(nums[0]);
    int i;
    struct TreeNode *root = NULL;
    int returnSize = 0;
    int *return_nums;

    for (i=0; i<nums_size; i++)
    {
        root = insert_node(root, nums[i]);
    }

    print_tree(root);
    return_nums = inorderTraversal(root, &returnSize);

    printf("address held in return_num in main ---> %p\n", return_nums);
    NEWLINE;
    printf("<--- Inorder traversal --->\n");
    for (i=0; i<returnSize; i++)
    {
        printf("%d ", return_nums[i]);
    }
    return EXIT_SUCCESS;
}

void left_child_push(struct TreeNode* root)
{
    struct TreeNode *ptr = root;
     while (NULL != ptr)
    {
        push(ptr);
        ptr = ptr->left;
    }
}


struct TreeNode *push(struct TreeNode* curr_node)
{
    if (isFull())
    {
        return curr_node;
    }
    else
    {
        STACK[++IDX] = curr_node;
        printf("Node of %d is pushed in\n",curr_node->val);
    }
    return curr_node;
}

struct TreeNode *pop()
{
    struct TreeNode *ptr = NULL;
    if (isEmpty())
    {
        return ptr;
    }
    else
    {
        ptr = STACK[IDX--];
    }
    return ptr;
}

void print_array(int *nums, int nums_size)
{
    int i;
    for (i=0; i<nums_size; i++)
    {
        printf("%d ",nums[i]);
    }
    NEWLINE;
}

int isEmpty()
{
    if(IDX < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (IDX <= SIZE-1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



struct TreeNode *insert_node(struct TreeNode *root, int value)
{
    if(NULL == root)
    {
        root = get_node(value);
        return root;
    }

    if (value == root->val)
    {
        return root;
    }

    if (value < root->val)
    {
        root->left = insert_node(root->left, value);
    }
    else
    {
        root->right = insert_node(root->right, value);
    }
    return root;
}


struct TreeNode *get_node(int value)
{
    struct TreeNode *new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void print_tree(struct TreeNode * root)
{
    printf("<--- Inorder --->\n");
    inorder(root);
    NEWLINE;
    printf("<--- Preorder --->\n");
    preorder(root);
    NEWLINE;
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

void preorder(struct TreeNode *root)
{
    if (NULL != root)
    {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}


/*
94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.


Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
 

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?
*/