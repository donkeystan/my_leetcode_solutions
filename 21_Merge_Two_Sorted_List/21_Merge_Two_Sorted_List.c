#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *create_node(int);
struct ListNode *create_list(struct ListNode *, int);
int print_nodes(struct ListNode *);
struct ListNode *sort(struct ListNode*);

struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *new_head = NULL;


    if(list1 == NULL && list2 != NULL)
    {
        printf("List 1 is empty\n");
        return list2;
    }
    
    if(list2 == NULL && list1 != NULL)
    {
        printf("List 2 is empty\n");
        return list1;
    }

    if(list1 == NULL && list2 == NULL)
    {
        printf("Both Lists are empty\n");
        return list1;
    }

    new_head = list1;

    while(new_head->next != NULL)
    {
        new_head = new_head->next;
    }
    new_head->next = list2;
    new_head = list1;

    sort(new_head);

    return new_head;
}

struct ListNode *sort(struct ListNode* head)
{
    int count = 0;
    int i;
    int j;
    int k;
    struct ListNode *ptr = NULL;
    ptr = head;
    
    while( ptr != NULL)
    {
        ptr=ptr->next;
        count++;
    }
    printf("Count--->%d\n",count);

    
    k = count;
    for(i=0; i<count-1; i++)
    {
        ptr = head;
        for(j=0; j<k-1; j++)
        {
            if( (ptr->val) > (ptr->next->val) )
            {
                printf("ptr->val > ptr->next->val ---> swap %d with %d  ",ptr->val, ptr->next->val);
                ptr->next->val ^= ptr->val;
                ptr->val ^= ptr->next->val;
                ptr->next->val ^= ptr->val;
                printf("ptr->val ---> %d , ptr->next->val ---> %d\n",ptr->val, ptr->next->val);
            }
            ptr=ptr->next;
        }
        k--;
    }
    return ptr;
}



int main(int argc, char *argv[])
{
    int i;
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;
    struct ListNode *mrg_list = NULL;

    for(i=0; i<100; i+=2)
    {
        list1 = create_list(list1 ,i);
    }
    
    // list1 = create_list(list1 ,1);
    // list1 = create_list(list1 ,2);
    // list1 = create_list(list1 ,4);
    // list1 = create_list(list1 ,8);
    
    for(i=-100; i<50; i+=3)
    {
        list2 = create_list(list2 ,i);
    }
    
    // list2 = create_list(list2 ,1);
    // list2 = create_list(list2 ,3);
    // list2 = create_list(list2 ,4);
    // list2 = create_list(list2 ,11);

    printf("<--- List1 --->\n");
    print_node(list1);
    printf("\n");

    printf("<--- List2 --->\n");
    print_node(list2);
    printf("\n");
    
    mrg_list = mergeTwoLists(list1, list2);

    printf("<--- Merged List --->\n");
    print_node(mrg_list);
    printf("\n");

    return 0;
}

struct ListNode *create_list(struct ListNode *head, int data)
{
    struct ListNode *ptr = NULL;
    if (head == NULL)
    {
        ptr = create_node(data);
        return ptr;
    }
    
    ptr = head;
    while( ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = create_node(data);

    return head;
}

struct ListNode *create_node(int data)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}

int print_node(struct ListNode *head)
{
    if(head == NULL)
    {
        printf("List is Empty!\n");
        return head;
    }
    int count = 0;
    struct ListNode *ptr = NULL;
    ptr = head;

    while( ptr!=NULL )
    {
        count ++;
        printf("Node %d ---> %d\n",count,ptr->val);
        ptr=ptr->next;
    }
    return count;
}


/*
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.


Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]


Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/