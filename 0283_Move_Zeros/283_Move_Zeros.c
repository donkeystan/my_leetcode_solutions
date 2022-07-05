#include<stdio.h>

void moveZeroes(int* nums, int numsSize)
{
    int counter = 0;
    int i, j;
    
    for(i=0; i<numsSize; i++)
    {
        if(nums[i] == 0)
        {
            counter ++;
        }
    }
    
    for(j=0; j<counter; j++)
    {
        for(i=0; i<numsSize-1; i++)
        {
            if(nums[i] == 0)
            {
                nums[i] ^= nums[i+1];
                nums[i+1] ^= nums[i];
                nums[i] ^= nums[i+1];
            }
        }
    }
}



/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

 
Example 1:
    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]

Example 2:
    Input: nums = [0]
    Output: [0]
 

Constraints:
1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1

*/

void main(void)
{
    int nums[] = {0,5,0,1,0,0,1,1,1,2,0};
    int i;
    
    moveZeroes(nums,11);
    
    for(i=0; i<11; i++)
    {
        printf("%d, ",nums[i]);
    }
 }
 
 
// High Level Answer

/*

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void moveZeroes(int* nums, int numsSize)
{
    int count = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            swap(&nums[i], &nums[count]);
            count++;
        }
        
    }
}

*/