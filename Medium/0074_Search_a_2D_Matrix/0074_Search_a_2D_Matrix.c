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
            return mid;
        }
        else if (target < nums[mid])
        {
            return bin_search(nums, target, start, mid-1);
        }
        else
        {
            return bin_search(nums, target, mid+1, end);
        }
    }
    return -1;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    // print_2d_array(matrix, matrixSize, (*matrixColSize));
    int i;
    int rc = 0;
    for (i=matrixSize-1; i>=0; i--)
    {
        printf("Checking nums[%d][0] ---> %d\n", i, *(*(matrix+i)+0) );
        if ( target >= matrix[i][0] )
        {
            printf("Search in nums[%d][0] ---> %d\n", i, *(*(matrix+i)+0) );
            rc = bin_search(matrix[i], target, 0, (*matrixColSize)-1);
            printf("Found at matrix[%d][%d] ---> %d\n", i, rc, matrix[i][rc]);
            return (rc != -1) ? 1 : 0;
            break;
        }
    }
    return rc;
}

int main(int argc, char const *argv[])
{
    int matrixSize = 3;
    int matrixColSize = 4;
    int **matrix = (int **)malloc( sizeof(int *) * matrixSize);
    int nums[] = {1,3,5,7,10,11,16,20,23,30,34,60 };
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    setMatrix(nums, nums_size, matrix, matrixSize, matrixColSize);
    int target = 3;
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
            // printf("Insert --> [ %d ]\n", nums[k]);
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
74. Search a 2D Matrix
Medium
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4

*/