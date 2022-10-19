#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};


struct ListNode *get_node(int val);
struct ListNode *create_list(struct ListNode* head, int val);
struct ListNode *set_cycle(struct ListNode *head, int pos);
int print_list(struct ListNode *head, int i);

bool hasCycle(struct ListNode *head)
{
    int i;
    
    if (head != NULL)
    {
        struct ListNode *ptr = head;
        struct ListNode *pin = head;

        while (ptr != NULL)
        {
            if (pin->next == NULL || pin->next->next == NULL)
            {
                return 0;
            }
            pin = pin->next->next;
            ptr = ptr->next;
            if (pin == ptr)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int nums[] = { 3, 2, 0, -4 };
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    int i;
    struct ListNode *head = NULL;
    int pos = 1;
    int rc;

    printf("nums_size ---> %d \n", nums_size);

    for (i=0; i<nums_size; i++)
    {
        head = create_list(head, nums[i]);
    }
    print_list(head, 0);
    head = set_cycle(head, pos);

    rc = hasCycle(head);

    printf("return code ---> %d\n", rc);

    return EXIT_SUCCESS;
}

struct ListNode *set_cycle(struct ListNode *head, int pos)
{
    if (head != NULL)
    {
        struct ListNode *ptr = head;
        struct ListNode *pin = NULL;
        int i = 0;
        
        while (ptr->next != NULL)
        {
            if (pos == i)
            {
                pin = ptr;
            }
            ptr = ptr->next;
            i++;
        }
        ptr->next = pin;
    }
    return head;
}

int print_list(struct ListNode *head, int i)
{
    if (head != NULL)
    {
        printf("Node [ %d ] ---> %d\n",i , head->val );
        i = print_list(head->next, i+1);
    }
    printf("\n");
    return i;
}


struct ListNode *create_list(struct ListNode* head, int val)
{
    if (head == NULL)
    {
        head = get_node(val);
        return head;
    }
    else
    {
        head->next = create_list( head->next, val );
    }
    return head;
}

struct ListNode *get_node(int val)
{
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
}

/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Constraints:
The number of the nodes in the list is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.
 

*/