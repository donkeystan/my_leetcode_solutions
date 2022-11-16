#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

/*
Solution Remark:
1. create a function that handles node swap, which will also return the new head of the sublist while record the tail nodes
2. in the main function, first check if it's more than two nodes.
3. set "odd_node" on head node
4. set "even_node" on head->next node
5. set "next" node to even_node's next
6. default two pointer to handle the link between previous sublist and current sublist
7. swap the first two nodes to form a sublist with tail pointer recording the sublist's tail
8. use while to make sure there are two more nodes to do the swap sublist operation
9. within while loop, we do
    a. make another copy of the tail pointer
    b. odd_node and even_node both step on their next next one node
    c. "next" node jump to even_node's next
    d. prev_tail->next to link with the new sublist while pin_tail to record the new sublists's tail

10. after while loop is done, make sure to link the final sublist's tail to the new remaining node "next"

O
    E    
         N
1   2    3    4

*/
struct ListNode *swap_nodes(struct ListNode *node1, struct ListNode *node2, struct ListNode **tail)
{
    node2->next = node1;
    node1->next = NULL;
    *tail = node1;
    return node2;
}

struct ListNode* swapPairs(struct ListNode* head)
{
    if (NULL == head)
    {
        return NULL;
    }

    if (NULL == head->next)
    {
        return head;
    }

    struct ListNode *odd_node = head;
    struct ListNode *even_node = head->next;
    struct ListNode *next = even_node->next;
    struct ListNode *pin_tail = NULL;
    struct ListNode *prev_tail = NULL;

    head = swap_nodes(odd_node, even_node, &pin_tail);
    
    while (NULL != next && NULL != next->next )
    {
        prev_tail = pin_tail;
        odd_node = next;
        even_node = next->next;
        next = even_node->next;
        prev_tail->next = swap_nodes(odd_node, even_node, &pin_tail);
    }
    pin_tail->next = next;

    return head;
}

struct ListNode *get_node(int val);
struct ListNode *insert(struct ListNode *head, int val);
int print_list(struct ListNode *head, int count);

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i;
    struct ListNode *head = NULL;
    for (i=0; i<numsSize; i++)
    {
        head = insert(head, nums[i]);
    }

    int count = print_list(head, 0);
    printf("Total [ %d ] Nodes \n", count);

    head = swapPairs(head);

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

24. Swap Nodes in Pairs
Medium

Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

*/