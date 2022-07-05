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

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* previous = NULL;
    struct ListNode* current = NULL;
    struct ListNode* freePtr = NULL;

    if ( head != NULL )
    {
        current = head;
        previous = current;
    }

    if ( current != NULL)
    {
        current= (struct ListNode*)current->next;
    }
    
    while (current != NULL)
    {

        if ( previous != NULL && current != NULL )
        {
            if (previous->val == current->val)
            {
                freePtr = current;

                current = (struct ListNode*)current->next;

                free(freePtr);
                freePtr = NULL;

                previous->next = current;

            }

            if ( previous != NULL && current != NULL )
            {
                if ( previous->val != current->val)
                {
                    previous = current;
                    current = (struct ListNode*)current->next;
                }    
            }
        }        
    }
    return head;
}


int main(int argv, char *argc[])
{
    int i;
    // int nums[] = {1,1,2,2};
    int nums[] = {-99, -96, -96, -95, -94, -93, -93, -93, -92, -92, -91, -91, -91, -91, -90, -89, -89, -89, -87, -86, -86, -86, -86, -85, -84, -83, -81, -81, -80, -80, -80, -79, -79, -79, -79, -78, -78, -78, -78, -76, -76, -75, -75, -75, -74, -74, -73, -73, -72, -72, -71, -71, -71, -70, -70, -70, -70, -69, -69, -68, -68, -68, -67, -67, -66, -66, -65, -64, -64, -62, -62, -61, -56, -56, -54, -54, -53, -53, -52, -49, -49, -48, -48, -48, -47, -46, -46, -44, -44, -43, -43, -43, -42, -41, -40, -40, -40, -38, -38, -38, -37, -37, -36, -36, -35, -35, -35, -35, -35, -35, -33, -32, -31, -31, -31, -31, -30, -28, -28, -27, -26, -26, -25, -24, -23, -23, -23, -21, -21, -20, -20, -19, -17, -17, -13, -13, -13, -12, -12, -10, -8, -8, -8, -8, -5, -4, -4, -4, -3, -3, -3, -2, -2, -2, -1, -1, -1, 0, 0, 2, 3, 5, 6, 6, 7, 7, 8, 9, 9, 10, 10, 12, 13, 15, 17, 17, 17, 17, 18, 18, 20, 21, 22, 23, 23, 23, 24, 25, 25, 25, 26, 27, 28, 29, 29, 29, 31, 31, 31, 32, 33, 34, 34, 36, 36, 36, 36, 37, 38, 40, 41, 41, 42, 45, 47, 47, 47, 48, 51, 52, 53, 53, 54, 55, 56, 58, 59, 60, 61, 61, 62, 62, 62, 63, 63, 63, 64, 64, 64, 64, 64, 64, 66, 67, 67, 68, 68, 70, 71, 72, 73, 73, 74, 74, 74, 74, 75, 76, 77, 78, 79, 80, 80, 80, 80, 81, 83, 83, 83, 85, 85, 85, 86, 86, 87, 87, 88, 88, 88, 88, 89, 90, 90, 90, 90, 90, 91, 91, 92, 94, 94, 95, 96, 96, 97, 97, 98, 99, 99, 99};
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

83. Remove Duplicates from Sorted List

Given the head of a sorted linked list,
delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100

The list is guaranteed to be sorted in ascending order.


*/

/*
// Attemp 1. Fail
    if (previous->val == current->val)
        {
            freePtr = current;
            current = (struct ListNode*)current->next;
            printf("current->next->val ---> [ %d ]\n",current->val);

            free(freePtr);
            freePtr = NULL;

            previous->next = current;
        }
        
        if (previous->val != current->val)
        {
            previous = current;
            if (current != NULL)
            {
                current = (struct ListNode*)current->next;
            }
        }        

*/