#include<stdio.h>
#include<stdlib.h>

#define ABS(num) ((num) < 0 ? -(num) : (num))

void quick_sort(int *nums, int start, int end);
int partition(int *nums, int start, int end, int pivot);
void swap(int *nums, int index1, int index2);

int threeSumClosest(int* nums, int numsSize, int target)
{
    // 0. Prerequisite, the array must be sorted for two point operation
    quick_sort(nums, 0, numsSize-1);
    int i;
    int current_sum = 0;
    int result_sum = 0xFFFFFFF;
    int left_p, right_p;

    // 1. Major for loop to loop from first elment to numsSize-2
    for (i=0; i<numsSize-2; i++)
    {
        // 1.1 Check from nums[i+1] to nums[ numsSize-1 ] in every nums[i] loop
        left_p = i+1, right_p = numsSize-1;
        while (left_p < right_p)
        {
            // Then get the sum of nums[i] and the element that other two pointers point to
            current_sum = nums[i] + nums[left_p] + nums[right_p];
            
            // Check if any sum is equal to target
            if (current_sum == target)
            {
                return current_sum;
            }
            
            // if the distnace from target is closer, save it to the result
            if (ABS(current_sum - target) <= ABS(result_sum - target))
            {
                result_sum = current_sum;
            }


            // ** Importnat Part :  if the current sum is larger than target, that means we have to shrink the right pointer back a little bit
            //                          else the left pointer step right a little bit
            if (current_sum > target)
            {
                right_p --;
            }
            else
            {
                left_p ++;
            }
        }
    }
    return result_sum;
}

void quick_sort(int *nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = nums[end];
    int pivot_loc = partition(nums, start, end, pivot);
    quick_sort(nums, start, pivot_loc-1);
    quick_sort(nums, pivot_loc+1, end);
}

int partition(int *nums, int start, int end, int pivot)
{
    int left_p = start, right_p = end;
    while (left_p < right_p)
    {
        while (nums[left_p] <= pivot && left_p < right_p)
        {
            left_p ++;
        }

        while (nums[right_p] >= pivot && left_p < right_p)
        {
            right_p --;
        }
        swap(nums, left_p, right_p);
    }
    swap(nums, left_p, end);
    return left_p;
}

void swap(int *nums, int index1, int index2)
{
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {-1, 2, 1, 4};
    int nums[] = {-1000,-5,-5,-5,-5,-5,-5,-1,-1,-1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    // int target = 1;
    int target = -14;
    printf("The Three Sum Closest is --> [ %d ]\n", threeSumClosest(nums, numsSize, target));
    return EXIT_SUCCESS;
}



/*

16. 3Sum Closest
Medium

Given an integer array nums of length n and an integer target,
find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).


Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-10^4 <= target <= 10^4

*/