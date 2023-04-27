#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isDup(int *nums, int mid, int start, int end)
{
    if (mid == start || mid == end)
    {
        return 1;
    }

    if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
    {
        return 1;
    }
    return 0;
}

void findLeftRight(int *nums, int mid, int *left_end, int *right_start, int start, int end)
{
    if (nums[mid-1] == nums[mid])
    {
        (*left_end) = mid-2;
        (*right_start) = mid+1;
    }

    if (nums[mid+1] == nums[mid])
    {
        (*left_end) = mid-1;
        (*right_start) = mid+2;
    }
}

bool isOddSize(int start, int end)
{
    if ( ((end - start + 1) % 2) != 0 ) 
    {
        return 1;
    }
    return 0;
}

/*
                                      0  1  2  3  4  5  6  7  8
    Looking into the array structure [1, 2, 2, 4, 4, 5, 5, 6, 6]
    Clearly we can see, due to the single Non-Duplicated numer, the array is in [ Odd Size ]

    if we start looking for the non-duplicated number by using binary search.

    [1, 2, 2, 4] [4] [5, 5, 6, 6] we can check if the current element at mid is a non-duplicated by function isDup( )
    then we use findLeftRight( ) to get the [end of left index] and [ start of the right index ] to see which one is in OddSize by using isOddSize( )
    if we get an oddSize left or right array, go into the search.

    [ 1, 2, 2 ] ->  [1] mid:[2] [2] -> [1] is odd
    [ 1 ] -> mid:[1], isDup() finds it a non-diplicated and return it.
*/

int find(int *nums, int start, int end)
{
    int mid;
    if (start <= end)
    {
        mid = (start + end) / 2;
        if (isDup(nums, mid, start, end))
        {
            return nums[mid];
        }

        int left_end, right_start;
        findLeftRight(nums, mid, &left_end, &right_start, start, end);

        if (left_end >= start && isOddSize(start, left_end))
        {
            return find(nums, start, left_end);
        }
        
        if (right_start <= end && isOddSize(right_start, end))
        {
            return find(nums, right_start, end);
        } 
    }
    return -1;
}

int singleNonDuplicate(int* nums, int numsSize)
{
    return find(nums, 0, numsSize-1 );
}

int main(int argc, char const *argv[])
{
    int nums[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("The Single Duplicate --> %d \n", singleNonDuplicate(nums, numsSize));
    return EXIT_SUCCESS;
}


/*

540. Single Element in a Sorted Array
Medium
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5

*/