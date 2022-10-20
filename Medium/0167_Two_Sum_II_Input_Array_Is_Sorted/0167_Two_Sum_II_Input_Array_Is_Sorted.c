#include<stdio.h>
#include<stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int bin_search(int *nums, int target , int start, int end);


int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int * result_list = (int *) malloc(sizeof(int) * 2);
    int i;
    int start = 0;
    int end = 0;
    int result = 0;

    for (i=0; i<numbersSize; i++)
    {
        start = i+1;
        end = numbersSize-1;
    
        result = bin_search(numbers, target-numbers[i], start, end);

        if (result != 0 && result != -1)
        {
            printf("Found target to sum at ---> [ %d ] \n", result);
            break;
        }

    }
    
    result_list[0] = i+1;
    result_list[1] = result+1;

    *returnSize = 2;
    return result_list;
}


int main(int argc, char const *argv[])
{
    int *result = NULL;

    // int nums[] = {2,7,11,15,16,25,30};
    int nums[] = {1,2,2,2,2,3,3,3,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 5;
    int returnSize = 0;

    result = twoSum(nums, numsSize, target, &returnSize);

    printf("Two Sum ---> [%d , %d]\n", result[0], result[1]);

    return EXIT_SUCCESS;
}


int bin_search(int *nums, int target , int start, int end)
{
    int mid;

    if (start <= end)
    {
        mid = (start + end) / 2;

        if (target == nums[mid])
        {
            printf("Target found ---> [ %d ] ---> %d\n", mid, nums[mid]);
            return mid;
        }
        else if (target < nums[mid])
        {
            printf(" Search Left ---> [ %d to %d ]\n", start, mid-1);
            return bin_search(nums, target, start, mid-1);
        }
        else
        {
            printf("Search Right ---> [ %d to %d ]\n", mid+1, end);
            return bin_search(nums, target,mid+1, end);
        }
    }
    return -1;
}





/*
167. Two Sum II - Input Array Is Sorted
Medium

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
find two numbers such that they add up to a specific target number.

Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

Constraints:

2 <= numbers.length <= 3 * 10^4
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.

*/