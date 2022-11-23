#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *get_node(int val);
struct TreeNode *insert(struct TreeNode *root, int val);

void preorder(struct TreeNode *root);
void inorder(struct TreeNode *root);
void postorder(struct TreeNode *root);

void operation(struct TreeNode *root, struct TreeNode **temp_head)
{
    if (root == NULL)
    {
        return;
    }
    operation(root->right, temp_head);
    operation(root->left, temp_head);
    root->left = NULL;
    root->right = (*temp_head);
    (*temp_head) = root;
}

void flatten(struct TreeNode* root)
{
    struct TreeNode *temp_head = NULL;
    operation(root, &temp_head);
}

/*

    1
  2    5
3  4     6

Solution:
1. DFS traversal to the deepest right 
2. once get the deepest bottom right node, set its left to NULL, and then set its right to the temp_head(by default, NULL)
3. then assign current node to temp_head for recursion caller 
4. we will get a flatten tree after the recursion is done

*/

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,5,3,4,6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i;
    struct TreeNode *root = NULL;
    for (i=0; i<numsSize; i++)
    {
        root = insert(root, nums[i]);
    }

    printf("<----- Pre Order ----->\n");
    preorder(root);


    printf("\n<----- In Order ----->\n");
    inorder(root);

    printf("\n<----- Post Order ----->\n");
    postorder(root);

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


struct TreeNode *get_node(int val)
{
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(val));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct TreeNode *insert(struct TreeNode *root, int val)
{
    if (NULL != root)
    {
        if (val == root->val)
        {
            return root;
        }

        if (val < root->val)
        {
            root->left = insert(root->left, val);
        }

        if (val > root->val)
        {
            root->right = insert(root->right, val);
        }
    }
    else
    {
        root = get_node(val);
        return root;
    }
    return root;
}


/*

114. Flatten Binary Tree to Linked List
Medium

Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class
where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

Follow up: Can you flatten the tree in-place (with O(1) extra space)?

*/