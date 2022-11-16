#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

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

struct ListNode* insertionSortList(struct ListNode* head)
{
    if ( head->next == NULL )
    {
        return head;
    }

    struct ListNode *pin_new_head_left = head;
    struct ListNode *pin_new_head_right = head;
    struct ListNode *pin_cut = head;
    pin_new_head_right = pin_new_head_right->next;
    pin_cut->next = NULL;

    while (NULL != pin_new_head_right)
    {    
        pin_cut = pin_new_head_right->next;
        pin_new_head_right->next = NULL;
        pin_new_head_left = merge_list(pin_new_head_left, pin_new_head_right);
        pin_new_head_right = pin_cut;
    }
    head = pin_new_head_left;

    return head;
}

struct ListNode *get_node(int val);
struct ListNode *insert(struct ListNode *head, int val);
int print_list(struct ListNode *head, int count);

int main(int argc, char const *argv[])
{
    int nums[] = {4, 2, 1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i;
    struct ListNode *head = NULL;
    for (i=0; i<numsSize; i++)
    {
        head = insert(head, nums[i]);
    }

    int count = print_list(head, 0);
    printf("Total [ %d ] Nodes \n", count);

    head = insertionSortList(head);

    count = print_list(head, 0);
    printf("Total [ %d ] Nodes \n", count);

    return EXIT_SUCCESS;
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

147. Insertion Sort List
Medium

Given the head of a singly linked list,
sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:
Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data,
finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm.
The partially sorted list (black) initially contains only the first element in the list.
One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Constraints:
The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000

*/