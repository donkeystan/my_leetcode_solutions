#include<stdio.h>
#include<stdlib.h>

int int_array_print(int *arr, int numsSize);

int removeElement(int* nums, int numsSize, int val)
{
    int i;
    int j;
    int count;
    int tmp;

    if(numsSize == 0)
    {
        return 0;
    }

    j = 0;
    for(i=0; i<numsSize; i++)
    {
        if(nums[i] != val)
        {
            nums[j] =  nums[i];
            j++;
        }
    }
    return j;
}


int main(int argc, char *argv[])
{
    int nums[] = {33, 1, 33, 3, 33, 5, 33, 7, 33, 9, 33, 11, 33, 13, 33, 15, 33, 17, 33, 19, 33, 21, 33, 23, 33, 25, 33, 27, 33, 29, 33, 31, 33, 33, 33, 35, 33, 37, 33, 39, 33, 41, 33, 43, 33, 45, 33, 47, 33, 49, 33, 1, 33, 3, 33, 5, 33, 7, 33, 9, 33, 11, 33, 13, 33, 15, 33, 17, 33, 19, 33, 21, 33, 23, 33, 25, 33, 27, 33, 29, 33, 31, 33, 33, 33, 35, 33, 37, 33, 39, 33, 41, 33, 43, 33, 45, 33, 47, 33, 49};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 33;
    int i;
    int rc;

    int_array_print(nums, numsSize);
    rc = removeElement(nums, numsSize,val);
    printf("rc--->%d\n",rc);
    int_array_print(nums, rc);
    return EXIT_SUCCESS;
}


int int_array_print(int *arr, int numsSize)
{
    int i;
    for(i=0; i<numsSize; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}


/*

27. Remove Element
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, 
you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array.
You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:
The judge will test your solution with the following code:
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

*/

/*

[33, 1, 33, 3, 33, 5, 33, 7, 33, 9, 33, 11, 33, 13, 33, 15, 33, 17, 33, 19, 33, 21, 33, 23, 33, 25, 33, 27, 33, 29, 33, 31, 33, 33, 33, 35, 33, 37, 33, 39, 33, 41, 33, 43, 33, 45, 33, 47, 33, 49, 33, 1, 33, 3, 33, 5, 33, 7, 33, 9, 33, 11, 33, 13, 33, 15, 33, 17, 33, 19, 33, 21, 33, 23, 33, 25, 33, 27, 33, 29, 33, 31, 33, 33, 33, 35, 33, 37, 33, 39, 33, 41, 33, 43, 33, 45, 33, 47, 33, 49]

*/