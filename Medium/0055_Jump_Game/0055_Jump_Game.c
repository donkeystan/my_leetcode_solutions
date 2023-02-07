#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 4, 0, 1, 0, 4
bool canJump(int* nums, int numsSize)
{
    // 0.return if the length of nums is 1 or if the first num is zero, return the 
    if (numsSize == 1)
    {
        return 1;
    }

    if (nums[0] == 0)
    {
        return 0;
    }

    // Concept of implementing Greedy Algorithm 

    // segment_end to be the outter loop to check the segments after being jumped over
    int segment_end = numsSize - 1;
    int i;

    // jumpable to check if a certain index + num[index] can jump over the segment end
    int jumpable = 0;
    
    // 1. segment_end is the current wall that the nums before it has to be checked to see if jumpable is found
    while (segment_end > 0)
    {
        // 1.1 set jumpable to be 0 when starting the inner segment check loop
        jumpable = 0;

        // 1.2 inner loop starts from segment_end - 1
        i = segment_end - 1;
        for (i; i>=0; i--)
        {
            // 1.3 if the index + nums[index] is able to jump over the wall
            if (i + nums[i] >= segment_end)
            {
                // 1.3.1 jumpable found, so the loop has to break  
                jumpable = 1;
                break;
            }
        }

        // if jumpable is found towards current wall, set the current wall at the index found in the inner loop
        if (jumpable)
        {
            segment_end = i;
        }

        // if no jumpable can be found from the end to 0, then it is a can't jump situation, return 0
        if (!jumpable)
        {
            return 0;
        }
    }

    // if the segment_end is at zero while no not jumpable found, it is a can jump situation
    return 1;
}


int main(int argc, char const *argv[])
{
    // int nums[] = {3, 1, 1, 1, 0, 4};
    // int nums[] = {3, 3, 1, 0, 4};
    // int nums[] = {3, 2, 1, 1, 0, 4};
    // int nums[] = {1,1,1,1,0};
    // int nums[] = {1,0};
    // int nums[] = {0,1};
    int nums[] = {3,0,8,2,0,0,1};
    // int nums[] = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    // int nums[] = { 4, 0, 1, 0, 4 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    if (canJump(nums, numsSize))
    {
        printf("< ----- Jumps ----- > \n");
    }
    else
    {
        printf("< ----- Unable -----> \n");
    }
    
    return EXIT_SUCCESS;
}


/*

55. Jump Game
Medium

You are given an integer array nums.
You are initially positioned at the array's first index,
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 
Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5

*/

/* Fail on " 8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5 "

The assertBadZero solution of bad zero is applicable when it meets something lie 3 0 1 0 
bool assertBadZero(int *nums, int segment_end, int segmnet_start)
{
    printf("Assert Bad Zero Sequence\n");
    printf("segment_end = [%d]:%d, segment_start = [%d]:%d\n", segment_end, nums[segment_end], segmnet_start, nums[segmnet_start]);
    int i;
    for (i=segment_end-1; i>=segmnet_start; i--)
    {
        if (i + nums[i] > segment_end)
        {
            return 0;
        }
    }
    return 1;
}

*/

/* Fail on " 3,0,8,2,0,0,1 " 
bool assertBarrier(int *nums, int segment_start, int segment_end)
{
    int i;
    for (i=segment_start; i<segment_end; i++)
    {
        // printf("nums[%d]---> %d ,  segment_end ---> %d\n", i, nums[i], segment_end);
        if (i+nums[i] > segment_end)
        {
            // printf("nums[%d] breaks the barrier\n", i+nums[i]);
            return 0;
        }
    }
    // printf("Can't break the Barrier\n");
    return 1;
}


bool canJump(int* nums, int numsSize)
{
    if (numsSize == 1)
    {
        return 1;
    }

    int end = numsSize - 1;
    int steps_required = end;
    int i;

    for (i=0; i<end; i++)
    {
        if (i+nums[i] < end && nums[i+nums[i]] == 0)
        {
            if (assertBarrier(nums, i, i+nums[i]))
            {
                return 0;
            }
            i += nums[i];
        }

        if (i+nums[i] >= end)
        {
            return 1;
        }
    }
    return 1;
}

*/