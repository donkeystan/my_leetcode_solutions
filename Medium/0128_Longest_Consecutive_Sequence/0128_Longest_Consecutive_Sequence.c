#include<stdio.h>
#include<stdlib.h>

void print_array(int *nums, int start, int end)
{
    int i;
    printf("[ ");
    for (i=start; i<=end; i++)
    {
        printf("%d",nums[i]);
        if (i < end)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

int maxLength(int *nums, int numsSize)
{
    int count = 1;
    int max = 1;
    int i, j;
    for (i=0, j=1; j<numsSize; i++, j++)
    {
        if ( 1 == (nums[j] - nums[i]) )
        {
            count ++;
            max = count > max ? count : max;
        }
        
        else if ( nums[j] == nums[i] ) 
        {
            max = count > max ? count : max;
        }
        
        else 
        {
            max = count > max ? count : max;
            count = 1;
        }
    }
    return max;
}

void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);
        int left_len = mid - start + 1;
        int right_len = end - mid;
        int nums_left[left_len];
        int nums_right[right_len];
        int i, j, k;
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

int longestConsecutive(int* nums, int numsSize)
{
    if (numsSize == 1)
    {
        return 1;
    }

    if (numsSize == 0 )
    {
        return 0;
    }

    print_array(nums, 0, numsSize-1);
    int start = 0;
    int end = numsSize - 1;
    merge_sort(nums, start, end);
    print_array(nums, 0, numsSize-1);
    return maxLength(nums, numsSize);
}

int main(int argc, char const *argv[])
{
    // int nums[] = {100, 4, 200, 1, 3, 2};
    // int nums[] = {0,3,7,2,5,8,4,6,0,1};
    // int nums[] = {0,1,2,5,7,8,9,10,12,13,14};
    int nums[] = { 1, 2, 0, 1 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int rc = 0;
    rc = longestConsecutive(nums, numsSize);
    printf("rc ---> %d\n", rc);
    return EXIT_SUCCESS;
}


/*

128. Longest Consecutive Sequence
Medium

Share
Given an unsorted array of integers nums,
return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 
Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

*/
