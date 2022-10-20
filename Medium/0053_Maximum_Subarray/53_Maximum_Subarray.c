#include<stdio.h>

int maxSubArray(int* nums, int numsSize)
{
    int sum=0;
    int max;
    int i,j;
    
    max = nums[0];                   // default max as arr[0]
    for(i=0; i<numsSize; i++)        // loop from 0 to numSize
    {
        sum = 0;                     // default a temporary sum for comparing the max
        for(j=i; j<numsSize; j++)    // inner loop gets where ' i ' at
        {
            sum += nums[j];          // sum gets plus everything in the array
            if(sum > max)
            {
                max = sum;           //  if new sum is bigger than old sum, stores in max
            }
        }
    }
    return max;
}


/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23

Constraints:
1 <= nums.length <= 3 * 10^4
-10^5 <= nums[i] <= 10^5
 
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/


void main(void)
{
    int nums[9] = {-1,-2,-3,0};
    int rc = 0;
    
    rc = maxSubArray(nums,9);
    
    printf("The maxSubArray amount is %d",rc);
    
}


// High Level Answer
/*

int maxSubArray(int* nums, int numsSize)
{
    
    if (numsSize == 1) 
    {
        return nums[0];
    }
    
    int global_max = nums[0], local_max = nums[0];
    
    for (int i = 1; i < numsSize; i++) 
    {
        
        local_max += nums[i];
        
        if (local_max < nums[i]) 
        {
            local_max = nums[i];
        }
        
        if (local_max > global_max) 
        {
            global_max = local_max;
        }
        
    }
    
    return global_max;
}

*/