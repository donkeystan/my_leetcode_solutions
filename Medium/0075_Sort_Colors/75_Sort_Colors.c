#include<stdio.h>
#include<stdlib.h>
#define NEWLINE printf("\n");

void print_array(int *num, int numsSize);
void merge_sort(int *nums, int start, int end);


void sortColors(int* nums, int numsSize)
{
    int start = 0;
    int end = numsSize -1 ;
    merge_sort(nums, start, end);
}

int main(int argc, char const *argv[])
{
    int nums[] = {1, 2, 0, 0, 0, 1, 2, 2, 1, 1, 2, 1, 2, 1, 0, 1, 0, 0, 1, 2, 2, 0, 2, 0, 1, 2, 0, 0, 0, 1, 2, 2, 0, 1, 1, 1, 2, 0, 0, 0, 0, 0, 2, 2, 1, 2, 1, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 2, 0, 2, 0, 2, 1, 1, 1, 2, 0, 1, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 2, 0, 1, 0, 1, 2, 2, 0, 2, 2, 2, 1, 2, 1, 2, 0, 2, 0, 1, 1, 2, 2, 0, 2, 1, 0, 2, 2, 0, 0, 2, 1, 2, 2, 2, 1, 0, 0, 1, 0, 1, 1, 0, 2, 0, 1, 1, 1, 0, 0, 1, 0, 2, 1, 1, 0, 1, 0, 2, 1, 1, 0, 0, 2, 1, 1, 1, 2, 0, 0, 2, 2, 0, 2, 2, 0, 1, 1, 2, 1, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 2, 2, 0, 2, 2, 1, 1, 2, 2, 1, 2, 2, 2, 1, 1, 2, 0, 1, 2, 2, 0, 0, 2, 1, 2, 0, 0, 2, 2, 2, 0, 2, 1, 0, 0, 1, 0, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 0, 1, 2, 0, 0, 2, 0, 2, 0, 2, 0, 2, 2, 1, 1, 2, 2, 2, 2, 1, 2, 2, 1, 1, 0, 0, 2, 1, 2, 2, 0, 2, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 2, 0, 0, 2, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 2, 0, 0, 0, 1, 0, 0, 0, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf(" Original Array\n");
    print_array(nums, numsSize);

    sortColors(nums, numsSize);

    printf(" Sorted Array\n");
    print_array(nums, numsSize);
    
    

    return EXIT_SUCCESS;
}

void merge_sort(int *nums, int start, int end)
{
    int mid;
    int i,j,k;

    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);

        int len_left = mid - start + 1;
        int len_right = end - mid;
        int nums_left[len_left];
        int nums_right[len_right];

        for (i=0; i < len_left; i++)
        {
            nums_left[i] = nums[start + i];
        }

        for (i=0; i < len_right; i++)
        {
            nums_right[i] = nums[mid + 1 + i];
        }
        
        for (i=0, j=0, k=start; i < len_left && j < len_right; k++)
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

        if (i < len_left)
        {
            for (i=i; i < len_left ;i++)
            {
                nums[k++] = nums_left[i];
            }
        }

        if (j < len_right)
        {
            for (j=j; j < len_right ;j++)
            {
                nums[k++] = nums_right[j];
            }
        }     
    }
}

void print_array(int *nums, int numsSize)
{
    int i;
    for (i=0; i<numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    NEWLINE
}


/*
75. Sort Colors
Medium

Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

*/