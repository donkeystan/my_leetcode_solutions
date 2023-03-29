#include<stdio.h>
#include<stdlib.h>
void print_2d_array(int **nums, int row_size, int *col_sizes);
void print_array(int *nums, int nums_size);
#define ROW 10
#define COL 10

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int horizontal_forward(int **matrix, int i, int j, int start, int end, int *result, int *count)
{
    for (j=start; j<=end; j++)
    {
        result[(*count)++] = matrix[i][j];
    }
    return j-1;
}

int horizontal_backward(int **matrix, int i, int j, int start, int end, int *result, int *count)
{
    for (j=start; j>=end; j--)
    {
        result[(*count)++] = matrix[i][j];
    }
    return j+1;
}

int vertical_forward(int **matrix, int i, int j, int start, int end, int *result, int *count)
{
    for (i=start; i<=end; i++)
    {
        result[(*count)++] = matrix[i][j];
    }
    return i-1;
}

int vertical_backward(int **matrix, int i, int j, int start, int end, int *result, int *count)
{
    for (i=start; i>=end; i--)
    {
        result[(*count)++] = matrix[i][j];
    }
    return i+1;
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    (*returnSize) = matrixSize * (*matrixColSize);
    int *result = (int *)malloc(sizeof(int) * (*returnSize));

    int curr_horizontal_length = (*matrixColSize);
    int curr_vertical_length = matrixSize-1;

    int horizontal_start = 0;
    int horizontal_end = (*matrixColSize)-1;
    int vertical_start = 1;
    int vertical_end = matrixSize-1;

    int count = 0;
    int i = 0;
    int j = 0;

    while (curr_horizontal_length != 0 || curr_vertical_length != 0)
    {
        if (curr_horizontal_length != 0)
        {
            j = horizontal_forward(matrix, i, j, horizontal_start, horizontal_end, result, &count);
            curr_horizontal_length --;
        }
        
        
        if (curr_vertical_length != 0)
        {
            i = vertical_forward(matrix, i, j, vertical_start, vertical_end, result, &count);
            curr_vertical_length --;
        }

        if (curr_horizontal_length != 0)
        {
            j = horizontal_backward(matrix, i, j, horizontal_end-1, horizontal_start, result, &count);
            horizontal_start ++;
            horizontal_end --;
            curr_horizontal_length --;
        }

        if (curr_vertical_length != 0)
        {
            i = vertical_backward(matrix, i, j, vertical_end-1, vertical_start, result, &count);
            vertical_start ++;
            vertical_end --;
            curr_vertical_length --;
        }
    }

    return result;

}

int main(int argc, char const *argv[])
{
    int maxtrixSize = ROW;
    int matrixColSize[ROW];
    int i, j;
    for (i=0; i<ROW; i++)
    {
        matrixColSize[i] = COL;
    }

    // int temp[ROW][COL] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17,18,19,20}, {21,22,23,24}};
    // int temp[ROW][COL] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    // int temp[ROW][COL] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    // int temp[ROW][COL] = {{1,2,3}, {4,5,6}, {7,8,9}};
    // int temp[ROW][COL] = {{1,2,3}};
    int temp[ROW][COL] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, {21, 22, 23, 24, 25, 26, 27, 28, 29, 30}, {31, 32, 33, 34, 35, 36, 37, 38, 39, 40}, {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}, {51, 52, 53, 54, 55, 56, 57, 58, 59, 60}, {61, 62, 63, 64, 65, 66, 67, 68, 69, 70}, {71, 72, 73, 74, 75, 76, 77, 78, 79, 80}, {81, 82, 83, 84, 85, 86, 87, 88, 89, 90}, {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}}; 

     

    int **matrix = (int **)malloc(sizeof(int *) * ROW);
    for (i=0; i<ROW; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * COL);
        for (j=0; j<COL; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }

    printf("< -- Matrix -->\n");
    print_2d_array(matrix, ROW, matrixColSize);
    int returnSize;
    int *result = spiralOrder(matrix, ROW, matrixColSize, &returnSize);

    printf("\n< -- On Spiral Order -- >\n");
    print_array(result, COL*ROW);
    
    return 0;
}

void print_2d_array(int **nums, int row_size, int *col_sizes)
{
    int i;
    printf("[ \n");
    for (i=0; i<row_size; i++)
    {
        print_array(nums[i], col_sizes[i]);
    }
    printf(" ]\n");
}

void print_array(int *nums, int nums_size)
{
    printf("[ ");
    int i;
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

54. Spiral Matrix
Medium
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/