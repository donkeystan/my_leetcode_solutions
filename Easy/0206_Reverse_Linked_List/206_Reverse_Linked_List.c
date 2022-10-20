#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode {
      int val;
     struct ListNode *next;
 };

struct ListNode *create_list(struct ListNode *, int);
struct ListNode *create_node(struct ListNode *, int);
void print_nodes(struct ListNode *);

struct ListNode* reverseList(struct ListNode* head)
{
    struct node* ptr1 = NULL;
    struct node* ptr2 = NULL;
    
    while(head != NULL)
    {
        ptr1 = head->next;  // move ptr1 to next node firs
        head->next = ptr2;  // ptr2 originally holds NULL, but later holds previous pos.
        ptr2 = head;        // ptr2 moves to where head was
        head = ptr1;        // head moves to ptr1
    }
    head = ptr2;            // when head reaches NULL, get out loop and take ptr2's pos  
    
    return head;
}

int main(int argv, char *argc[])
{
    int i;
    int nums[] = {1,2,3,4,5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    struct ListNode *ptr = NULL;
    struct ListNode *head = NULL;
    
    for (i=0; i<numsSize; i++)
    {
        head = create_list(head, nums[i]);
    }

    print_nodes(head);
    ptr = deleteDuplicates(head);
    printf("------------------The result after calling deleteDuplicates()-------------------\n");
    print_nodes(ptr);

    return EXIT_SUCCESS;
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
206. Reverse Linked List

Share
Given the head of a singly linked list,
reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
*/
