#include<stdio.h>
#include<stdlib.h>

# define MAX(a, b) ((a) > (b) ? (a) : (b))

int jump(int* nums, int numsSize)
{
    // preare start / end for slide window operation
    int jumps = 0, start = 0, end = 0, max_jump, i;

    // if end of slide window does not exceed the numsSize-1, loop goes
    while (end < numsSize-1)
    {

        // set max_jump to defauly
        max_jump = 0;

        // loop from start to the end of the window
        for (i=start; i<=end; i++)
        {
            // find the max jump poisition to update the end of window for next loop
            max_jump = MAX(max_jump, (i + nums[i]));
        }

        // update start with previous end's next position
        // update end with max_jummp position
        // another window found means jump should be incremented by 1
        start = end + 1;
        end = max_jump;
        jumps ++;
    }
    return jumps;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {2,3,1,1,4};
    // int nums[] = {1, 1, 1, 2, 0, 1, 1, 0};
    int nums[] = {4, 1, 1, 1, 1, 2, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("The minimum number of jumps to numsSize-1 --> [%d]\n", jump(nums, numsSize));
    return EXIT_SUCCESS;
}

/*

45. Jump Game II
Medium

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2

Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].

*/