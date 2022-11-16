#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode
{
    int val;
    struct ListNode *next;
};

#define SIZE 20000
struct TreeNode *get_TreeNode(int val);
struct TreeNode *insert_TreeNode(struct TreeNode *root, int val);
void binary_insert(struct TreeNode **root, int *nums, int start, int end);
int insert_nodes_to_nums(struct ListNode *head, int *nums);

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    struct TreeNode *root = NULL;
    if (NULL != head)
    {
        int nums[SIZE];
        int numsSize = insert_nodes_to_nums(head, nums);
        int i;
        binary_insert(&root, nums, 0, numsSize);
    }
    return root;
}

void binary_insert(struct TreeNode **root, int *nums, int start, int end)
{
    int mid;
    if ( start < end )
    {
        mid = (start + end) / 2;
        *root = insert_TreeNode((*root), nums[mid]);
        binary_insert(root, nums, start, mid);
        binary_insert(root, nums, mid+1, end);
    }
}

int insert_nodes_to_nums(struct ListNode *head, int *nums)
{
    int count = 0;
    while (NULL != head)
    {
        nums[count++] = head->val;
        head = head->next;
    }
    return count;
}

struct TreeNode *insert_TreeNode(struct TreeNode *root, int val)
{
    if (NULL != root)
    {
        if (val == root->val)
        {
            return root;
        }

        if (val < root->val)
        {
            root->left = insert_TreeNode(root->left, val);
        }

        if (val > root->val)
        {
            root->right = insert_TreeNode(root->right, val);
        }
    }
    else
    {
        root = get_TreeNode(val);
        return root;
    }
    return root;
}

struct TreeNode *get_TreeNode(int val)
{
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node -> val = val;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}


////////////////////////////////////////////////////////////////////////////////////////

struct ListNode *get_listnode(int val);
struct ListNode *insert_listnode(struct ListNode *head, int val);
int print_list(struct ListNode *head, int count);
void print_array(int *nums, int start, int end);

void inorder(struct TreeNode *root);
void preorder(struct TreeNode *root);
void postorder(struct TreeNode *root);

int main(int argc, char const *argv[])
{
    int nums[] = {-10,-3,0,5,9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i;
    struct ListNode *head = NULL;
    for (i=0; i<numsSize; i++)
    {
        head = insert_listnode(head, nums[i]);
    }

    int count = print_list(head, 0);
    printf("Total [ %d ] Nodes \n", count);

    struct TreeNode *root = NULL;
    root = sortedListToBST(head);

    printf("<--- Pre Order -->\n");
    preorder(root);

    printf("\n<--- In Order -->\n");
    inorder(root);
    
    return EXIT_SUCCESS;
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

struct ListNode *insert_listnode(struct ListNode *head, int val)
{
    if (NULL != head)
    {
        head->next = insert_listnode(head->next, val);
    }
    else
    {
        head = get_listnode(val);
        return head;
    }
    return head;
}

struct ListNode *get_listnode(int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

int print_list(struct ListNode *head, int count)
{
    if (NULL != head)
    {
        printf("L [ %d ] ---> %d \n", count, head->val);
        count = print_list(head->next, count + 1);
    }
    return count;
}

void print_array(int *nums, int start, int end)
{
    int i;
    printf("[ ");
    for (i=start; i<=end; i++)
    {
        printf("%d", nums[i]);
        if (i < end)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}


/*

109. Convert Sorted List to Binary Search Tree
Medium

Given the head of a singly linked list where elements are sorted in ascending order,
convert it to a height-balanced binary search tree.

Example 1:

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []

Constraints:
The number of nodes in head is in the range [0, 2 * 10^4].
-10^5 <= Node.val <= 10^5

*/