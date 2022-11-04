#include<stdio.h>
#include<stdlib.h>

void print_list(int *nums, int matrixSize);

void rotate(int (*matrix)[5], int matrixSize, int* matrixColSize)
{
    int rotatedNums[matrixSize][matrixSize];
    int i, j, k;
    for (i=0; i<matrixSize; i++)
    {
        k = matrixSize-1;
        for (j=0; j<matrixSize; j++)
        {
            rotatedNums[i][j] = matrix[k--][i];
        }
    }

    for (i=0; i<matrixSize; i++)
    {
        for (j=0; j<matrixSize; j++)
        {
            matrix[i][j] = rotatedNums[i][j];
        }
    }
}


int main(int argc, char const *argv[])
{
    // int nums[3][3] = {
    //                   { 1,2,3 },
    //                   { 4,5,6 },
    //                   { 7,8,9 }
    //                   };

    int nums[5][5] ={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25},

    };
                      
    int matrixSize = 5;
    int matrixColSize = 5;

    int i;
    printf("[\n");
    for (i=0; i<matrixSize; i++)
    {
        print_list(nums[i], matrixColSize);
    }
    printf("]\n");

    rotate(nums, matrixSize, &matrixColSize);

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

48. Rotate Image
Medium

Share
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/