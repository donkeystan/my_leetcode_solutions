#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create_node(int);
struct TreeNode *insertNode(struct TreeNode*, int);
void print_inorder(struct TreeNode *root);
void print_postorder(struct TreeNode *root);
void print_preorder(struct TreeNode *root);

/*
     4
    / \
   2   7
  / \
 1  3
*/

struct TreeNode* searchBST(struct TreeNode* root, int val)
{
    struct TreeNode *ptr = root;
    if( ptr == NULL )                                     // base condition: if found nothing smaller or larger than current node
    {                                      
        printf("ptr->val == NULL, return NULL\n");
        ptr = NULL;
        return ptr;
    }

    if( ptr->val == val )                                // if current node's value is equal to search value, returns its pointer
    {
        printf("ptr->val--->%d   ==   val--->%d\n",ptr->val, val);
        return ptr;
    }
    
    if( val > ptr->val )                                // going to recursive if val is larger than current node
    {
        printf("val--->%d  >  ptr->val--->%d\n", val, ptr->val);
        ptr = searchBST(ptr->right, val);               // pass the right pointer if we look for larger number
    }
    else                                                // likewise, we do the same if in invert condition.
    {
        printf("val--->%d  <  ptr->val--->%d\n", val, ptr->val);
        ptr = searchBST(ptr->left, val);
    }
    return ptr;
}


int main(int argc, char *argv[])
{
    int numList[] = {4,2,7,1,3,5,8,9,10};
    int numsSize = sizeof(numList) / sizeof(numList[0]);
    int i;
    printf("numsSize ---> %d\n",numsSize);

    struct TreeNode * root = NULL;

    for(i=0; i<numsSize; i++)
    {
        root = insertNode(root, numList[i]);
    }

    printf("<--- In Order --->\n");
    print_inorder(root);
    printf("\n<--- Post Order --->\n");
    print_postorder(root);    
    printf("\n<--- Pre Order --->\n");
    print_preorder(root);
    printf("\n");

    struct TreeNode *ptr = searchBST(root,7);
    
    printf("<--- In Order --->\n");
    print_inorder(ptr);
    printf("\n<--- Post Order --->\n");
    print_postorder(ptr);    
    printf("\n<--- Pre Order --->\n");
    print_preorder(ptr);
    printf("\n");

    return EXIT_SUCCESS;
}

void print_inorder(struct TreeNode *root)
{
    if(root != NULL)
    {
        print_inorder(root->left);
        printf("%d ",root->val);
        print_inorder(root->right);
    }
}

void print_postorder(struct TreeNode *root)
{
    if(root != NULL)
    {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ",root->val);
    }
}

void print_preorder(struct TreeNode *root)
{
    if(root != NULL)
    {
        printf("%d ",root->val);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}


struct TreeNode *insertNode(struct TreeNode *root, int val)
{
    if(root==NULL)
    {
        root = create_node(val);
        return root;
    }

    struct TreeNode *ptr = root;

    if(val == ptr->val)
    {
        return;
    }

    if(val > root->val )
    {
        root->right = insertNode(root->right, val);
    }
    else
    {
        root->left = insertNode(root->left, val);
    }
    return root;
}

struct TreeNode* create_node(int val)
{
    struct TreeNode * newNode = malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
}

/*
700. Search in a Binary Search Tree

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node.
If such a node does not exist, return null.


Example 1:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:
Input: root = [4,2,7,1,3], val = 5
Output: []

Constraints:
The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107

*/