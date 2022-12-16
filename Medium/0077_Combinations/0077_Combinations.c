#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void combination(int *nums, int n, int *path, int level, int k, int **result, int *combo)
{
    // 7. Base Condition, according to the concept model, the depth of recursion should not exceed the k
    //    e.g. k=3, the loop goes 3 times, path[] goes from 0...2, and if k=4, Loop should go 4 times, path[] goes fron 0...3
    //    Upon base condition is satisfied, malloc a k-int size space to result's pointer as well as assign value get form nums[path[]] to each pointer
    if (level == k)
    {
        int i;
        result[(*combo)] = (int *)malloc(sizeof(int) * k);
        for (i=0; i<k; i++)
        {
            result[(*combo)][i] = nums[path[i]];
        }       
        (*combo)++;
        return;
    }
    
    // 5. It's very important to assing the initial point to each layer of loop
    //    according to the model, every inner layer takes minus one from its predecessor loop
    //    i, j = i+1,  k = j+1.. etc.
    //    eliminte the level 0 as it dose not do minus from the beginning
    int start = 0;
    if (level != 0)
    {
        start = path[level-1] + 1;
    }
    
    // 6. Recursive Loops begin 
    for (path[level] = start; path[level] < n; path[level]++ )
    {
        combination(nums, n, path, level+1, k, result, combo );
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{   

    // 1. Prepare an array with numbers for combination sets
    int nums[n];
    int i;
    for (i=0; i<n; i++)
    {
        nums[i] = i+1;
    }

    // 2. Create a path[] array for recursive looping
    int path[k];
    for (i=0; i<k; i++)
    {
        path[i] = 0;
    }

    // 3. Since the combination count is too large to calculate, the largest sets are formed by C^n:20_k:12, which is 125970, we assigned 130000 to malloc space
    int **result = (int **)malloc(sizeof(int *) * 130000);
    int combo = 0;
    int level = 0;

    // 4. Combination Process by recursion starts
    combination(nums, n, path, level, k, result, &combo);
    (*returnSize) = combo;

    // . After the recursion process, according to leetcode, we have to tell how big each pointer is poiting to
    // . assigned combo * int size ( 1D array of combo-amount int ) 
    //    each element holds how big each array should be
    int *return_col = malloc(sizeof(int)*combo);
    for(i=0; i<combo; i++)
    {
        return_col[i] = k;
    }
    *returnColumnSizes = return_col;

    return result;
}

void concept();
void print_2d_array(int **nums, int row_size, int col_size);

int main(int argc, char const *argv[])
{
    // concept();
    int n = 20;
    int k = 12;
    int **returnColumnSizes;
    int returnSize;
    int **result = combine(n, k, &returnSize, returnColumnSizes);
    print_2d_array(result, returnSize ,k);    
    return 0;
}

void concept()
{
    int n = 9;
    int nums[n];
    int i, j, k;
    for (i=0; i<n; i++)
    {
        nums[i] = i+1;
    }
    for (i=0; i<n; i++)
    {
        for (j=i+1; j<n; j++)
        {
            for (k=j+1; k<n; k++)
            {
                printf("( %d %d %d )\n", nums[i], nums[j], nums[k]);
            }
        }
    }
}

void print_2d_array(int **nums, int row_size, int col_size)
{
    int i, j;
    for (i=0; i<row_size; i++)
    {
        printf("Combo [ %d ] ---> [", i+1);
        for (j=0; j<col_size; j++)
        {
            printf("%d", nums[i][j]);
            if (j < col_size-1)
            {
                printf(", ");
            }
        }
        printf(" ]\n");
    }
}

/*

77. Combinations
Medium

Companies
Given two integers n and k,
return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

Constraints:
1 <= n <= 20
1 <= k <= n

*/