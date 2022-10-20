#include<stdlib.h>
#include<stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int print_list(struct ListNode *head, int count);
struct ListNode *get_node(int val);
struct ListNode *insert(struct ListNode *head, int val);


struct ListNode *get_node_addr(struct ListNode *head, int pos);

struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    int count;
    int i;
    if (NULL != head)
    {
        if (left <= 1)
        {
            struct ListNode *curr = head;
            struct ListNode *dragger = get_node_addr(head, right);
            struct ListNode *stop = dragger->next;
            dragger = stop;
            struct ListNode *mover = NULL;
            
            while (curr != stop)
            {
                mover = curr->next;
                curr->next = dragger;
                dragger = curr;
                curr = mover;
            }
            head = dragger;
        }
        else
        {
            struct ListNode *pin_joint = head;
            int pin_pos = left - 1;
            for (i=1; i<pin_pos; i++)
            {
                pin_joint = pin_joint->next;
            }
            struct ListNode *curr = pin_joint -> next;
            struct ListNode *dragger = get_node_addr(head, right);
            struct ListNode *stop = dragger->next;
            dragger = stop;
            struct ListNode *mover = NULL;
            
            while (curr != stop)
            {
                mover = curr->next;
                curr->next = dragger;
                dragger = curr;
                curr = mover;
            }
            pin_joint->next = dragger;
            head = head;
        }
    }    
    return head;
}

struct ListNode *get_node_addr(struct ListNode *head, int pos)
{
    if (NULL != head)
    {
        int count = 1;
        while (NULL != head && pos != count )
        {
            head = head->next;
            count ++;
        }
    }
    return head;
}


int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    // int nums[] = {1,2};
    int nums_sizes = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = NULL;
    int i;
    
    printf("Before Creation: \n");
    print_list(head, 0);
    printf("<------------------------------>\n\n");

    for (i=0; i<nums_sizes; i++)
    {
        head = insert(head, nums[i]);
    }

    int rc = 0;
    printf("\nAfter Creation: \n");
    rc = print_list(head, 1);
    printf("<---------------Print [ %d ] Nodes--------------->\n\n", rc-1);

    int left = 6;
    int right = 8;
    head = reverseBetween(head, left, right);

    printf("\nAfter ReverseBetween: [%d to %d ]\n", left, right);
    rc = print_list(head, 1);
    printf("<---------------Print [ %d ] Nodes--------------->\n\n", rc-1);



    return EXIT_SUCCESS;
}


int print_list(struct ListNode *head, int count)
{
    if (NULL != head)
    {
        printf("L[ %d ] ---> %d\n",count, head->val);
        count = print_list(head->next, count+1);
    }
    return count;
}


struct ListNode *insert(struct ListNode *head, int val)
{
    if (NULL != head)
    {
        head->next = insert(head->next, val);
    }
    else
    {
        printf("Node [ %d ] created.\n", val);
        head = get_node(val);
        return head;
    }
    return head;
}


struct ListNode *get_node(int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;
}

/*
92. Reverse Linked List II
Medium

Share
Given the head of a singly linked list and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

*/