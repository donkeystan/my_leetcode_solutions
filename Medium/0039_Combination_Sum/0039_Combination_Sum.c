#include<stdio.h>
#include<stdlib.h>

void print_2d_array(int **nums, int row_size, int *col_sizes);
void print_array(int *nums, int nums_size);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define TMP_SIZE 256
struct list_node
{
    int *nums;
    int nums_size;
    struct list_node *next;
};

struct list_node *get_node(int *nums, int nums_size)
{
    struct list_node *new_node = (struct list_node *)malloc(sizeof(struct list_node));
    new_node->nums = (int *)malloc(sizeof(int) * nums_size);
    int i;
    for (i=0; i<nums_size; i++)
    {
        new_node->nums[i] = nums[i];
    }
    new_node->nums_size = nums_size;
    new_node->next = NULL;
    return new_node;
}

struct list_node *append_list(struct list_node *head, struct list_node **tail, int *nums, int nums_size)
{
    if (NULL != head)
    {
        (*tail)->next = get_node(nums, nums_size);
        (*tail) = (*tail)->next;
    }
    else
    {
        head = get_node(nums, nums_size);
        (*tail) = head;
    }
    return head;
}


void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);
        int i, j, k, left_len = (mid - start) + 1, right_len = (end - mid), nums_left[left_len], nums_right[right_len];
        for (i=0; i<left_len; i++)
        {
            nums_left[i] = nums[start + i];
        }
        for (i=0; i<right_len; i++)
        {
            nums_right[i] = nums[mid + 1 + i];
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
        while (i < left_len)
        {
            nums[k++] = nums_left[i++];
        }
        while (j < right_len)
        {
            nums[k++] = nums_right[j++];
        }
    }
}

int **write_result(struct list_node *head, int *returnSize, int **returnColumnSizes)
{
    int **result = (int **)malloc(sizeof(int *) * (*returnSize));
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    int i;
    for (i=0; i<(*returnSize) && NULL != head; i++)
    {
        result[i] = head->nums;
        (*returnColumnSizes)[i] = head->nums_size;
        head = head->next;
    }
    return result;
}

void __combinationSum(int *nums, int nums_size, int start, int target, int level, int *returnSize, int *temp, struct list_node **head, struct list_node **tail)
{

    // 3.4 if any zero found, that means the candidate from the recursion in each i index sums up as the target
    //     then save it in a node of the linked list.
    if (target == 0)
    {
        (*head) = append_list((*head), tail, temp, level);
        (*returnSize)++;
        return;
    }

    //3.1 The main loop will loop through the candidates array
    int i;
    for (i=start; i<nums_size; i++)
    {
        // 3.2 check if the answer of target minus current element is less than zero
        //     if yes then further recursion to find candidates is not required.
        if (target - nums[i] < 0)
        {
            break;
        }

        // 3.3 store current element in the temp array, and then goes to the smae element index but in level + 1 
        temp[level] = nums[i];
        __combinationSum(nums, nums_size, i, target-nums[i], level+1, returnSize, temp, head, tail);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    // 1. Sort the candidates first
    merge_sort(candidates, 0, candidatesSize-1);
    
    // 2. Preprocess : initialize returnSize, then prepare an array for temporary storage, and prepare a linked list for 2d array temp storage
    (*returnSize) = 0;
    int start = 0;
    int level = 0;
    int temp[TMP_SIZE];
    struct list_node *head = NULL;
    struct list_node *tail = NULL;

    // 3. start the backtracking sequence
    __combinationSum(candidates, candidatesSize, start, target, level, returnSize, temp, &head, &tail);
    int **result = write_result(head, returnSize, returnColumnSizes);
    return result;
}

int main(int argc, char const *argv[])
{
    int nums[] = {8, 7, 4, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 11;
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **result = combinationSum(nums, numsSize, target, &returnSize, &returnColumnSizes);
    print_2d_array(result, returnSize, returnColumnSizes);
    return EXIT_SUCCESS;
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
    printf(" ]\n");

    printf("Total [%d] Sets of Data\n", i);
}

int print_list(struct list_node *head, int count)
{
    if (NULL != head)
    {
        printf("Combo [%d] --> [ ", count+1);
        int i;
        for (i=0; i<head->nums_size; i++)
        {
            
            printf("%d", head->nums[i]);
            if (i < head->nums_size-1)
            {
                printf(", ");
            }
        }
        printf(" ]\n");
        count = print_list(head->next, count+1);
    }
    return count;
}

void print_array(int *nums, int nums_size)
{
    int i;
    printf("[ ");
    for (i=0; i<nums_size; i++)
    {
        printf("%d", nums[i]);
        if (i < nums_size-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}
/*

39. Combination Sum
Medium

Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates where the chosen numbers sum to target.
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Constraints:
1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40

*/