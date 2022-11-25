#include<stdlib.h>
#include<stdio.h>


struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head)
{
    if (NULL == head->next)
    {
        return NULL;
    }
    
    struct ListNode *mid = head;
    struct ListNode *tail = head;
    struct ListNode *cut = mid;
    
    while (NULL != tail && NULL != tail->next)
    {
        cut = mid;
        mid = mid->next;
        tail = tail->next->next;
    }
    cut->next = mid->next;
    return head;
}

int print_list(struct ListNode *head, int count);
struct ListNode * insert(struct ListNode *head, int val);
struct ListNode *get_node(int val);

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3,4,5,6};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = NULL;
    int i, rc;

    for (i=0; i<nums_size; i++)
    {
        head = insert(head, nums[i]);
    }

    rc = print_list(head, 0);
    printf(" Total [ %d ] nodes\n\n", rc);

    head = deleteMiddle(head);    
    printf("After Delete Middle:\n");
    rc = print_list(head, 0);
    printf(" Total [ %d ] nodes\n\n", rc);

    return EXIT_SUCCESS;
}

struct ListNode *get_node(int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;
}

struct ListNode * insert(struct ListNode *head, int val)
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

int print_list(struct ListNode *head, int count)
{
    if (NULL != head)
    {
        if (NULL == head->next)
        {
            printf("[ (%d):%d ]-->NULL\n", count, head->val );
            count = print_list(head->next, count+1);
        }
        else
        {
            printf("[ (%d):%d ]-->", count, head->val );
            count = print_list(head->next, count+1);
        }
    }
    return count;
}



/*

2095. Delete the Middle Node of a Linked List
Medium

You are given the head of a linked list.
Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node
from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 105

*/