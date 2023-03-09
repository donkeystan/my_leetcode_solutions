#include<stdlib.h>
#include<stdio.h>

void print_array(int *nums, int start, int end)
{
    int i;
    printf("[ ");
    for (i=start; i<=end; i++)
    {
        printf("%d",nums[i]);
        if (i < end)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

// 10, 9, 8, 4, 3, 3, 2, 2, 1

// 1, 1, 1, 1, 1

#define min(a,b) (a < b ? a : b)

// Two Pointer solution from Leetcode official solutions

int minSubArrayLen(int target, int* nums, int numsSize)
{
    // 1. Preprocess: sum for , minimam length set at int 32bit max value, and  
    int sum = 0;
    int min_len = 0x7FFFFFFF;
    int left_p = 0;
    
    // 2. Loop through each element
    int i;
    for (i=0; i<numsSize; i++)
    {
        // 2.1 Sum up with every element
        sum += nums[i];

        // 2.2 Whenever sum is found to be larger than taret, roll back by deducting each element that left_p points to
        while (sum >= target)
        {
            // 2.2.1 during each roll back while the sum still within larger/equal to taret
            //       find the min length and rewrite the min length
            min_len = min(min_len, i-left_p+1);

            // 2.2.2 Rollback with left_p pointer increment
            sum -= nums[left_p++];
        }
    }

    // 3. Return min_len if it's rewritten
    return (min_len < 0x7FFFFFFF) ? min_len : 0;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {2,3,1,2,4,3};
    int nums[] = {2,2,3,4,1};
    // int nums[] = {1,1,1,1,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 7;

    printf("NumsSize ---> %d\n\n", numsSize);
    printf("minSubArrayLen ---> %d\n", minSubArrayLen(target, nums, numsSize));

    return 0;
}


/*
209. Minimum Size Subarray Sum
Medium

Given an array of positive integers nums and a positive integer target,
return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target.
If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:
1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4

Follow up: If you have figured out the O(n) solution,
try coding another solution of which the time complexity is O(n log(n)).
*/

/*
// First Attemp - Fail

void find(int *nums, int target, int pin, int numsSize, int *count)
{   
    if ( pin == numsSize )
    {
        (*count) = 0;
        return;
    }

    if ( target - nums[pin] == 0 )
    {
        (*count) ++;
        return;
    }

    if ( target - nums[pin] > 0 )
    {
        target -= nums[pin];
        (*count) ++;
    }

    find (nums, target, pin+1, numsSize, count);
}


*/