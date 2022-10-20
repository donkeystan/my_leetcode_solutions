#include<stdlib.h>
#include<stdio.h>

void print_array(int *nums, int numsSize);

/*
Step 1: Find the actual rotate point by %=
Step 2: Pin the actual rotate point
Step 3: Get an extra space to process the array rotate a swap
*/
void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;
    if (k != 0)
    {
        int tmp[numsSize];
        int pinIndex = numsSize-k;
        int i;
        for (i=0; pinIndex<numsSize; i++)
        {
            tmp[i] = nums[pinIndex++];
        }

        int j = 0;
        for (i; i < numsSize; i++)
        {
            tmp[i] = nums[j++]; 
        }

        for (i=0; i<numsSize; i++)
        {
            nums[i] = tmp[i];
        }
    }
}


int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3,4,5,6,7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 8;

    rotate(nums, numsSize, k);
    print_array(nums, numsSize);


    return EXIT_SUCCESS;
}


void print_array(int *nums, int numsSize)
{
    int i;
    printf("Array ---> [ ");
    for (i=0; i<numsSize; i++)
    {
        printf("%d", nums[i]);
        if (i<numsSize-1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}



/*

189. Rotate Array
Medium
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5
 
Follow up:
Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/