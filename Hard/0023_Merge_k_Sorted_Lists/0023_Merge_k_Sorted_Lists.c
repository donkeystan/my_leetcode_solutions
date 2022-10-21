#include<stdlib.h>
#include<stdio.h>

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
    struct ListNode *next;
};

int print_list(struct ListNode *head, int count);
struct ListNode *insert(struct ListNode *head, int val);
struct ListNode *append_node(struct ListNode *head, struct ListNode **last, int val);

struct ListNode *merge(struct ListNode *list1, struct ListNode *list2);
struct ListNode *get_node(int val);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{    
    struct ListNode *head = NULL;
    
    if (listsSize >= 2)
    {
        int i;
        for (i=0; i<listsSize-1; i++)
        {
            head = merge(lists[i], lists[i+1]);
            lists[i+1] = head;
        }
    }
    else
    {
        if (listsSize == 0)
        {
            return head;
        }
        else
        {
            head = lists[0];
        }
    }
    
    return head;
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

struct ListNode *append_node(struct ListNode *head, struct ListNode **last, int val)
{
    if (NULL != head)
    {
        (*last)->next = get_node(val);
        (*last) = (*last)->next;
        return head;
    }
    else
    {
        head = get_node(val);
        *last = head;
        return head;
    }
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


int main(int argc, char const *argv[])
{
    int *nums[] = {
                    (int []) {1, 4, 5, '\0'},
                    (int []) {1, 3, 4, '\0'}, 
                    (int []) {2, 6, '\0'}
                    };

    int listsSize = sizeof(nums) / sizeof( nums[0] );
    printf("listsSize ---> %d\n", listsSize);

    struct ListNode *lists[listsSize];
    int i, j;
    for (i=0; i<listsSize; i++)
    {
        lists[i] = NULL;
        for (j=0; nums[i][j] != '\0'; j++)
        {
            // printf("Insert [%d][%d] to List[%d] ---> %d\n", i, j, i, nums[i][j]);
            lists[i] = insert(lists[i], nums[i][j]);
        }
        //  printf("\n");
    }

    struct ListNode *return_head = mergeKLists(lists, listsSize);

    print_list(return_head, 0);

    return EXIT_SUCCESS;
}

int print_array(int *nums)
{

}



int print_list(struct ListNode *head, int count)
{
    if (NULL != head)
    {
        printf("L[%d] ---> %d\n", count, head->val);
        count = print_list(head->next, count+1);
    }
    return count;
}

/*

23. Merge k Sorted Lists
Hard

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.

*/

/* Fail Code 2 ==> LTE 
struct ListNode *merge(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *merged_list = NULL;
    struct ListNode *last = NULL;

    while ( (NULL != list1) && (NULL != list2) )
    {
        if (list1->val <= list2->val)
        {
            merged_list = append_node(merged_list, &last, list1->val);
            list1 = list1->next;
        }
        else
        {
            merged_list = append_node(merged_list, &last, list2->val);
            list2 = list2->next;
        }
    }

    while (NULL != list1)
    {
        merged_list = append_node(merged_list, &last, list1->val);
        list1 = list1->next;
    }

    while (NULL != list2)
    {
        merged_list = append_node(merged_list, &last, list2->val);
        list2 = list2->next;
    }
    return merged_list;
}

*/


/* Fail Code => TLE : create a new list everytime

struct ListNode *merge(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *merged_list = NULL;
    while ( (NULL != list1) && (NULL != list2) )
    {
        if (list1->val <= list2->val)
        {
            merged_list = insert(merged_list, list1->val);
            list1 = list1->next;
        }
        else
        {
            merged_list = insert(merged_list, list2->val);
            list2 = list2->next;
        }
    }

    while (NULL != list1)
    {
        merged_list = insert(merged_list, list1->val);
        list1 = list1->next;
    }

    while (NULL != list2)
    {
        merged_list = insert(merged_list, list2->val);
        list2 = list2->next;
    }

    return merged_list;
}


*/