#include<stdlib.h>
#include<stdio.h>

int search(int *nums, int start, int end, int numsSize)
{
    int mid;

    if ( start < end )
    {
        mid = (start + end) / 2;        

        if ( mid != 0 && nums[mid] < nums[mid-1]) 
        {
            return search( nums, start, mid-1, numsSize);
        }
        else if ( mid != numsSize-1 && nums[mid] < nums[mid+1])
        {
            return search( nums, mid+1, end, numsSize);
        }
        else
        {
            return mid;
        }
    }

    return start;
}

int findPeakElement(int* nums, int numsSize)
{
    return search(nums, 0, numsSize-1, numsSize);
}

int main(int argc, char const *argv[])
{
    // int nums[] = {1,2,1,3,5,6,4};
    // int nums[] = {1,2,3,4,5,6,7};
    // int nums[] = {7,6,5,4,3,2,1};
    int nums[] = {5,4,3,4,5};
    // int nums[] = {2,1};
    // int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int rc = findPeakElement(nums, numsSize);
    printf("Peak Num ---> %d \n", rc);
    return EXIT_SUCCESS;
}

/*

162. Find Peak Element
Medium

A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞.
In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

Constraints:
1 <= nums.length <= 1000
-2^31 <= nums[i] <= 2^31 - 1
nums[i] != nums[i + 1] for all valid i.

*/