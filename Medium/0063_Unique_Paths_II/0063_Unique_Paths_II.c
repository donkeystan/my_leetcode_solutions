#include<stdlib.h>
#include<stdio.h>
#define GRID_SIZE 4
#define GRID_COL_SIZE 4

int get_path(int **obstacleGrid, int i, int j)
{
    if (obstacleGrid[i][j] == 1)
    {
        return 0;
    }

    if (i>0 && j>0)
    {
        return obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
    }

    if (i>0)
    {
        return obstacleGrid[i-1][j]; 
    }

    if (j>0)
    {
        return obstacleGrid[i][j-1];
    }

    return 1;
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    if (1 == obstacleGrid[obstacleGridSize-1][obstacleGridColSize[0]-1] || 1 == obstacleGrid[0][0])
    {
        return 0;
    }
    
    int i, j;
    for (i=0; i<obstacleGridSize; i++)
    {
        for (j=0; j<obstacleGridColSize[0]; j++)
        {
            obstacleGrid[i][j] = get_path(obstacleGrid, i, j);        
        }
    }
    return obstacleGrid[i-1][j-1];
}

/*
Since it only allows the robot to go right or down.
The path that can reach current dp[i][j] should only come from top and left
So, we just write things to conduct the following operation.

Solution:

0 0 0       1 1 1
0 1 0  -->  1 0 1
0 0 0       1 1 2
return 2
(bottom right dp[i][j])

0 0 0 0     1 1 1 1
0 0 0 0     1 2 3 4
0 1 0 0 --> 1 0 3 7
0 0 0 0     1 1 4 11
return 11
(bottom right dp[i][j])

*/

int main(int argc, char const *argv[])
{
    int obstacleGridColSize[GRID_SIZE];
    int i, j;
    for (i=0; i<GRID_SIZE; i++)
    {
        obstacleGridColSize[i] = GRID_COL_SIZE;
    }
    
    // int tmp[GRID_SIZE][GRID_COL_SIZE] =
    // {
    //     {0, 0, 0},
    //     {0, 1, 0},
    //     {0, 0, 0}
    // };

    int tmp[GRID_SIZE][GRID_COL_SIZE] =
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
    };


    int **obstacleGrid = (int **)malloc(sizeof(int *) * (GRID_SIZE));
    for (i=0; i<GRID_SIZE; i++)
    {
        obstacleGrid[i] = (int *)malloc(sizeof(int) * GRID_COL_SIZE);
        for (j=0; j<GRID_COL_SIZE; j++)
        {
            obstacleGrid[i][j] = tmp[i][j];
        }
    }
    printf(" Unique Path without Obstacle --> [ %d ]\n", uniquePathsWithObstacles(obstacleGrid, GRID_SIZE, obstacleGridColSize));   
    return EXIT_SUCCESS;
}

/*

63. Unique Paths II
Medium
You are given an m x n integer array grid. There is a robot initially located at the top-left corner
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner
(i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 
Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

*/
