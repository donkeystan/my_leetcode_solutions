#include<stdio.h>
#include<stdlib.h>

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
    struct ListNode * next;
};

struct ListNode* create_list(struct ListNode*, int);

struct ListNode* middleNode(struct ListNode* head)
{
   /*
    * pass a linked list in
    * traverse the list and count nodes
    * reset the ptr from head after count
    * devide the count by 2
    * use a for loop to traverse to designated node
    * use a ptr to store the address
    * return the ptr to caller
    * 
    */
    
    struct ListNode* ptr = head;
    int count =0;
    int i;
    
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    
    ptr = head;
    
    printf("Found %d nodes\n",count);
    
    for(i=0; i<count/2; i++)
    {
        ptr = ptr->next;
    }

    return ptr;
}


/*

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

*/

int main()
{
    int i;
    int arr[] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    struct ListNode* ptr;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    head->val = arr[0];
    head->next = NULL;
    
    ptr = head;
    for(i=1; i<n; i++)
    {
        ptr = create_list(ptr, arr[i]);
    }
    ptr = head;
    
    i=0;
    while(ptr != NULL)
    {
        i++;
        printf("List %d is %d\n",i,ptr->val);
        ptr=ptr->next;
    }
    ptr = head;
    
    
    ptr = middleNode(head);
    
    printf("------------------The result after calling middle node-------------------\n");
    
    i=0;
    while(ptr != NULL)
    {
        i++;
        printf("List %d is %d\n",i,ptr->val);
        ptr=ptr->next;
    }
    ptr = head;
    
    
    return 0;
}

struct ListNode* create_list(struct ListNode* ptr, int data)
{
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    temp -> val = data;
    temp -> next = NULL;
    ptr->next = temp;

    return temp;
}


/*

//High Level Answer

struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    
    while (fast != NULL)
    {
        
        if (fast->next == NULL)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
*/