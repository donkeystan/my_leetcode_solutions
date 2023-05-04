#include<stdio.h>
#include<stdlib.h>

void print_array(int *nums, int numsSize);

#define MAX(a, b) ((a)>(b) ? (a):(b))

/*  Solution Note
    Use Dynamic Programming SKill with Tabulation

        +---+---+---+---+---+
    idx | 0 | 1 | 2 | 3 | 4 |
        +---+---+---+---+---+
    val | 2 | 5 | 3 | 5 | 7 |
        +---+---+---+---+---+
max val | 4 | 2 | 3 | 2 | 1 |
        +---+---+---+---+---+

    Concept:
    each element is 1 in length, so we create a DP table to hold 1 in each element's max
    use two for loop to find current element's longest increasing sub array

    int LIS[numsSize]
    for j from [end] to [start]
        for [i] from [j+1] to [end]
            if nums[j] sees nums[i] as increasing
                LIS[j] gets the bigger one from LIS[j] vs. 1 + LIS[i]
        check and write max for return.
*/

int lengthOfLIS(int* nums, int numsSize)
{
    int LIS[numsSize];
    int i, j;
    int max = 1;
    for (j=numsSize-1; j>=0; j--)
    {
        LIS[j] = 1;
        for (i=j+1; i<numsSize; i++)
        {
            
            if (nums[j] < nums[i] && i < numsSize)
            {
                LIS[j] = MAX(LIS[j], 1+ LIS[i]);
            }
        }
        max = MAX(max, LIS[j]);
    }
    return max;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {0,1,0,3,2,3};
    // int nums[] = {2,5,3,5,7};
    int nums[] = {10,9,2,5,3,7,101,18};
    // int nums[] ={ 8, 7, 8, 9, 2, 3, 7, 10, 99, 90, 1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("The Longest Increasing Subsequence Length ---> [ %d ]\n", lengthOfLIS(nums, numsSize));
    return EXIT_SUCCESS;
}

void print_array(int *nums, int numsSize)
{
    int i;
    printf("[ ");
    for (i=0; i<numsSize; i++)
    {
        printf("%d", nums[i]);
        if (i < numsSize-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

/*
300. Longest Increasing Subsequence
Medium
Given an integer array nums, return the length of the longest strictly increasing subsequence

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:\
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
 
Constraints:
1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4

*/