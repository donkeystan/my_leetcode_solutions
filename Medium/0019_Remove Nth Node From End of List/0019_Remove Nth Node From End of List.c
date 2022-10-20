#include<stdlib.h>
#include<stdio.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode *insert(struct ListNode *head, int val);
struct ListNode *get_node(int val);
int print_list(struct ListNode *head, int count);

int getListSize(struct ListNode *head);

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int count = getListSize(head);
    int pos = count - n;
    
    if (NULL != head)
    {
        struct ListNode *ptr = head;
        struct ListNode *prev = NULL;
        int i = 0;

        if (pos > 0)
        {
            while (i != pos)
            {
                prev = ptr;
                ptr = ptr->next;
                i ++;
            }
            prev->next = ptr->next;
            free(ptr);
        }
        else
        {
            ptr = ptr->next;
            free(head);
            head = ptr;
        }
    }
    return head;
}

int getListSize(struct ListNode *head)
{
    int count = 0;
    if (NULL != head)
    {
        while (NULL != head)
        {
            head = head->next;
            count ++;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    int pos = 2;
    int i;
    int rc;
    struct ListNode *head = NULL;

    for (i=0; i<nums_size; i++)
    {
        head = insert(head, nums[i]);
    }

    printf("Before removal of nth node :\n");
    rc = print_list(head, 0);
    printf("Count [ %d ] Nodes \n\n", rc);

    head = removeNthFromEnd(head, pos);

    printf("\n");
    printf("After removal of nth node :\n");
    rc = print_list(head, 0);
    printf("Count [ %d ] Nodes \n\n", rc);

    return EXIT_SUCCESS;
}


int print_list(struct ListNode *head, int count)
{
    if (NULL != head)
    {
        printf("L[ %d ] : %d\n", count, head->val);
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
        head = get_node(val);
        return head;
    }
    return head;
}

struct ListNode *get_node(int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node -> next = NULL;
    new_node -> val = val;
    return new_node;
}


/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

*/