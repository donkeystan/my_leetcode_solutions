#include<stdio.h>
#include<stdlib.h>

#define NEWLINE printf("\n");

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode *create_node(int value);
struct ListNode *create_list(struct ListNode *head, int value);
void print_list(struct ListNode *head);

struct ListNode *reverse_group(struct ListNode *head, int k,  struct ListNode **tail_recorder);
struct ListNode *get_head(struct ListNode *head, int k);
struct ListNode *get_new_group_head(struct ListNode *group_head, int k);

/*
    // k = 2
    //
    // step = 1
    // 
    // traverse process k steps a cycle
    // h = 2
    //       p
    //       g
    //
    // 1  2  3  4
    //
    // t[  ]->next = [  ]
*/

struct ListNode *reverseKGroup(struct ListNode* head, int k)
{
    int step;

    if ( NULL != head )
    {
        struct ListNode *ptr = head;
        struct ListNode *group_head = ptr;
        struct ListNode *tail = NULL;
    
        head = get_head(head, k);

        printf("head at [%d]\n", head->val);

        step = 0;

        while (NULL != ptr)
        {
            ptr = ptr->next;
            step++;

            if ( (NULL != ptr) && (step == k-1) )
            {
                ptr = ptr->next;
                group_head = reverse_group(group_head, k, &tail);

                printf("Received tail at: [ %p ] ---> get node[ %d ] \n", tail, tail->val);

                group_head = ptr;
                tail->next = get_new_group_head(group_head, k);

                printf("tail->next received ---> [ %p ]\n", tail->next);

                NEWLINE

                step = 0;
            }
        }
    }

    return head;
}


int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    int k = 4;
    int i;
    struct ListNode *head = NULL;

    for (i=0; i<nums_size; i++)
    {
        head = create_list(head, nums[i]);
    }

    print_list(head);
    NEWLINE

    head = reverseKGroup(head, k);

    printf("\nAfter Reverse K Group\n");
    print_list(head);
    NEWLINE

    return EXIT_SUCCESS;
}

struct ListNode *reverse_group(struct ListNode *head, int k, struct ListNode **tail)
{

    if (NULL != head)
    {
        struct ListNode *current_head = head;
        struct ListNode *pin_tail = head;

        struct ListNode *dragger = NULL;
        struct ListNode *mover = NULL;

        int i;

        for (i=0; i<k; i++)
        {
            mover = current_head->next;
            current_head->next = dragger;
            dragger = current_head;
            current_head = mover;
        }

        *tail = pin_tail;
        head = dragger;
        
        printf("Reverse Complete: \n");
        printf("head at [%p] ---> [%d] \n", head, head->val);
        printf("tail at [%p] ---> [%d] \n", pin_tail, pin_tail->val);
    }

    return head;
}




struct ListNode *get_head(struct ListNode *ptr, int k)
{
    int i;
    int loop_size = k - 1;
    for (i=0; i<k-1; i++)
    {
        ptr = ptr->next;
    }
    return ptr;
}

struct ListNode *get_new_group_head(struct ListNode *group_head, int k)
{
    printf("Get new group head :\n");

    struct ListNode *new_group_head = NULL;

    if (NULL != group_head)
    {
        int i;
        new_group_head = group_head;

        for (i=0; i<k-1; i++)
        {
            new_group_head = (struct ListNode *)new_group_head->next;

            if (NULL == new_group_head)
            {
                printf(" ( NULL == new_group_head) return group_head ---> [ %p ] : [ %d ] \n", group_head, group_head->val);
                
                return group_head;
            }
        }
    }
    else
    {
        printf(" (NULL == group_head) return group_head ---> [ %p ] : [ %d ] \n", group_head, group_head->val);
        return group_head;
    }

    printf(" return new_group_head ---> [ %p ] : [ %d ]\n", new_group_head, new_group_head->val);
    return new_group_head;
}

struct ListNode *create_list(struct ListNode *head, int value)
{
    if (head != NULL)
    {
        struct ListNode *ptr = head;

        while (NULL != ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = create_node(value);
    }
    else
    {
        head = create_node(value);
    }
    return head;
}

struct ListNode *create_node(int value)
{
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = value;
    new_node->next = NULL;
}

void print_list(struct ListNode *head)
{
    int count = 0;

    if (head != NULL)
    {
        while (NULL != head)
        {
            if (NULL != head)
            {
                printf("Node[%d] ---> [ %d ]\n", count, head->val);
            }
            count ++;
            head = head->next;
        }
    }
    else
    {
        printf("List is empty...\n");
    }
}



/*

25. Reverse Nodes in k-Group
Hard

Given the head of a linked list,
reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

Follow-up: Can you solve the problem in O(1) extra memory space?

*/

/*

*/