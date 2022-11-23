#include<stdio.h>
#include<stdlib.h>
#define NEWLINE printf("\n");

struct ListNode
{
    int val;
    struct ListNode *next;
};

int print_list(struct ListNode *head, int count);
struct ListNode *get_node(int val);
struct ListNode *insert(struct ListNode *head, int val);
struct ListNode *make_list(struct ListNode *head, int *nums, int numsSize);
struct ListNode *reverse_list(struct ListNode *head);
struct ListNode *update(struct ListNode *head, int pos, int val);
struct ListNode *delete(struct ListNode *head, int pos);
struct ListNode *merge_sort(struct ListNode *head);
struct ListNode *merge(struct ListNode *list1, struct ListNode *list2);


struct ListNode *merge_odd_even(struct ListNode *odd, struct ListNode *even, int count)
{
    struct ListNode *odd_ptr = odd;
    struct ListNode *even_ptr = even;
    struct ListNode *next_node = even->next;

    while (NULL != next_node)
    {
        if (0 != count%2)
        {
            next_node = even_ptr->next;
            odd_ptr->next = next_node;
            if (NULL != odd_ptr->next)
            {
                odd_ptr = odd_ptr->next;
            }
            count ++;
        }
        else
        {
            next_node = odd_ptr->next;
            even_ptr->next = next_node;
            even_ptr = even_ptr->next;
            count ++;
        }
    }
    odd_ptr->next = even;
    return odd;
}

struct ListNode* oddEvenList(struct ListNode* head)
{
    if (NULL == head || NULL == head->next)
    {
        return head;
    }

    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    head = merge_odd_even(odd, even, 1);
    return head;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {1};
    // int nums[] = {1,2};
    // int nums[] = {1,2,3};
    // int nums[] = {1,2,3,4};
    int nums[] = {1,2,3,4,5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = NULL;
    head = make_list(head, nums, numsSize);
    printf("<--- Creation --->\n");
    int rc = print_list(head, 0);
    printf("<--- Total [ %d ] Nodes --->\n", rc);
    NEWLINE

    printf("<--- OddEven --->\n");
    head = oddEvenList(head);
    print_list(head, 0);


    return EXIT_SUCCESS;
}

struct ListNode *merge(struct ListNode *l1, struct ListNode *l2)
{
    if (NULL == l1)
    {
        return l2;
    }

    if (NULL == l2)
    {
        return l1;
    }

    if (l1->val <= l2->val)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l2->next, l1);
        return l2;
    }
}

struct ListNode *merge_sort(struct ListNode *head)
{
    if (NULL == head || NULL == head->next)
    {
        return head;
    }

    struct ListNode *mid = head;
    struct ListNode *cut = head;
    struct ListNode *tail = head;

    while (NULL != tail && NULL != tail->next)
    {
        cut = mid;
        mid = mid->next;
        tail = tail->next;
    }
    cut->next = NULL;
    return merge(merge_sort(head), merge_sort(mid));
}

struct ListNode *reverse_list(struct ListNode *head)
{
    if (NULL != head)
    {
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
        head = prev;
    }
    return head;
}

struct ListNode *delete(struct ListNode *head, int pos)
{
    if (NULL == head)
    {
        return head;
    }

    if (NULL == head->next)
    {
        free(head);
        return NULL;
    }

    if (pos <= 0)
    {
        struct ListNode *curr = head;
        head = head->next;
        free(curr);
        return head;
    }

    struct ListNode *curr = head;
    struct ListNode *prev = head;
    
    while (NULL != curr->next && pos != 0)
    {
        prev = curr;
        curr = curr->next;
        pos --;
    }
    prev->next = curr->next;
    free(curr);
    return head;
}

struct ListNode *update(struct ListNode *head, int pos, int val)
{
    if (NULL == head || pos <= 0)
    {
        struct ListNode *new_node = get_node(val);
        new_node->next = head;
        return new_node;
    }

    struct ListNode *curr = head;
    struct ListNode *prev = head;

    while (NULL != curr && pos != 0)
    {
        prev = curr;
        curr = curr->next;
        pos --;
    }
    prev->next = get_node(val);
    prev->next->next = curr;
    return head;
}

struct ListNode *make_list(struct ListNode *head, int *nums, int numsSize)
{
    int i;
    for (i=0; i<numsSize; i++)
    {
        head = insert(head, nums[i]);
    }
    return head;
}

// int print_list(struct ListNode *head, int count)
// {
//     if (NULL != head)
//     {
//         printf("L [ %d ] ---> %d \n", count, head->val);
//         count = print_list(head->next, count+1);
//     }
//     return count;
// }

int print_list(struct ListNode *head, int count)
{
    while (NULL != head)
    {
        printf("L [ %d ] ---> %d \n", count++, head->val);
        head= head->next;
    }
    return count;
}

struct ListNode *get_node(int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

// struct ListNode *insert(struct ListNode *head, int val)
// {
//     if (NULL != head)
//     {
//         head->next = insert(head->next, val);
//     }
//     else
//     {
//         head = get_node(val);
//         return head;
//     }
//     return head;
// }

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

/*

328. Odd Even Linked List
Medium

Given the head of a singly linked list,
group all the nodes with odd indices together followed by the nodes with even indices,
and return the reordered list.

The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

Constraints:
The number of nodes in the linked list is in the range [0, 10^4].
-10^6 <= Node.val <= 10^6

*/

