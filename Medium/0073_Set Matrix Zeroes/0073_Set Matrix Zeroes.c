#include<stdio.h>
#include<stdlib.h>

void setZeroes(int (*matrix)[4], int matrixSize, int* matrixColSize)
{
    int row_idx[200] = {0};
    int col_idx[200] = {0};

    int i, j;
    for (i=0; i<matrixSize; i++)
    {
        for (j=0; j<(*matrixColSize); j++)
        {
            if ( 0 == matrix[i][j] )
            {
                row_idx[i] = 1;
                col_idx[j] = 1;
            }
        }
    }

    for (i=0; i<matrixSize; i++)
    {
        for (j=0; j<(*matrixColSize); j++)
        {
            if ( 1 == row_idx[i] || 1 == col_idx[j] )
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void print_list(int *nums, int matrixColSize);

int main(int argc, char const *argv[])
{
    // int nums[3][3] = {
    //                   { 1,1,1 },
    //                   { 1,0,1 },
    //                   { 1,1,1 }
    //                   };

    int nums[3][4] = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5},
    };
                      
    int matrixSize = 3;
    int matrixColSize = 4;

    int i;
    printf("[\n");
    for (i=0; i<matrixSize; i++)
    {
        print_list(nums[i], matrixColSize);
    }
    printf("]\n");

    setZeroes(nums, matrixSize, &matrixColSize);

    printf("[\n");
    for (i=0; i<matrixSize; i++)
    {
        print_list(nums[i], matrixColSize);
    }
    printf("]\n");


    return EXIT_SUCCESS;
}

void print_list(int *nums, int matrixColSize)
{
    int i;
    printf("  [ ");
    for (i=0; i<matrixColSize; i++)
    {
        printf("%d",nums[i]);
        if (i < matrixColSize-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

/*

73. Set Matrix Zeroes
Medium
Given an m x n integer matrix matrix,
if an element is 0,
set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1
 

Follow up:
A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


*/