#include<stdio.h>
#include<stdlib.h>

void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);
        int i, j, k, left_len = (mid - start + 1), right_len = (end - mid);
        int nums_left[left_len], nums_right[right_len];
        for (i=0; i<left_len; i++)
        {
            nums_left[i] = nums[start + i];
        }
        for (i=0; i<right_len; i++)
        {
            nums_right[i] = nums[mid + 1 + i];
        }
        for (i=0, j=0, k=start; i<left_len && j<right_len; k++)
        {
            if (nums_left[i] <= nums_right[j])
            {
                nums[k] = nums_left[i++];
            }
            else
            {
                nums[k] = nums_right[j++];
            }
        }
        while (i < left_len)
        {
            nums[k++] = nums_left[i++];
        }
        while (j < right_len)
        {
            nums[k++] = nums_right[j++];
        }
    }
}

// 0 1 2 3 4
// 2 3 4 5 1
int findMin(int* nums, int numsSize)
{
    merge_sort(nums, 0, numsSize-1);
    return nums[0];
}

int main(int argc, char const *argv[])
{
    // int nums[] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 1, 2 };
    // int nums[] = {3,1,2};
    int nums[] = {2,3,4,5,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int rc = findMin(nums, numsSize);
    printf("rc ---> %d \n", rc);
    return 0;
}

/*

153. Find Minimum in Rotated Sorted Array
Medium
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.

*/

/* Solution 1, merge sort, but slow, only beats 7% of the submission

void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);
        int i, j, k, left_len = (mid - start + 1), right_len = (end - mid);
        int nums_left[left_len], nums_right[right_len];
        for (i=0; i<left_len; i++)
        {
            nums_left[i] = nums[start + i];
        }
        for (i=0; i<right_len; i++)
        {
            nums_right[i] = nums[mid + 1 + i];
        }
        for (i=0, j=0, k=start; i<left_len && j<right_len; k++)
        {
            if (nums_left[i] <= nums_right[j])
            {
                nums[k] = nums_left[i++];
            }
            else
            {
                nums[k] = nums_right[j++];
            }
        }
        while (i < left_len)
        {
            nums[k++] = nums_left[i++];
        }
        while (j < right_len)
        {
            nums[k++] = nums_right[j++];
        }
    }
}

*/