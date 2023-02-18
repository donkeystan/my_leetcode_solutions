#include<stdio.h>
#include<stdlib.h>

void print_2darray(int **nums, int row_size, int *returnColumnSizes);
void print_list(int *nums, int numsSize);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct list_threeSum
{
    int val1;
    int val2;
    int val3;
    struct list_threeSum *next;
};

struct list_threeSum *get_node(int num1, int num2, int num3);
struct list_threeSum *append_node(struct list_threeSum *head, struct list_threeSum **tail,int num1, int num2, int num3);
void write_result(struct list_threeSum *head, int **result);
void merge_sort(int *nums, int start, int end);
void twoSum(int *nums, int target, int start, int end, int *returnSize, struct list_threeSum **head, struct list_threeSum **tail);

struct list_threeSum *get_node(int num1, int num2, int num3)
{
    struct list_threeSum *new_node = (struct list_threeSum *)malloc(sizeof(struct list_threeSum));
    new_node->val1 = num1;
    new_node->val2 = num2;
    new_node->val3 = num3;
    new_node->next = NULL;
    return new_node;
}

struct list_threeSum *append_node(struct list_threeSum *head, struct list_threeSum **tail,int num1, int num2, int num3)
{
    if (NULL != head)
    {
        (*tail)->next = get_node(num1, num2, num3);
        (*tail) = (*tail)->next;
    }
    else
    {
        head = get_node(num1, num2, num3);
        (*tail) = head;
    }
    return head;
}

void write_result(struct list_threeSum *head, int **result)
{
    int count = 0;
    while (NULL != head)
    {
        result[count] = (int *)malloc(sizeof(int) * 3);
        result[count][0] = head->val1;
        result[count][1] = head->val2;
        result[count][2] = head->val3;
        head = head->next;
        count ++;
    }
}

void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid + 1, end);
        int i, j, k, left_len = (mid - start + 1), right_len = (end - mid);
        int nums_left[left_len], nums_right[right_len];
        for (i=0; i<left_len; i++)
        {
            nums_left[i] = nums[start + i];
        }

        for (i=0; i<right_len; i++)
        {
            nums_right[i] = nums[mid + 1 + i];
        }

        for (i=0, j=0, k=start; i<left_len & j <right_len; k++)
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

void twoSum(int *nums, int target, int start, int end, int *returnSize, struct list_threeSum **head, struct list_threeSum **tail)
{
    // 2.2.1 Loop while left does not meet right
    int left_p = start, right_p = end;
    while (left_p < right_p)
    {
        // 2.2.1.1 store the three nums when num at left_p plus nums at right_p meets target
        if (nums[left_p] + nums[right_p] == target)
        {
            (*returnSize) ++;
            (*head) = append_node((*head), tail, -(target), nums[left_p], nums[right_p]);
        }

        // 2.2.1.2 then look for other option 
        // if num at left_p plust num at right_p is less than target, that means num at left_p is too small, left increment required
        // if num at left_p plust num at right_p is larger than target, that means num at right_p is too large, right decrement required
        if (nums[left_p] + nums[right_p] < target)
        {
            do
            {
                left_p ++;
            }
            while(nums[left_p] == nums[left_p-1] && left_p < right_p);
        }
        else
        {
            do
            {
                right_p--;
            }
            while (nums[right_p] == nums[right_p+1] && left_p < right_p);
        }
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // 0. Prepare linked list to store the data sets
    (*returnSize) = 0;
    struct list_threeSum* head = NULL;
    struct list_threeSum* tail = NULL;

    // 1. Sort the array for 3Sum()
    merge_sort(nums, 0, numsSize-1);
    int i;
    
    // 2. Loop from the beginnig 
    for (i=0; i<numsSize-2 && nums[i] <= 0 ; i++)
    {
        // 2.1 if nums[i] is equal to its previous nums[i-1], skip the loop
        if (i > 0 && nums[i] == nums[i-1])
        {
            continue;
        }

        // 2.2 if no repeat for the first num, set it as target, and i+1 as sequence start numsSize-1 as sequence end for twoSum process
        twoSum(nums, -(nums[i]), i+1, numsSize-1, returnSize, &head, &tail);
    }

    // 3. prepare an malloc 2D array and copy all the info from the linked list to it
    int **result = (int **)malloc(sizeof(int *) * (*returnSize));
    write_result(head, result);

    // 4. Remember to also write the returnColSizes array to the caller
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    for (i=0; i<(*returnSize); i++)
    {
        (*returnColumnSizes)[i] = 3;
    }

    // 5. End
    return result;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {0,1,0,1,-1,0,1};
    // int nums[] = {-3, -3, -2, -1 , 0, 0, 1, 1, 2, 2};
    // int nums[] = {0,0,0};
    int nums[] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    print_2darray(result, returnSize, returnColumnSizes);
    return EXIT_SUCCESS;
}

int print_list_threeSum(struct list_threeSum *head, int count)
{
    if (NULL != head)
    {
        printf("[ %d %d %d ]\n", head->val1, head->val2, head->val3);
        count = print_list_threeSum(head->next, count+1);
    }
    return count;
}

void print_2darray(int **nums, int row_size, int *returnColumnSizes)
{
    int i, j;
    printf("[ \n");
    for (i=0; i<row_size; i++)
    {
        printf("[ ");
        for (j=0; j<returnColumnSizes[i]; j++)
        {
            printf("%d", nums[i][j]);
            if (j < returnColumnSizes[i]-1)
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

void print_list(int *nums, int numsSize)
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

/*

15. 3Sum
Medium
Given an integer array nums,
return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5

*/

/*

write_result(nums, -(target), nums[left_p], nums[right_p], (*returnSize), result);

void write_result(int *nums, int num1, int num2, int num3, int size, int **result, struct list_threeSum **head, struct list_threeSum **tail)
{
    int i, j;
    if (size == 1)
    {
        result[size-1] = (int *)malloc(sizeof(int) * 3);
        result[size-1][0] = num1;
        result[size-1][1] = num2;
        result[size-1][2] = num3;
        return;
    }

    // int **expand_result = (int **)malloc(sizeof(int *) * size);

    // printf("size ---> %d\n", size);
    // for (i=0; i<size-1; i++)
    // {
    //     expand_result[i] = (int *)malloc(sizeof(int) * 3);
    //     for(j=0; j<3; j++)
    //     {
    //         expand_result[i][j] = result[i][j];
    //         printf("       result[%d][%d] --> %d\n", i,j, result[i][j]);
    //         printf("expand_result[%d][%d] --> %d\n", i,j, expand_result[i][j]);
    //     }
    //     int *dump_row = result[i];
    //     free(dump_row);
    // }
    
    // int **dump = result;
    // free(dump);

    // result = expand_result;

    // result[size-1] = (int *)malloc(sizeof(int) * 3);
    // result[size-1][0] = num1;
    // result[size-1][1] = num2;
    // result[size-1][2] = num3;

    // int **dump = result;
    // result = (int **)realloc(result, sizeof(int *) * size);
    result[size-1] = (int *)malloc(sizeof(int) * 3);
    result[size-1][0] = num1;
    result[size-1][1] = num2;
    result[size-1][2] = num3;

    for (i=0; i<size; i++)
    {
        printf("result[%d]-->", i);
        for (j=0; j<3; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("Write Complete\n\n");
}



*/
