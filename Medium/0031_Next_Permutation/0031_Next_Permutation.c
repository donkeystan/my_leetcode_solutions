#include<stdlib.h>
#include<stdio.h>


void swap(int *nums, int index1, int index2)
{
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}

void reverse_array(int *nums, int start, int end)
{
    while (start < end)
    {
        swap(nums, start, end);
        start ++;
        end --;
    }
}
/* This solution is provided by Leetcode Official */
void nextPermutation(int* nums, int numsSize)
{
    int i = numsSize - 2;
    while (i >= 0 && nums[i + 1] <= nums[i])
    {
        i--;
    }   

    if (i >= 0)
    {
        int j = numsSize - 1;
        while (nums[j] <= nums[i])
        {
            j--;
        }
        swap(nums, i, j);
    }
    reverse_array(nums, i + 1, numsSize-1);
}


void print_list(int *nums, int numsSize);

int main(int argc, char const *argv[])
{
    int nums[] = {1,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    nextPermutation(nums, numsSize);
    print_list(nums, numsSize);
    return EXIT_SUCCESS;
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



/*

31. Next Permutation
Medium

Companies
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

*/