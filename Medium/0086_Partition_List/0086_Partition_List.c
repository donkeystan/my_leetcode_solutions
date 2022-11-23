#include<stdlib.h>
#include<stdio.h>

struct ListNode *get_node(int val);
struct ListNode *insert(struct ListNode *head, int val);
void make_list(struct ListNode **head, int *nums, int numsSize);
int print_list(struct ListNode *head, int count);
int print_array(int *nums, int start, int end);

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *get_node(int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

struct ListNode *append_node(struct ListNode *head, struct ListNode **tail, int val)
{
    if (NULL == head)
    {
        head = get_node(val);
        (*tail) = head;
        return head;
    }
    struct ListNode *new_node = get_node(val);
    (*tail)->next = new_node;
    (*tail) = new_node;
    return head;    
}

struct ListNode* partition(struct ListNode* head, int x)
{
    if (NULL == head || NULL == head->next)
    {
        return head;
    }
    struct ListNode *smaller = NULL;
    struct ListNode *larger = NULL;
    struct ListNode *tailLarger = NULL;
    struct ListNode *tailSmaller = NULL;
    
    struct ListNode *ptr = head;
    while (NULL != ptr)
    {
        if (ptr->val >= x)
        {
            larger = append_node(larger, &tailLarger, ptr->val);
        }
        else
        {
            smaller = append_node(smaller, &tailSmaller, ptr->val);
        }
        ptr=ptr->next;
    }
    
    if (NULL == smaller && NULL == larger)
    {
        return head;
    }
    
    if (NULL == smaller && NULL != larger)
    {
        return larger;
    }
    
    if (NULL == larger && NULL != smaller)
    {
        return smaller;
    }
    
    tailSmaller->next = larger;
    head = smaller;
    
    return head;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {1,4,3,2,5,2};
    // int nums[] = {2,1,2};
    int nums[] = { 9, 10, 1, 2, 3 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int x = 10;
    struct ListNode *head = NULL;
    make_list(&head, nums, numsSize);
    print_list(head, 0);
    printf("x ---> %d\n", x);
    printf("\n\n<----- Partitioned ----->\n");
    head = partition(head, x);
    print_list(head, 0);
    return EXIT_SUCCESS;
}

void make_list(struct ListNode **head, int *nums, int numsSize)
{
    int i;
    for (i=0; i<numsSize; i++)
    {
        (*head) = insert((*head), nums[i]);
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


int print_list(struct ListNode *head, int count)
{
    if (NULL != head)
    {
        printf("L [ %d ] ---> %d \n", count, head->val);
        count = print_list(head->next, count + 1);
    }
    return count;
}

int print_array(int *nums, int start, int end)
{
    int i;
    printf("[ ");
    for (i=start; i<=end; i++)
    {
        printf("%d", nums[i]);
        if (i < end)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

/*

86. Partition List
Medium

Given the head of a linked list and a value x,
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

*/