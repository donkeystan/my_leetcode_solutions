#include<stdlib.h>
#include<stdio.h>

void print_list(int *nums, int start, int end);

void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);
        int i, j, k, left_len = (mid - start + 1), right_len = (end - mid);
        int nums_left[left_len], nums_right[right_len];
        for (i=0; i<left_len; i++)
        {
            nums_left[i] = nums[start + i];
        }
        for (i=0; i<right_len; i++)
        {
            nums_right[i] = nums[mid + 1 + i];
        }
        for (i=0, j=0, k=start; i<left_len && j<right_len; k++)
        {
            if (nums_left[i] <= nums_right[j])
            {
                nums[k] = nums_left[i++];
            }
            else
            {
                nums[k] = nums_right[j++];
            }
        }
        while (i < left_len)
        {
            nums[k++] = nums_left[i++];
        }
        while (j < right_len)
        {
            nums[k++] = nums_right[j++];
        }
    }
}

int singleNumber(int* nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }

    int singleNum = 0;
    merge_sort(nums, 0, numsSize-1);
    print_list(nums, 0, numsSize-1);

    int i;
    if (nums[0] != nums[1])
    {
        return nums[0];
    }

    if (nums[numsSize-1] != nums[numsSize-2])
    {
        return nums[numsSize-1];
    }

    for (i=1; i<numsSize-2; i++)
    {
        if (nums[i] != nums[i-1] && nums[i] != nums[i+1])
        {
            return nums[i];
        }
    }

    return singleNum;
}

/*

if 0-idx is different from 1-idx, 0-idx is a single number

if end-idx is different from end-1-idx , end-idx is a single number

rest of the check relie on looping through 1-idx to end-1-idx
check if the pointed idx is different from previous one and next one

*/

int main(int argc, char const *argv[])
{
    int nums[] = {0,1,0,1,0,1,99};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    print_list(nums, 0, numsSize-1);
    int rc = singleNumber(nums, numsSize);
    printf("The Single Number ---> %d \n", rc);
    return EXIT_SUCCESS;
}


void print_list(int *nums, int start, int end)
{
    int i;
    printf("[ ");
    for (i=start; i<=end; i++)
    {
        printf("%d", nums[i]);
        if (i < end)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}



/*


137. Single Number II
Medium

Given an integer array nums where every element appears three times except for one,
which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99

Constraints:
1 <= nums.length <= 3 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
Each element in nums appears exactly three times except for one element which appears once.

*/