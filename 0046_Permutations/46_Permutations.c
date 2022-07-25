#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// int COMBO = 0;

int get_permutation_amount(int num);
void permutation(int *nums, int *var, int level, int nums_size, int **ptr, int *ptr_count);
int isContinue(int *var, int level);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int permutation_amount = get_permutation_amount(numsSize);
    int **result = (int **)malloc( permutation_amount * sizeof(int *) );
    int i;
    int ptr_count = 0;

    int *return_col = malloc(sizeof(int)*permutation_amount);

    for(i=0; i<permutation_amount; i++)
    {
        return_col[i] = numsSize;
    }
    *returnColumnSizes = return_col;

    *returnSize = permutation_amount;
    int var[permutation_amount];
    permutation(nums, var, 0, numsSize, result, &ptr_count);

    return result;
}

void permutation(int *nums, int *var, int level, int nums_size, int **ptr, int *ptr_count)
{
    if (level == nums_size)
    {
        ptr[(*ptr_count)] = (int *) malloc(sizeof(int) * nums_size);
        int i;
        for (i=0; i<nums_size; i++)
        {
            ptr[(*ptr_count)][i] = nums[var[i]];
        }
        (*ptr_count) ++;
        return;
    }

    for (var[level]=0; var[level]<nums_size; var[level]++)
    {
        if (isContinue(var, level))
        {
            continue;
        }
        permutation(nums, var, level+1, nums_size, ptr, ptr_count);
    }
}

int isContinue(int *var, int level)
{
    // ( i==j || i==k || i==l || j==k || j==l || k ==L )  <== it's a double loop structure to find continue condition

    int i;
    int j;

    for (i=0; i<=level; i++)
    {
        for (j=i+1; j<=level; j++)
        if (var[i] == var[j])
        {
            return 1;
        }
    }

    return 0;
}

int get_permutation_amount(int num)
{
    if (num == 1)
    {
        return num;
    }
    return num * get_permutation_amount(num-1);
}

int main(int argc, char *argv[])
{
    int nums[] = {1,2,3,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int returnSize = 0;
    int columnSizes = 0;

    int **returnColumnSizes;
    int **list = NULL;

    list = permute(nums, numsSize, &returnSize, returnColumnSizes);

    int i;
    int j;

    for (i=0; i<returnSize; i++)
    {
        printf("Combo [ %2d ] ---> ", i+1);
        for (j=0; j<numsSize; j++)
        {
            printf("%d ", list[i][j]);
        }
        printf("\n");
    }

    // printf("returnSize --->%d ,  returnColumnSizes ---> %d\n", returnSize, *returnColumnSizes);


    return 0;
}


/*

46. Permutations
Medium

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/