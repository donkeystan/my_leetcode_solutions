#include<stdio.h>
#include<stdlib.h>

void print_list(int *nums, int numsSize);

int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 1)
    {
        return 1;
    }

    if (numsSize == 2)
    {
        return 2;
    }
 
    // 1. two pointer from 0 and 1 , traverse the same time.
    int prev = 0;
    int curr = 1;
    int same = 0;
    int count = 0;
    

    // 2. Loop through the array
    while (curr < numsSize)
    {
        // 2.1. if two pointer sits in two different value, same default 0
        //      or update same by increment
        same = (nums[prev] == nums[curr]) ? (++same) : 0 ;   
        
        // 2.2 if same is within 2
        if (same == 0 || same == 1)
        {
            
            // 2.2.1 put prev and curr into the nums starting from count = 0
            nums[count++] = nums[prev];           
            nums[count] = nums[curr];
        }

        prev ++;
        curr ++;
    }
    return count+1;
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
    int nums[] = {0,0,1,1,1,1,2,3,3};
    // int nums[] = {1,1,1,2,2,3};
    // int nums[] = {0,1,2,3};
    // int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    print_list(nums, numsSize);
    returnSize = removeDuplicates(nums, numsSize);
    printf("\nReturn K Size ---> %d \n", returnSize);
    print_list(nums, returnSize);
    return EXIT_SUCCESS;
}


/*

80. Remove Duplicates from Sorted Array II
Medium

Given an integer array nums sorted in non-decreasing order,
remove some duplicates in-place such that each unique element appears at most twice.
The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages,
you must instead have the result be placed in the first part of the array nums.
More formally, if there are k elements after removing the duplicates,
then the first k elements of nums should hold the final result.
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array.
You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Example 1:
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:
1 <= nums.length <= 3 * 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in non-decreasing order.

*/