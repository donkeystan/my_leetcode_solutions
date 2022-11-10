#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void print_2d_array(int** matrix, int matrixSize, int matrixColSize);
void setMatrix(int *nums, int nums_size, int **matrix, int matrixSize, int matrixColSize);

int bin_search(int *nums, int target, int start, int end)
{
    int mid;
    if (start <= end)
    {
        mid = (start + end) / 2;

        if (target == nums[mid])
        {
            printf("Target Found at [ %d ]\n", mid);
            return mid;
        }
        else if (target < nums[mid])
        {
            printf("%d < %d ---> Search Left [ %d to %d ]\n", target, nums[mid], start, mid-1);
            return bin_search(nums, target, start, mid-1);
        }
        else
        {
            printf("%d > %d ---> Search Right [ %d to %d ]\n", target, nums[mid], mid+1, end);
            return bin_search(nums, target, mid+1, end);
        }
    }
    return -1;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    print_2d_array(matrix, matrixSize, (*matrixColSize));

    int i;
    int rc = 0;
    for (i=matrixSize-1; i>=0; i--)
    {
        if (target >= matrix[i][0] && target <= matrix[i][(*matrixColSize)-1])
        {
            printf("Search matrix[%3d][0] ~ [%3d][%3d] ---> %3d ~ %3d \n", i, i, (*matrixColSize)-1, matrix[i][0], matrix[i][(*matrixColSize)-1]);
            rc = bin_search(matrix[i], target, 0, (*matrixColSize)-1);
            printf("RC ---> %d\n", rc);
            if (rc != -1)
            {
                printf("Found at matrix[%3d][%3d] ---> %3d\n", i, rc, matrix[i][rc]);
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int matrixSize = 5;
    int matrixColSize = 5;
    int **matrix = (int **)malloc( sizeof(int *) * matrixSize);
    int nums[] = {1,4,7,11,15,2,5,8,12,19,3,6,9,16,22,10,13,14,17,24,18,21,23,26,30};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    setMatrix(nums, nums_size, matrix, matrixSize, matrixColSize);
    int target = 20;
    int rc = 0;
    rc = searchMatrix(matrix, matrixSize, &matrixColSize, target);
    printf("rc ---> %d\n", rc);
    return EXIT_SUCCESS;
}

void setMatrix(int *nums, int nums_size, int **matrix, int matrixSize, int matrixColSize)
{
    int i, j, k=0;
    for (i=0; i<matrixSize; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * matrixColSize);
        for (j=0; j<matrixColSize; j++)
        {
            printf("Insert --> [ %d ]\n", nums[k]);
            matrix[i][j] = nums[k++];
        }
    }
}

void print_2d_array(int** matrix, int matrixSize, int matrixColSize)
{
    int i, j;
    printf("[ \n");
    for (i=0; i<matrixSize; i++)
    {
        printf(" [ ");
        for (j=0; j<matrixColSize; j++)
        {
            printf("%3d", matrix[i][j]);
            if (j < matrixColSize-1)
            {
                printf(" ");
            }
        }
        printf(" ] \n");
    }
    printf("]\n");
}


/*
240. Search a 2D Matrix II
Medium

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 
Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-10^9 <= matrix[i][j] <= 10^9

All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-10^9 <= target <= 10^9

*/