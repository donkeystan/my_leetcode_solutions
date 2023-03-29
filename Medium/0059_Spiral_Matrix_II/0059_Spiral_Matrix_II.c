#include<stdio.h>
#include<stdlib.h>
void print_array(int *nums, int nums_size);
void print_2d_array(int **nums, int row_size, int *col_sizes);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int forward_traverse(int **matrix, int *value, int i, int j, int start, int end, int go_vertical)
{
    if (go_vertical)
    {
        for (i=start; i<=end; i++)
        {
            matrix[i][j] = (*value)++;
        }
        return i-1;
    }

    for (j=start; j<=end; j++)
    {
        matrix[i][j] = (*value)++;
    }
    return j-1;
}


int backward_traverse(int **matrix, int *value, int i, int j, int start, int end, int go_vertical)
{
    if (go_vertical)
    {
        for (i=start; i>=end; i--)
        {
            matrix[i][j] = (*value) ++;
        }
        return i+1;
    }

    for (j=start; j>=end; j--)
    {
        matrix[i][j] = (*value) ++;
    }
    return j+1;
}

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    (*returnSize) = n;
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    int **matrix = (int **)malloc(sizeof(int *) * (*returnSize));
    int i, j;
    int curr_horizontal_length = n;
    int curr_vertical_lenght = n-1;
    int curr_start = 0;
    int curr_end = n-1;
    int value = 1;
    int go_vertical = 0;
    
    for (i=0; i<n; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    i = 0;
    j = 0;

    while (curr_horizontal_length != 0 || curr_vertical_lenght != 0)
    {
        if (curr_horizontal_length != 0)
        {
            j = forward_traverse(matrix, &value, i, j, curr_start, curr_end, go_vertical);
            go_vertical = 1;
            curr_horizontal_length --;   
        }

        if (curr_vertical_lenght != 0)
        {
            i = forward_traverse(matrix, &value, i, j, curr_start+1, curr_end, go_vertical);
            go_vertical = 0;
            curr_vertical_lenght --;
        }

        if (curr_horizontal_length != 0)
        {
            j = backward_traverse(matrix, &value, i, j, curr_end-1, curr_start, go_vertical);
            go_vertical = 1;
            curr_start ++;
            curr_horizontal_length --;
        }

        if (curr_vertical_lenght != 0)
        {
            i = backward_traverse(matrix, &value, i, j, curr_end-1, curr_start, go_vertical);
            curr_end --;
            go_vertical = 0;
            curr_vertical_lenght --;
        }
    }

    return matrix;
}

int main(int argc, char const *argv[])
{
    int n = 6;
    int returnSize;
    int *returnColumnSizes = NULL;
    int **result = generateMatrix(n, &returnSize, &returnColumnSizes);
    print_2d_array(result, returnSize, returnColumnSizes);
    return 0;
}

void print_array(int *nums, int nums_size)
{
    int i;
    printf("[ ");
    for (i=0; i<nums_size; i++)
    {
        printf("%2d", nums[i]);
        if (i < nums_size-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void print_2d_array(int **nums, int row_size, int *col_sizes)
{
    int i;
    printf("[\n");
    for (i=0; i<row_size; i++)
    {
        print_array(nums[i], col_sizes[i]);
    }
    printf("]\n");
}



/*

59. Spiral Matrix II

Medium
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:

1 <= n <= 20

*/