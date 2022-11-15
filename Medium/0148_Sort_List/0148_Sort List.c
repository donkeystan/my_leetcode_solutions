#include<stdlib.h>
#include<stdio.h>
#define NEWLINE printf("\n");

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *merge_lists(struct ListNode *list1, struct ListNode *list2)
{
    if (NULL == list1)
    {
        return list2;
    }

    if (NULL == list2)
    {
        return list1;
    }

    if (list1->val <= list2->val)
    {
        list1->next = merge_lists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = merge_lists(list2->next, list1);
        return list2;
    }
}

struct ListNode* sortList(struct ListNode* head)
{
    if ( NULL == head )
    {
        return NULL;
    }

    if ( NULL == head->next )
    {
        return head;
    }
    
    struct ListNode *mid = head;
    struct ListNode *pin = head;
    struct ListNode *tail = head;

    while (NULL != tail && NULL != tail->next)
    {
        pin = mid;
        mid = mid->next;
        tail = tail->next->next;
    }
    pin->next = NULL;
    return merge_lists(sortList(head), sortList(mid));
}

/*

6 5 4 3 2 1 

*/


int print_list(struct ListNode *head, int count);
struct ListNode * insert(struct ListNode *head, int val);
struct ListNode *get_node(int val);

int main(int argc, char const *argv[])
{
    int nums[] = { 6, 5, 4, 3, 2, 1 };
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = NULL;
    int i, rc;

    for (i=0; i<nums_size; i++)
    {
        head = insert(head, nums[i]);
    }

    rc = print_list(head, 0);
    printf("Total [ %d ] nodes\n", rc);
    NEWLINE

    head = sortList(head);
    printf("After Sort:\n");
    print_list(head, 0);
    NEWLINE

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
        printf("L[ %d ] --> %d\n", count, head->val);
        count = print_list(head->next, count + 1);
    }
    return count;
}

/*

148. Sort List
Medium
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []
 
Constraints:
The number of nodes in the list is in the range [0, 5 * 10^4].
-10^5 <= Node.val <= 10^5

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

*/



/* TLE

#define SIZE 50000
int divide_nodes(struct ListNode *head, struct ListNode **nodes);

struct ListNode *merge(struct ListNode *list1, struct ListNode *list2);
struct ListNode *merge_lists(struct ListNode *list1, struct ListNode *list2);
struct ListNode *get_node(int val);

struct ListNode* sortList(struct ListNode* head)
{
    struct ListNode *nodes[SIZE] = {NULL};
    int listsSize = divide_nodes(head, nodes);

    head = NULL;
    int i;

    for (i=0; i<listsSize-1; i++)
    {
        head = merge_lists(nodes[i], nodes[i+1]);
        nodes[i+1] = head;   
    }

    return head;
}

struct ListNode *merge_lists(struct ListNode *list1, struct ListNode *list2)
{
    if (NULL == list1)
    {
        return list2;
    }

    if (NULL == list2)
    {
        return list1;
    }

    if (list1->val <= list2->val)
    {
        list1->next = merge_lists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = merge_lists(list2->next, list1);
        return list2;
    }
}

int divide_nodes(struct ListNode *head, struct ListNode **nodes)
{
    int count = 0;
    struct ListNode *pin = NULL;
    while (NULL != head)
    {
        pin = head;
        nodes[count] = pin;
        head = head->next;
        nodes[count]->next = NULL;
        count ++;
    }
    return count;
}

struct ListNode *merge(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *head_of_merged = NULL;
    struct ListNode *pinResult = NULL;
    struct ListNode *pin1 = NULL;
    struct ListNode *pin2 = NULL;

    pinResult = get_node(0);
    head_of_merged = pinResult;

    while ( (NULL != list1) && (NULL != list2) )
    {
        if (list1->val <= list2->val)
        {
            pin1 = list1;
            list1 = list1->next;
            pinResult->next = pin1;
            pinResult = pinResult->next;
        }
        else
        {
            pin2 = list2;
            list2 = list2->next;
            pinResult->next = pin2;
            pinResult = pinResult->next;
        }
    }

    while (NULL != list1)
    {
        pin1 = list1;
        list1 = list1->next;
        pinResult->next = pin1;
        pinResult = pinResult->next;
    }

    while (NULL != list2)
    {
        pin2 = list2;
        list2 = list2->next;
        pinResult->next = pin2;
        pinResult = pinResult->next;
    }

    head_of_merged = head_of_merged->next;
    return head_of_merged;
}

struct ListNode *get_node(int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;
}



*/