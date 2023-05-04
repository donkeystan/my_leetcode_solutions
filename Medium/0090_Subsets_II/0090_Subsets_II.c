#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void print_2d_array(int **nums, int row_size, int *col_sizes);
void print_array(int *nums, int numsSize);

struct list_node
{
    int *nums;
    int numsSize;
    struct list_node *next;
};

void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);
        int i, j, k, left_len=(mid-start+1), right_len=(end-mid), nums_left[left_len], nums_right[right_len];
        for (i=0; i<left_len; i++)
        {
            nums_left[i] = nums[start + i];
        }
        for (i=0; i<right_len; i++)
        {
            nums_right[i] = nums[mid+1+i];
        }

        for (i=0, j=0, k=start; i<left_len && j<right_len; k++)
        {
            if (nums_left[i] <= nums_right[j])
            {
                nums[k] = nums_left[i++];
            }
            else
            {
                nums[k] = nums_right[j++];
            }
        }

        while (i<left_len)
        {
            nums[k++] = nums_left[i++];
        }

        while (j<right_len)
        {
            nums[k++] = nums_right[j++];
        }
    }
}

struct list_node *get_node(int *nums, int numsSize)
{
    struct list_node *new_node = malloc(sizeof(struct list_node));
    new_node->nums = (int *)malloc(sizeof(int) * numsSize);
    int i;
    for (i=0; i<numsSize; i++)
    {
        new_node->nums[i] = nums[i];
    }
    new_node->numsSize = numsSize;
    new_node->next = NULL;
    return new_node;
}

struct list_node *append(struct list_node *head, struct list_node **tail, int *nums, int numsSize)
{
    if (NULL != head)
    {
        (*tail)->next = get_node(nums, numsSize);
        (*tail) = (*tail)->next;
        
    }
    else
    {
        head = get_node(nums, numsSize);
        (*tail) = head;
    }
    return head;
}

int ** write_result(int *returnSize, int **returnColumnSizes, struct list_node *head)
{
    int **result = (int **)malloc(sizeof(int *) * (*returnSize));
    int i, j;
    for (i=0; i<(*returnSize) && NULL != head; i++)
    {
        (*returnColumnSizes)[i] = head->numsSize;
        result[i] = head->nums;
        head = head->next;
    }
    return result;
}

// Tracerse from head to check if the new nums's combination exiests 
int isDup(struct list_node *head, struct list_node **tail, int *nums, int numsSize)
{
    int i, count=0;
    while (NULL != head)
    {
        if (head->numsSize == numsSize)
        {
            count = 0;
            for (i=0; i<numsSize; i++)
            {
                if (nums[i] == head->nums[i])
                {
                    count ++;
                }
            }
        }

        if (count == numsSize)
        {
            return 1;
        }
        
        head = head->next;
    }
    return 0;
}

void combinations(int *nums, int numsSize, int *path, int level, int k, struct list_node **head, struct list_node **tail, int *returnSize)
{
    if (level >= k)
    {
        int i, tmp[k];
        for (i=0; i<k; i++)
        {
            tmp[i] = nums[path[i]];
        }
        if (! isDup((*head), tail, tmp, k))
        {
            (*head) = append((*head), tail, tmp, k);
            (*returnSize)++;
        }        
        return;
    }
    
    int start = 0;
    if (level != 0)
    {
        start = path[level - 1] + 1;
    }
    for (path[level] = start; path[level] < numsSize; path[level]++)
    {
        combinations(nums, numsSize, path, level+1, k, head, tail, returnSize);
    }
}

/*
    My solutions is to use the backtracking and linked list to find combinations of C K,
    and use a isDup() to decide if the new node should be append.
    The solution is slow but space complexity is good.
*/

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    struct list_node *head = NULL;
    struct list_node *tail = NULL;
    (*returnSize) = 1;
    int temp[] = {};
    head = append(head, &tail, temp, 0);
    merge_sort(nums, 0, numsSize-1);
    int i;
    for (i=1; i<=numsSize; i++)
    {
        int path[i];
        combinations(nums, numsSize, path, 0, i, &head, &tail, returnSize);
    }
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    int **result = write_result(returnSize, returnColumnSizes, head);
    return result;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {1,2,2,2,1,2,4,3,1};
    // int nums[] = {1,2,2,1,2,1};
    // int nums[] = {1,2,2,1,2,1,3,4,5,1};
    // int nums[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int nums[] = {1,1,1,1,1,1,1,1,1,1,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **result = subsetsWithDup(nums, numsSize, &returnSize, &returnColumnSizes);
    print_2d_array(result, returnSize, returnColumnSizes);
    printf("< --- Total [ %d ] Sets of Data--- >\n");
    return 0;
}

void print_array(int *nums, int numsSize)
{
    int i;
    printf("[ ");
    for (i=0; i<numsSize; i++)
    {
        printf("%d", nums[i]);
        if (i < numsSize-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void print_2d_array(int **nums, int row_size, int *col_sizes)
{
    int i, j;
    printf("[\n");
    for (i=0; i<row_size; i++)
    {
        printf("[ ");
        for (j=0; j<col_sizes[i]; j++)
        {
            printf("%d", nums[i][j]);
            if (j < col_sizes[i]-1)
            {
                printf(", ");
            }
        }
        printf(" ]");
        if (i < row_size-1)
        {
            printf(", ");
        }
        printf("\n");
    }
    printf("]\n");
}


/*

90. Subsets II
Medium
7.6K
216
Companies
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10


*/
