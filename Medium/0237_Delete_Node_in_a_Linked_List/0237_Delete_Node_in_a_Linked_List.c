#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int print_list(struct ListNode *head, int count);
struct ListNode *get_node(int val);
struct ListNode *insert(struct ListNode *head, int val);
struct ListNode *append_node(struct ListNode *head, struct ListNode **tail, int val);
struct ListNode *update(struct ListNode *head, int pos, int val);
struct ListNode *delete(struct ListNode *head, int pos);
struct ListNode *reverse_list(struct ListNode *head);
struct ListNode *merge_sort(struct ListNode *head);
struct ListNode *merge(struct ListNode *list1, struct ListNode *list2);
struct ListNode *grab_a_node(struct ListNode *head, int target);

void deleteNode(struct ListNode* node)
{
    struct ListNode *curr = node;
    struct ListNode *prev = curr;

    while (NULL != curr->next)
    {
        prev = curr;
        curr= curr->next;
        prev->val = curr->val;
    }
    prev->next = NULL;
}

int main(int argc, char const *argv[])
{
    int nums[] = {0,1,2,3,4,5,6,7,8,9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    struct ListNode *node = NULL;
    int i, count = 0, target = 6;
    for (i=0; i<numsSize; i++)
    {
        head = append_node(head, &tail, nums[i]);
    }

    printf("<----- On Create ---->\n");
    count = print_list(head, 0);
    printf("  Total [ %d ] Nodes \n\n", count);

    node = grab_a_node(head, target);
    printf("Node ---> %d \n", node->val);

    deleteNode(node);
    printf("<----- On Delete ---->\n");
    count = print_list(head, 0);
    printf("  Total [ %d ] Nodes \n\n", count);

    return EXIT_SUCCESS;
}

struct ListNode *grab_a_node(struct ListNode *head, int target)
{
    while (head != NULL)
    {
        if (target == head->val)
        {
            struct ListNode *node = head;
            return node;
        }
        head = head->next;
    }
    return NULL;
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
        tail = tail->next->next;
    }
    cut->next = NULL;
    return merge(merge_sort(head), merge_sort(mid));
}

struct ListNode *merge(struct ListNode *list1, struct ListNode *list2)
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
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = merge(list2->next, list1);
        return list2;
    }
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

    if (NULL == head->next || pos <= 0)
    {
        struct ListNode *__free = head;
        head = head->next;
        free(__free);
        return head;
    }

    struct ListNode *curr = head;
    struct ListNode *prev = curr;
    while (NULL != curr->next && 0 != pos)
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
    struct ListNode *prev = curr;
    while (NULL != curr && 0 != pos)
    {
        prev = curr;
        curr = curr->next;
        pos --;
    }
    prev->next = get_node(val);
    prev->next->next = curr;
    return head;
}

struct ListNode *append_node(struct ListNode *head, struct ListNode **tail, int val)
{
    if (NULL == head)
    {
        head = get_node(val);
        (*tail) = head;
        return head;
    }

    if (NULL != (*tail))
    {
        (*tail)->next = get_node(val);
        (*tail) = (*tail)->next;
        return head;
    }
    printf("Tail == NULL, Append Fail\n");
    return head;
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
    // if (NULL == head)
    // {
    //     head = get_node(val);
    //     return head;
    // }
    // struct ListNode *curr = head;
    // while (NULL != curr->next)
    // {
    //     curr = curr->next;
    // }
    // curr->next = get_node(val);
    // return head;
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
        printf("[(%d):%d]-->",count, head->val);
        count = print_list(head->next, count+1);
    }

    if (NULL == head)
    {
        printf("NULL\n");
    }
    return count;
    
    // while (NULL != head)
    // {
    //     printf("[(%d):%d]-->",count, head->val);
    //     head = head->next;
    //     count ++;
    // }

    // if (NULL == head)
    // {
    //     printf("NULL\n");
    // }
    // return count;
}


/*

237. Delete Node in a Linked List
Medium

There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node. You will not be given access to the first node of head.
All the values of the linked list are unique,
and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.

Custom testing:
For the input, you should provide the entire linked list head and the node to be given node.node should not be
the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.

Example 1:
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

Example 2:
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.

Constraints:
The number of the nodes in the given list is in the range [2, 1000].
-1000 <= Node.val <= 1000
The value of each node in the list is unique.
The node to be deleted is in the list and is not a tail node.

*/