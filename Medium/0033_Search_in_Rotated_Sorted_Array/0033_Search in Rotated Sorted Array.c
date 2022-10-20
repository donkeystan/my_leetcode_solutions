#include<stdlib.h>
#include<stdio.h>
#define NEWLINE printf("\n");
void print_array(int *nums, int start, int end);

int div_search(int *nums, int target, int start, int end);

int search(int* nums, int numsSize, int target)
{
    int rc = -1;
    int start = 0;
    int end = numsSize - 1;
    rc = div_search(nums, target, start, end);
    return rc;
}

int div_search(int *nums, int target, int start, int end)
{
    int mid;

    if (start == end)
    {
        int i;
        for (i=start; i<=end; i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }
    }

    if (start < end)
    {
        mid = (start + end) / 2;

        div_search(nums, target, start, mid);
        div_search(nums, target, mid+1, end);
        
        int i;
        for (i=start; i<=end; i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }
    }
    return -1;
}


int main(int argc, char const *argv[])
{
        
    int nums[] = {8,9,10,11,12,13,14,15,16,17,18,19,20, 1,2,3,4,5,6,7};

    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("NumsSize ---> %d \n\n", numsSize);
    int target = 7;
    int rc = 0;

    rc = search(nums, numsSize, target);
    printf("Return Code ---> %d \n", rc);

    return EXIT_SUCCESS;
}


void print_array(int *nums, int start, int end)
{
    int i;

    printf("[ ");
    for (i=start; i<=end; i++)
    {
        printf("%d", nums[i]);
        if (i != end)
        {
            printf(", ");
        }
    }
    printf(" ]");
    printf("\n");
}

/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function,
nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such
that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target,
return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4

*/