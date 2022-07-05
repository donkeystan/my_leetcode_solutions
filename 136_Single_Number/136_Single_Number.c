#include<stdio.h>

int singleNumber(int* nums, int numsSize)
{
    int i,j;
    int nonRptNum =0;
    int index = 0 ;
    
    for(i=0; i<numsSize; i++)
    {
        for(j=0; j<numsSize; j++)
        {
            if(nums[i] == nums[j] && i!=j)         // break when same value but not in same index found
            {
                break;
            }
            
            if(j == numsSize-1)                    // check if inner loop runs till the end
            {
                index = i;
            }
        }   
    }  
    nonRptNum = nums[index];

    return nonRptNum;
}

/*

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.


*/


int main()
{
    int nums[] = {4,1,2,1,2,4,5,5,6,6,7,8,7,6};
    int returnValue = 0;
    int n = (sizeof(nums)/sizeof(nums[0])); 
    
    returnValue = singleNumber(nums, n);
    
    printf("%d is the single number",returnValue);
    
    return 0;
}


// High Level Bitwise Operator Solution
/*

int singleNumber(int* nums, int numsSize)
{
    int result = 0;
    while(numsSize>0)
    {
        result = result^nums[numsSize-1];
        numsSize--;
    }
    
    return result;
}

*/