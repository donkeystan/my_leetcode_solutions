#include<stdio.h>
#include<stdlib.h>

void print_list(int *nums, int numsSize);

void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);
        int i,j,k;
        int left_len = mid - start + 1;
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

int findKthLargest(int* nums, int numsSize, int k)
{
    merge_sort(nums, 0, numsSize-1);
    print_list(nums, numsSize);
    return nums[numsSize-k];
}

void print_list(int *nums, int numsSize)
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


int main(int argc, char const *argv[])
{
    int nums[] = {3,2,1,5,6,4};
    int k = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int rc = findKthLargest(nums, numsSize, k);
    printf("rc---> %d\n", rc);
    return EXIT_SUCCESS;
}

/*

215. Kth Largest Element in an Array
Medium
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
You must solve it in O(n) time complexity.

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

*/