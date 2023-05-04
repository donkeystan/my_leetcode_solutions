#include<stdio.h>
#include<stdlib.h>

void print_array(int *nums, int numsSize);

#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

int rob(int* nums, int numsSize)
{
    // return this single number if only oone element in the array
    if (numsSize == 1)
    {
        return nums[0];
    }

    // 0. Prepare a DP table to save the max at the element
    // The tabulation of DP, each DP[i] element represents nums[i]'s largest amount by jumping two step right
    int DP[numsSize];
    int i, j;
    int max = 0;

    
    // 1. Two write the largest amount eash DP[i] can get
    //    we start to traverse from the last element of nums[]
    for (j=numsSize-1; j>=0; j--)
    {
        // Table DP[j] gets nums[j] as original amount it can get
        DP[j] = nums[j];

        // then starting from two steps to the right by for loop of i
        for (i=j+2; i<numsSize; i++)
        {
            // if index i still within the array, do the max value check
            if (i < numsSize)
            {

                // if two steps to the right of current nums[j],
                // check if current nums[j] plus it is larger than the written record of DP[j]
                DP[j] = MAX(DP[j], nums[j] + DP[i]);
            }
        }
        // write max every time we get a new largest value from current DP[j]
        max = MAX(max, DP[j]);
    }

    print_array(DP, numsSize);
    return max;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {1,2,3,1,5,6,8};
    // int nums[] = {2,7,9,3,1};
    // int nums[] = {3,2,0,100};
    int nums[] = {83, 167, 117, 53, 199, 280, 281, 35, 99, 359, 189, 290, 91, 359, 62, 41, 212, 110, 244, 397, 183, 186, 216, 170, 83, 206, 393, 66, 76, 292, 191, 233, 151, 254, 86, 104, 326, 277, 93, 198, 123, 114, 50, 20, 50, 131, 365, 246, 235, 121, 273, 284, 236, 290, 249, 375, 310, 254, 358, 102, 393, 8, 354, 132, 162, 178, 346, 116, 147, 159, 226, 279, 47, 256, 116, 132, 136, 87, 35, 192, 156, 304, 228, 209, 48, 158, 21, 370, 146, 207, 298, 260, 324, 243, 52, 198, 322, 393, 152, 151};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int rc = rob(nums, numsSize);
    printf("rc ---> %d \n", rc);
    return EXIT_SUCCESS;
}

void print_array(int *nums, int numsSize)
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

198. House Robber
Medium
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that
adjacent houses have security systems connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400

*/


/*

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize)
{
    int i;
    int *dp = malloc(sizeof(int) * numsSize);
    
    if (numsSize == 0)
        return 0;
    
    for (i = 0; i < numsSize; i++) {
        switch(i) {
            case 0:
                dp[i] = nums[0];
                break;
            case 1:
                dp[i] = MAX(nums[i], dp[i - 1]);
                break;
            default:
                dp[i] = MAX(nums[i] + dp[i - 2], dp[i - 1]);
        }
    }
    
    return dp[numsSize - 1];
}

*/

/* Fail Code : It's not a even or odd issue.

    int odd_ptr = 1;
    int odd_sum = 0;
    int even_ptr = 0;
    int even_sum = 0;

    while ( odd_ptr < numsSize && even_ptr < numsSize )
    {
        printf("evn: nums[%d] ---> %d \n", even_ptr, nums[even_ptr]);
        even_sum += nums[even_ptr];
        printf("even_sum ---> %d \n", even_sum);

        printf("odd: nums[%d] ---> %d \n", odd_ptr, nums[odd_ptr]);
        odd_sum += nums[odd_ptr];
        printf("odd_sum ---> %d \n", odd_sum);
        
        even_ptr += 2;
        odd_ptr += 2;
    }

    if ( numsSize%2 != 0)
    {
        printf("Extra evn: nums[%d] ---> %d \n", even_ptr, nums[even_ptr]);
        even_sum += nums[even_ptr];
    }

    printf("odd_sum ---> %d \n", odd_sum);
    printf("even_sum ---> %d \n", even_sum);

    return odd_sum >= even_sum ? odd_sum : even_sum;

*/