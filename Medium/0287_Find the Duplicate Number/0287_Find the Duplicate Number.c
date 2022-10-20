#include<stdlib.h>
#include<stdio.h>

int compare(int *nums, int numsSize, int curr);

int findDuplicate(int* nums, int numsSize)
{
    int start = 1;
    int end = numsSize;
    int duplicate = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        printf("curr --> %d,  low --> %d,  high --> %d\n", mid, start, end);

        if ( compare(nums, numsSize, mid) > mid )  // if count of all num in arr is smaller than mid, go left, else go right
        {
            duplicate = mid;                       // Search Right
            end = mid - 1;
        }
        else
        {
            start = mid + 1;                       // Search Left
        }
    }
    return duplicate;
}

int compare(int *nums, int numsSize, int mid)
{
    int count = 0;
    int i;
    for (i=0; i<numsSize; i++)
    {
        if (nums[i] <= mid)
        {
            count ++;            // check if current nums[i] is le to mid
        }
    }
    return count;
}



int main(int argc, char const *argv[])
{
    // int nums[] = {5,6,17,18,7,8,12,13,14,1,2,3,9,10,11,4,15,16,19,20,20};
    int nums[] = {5,1,2,3,4,5};
    
    int numsSize = sizeof(nums) / sizeof(nums[0]) ;

    printf("NumsSize ---> %d\n", numsSize);

    int rc = findDuplicate(nums, numsSize);
    printf("Duplicates ---> %d", rc);

    return EXIT_SUCCESS;
}

/*

287. Find the Duplicate Number
Medium

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
 
Constraints:
1 <= n <= 10^5
nums.length == n + 1
1 <= nums[i] <= n

All the integers in nums appear only once except for precisely one integer which appears two or more times.

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

*/