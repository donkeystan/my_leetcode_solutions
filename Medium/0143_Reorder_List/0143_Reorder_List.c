#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int print_list(struct ListNode *head, int count);

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

    list1->next = merge_lists(list2, list1->next);
    return list1;
}

struct ListNode *reverse_list(struct ListNode *head)
{
    if (NULL == head || NULL == head->next)
    {
        return head;
    }
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    while (NULL != curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reorderList(struct ListNode* head)
{
    if (NULL == head || NULL == head->next)
    {
        return;
    }

    struct ListNode *mid = head;
    struct ListNode *cut = head;
    struct ListNode *tail = head;

    while (NULL != tail && NULL != tail->next)
    {
        cut = mid;
        mid = mid->next;
        tail = tail->next->next;
    }
    cut->next = NULL;
    mid = reverse_list(mid);
    head = merge_lists(head, mid);
}

struct ListNode *insert(struct ListNode *head, int val);
struct ListNode *get_node(int val);


int main(int argc, char const *argv[])
{
    int nums[] = {1, 2, 3, 4, 5};
    // int nums[] = {1, 2, 3, 4};
    // int nums[] = {1, 2, 3};
    // int nums[] = {1, 2};
    // int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = NULL;
    int i;
    for (i=0; i<numsSize; i++)
    {
        head = insert(head, nums[i]);
    }

    printf("<----- On Create ---->\n");
    int count = print_list(head, 0);
    printf("\n Total [ %d ] Nodes\n\n", count);

    reorderList(head);

    printf("<----- On ReOrder ---->\n");
    count = print_list(head, 0);
    printf("\n Total [ %d ] Nodes\n\n", count);

    return EXIT_SUCCESS;
}

struct ListNode *insert(struct ListNode *head, int val)
{
    if (NULL == head)
    {
        head = get_node(val);
        return head;
    }
    struct ListNode *ptr = head;
    while (NULL != ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = get_node(val);
    return head;
}


struct ListNode *get_node(int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node -> val = val;
    new_node -> next = NULL;
    return new_node;
}

int print_list(struct ListNode *head, int count)
{
    while (NULL != head)
    {
        if (NULL == head->next)
        {
            printf("[ (%d): %d ]-->NULL\n", count, head->val );    
            head = head->next;
            count ++;
        }
        else
        {
            printf("[ (%d): %d ]-->", count, head->val );
            head = head->next;
            count ++;
        }
    }
    return count;
}

/*

143. Reorder List
Medium

Share
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:
The number of nodes in the list is in the range [1, 5 * 10^4].
1 <= Node.val <= 1000

*/