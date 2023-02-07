#include<stdio.h>
#include<stdlib.h>

void print_2d_array(int **nums, int row_size, int *col_sizes);
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void combination(int *nums, int numsSize, int *path, int level, int k, int **result, int *combo, int **returnColumnSizes)
{
    if (level == k)
    {
        int i;
        result[(*combo)] = (int *)malloc(sizeof(int) * k);
        for (i=0; i<k; i++)
        {
            result[(*combo)][i] = nums[path[i]];
            (*returnColumnSizes)[(*combo)] = k;
        }       
        (*combo)++;
        return;
    }
    
    int start = 0;
    if (level != 0)
    {
        start = path[level-1] + 1;
    }
    
    for (path[level] = start ; path[level] < numsSize; path[level]++ )
    {
        combination(nums, numsSize, path, level+1, k, result, combo, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    (*returnSize) = 1 << (numsSize);
    int **result = (int **)malloc(sizeof(int *) * (*returnSize));
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    int combo = 0;
    result[combo] = (int *)malloc(sizeof(int) * 0);
    (*returnColumnSizes)[combo] = 0;
    combo ++;

    int i, j;
    for (i=0; i<numsSize; i++)
    {
        int path[i+1];
        for (j=0; j<i+1; j++)
        {
            path[j] = 0;
        }
        combination(nums, numsSize, path, 0, i+1, result, &combo, returnColumnSizes);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int combo = 0;
    int **result = subsets(nums, numsSize, &returnSize, &returnColumnSizes);
    print_2d_array(result, returnSize, returnColumnSizes);
    return EXIT_SUCCESS;
}

void print_2d_array(int **nums, int row_size, int *col_sizes)
{
    int i, j;
    printf("[ ");
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
    }
    printf(" ]\n");
}

/*

78. Subsets
Medium

Given an integer array nums of unique elements, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/
