#include<stdio.h>
#include<stdlib.h>

void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);
        int i, j, k, left_len=(mid - start + 1), right_len = (end - mid);
        int nums_left[left_len], nums_right[right_len];
        for (i=0; i<left_len; i++)
        {
            nums_left[i] = nums[start + i];
        }

        for (i=0; i<right_len; i++)
        {
            nums_right[i] = nums[mid + 1+ i];
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

        while (i<left_len)
        {
            nums[k++] = nums_left[i++];
        }

        while (j<right_len)
        {
            nums[k++] = nums_right[j++];
        }
    }
}


int maxIceCream(int* costs, int costsSize, int coins)
{
    merge_sort(costs, 0, costsSize-1);
    int i = 0;
    while (coins >= costs[i] && i<costsSize)
    {
        coins -= costs[i++];  
    }
    return i;
}

int main(int argc, char const *argv[])
{
    // int costs[] = {10,6,8,7,7,8};
    // int costs[] = {1,6,3,1,2,5};
    int costs[] = {1,3,2,4,1};
    int costsSize = sizeof(costs) / sizeof(costs[0]);
    int coins = 7;
    printf("This little boy is able to buy [ %d ] IceCreams\n", maxIceCream(costs, costsSize, coins));
    return EXIT_SUCCESS;
}

/*

1833. Maximum Ice Cream Bars
Medium

It is a sweltering summer day, and a boy wants to buy some ice cream bars.
At the store, there are n ice cream bars. You are given an array costs of length n,
where costs[i] is the price of the ith ice cream bar in coins.
The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
Return the maximum number of ice cream bars the boy can buy with coins coins.

Note: The boy can buy the ice cream bars in any order.

Example 1:
Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.

Example 2:
Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.

Example 3:
Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.

Constraints:
costs.length == n
1 <= n <= 10^5
1 <= costs[i] <= 10^5
1 <= coins <= 10^8

*/
