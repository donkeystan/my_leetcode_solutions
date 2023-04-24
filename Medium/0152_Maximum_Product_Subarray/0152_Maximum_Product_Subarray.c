#include<stdio.h>
#include<stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void swap(int *num1, int *num2)
{
    int tmp = (*num1);
    (*num1) = (*num2);
    (*num2) = tmp;
}

int maxProduct(int* nums, int numsSize)
{
    // 0. Prepare 3 variables to store the temporary maximum, minimum for possible negative value multiplication for max min reverse
    //    while store the current maxium product in result variable for return
    // save the first element in result, max, and min variables

    int i;
    int result = nums[0];
    int max = result, min = result;

    // 1.1 Loop through 1 to the last element
    for (i=1; i<numsSize; i++)
    {
        // 1.1 Both temp max and min multiplied by current element, nums[i] 
        max *= nums[i];
        min *= nums[i];

        // 1.2 if current element is a negative value, swap the value
        if (nums[i] < 0)
        {
            swap(&max, &min);
        }

        // 1.3 After multiplication by current element
        // situation #1: if current element is a zero, then both max and min will be zero while result still remains previous max value
        // situation #2: if previous element is a zero, causing max and temp to be set at zero
        //                  if current element is larger than 0, then current element can be set as max for next element mulbiplication
        //                  if current element is less than 0, then current element can be set as min for next element mulbiplication and see if possible reverse occur 
        max = MAX(max, nums[i]);
        min = MIN(min, nums[i]);

        // 1.4 Always check if result has the maximum product
        result = MAX(max, result);

        printf("nums[%3d] --> %3d, max --> %3d, min --> %3d, result --> %3d\n", i, nums[i], max, min, result);
    }

    // return the result whether result has gone through the loop or not
    return result;
}


int main(int argc, char const *argv[])
{
    int nums[] = {2, 3, 2, 4};
    // int nums[] = { -9, 8, 2, 1, 0, 3, -4, 5, 8 };
    int numsSize = sizeof(nums) / sizeof(nums[0]); 
    printf("Max Product --> %d\n", maxProduct(nums, numsSize));
    return EXIT_SUCCESS;
}

/*

152. Maximum Product Subarray
Medium
Given an integer array nums, find a subarray
that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

Constraints:
1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

*/