#include<stdio.h>
#include<stdlib.h>
#define COL 2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void print_array(int *nums, int nums_size);
void print_2d_array(int **nums, int row_size, int col_size);

void merge_sort_2d(int **nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort_2d(nums, start, mid);
        merge_sort_2d(nums, mid+1, end);

        int i, j, k, q;
        int left_len = (mid - start + 1), right_len = (end - mid);
        int nums_left[2][left_len];
        int nums_right[2][right_len];

        for (i=0; i<2; i++)
        {
            for (j=0; j<left_len; j++)
            {
                nums_left[i][j] = nums[i][start + j];
            }
        }

        for (i=0; i<2; i++)
        {
            for (j=0; j<right_len; j++)
            {
                nums_right[i][j] = nums[i][mid + 1 + j];
            }
        }

        for (i=0, j=0, k=start; i<left_len && j<right_len; k++)
        {
            if (nums_left[0][i] <= nums_right[0][j])
            {
                for (q=0; q<2; q++)
                {
                    nums[q][k] = nums_left[q][i];
                }
                i++;
            }
            else
            {
                for (q=0; q<2; q++)
                {
                    nums[q][k] = nums_right[q][j];
                }
                j++;
            }
        }

        while (i < left_len)
        {
            for (q=0; q<2; q++)
            {
                nums[q][k] = nums_left[q][i];
            }
            k++;
            i++;
        }

        while (j < right_len)
        {
            for (q=0; q<2; q++)
            {
                nums[q][k] = nums_right[q][j];
            }
            k++;
            j++;
        }
    }
}

void bin_search(int **nums, int target, int start, int end, int *the_index)
{
    int mid;
    if (start <= end)
    {
        mid = (start + end) / 2;
        if (target == nums[0][mid])
        {
            (*the_index) = nums[1][mid];
            return;
        }
        else if (target < nums[0][mid])
        {
            (*the_index) = nums[1][mid];
            bin_search(nums, target, start, mid-1, the_index);
        }
        else
        {
            bin_search(nums, target, mid+1, end, the_index);
        }
    }
}
/*
    My Solution Note:

    1. to return an array recording the index of each intervals minimized right intervals
    2. I use tabulation to write a 2d table to record each unique interval start and its index in an malloc 2d array
    
        for 2d array [ [ 5, 6 ], [ 3, 4 ], [ 2, 3 ], [ 1, 2 ] ]

        Its table_of_starts looks like this:
                    +---+---+---+---+
                idx | 0 | 1 | 2 | 3 |
                    +---+---+---+---+
            starts | 5 | 3 | 2 | 1 |
                    +---+---+---+---+
        starts_idx | 0 | 1 | 2 | 3 |
                    +---+---+---+---+

    3. Then do the merge_sort_2d, and it will loks like this:

                    +---+---+---+---+
                idx | 0 | 1 | 2 | 3 |
                    +---+---+---+---+
            starts | 1 | 2 | 3 | 5 |
                    +---+---+---+---+
        starts_idx | 3 | 2 | 1 | 0 |
                    +---+---+---+---+

    4. Then do the binary search without return, but to use an variable (call by refrence to record)
        
        initialize a variable -1 and pass it's reference

        target = intervals[i][1] 

        if the target is equal to nums[mid][0], record the nums[mid][1] as the starts_index and return
        if the target is smaller than nums[mid][0], record the nums[mid][1] as the current starts_index, but to keep search right for closer answer
        if the target is larger than nums[mid][0], don't record, just keep searching left

    5. then write the answer in the malloc array and return it to caller
*/
int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize)
{
    (*returnSize) = intervalsSize;
    int *result = (int *)malloc(sizeof(int) * (*returnSize));
    int i;
    int **table_of_starts = (int **)malloc(sizeof(int *) * 2);
    for (i=0; i<2; i++)
    {
        table_of_starts[i] = (int *)malloc(sizeof(int) * (*returnSize));    
    }

    for (i=0; i<intervalsSize; i++)
    {
        table_of_starts[0][i] = intervals[i][0];
        table_of_starts[1][i] = i;
    }

    print_2d_array(table_of_starts, 2, intervalsSize);
    merge_sort_2d(table_of_starts, 0, intervalsSize-1);
    print_2d_array(table_of_starts, 2, intervalsSize);

    for (i=0; i<intervalsSize; i++)
    {
        int the_index = -1;
        bin_search(table_of_starts, intervals[i][1], 0, intervalsSize-1, &the_index);
        result[i] = the_index;
    }

    return result;
}


int main(int argc, char const *argv[])
{
    int temp[][COL] = {{5,6}, {3,4}, {2,3}, {1,2}};
    // int temp[][COL] = {{8, 9}, {3,4}, {2,3}, {1,2}, {5,6}};
    int intervalsSize = sizeof(temp) / sizeof(temp[0]); 
    int intervalsColSize = COL;
    int **intervals = (int **)malloc(sizeof(int *) * intervalsSize);
    int returnSize;
    int i, j;
    for (i=0; i<intervalsSize; i++)
    {
        intervals[i] = (int *)malloc(sizeof(int) * COL);
        for (j=0; j<COL; j++)
        {
            intervals[i][j] = temp[i][j];
        }
    }
    print_2d_array(intervals, intervalsSize, COL);
    
    int *result = findRightInterval(intervals, intervalsSize, &intervalsColSize, &returnSize);
    print_array(result, returnSize);

    return EXIT_SUCCESS;
}

void print_2d_array(int **nums, int row_size, int col_size)
{
    int i;
    printf("[\n");
    for (i=0; i<row_size; i++)
    {
        print_array(nums[i], col_size);
    }
    printf("]\n");
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


/*

436. Find Right Interval
Medium
You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.
Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.

Example 1:
Input: intervals = [[1,2]]
Output: [-1]
Explanation: There is only one interval in the collection, so it outputs -1.

Example 2:
Input: intervals = [[3,4],[2,3],[1,2]]
Output: [-1,0,1]
Explanation: There is no right interval for [3,4].
The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.

Example 3:
Input: intervals = [[1,4],[2,3],[3,4]]
Output: [-1,2,-1]
Explanation: There is no right interval for [1,4] and [3,4].
The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.
 
Constraints:
1 <= intervals.length <= 2 * 10^4
intervals[i].length == 2
-10^6 <= starti <= endi <= 10^6
The start point of each interval is unique.

*/