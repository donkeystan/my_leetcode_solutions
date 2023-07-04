#include<stdio.h>
#include<stdlib.h>
#define GRID_SIZE 3

#define MIN(a, b) ((a) <= (b) ? (a) : (b) )

int get_current_min_sum(int **grid, int i, int j)
{
    if (j>0 && i >0)
    {
        return MIN(grid[i][j]+grid[i-1][j], grid[i][j]+grid[i][j-1]);
    }
    
    if (j>0)
    {
        return grid[i][j] + grid[i][j-1];
    }
    
    if (i>0)
    {
        return grid[i][j] + grid[i-1][j];
    }
    
    return grid[i][j];
}

// traverse through the grid
// grid[i][j] get grid[i-1][j] or grid[i][j-1] as a temp minimum sum
// the return the last grid[i][j]
int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int i, j;
    for (i=0; i<gridSize; i++)
    {
        for (j=0; j<gridColSize[i]; j++)
        {
            grid[i][j] = get_current_min_sum(grid, i, j);
        }
    }
    return grid[i-1][j-1];
}

int main(int argc, char const *argv[])
{
    int gridColSize[GRID_SIZE];
    int i, j;
    for (i=0; i<GRID_SIZE; i++)
    {
        gridColSize[i] = GRID_SIZE;
    }
    
    int tmp[GRID_SIZE][GRID_SIZE] =
    {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int **grid = (int **)malloc(sizeof(int *) * (GRID_SIZE));
    for (i=0; i<GRID_SIZE; i++)
    {
        grid[i] = (int *)malloc(sizeof(int) * GRID_SIZE);
        for (j=0; j<GRID_SIZE; j++)
        {
            grid[i][j] = tmp[i][j];
        }
    }
    printf(" Minumum Path Sum --> [ %d ]\n", minPathSum(grid, GRID_SIZE, gridColSize));
    return 0;
}

/*

64. Minimum Path Sum
Medium
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

*/