#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int count_nodes(struct ListNode *head, struct ListNode **tail)
{
    int count = 0;
    while (NULL != head)
    {
        count ++;
        *tail = head;
        head = head->next;
    }
    
    return count;
}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode *pin_tail = NULL;
    int listSize = count_nodes(head, &pin_tail);

    if (listSize == 0)
    {
        return head;
    }

    k %= listSize;
    
    if (k != 0)
    {
        int i;
        struct ListNode *pin_old_head = head;
        struct ListNode *pin_new_head = head;
        struct ListNode *pin_cut = head;
        for (i=0; i<listSize-k; i++ )
        {
            pin_cut = pin_new_head;
            pin_new_head = pin_new_head->next;
        }
        pin_cut->next = NULL;
        pin_tail->next = pin_old_head;
        head = pin_new_head;
    }

    return head;
}

struct ListNode *get_node(int val);
struct ListNode *insert(struct ListNode *head, int val);
int print_list(struct ListNode *head, int count);
struct ListNode *merge_list(struct ListNode *list_left, struct ListNode *list_right);

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3,4,5};
    // int nums[] = {0, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i;
    int k = 2;
    struct ListNode *head = NULL;
    for (i=0; i<numsSize; i++)
    {
        head = insert(head, nums[i]);
    }

    int count = print_list(head, 0);
    printf("Total [ %d ] Nodes \n", count);

    head = rotateRight(head, k);

    count = print_list(head, 0);
    printf("Total [ %d ] Nodes \n", count);


    return EXIT_SUCCESS;
}

struct ListNode *merge_list(struct ListNode *list_left, struct ListNode *list_right)
{
    if (list_left == NULL)
    {
        return list_right;
    }

    if (list_right == NULL)
    {
        return list_left;
    }

    if (list_left->val <= list_right->val)
    {
        list_left->next = merge_list(list_left->next, list_right);
        return list_left;
    }
    else
    {
        list_right->next = merge_list(list_right->next, list_left);
        return list_right;
    }
}


struct ListNode *insert(struct ListNode *head, int val)
{
    if (NULL != head)
    {
        head->next = insert(head->next, val);
    }
    else
    {
        head = get_node(val);
        return head;
    }
    return head;
}

struct ListNode *get_node(int val)
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


/*

61. Rotate List
Medium

Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100

0 <= k <= 2 * 10^9

*/
