#include<stdio.h>
#include<stdlib.h>

#define ROW 5
#define COL 5

void print_array(int *nums, int nums_size);
void print_2d_array(int **nums, int row_size, int *cols_size);

void merge_sort(int **matrix, int start_row, int end_row, int colSize)
{
    int mid_row;
    if (start_row < end_row)
    {
        mid_row = (start_row + end_row) / 2;
        merge_sort(matrix, start_row, mid_row, colSize);
        merge_sort(matrix, mid_row+1, end_row, colSize);
        int left_len = (mid_row - start_row + 1) * colSize;
        int right_len = (end_row - mid_row) * colSize;
        int nums_left[left_len];
        int nums_right[right_len];
        int i, j, k, k_col;
        k = 0;
        for (i=0; i<(mid_row-start_row+1); i++)
        {
            for (j=0; j<colSize; j++)
            {
                nums_left[k++] = matrix[start_row + i][j];
            }
        }

        k = 0;
        for (i=0; i<(end_row-mid_row); i++)
        {
            for (j=0; j<colSize; j++)
            {
                nums_right[k++] = matrix[mid_row + 1 + i][j];
            }
        }

        i=0, j=0, k=start_row, k_col = 0;
        while (i<left_len && j<right_len)
        {
            if (nums_left[i] <= nums_right[j])
            {
                matrix[k][k_col++] = nums_left[i++];
            }
            else
            {
                matrix[k][k_col++] = nums_right[j++];
            }

            if (k_col == colSize)
            {
                k_col = 0;
                k ++;
            }
        }

        if (i < left_len)
        {
            for (k=k; k<(end_row-start_row+1); k++)
            {
                for (k_col=k_col; k_col<colSize; k_col++)
                {
                    matrix[k][k_col] = nums_left[i++];
                }
            }
        }

        if (i < right_len)
        {
            for (k=k; k<(end_row-start_row+1); k++)
            {
                for (k_col=k_col; k_col<colSize; k_col++)
                {
                    matrix[k][k_col] = nums_right[j++];
                }
            }
        }
    }
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    print_2d_array(matrix, matrixSize, matrixColSize);
    merge_sort(matrix, 0, matrixSize-1, matrixColSize[0]);
    print_2d_array(matrix, matrixSize, matrixColSize);
   
    if (k%matrixColSize[0] == 0)
    {
        return matrix[k/matrixColSize[0]-1][matrixColSize[0]-1];
    }
    return matrix[k/matrixColSize[0]][(k%matrixColSize[0])-1];
}


int main(int argc, char const *argv[])
{   
    int input[ROW][COL] =
    {
        {  1,  4,  7, 11, 15 },
        {  2,  5,  8, 12, 19 },
        {  3,  6,  9, 16, 22 },
        { 10, 13, 14, 17, 24 },
        { 18, 21, 23, 26, 30 }
    };
    
    int k = 5;
    // int k = 9521;
    int **matrix = (int **)malloc(sizeof(int *) * ROW);
    int matrixColSize[ROW];
    int i, j;
    for (i=0; i<ROW; i++)
    {
        matrixColSize[i] = COL;
        matrix[i] = (int *)malloc(sizeof(int) * COL);
        for (j=0; j<COL; j++)
        {
            matrix[i][j] = input[i][j];
        }
    }
    printf("%dthSnallest --> %d\n",kthSmallest(matrix, ROW, matrixColSize, k));
    return EXIT_SUCCESS;
}

void print_array(int *nums, int nums_size)
{
    int i;
    printf("[ ");
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

void print_2d_array(int **nums, int row_size, int *cols_size)
{
    int i;
    printf("[");
    for (i=0; i<row_size; i++)
    {
        print_array(nums[i], cols_size[i]);
    }
    printf("]\n");
}

/*

378. Kth Smallest Element in a Sorted Matrix
Medium
Given an n x n matrix where each of the rows and columns is sorted in ascending order,
return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2).

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2

Follow up:
Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.

*/