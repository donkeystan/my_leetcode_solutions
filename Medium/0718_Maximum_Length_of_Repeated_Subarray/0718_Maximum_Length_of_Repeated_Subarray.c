#include<stdlib.h>
#include<stdio.h>

#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

/*
My Solution is to use a dp table to keep track of the subarray as following:

** check the dp[i-1][j-1] to track the max subarray length

  3 2 1 4 7
1 0 0 1 0 0
2 0 1 0 0 0
3 1 0 0 0 0
2 0 2 0 0 0
1 0 0 3 0 0

if nums[i] is equal to nums[j]

    initialize dp[i][j] with 0
    we check if [i-1][j-1] has number in it.
        if i and j are both larger than 0, then we can simply increment the dp[i][j] value by dp[i-1][j-1]
        or we just put 1 in dp[i][j]

*/

int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int max = 0;
    int dp[nums1Size][nums2Size];
    int i, j;

    for (i=0; i<nums1Size; i++)
    {
        for (j=0; j<nums2Size; j++)
        {
            dp[i][j] = 0;
            if (nums1[i] == nums2[j])
            {
                dp[i][j] = 1;
                if (i>0 && j>0)
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
            max = MAX(max, dp[i][j]);
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{

    int nums1[] = {1,2,3,2,1};
    int nums2[] = {3,2,1,4,7};

    // int nums1[] = {1,2,3,4,6,7,8,9};
    // int nums2[] = {6,7,8,1,2,3,4,9};

    // int nums1[] = {1};
    // int nums2[] = {2};

    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    printf("The Maximum Length of Repeated Subarray ---> [ %d ]\n", findLength(nums1, nums1Size, nums2, nums2Size));
    return EXIT_SUCCESS;
}

/*

718. Maximum Length of Repeated Subarray
Medium
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Example 1:
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Example 2:
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100


*/