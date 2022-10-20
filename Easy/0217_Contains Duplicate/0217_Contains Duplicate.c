#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

void merge_sort(int *nuns, int start, int end);


bool containsDuplicate(int* nums, int numsSize)
{
    merge_sort(nums, 0, numsSize-1);
    int i;
    for (i=0; i<numsSize-1; i++)
    {
        if ( nums[i] == nums[i+1] )
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {5,6,17,18,7,8,12,13,14,1,2,3,9,10,11,4,15,16,19,20,20};
    // int nums[] = {5,1,2,3,4,5};
    int nums[] = {1,1,1,3,3,4,3,2,4,2};
    
    
    int numsSize = sizeof(nums) / sizeof(nums[0]) ;

    printf("NumsSize ---> %d\n", numsSize);

    int rc = containsDuplicate(nums, numsSize);
    printf("containsDuplicate ---> %d", rc);

    return EXIT_SUCCESS;
}

void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;

        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);

        int i,j,k;
        int left_len = mid - start + 1 ;
        int right_len = end - mid;
        int nums_left[left_len];
        int nums_right[right_len];

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

        if (i<left_len)
        {
            for (i=i; i<left_len; i++)
            {
                nums[k++] = nums_left[i];
            }
        }

        if (j<right_len)
        {
            for (j=j; j<right_len; j++)
            {
                nums[k++] = nums_right[j];
            }
        }
    }
}


/*
217. Contains Duplicate

Share
Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

*/