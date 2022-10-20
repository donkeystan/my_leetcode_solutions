#include<stdlib.h>
#include<stdio.h>
#define NEWLINE printf("\n");

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

int print_list(struct ListNode *head);
struct ListNode *create_node(int);
struct ListNode *create_list(struct ListNode *head, int value);

struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *result_list = NULL;
    printf("List 1:\n");
    print_list(l1);
    NEWLINE
    printf("List 1:\n");
    print_list(l2);
    NEWLINE

    struct ListNode *ptr_l1 = l1;
    struct ListNode *ptr_l2 = l2;
    
    int nums_l1 = 0;
    int nums_l2 = 0;
    int tmp_sum = 0;
    int curr_num_to_save = 0;
    int carry = 0;
    int i = 0;

    while (NULL != ptr_l1  ||  NULL != ptr_l2 || 1 == carry)
    {
        tmp_sum = 0;
        nums_l1 = 0;
        nums_l2 = 0;

        if (NULL != ptr_l1)
        {
            nums_l1 = ptr_l1->val;
        }
        else
        {
            nums_l1 = 0;
        }

        
        if (NULL != ptr_l2)
        {
            nums_l2 = ptr_l2->val;
        }
        else
        {
            nums_l2 = 0;
        }


        tmp_sum = nums_l1 + nums_l2 + carry;
    

        if (tmp_sum > 9)
        {   
            carry = 1;
            curr_num_to_save = tmp_sum % 10;
        }
        else
        {
            carry = 0;
            curr_num_to_save = tmp_sum;
        }

        result_list = create_list(result_list, curr_num_to_save);

        if (NULL != ptr_l1)
        {
            ptr_l1 = ptr_l1->next;
        }
        
        if (NULL != ptr_l2)
        {
            ptr_l2 = ptr_l2->next;
        }
    }
    
    return result_list;
}


int main(int argc, char const *argv[])
{
    
    int nums_l1[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    int nums_l2[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

    int l1_nums_size = sizeof(nums_l1) / sizeof(nums_l1[0]);
    int l2_nums_size = sizeof(nums_l2) / sizeof(nums_l2[0]);

    int i;

    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode *result = NULL;


    for (i=0; i<l1_nums_size; i++)
    {
        l1 = create_list(l1, nums_l1[i]);
    }

    for (i=0; i<l2_nums_size; i++)
    {
        l2 = create_list(l2, nums_l2[i]);
    }

    result = addTwoNumbers(l1, l2);

    printf("Result :\n");
    print_list(result);

    return EXIT_SUCCESS;
}


struct ListNode *create_node(int value)
{
    struct ListNode *new_node = (struct ListNode *) malloc(sizeof(struct ListNode));
    new_node->val = value;
    new_node->next = NULL;
    return new_node;
}

struct ListNode *create_list(struct ListNode *head, int value)
{
    struct ListNode *ptr = NULL;

    if (NULL == head)
    {
        ptr = create_node(value);
        head = ptr;
    }
    else
    {
        ptr = head;

        while (NULL != ptr->next)
        {
            ptr = ptr->next;
        }

        ptr->next = create_node(value);
    }

    return head;
}

int print_list(struct ListNode *head)
{
    int count = 0;
    struct ListNode *ptr;

    if (head == NULL)
    {
        printf("List is empty...\n");
    }
    else
    {
        ptr = head;
            
        while (ptr != NULL)
        {
            if (ptr != NULL)
            {
                printf("Node [%d] : %d\n", count, ptr->val);
                count ++;
            }
            ptr = (struct ListNode *)ptr->next;
        }
    }
    return count;
}



/*
2. Add Two Numbers
Medium

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

*/
