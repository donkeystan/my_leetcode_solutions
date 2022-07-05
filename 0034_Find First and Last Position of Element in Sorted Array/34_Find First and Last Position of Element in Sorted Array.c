#include<stdio.h>
#include<stdlib.h>
#define NEWLINE printf("\n");

int print_array(int *array, int array_size);
int search(int *array, int target, int start_index, int end_index);

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{

    int *return_nums = (int *)malloc(2 * sizeof(int));
    int mid = numsSize / 2;
    int end = numsSize-1;
    int rc;
    int *ptr_high = nums + end;   // pointer starts from end idx
    int *ptr_low = nums;          // pointer starts from start idx
    int low_index = -1;           // initialize
    int high_index = -1;
    int i;

    for (i=0; i<numsSize/2+1; i++)
    {
        printf("*ptr_l+%d ---> %d\n", i, *ptr_low);
        if(target == *ptr_low)
        {
            low_index = i;
            break;
        }

        ptr_low += 1;
    }

    for (i=0; i<numsSize/2; i++)
    {
        printf("*ptr_h-%d ---> %d\n", i, *ptr_high);
        
        if(target == *ptr_high)
        {
            high_index = (end-i);
            break;
        }
        ptr_high -= 1;
    }

    printf("low_index---> %d, high_idex---> %d\n", low_index, high_index);
    return_nums[0] = low_index;
    return_nums[1] = high_index;
    *returnSize = 2;

    return return_nums;
}





int main(int argc, char const *argv[])
{
    int nums[] = {5,7,7,8,8,10};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    int target = 6;
    int returnSize = 0;
    int *return_nums;

    printf("nums_size---> %d\n", nums_size);
    print_array(nums, nums_size);

    return_nums = searchRange(nums, nums_size, target, &returnSize);
    NEWLINE;

    printf("Range :");
    print_array(return_nums, returnSize);

    return EXIT_SUCCESS;
}

int print_array(int *nums, int nums_size)
{
    int i;

    for (i=0; i<nums_size; i++)
    {
        printf("%d ", nums[i]);
    }
    NEWLINE
}


/*

34. Find First and Last Position of Element in Sorted Array
Medium

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
 

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9


*/



/*

for (i=0; i<numsSize/2; i++)
    {
        printf("*ptr_l+%d ---> %d,  *ptr_h-%d ---> %d\n", i, *ptr_low, i, *ptr_high);
        if(target == *ptr_low)
        {
            low_index = i;
        }

        if(target == *ptr_high)
        {
            high_index = (end-i);
        }

        if (ptr_low == ptr_high || (ptr_high-1 == ptr_low))
        {
            printf("ptr_l == ptr_h, break\n");
            break;
        }

        // printf("ptr_l: %p,  ptr_h: %p\n", ptr_l, ptr_h);

        ptr_low += 1;
        ptr_high -= 1;
    }

    printf("low_index---> %d, high_idex---> %d\n", low_index, high_index);

*/

/*

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int start = 0;
    int end = numsSize - 1;
    int rc1;
    int rc2;

    rc1 = search(nums, target, start, end);
    printf("rc1 ---> %d\n", rc1);
    NEWLINE

    rc2 = search(nums, target, rc1+1, end);
    printf("rc2 ---> %d\n", rc2);
    NEWLINE

    rc2 = search(nums, target, start, rc1-1);
    printf("rc2 ---> %d\n", rc2);
    NEWLINE
}

int search(int *nums, int target, int start, int end)
{
    int i;
    int mid = (start + end) / 2;
    int return_index = -1;
    int done = 0;

    while (!done)
    {
        if (nums[mid] == target)
        {
            printf("idx found---> %d\n", mid);
            done = 1;
            return_index = mid;
        }
        else if (target > nums[mid])
        {
            printf("target > nums[%d] Go right:  ", mid);
            start = mid;
            mid = ((mid + 1) + end) / 2;
            printf("New mid ---> %d\n", mid);
        }
        else
        {
            printf("target < nums[%d] Go Left:  ", mid);
            end = mid;
            mid = ((start + end) /2);
            printf("New mid ---> %d\n", mid);
        }

        if (end-start <= 1)
        {
            done = 1;
        }
    }
    
    return return_index;
}

*/