#include<stdio.h>
#include<stdlib.h>
#define NEWLINE printf("\n");

int print_array(int *array, int array_size);
int bin_search(int *array, int target, int start_index, int end_index);

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *return_nums = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    int start = 0;
    int end = numsSize - 1;
    int rc = -1;
    int i, j;
    int range_low = -1;
    int range_high = -1;

    if (numsSize != 0)
    {
        rc = bin_search(nums, target, start, end);
    }

    if (rc != -1)
    {
        i = rc;
        while (i >= 0 && nums[i] == target)
        {
            range_low = i;
            i --;
        }
        
        j = rc;
        while ( j <= end && nums[j] == target)
        {
            range_high = j;
            j++;
        }
    }

    return_nums[0] = range_low;
    return_nums[1] = range_high;

    return return_nums;
}

int bin_search(int *nums, int target, int start, int end)
{
   int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (target == nums[mid])
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}



int main(int argc, char const *argv[])
{
    int nums[] = {5,7,7,8,8,10};
    // int nums[] = {};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    int target = 8;
    int returnSize = 0;
    int *return_nums;

    printf("nums_size---> %d\n", nums_size);
    print_array(nums, nums_size);

    return_nums = searchRange(nums, nums_size, target, &returnSize);
    NEWLINE;

    printf("Range :");
    print_array(return_nums, returnSize);

    return EXIT_SUCCESS;
}

int print_array(int *nums, int nums_size)
{
    int i;

    for (i=0; i<nums_size; i++)
    {
        printf("%d ", nums[i]);
    }
    NEWLINE
}


/*

34. Find First and Last Position of Element in Sorted Array
Medium

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
 

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9


*/

/*

int bin_search(int *nums, int target, int start, int end)
{
    int mid;
    
    if (start <= end)
    {
        mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            printf("target found at nums[%d]\n", mid);
            return mid;
        }
        else if (target < nums[mid])
        {
            printf("Go left---> nums[%d to %d]\n", start, mid-1);
            return bin_search(nums, target, start, mid-1);
        }
        else
        {
            printf("Go Right---> nums[%d to %d]\n", mid+1, end);
            return bin_search(nums, target, mid+1, end);
        }
    }
    return -1;
}

*/

/*

int bin_search(int *nums, int target, int start, int end)
{
   int mid;

    while (start < end)
    {
        mid = (start + end) / 2;

        if (target == nums[mid])
        {
            return mid;
        }

        if (target < nums[mid])
        {
            printf("Go left ---> [%d to %d]\n", start, mid);
            end = mid - 1;
        }
        else
        {
            printf("Go left ---> [%d to %d]\n", mid+1, end);
            start = mid + 1;
        }
    }

    return -1;
}


*/
