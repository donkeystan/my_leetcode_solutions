#include <stdio.h>
#include <stdlib.h>

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
    struct ListNoe *next;
};

struct ListNode *create_list(struct ListNode *, int);
struct ListNode *create_node(struct ListNode *, int);
void print_nodes(struct ListNode *);

struct ListNode *mergeNodes(struct ListNode *head)
{
    struct ListNode *ptr = NULL;
    struct ListNode *pin = NULL;
    struct ListNode *terminator = NULL;
    int tmp_sum;
    int count;

    if (head != NULL)
    {
        ptr = head;
        pin = head;
    }

    while (ptr->next != NULL)
    {
        if (0 == ptr->val)                                  // process to find val to merge and create new list to store
        {                                                  // must check if ptr->next is not null to prevent pin to become a NULL pointer
            ptr = (struct ListNode *)ptr->next;
            tmp_sum = 0;
            count = 0;
            while (1)
            {
                tmp_sum += ptr->val;
                if (ptr->next != NULL)
                {
                    ptr = (struct ListNode *)ptr->next;
                }
                
                if (0 == ptr->val)    // break point, save the merged val to list, move ptr to pin for traverse
                {
                    terminator = pin;
                    pin->val = tmp_sum;
                    if(pin->next != NULL)
                    {
                        pin = (struct ListNode *)pin->next;
                        count ++;
                    }
                    break;
                }
            }
        }
    }
    ptr = head;
    terminator->next = NULL;
    printf("pin---> %d\n",pin->val);
    printf("terminator---> %d\n",terminator->val);
    return ptr;
}


int main(int argv, char *argc[])
{
    int i;
    int nums[] = {0, 3, 1, 0, 4, 5, 2, 0, 9, 8, 7, 6, 0, 3, 4, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    struct ListNode *ptr = NULL;
    struct ListNode *head = NULL;
    
    for (i=0; i<numsSize; i++)
    {
        head = create_list(head, nums[i]);
    }

    print_nodes(head);
    ptr = mergeNodes(head);
    printf("------------------The result after calling mergeNode()-------------------\n");
    printf("address in ptr ---> [ %p ]\n", ptr);
    print_nodes(ptr);

    return EXIT_SUCCESS;
}

struct ListNode *rm_list(struct ListNode *head)
{
    struct ListNode *ptr = NULL;
    if (head != NULL)
    {
        head = (struct ListNode *)ptr;
    }
    else
    {
        printf("List is empty...\n");
        return head;
    }

    while ( ptr != NULL )
    {
        ptr = (struct ListNode *)ptr->next;
        free(head);
        head = ptr;
    }
    head = NULL;
    ptr = NULL;

    return head;
}

struct ListNode *create_list(struct ListNode *head, int num)
{
    struct ListNode *ptr = NULL;

    if (NULL == head)
    {
        ptr = create_node(ptr,num);
        head = ptr;
        return head;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = (struct ListNode *)ptr->next;
        }
        ptr->next = create_node(ptr,num);
    }
    return head;
}

struct ListNode *create_node(struct ListNode *head, int num)
{
    struct ListNode *ptr = NULL;
    ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = num;
    ptr->next = NULL;
    head = ptr;
    return head;
}

void print_nodes(struct ListNode *head)
{
    int i;
    if ( head != NULL )
    {
        struct ListNode *ptr = head;

        i = 0;
        while (ptr != NULL)
        {
            i++;
            printf("List %d is %d\n", i, ptr->val);
            ptr = (struct ListNode *)ptr->next;
        }
    }
    else
    {
        printf("List is empty...\n");
    }
}

/*
2181. Merge Nodes in Between Zeros

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

Example 1:
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation:
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

Example 2:
Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation:
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.

Constraints:
The number of nodes in the list is in the range [3, 2 * 105].
0 <= Node.val <= 1000
There are no two consecutive nodes with Node.val == 0.
The beginning and end of the linked list have Node.val == 0.

*/
