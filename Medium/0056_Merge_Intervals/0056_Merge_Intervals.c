#include<stdio.h>
#include<stdlib.h>


void print_2d_array(int **nums, int row_size, int *col_sizes);
void print_array(int *nums, int numsSize);
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void merge_sort_2d(int **nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort_2d(nums, start, mid);
        merge_sort_2d(nums, mid+1, end);
        int left_len = mid - start + 1;
        int right_len = end - mid;
        int i, j, k;
        int nums_left[left_len][2];
        int nums_right[right_len][2];
        
        for (i=0; i<left_len; i++)
        {
            for (j=0; j<2; j++)
            {
                nums_left[i][j] = nums[start + i][j];
            }
        }

        for (i=0; i<right_len; i++)
        {
            for (j=0; j<2; j++)
            {
                nums_right[i][j] = nums[mid + 1 + i][j];
            }
        }

        for (i=0, j=0, k=start; i<left_len && j <right_len; k++)
        {
            if (nums_left[i][0] <= nums_right[j][0])
            {
                nums[k][0] = nums_left[i][0];
                nums[k][1] = nums_left[i++][1];
            }
            else
            {
                nums[k][0] = nums_right[j][0];
                nums[k][1] = nums_right[j++][1];
            }
        }

        while (i < left_len)
        {
            nums[k][0] = nums_left[i][0];
            nums[k++][1] = nums_left[i++][1];
        }
        
        while (j < right_len)
        {
            nums[k][0] = nums_right[j][0];
            nums[k++][1] = nums_right[j++][1];
        }
    }
}


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    // 0. if length of the intervals is less than 2, simply return the original intervals back
    if (intervalsSize < 2)
    {
        (*returnSize) = 1;
        (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
        (*returnColumnSizes)[0] = 2;
        return intervals;
    }

    // 1. use merge sort to sort by the first index of each intervals
    merge_sort_2d(intervals, 0, intervalsSize-1);

    // 2. set a segment head and a segment end by intervals[0]
    int i, count = 0;
    int seg_head = intervals[0][0], seg_end = intervals[0][1];
    int **result = (int **)malloc(sizeof(int *) * intervalsSize);

    // 3. Loop through the sorted intervals from [1] as [0] is set as a base one
    for (i=1; i<intervalsSize; i++)
    {
        // 3.1 if current interval head is less than seg_end, which means it's within the current segment
        if (seg_end >= intervals[i][0])
        {
            // 3.1.1 if current interval is within the segment, then compare if the seg_end needs to be enlarged
            seg_end = intervals[i][1] > seg_end ? intervals[i][1] : seg_end; 
        }
        else
        {
            // 3.1.2  if current intervalis not within the segment, then write the head and end as a new set to the resultant malloc space
            result[count] = (int *)malloc(sizeof(int) * 2);
            result[count][0] = seg_head;
            result[count][1] = seg_end;
            count ++;

            // 3.1.2 after resultant write process is done, set current interval as segment head and segment end for rest of the loop
            seg_head = intervals[i][0];
            seg_end = intervals[i][1];
        }
    }

    // 4. Once the loop is done, write the current segment head and segment end to the resultant malloc space and return the result
    result[count] = (int *)malloc(sizeof(int) * 2);
    result[count][0] = seg_head;
    result[count][1] = seg_end;
    count ++;
    (*returnSize) = count;
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    for (i=0; i<count; i++)
    {
        (*returnColumnSizes)[i] = 2;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int samples[8][2] = { {1,3}, {2,6}, {6,8}, {8,10}, {15,18}, {8,10}, {3,4}, {13,15} };
    int intervalSize = sizeof(samples)/sizeof(samples[0]); 
    int intervalColSize = sizeof(samples[0]) / sizeof(samples[0][0]);
    int **intervals = (int **)malloc(sizeof(int *) * intervalSize);

    printf("IntervalSize ---> %d\n", intervalSize);
    printf("colSize --------> %d\n", intervalColSize);

    int i, j;
    
    for (i=0; i<intervalSize; i++)
    {
        intervals[i] = (int *)malloc(sizeof(int) * 2);
    }

    for (i=0; i<intervalSize; i++)
    {
        for (j=0; j<intervalColSize; j++)
        {
            intervals[i][j] = samples[i][j];
        }
    }

    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **result = merge(intervals, intervalSize, &intervalColSize, &returnSize, &returnColumnSizes);
    print_2d_array(result, returnSize, returnColumnSizes);
    return EXIT_SUCCESS;
}

void print_array(int *nums, int numsSize)
{
    int i;
    printf("[ ");
    for (i=0; i<numsSize; i++)
    {
        printf("%d", nums[i]);
        if (i < numsSize-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void print_2d_array(int **nums, int row_size, int *col_sizes)
{
    int i, j;
    printf("[\n");
    for (i=0; i<row_size; i++)
    {
        printf(" [ ");
        for (j=0; j<col_sizes[i]; j++)
        {
            printf("%d", nums[i][j]);
            if (j < col_sizes[i]-1)
            {
                printf(", ");
            }
        }
        printf(" ]");
        if (i < row_size-1)
        {
            printf(", ");
        }
        printf("\n");
    }
    printf("]\n\n");
}

/*

56. Merge Intervals
Medium

Companies
Given an array of intervals where intervals[i] = [starti, endi],
merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Constraints:

1 <= intervals.length <= 10^4
intervals[i].length == 2

0 <= starti <= endi <= 10^4
*/