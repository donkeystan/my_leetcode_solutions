#include<stdio.h>
#include<stdlib.h>
void print_array(int *nums, int nums_size);

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int coinChange(int* coins, int coinsSize, int amount)
{
    
    int combo_table[amount + 1];
    int the_amount, j;

    for (j=0; j<amount + 1; j++)
    {
        combo_table[j] = 0xFFFF;
    }

    combo_table[0] = 0;
    for (the_amount=0; the_amount < amount+1; the_amount++)
    {
        for (j=0; j<coinsSize; j++)
        {
            // 從小到大找到amount 為止各金額的組合，舉例 11，就找 1 ～ 11 中的能夠使用 coins 中錢幣種類組合而成的最小組
            // 例： coins = [ 2, 5 ]  組成 11
            // 可得 combo_table[2]  得  combo_table[ 目前金額: 2 - 可用錢幣:2 ] + 1 
            // 接著 combo_table[3]  得  combo_table[ 目前金額: 3 - 可用錢幣:2 ] + 1 --> 意味追查到 combo_table[1] 時發現數職為預設65535 ，代表之前沒發現可組成 金額為 1 的最小組數
            // 因此 combo_table[3] 再比較 combo_table[1]+1 的65536後，維持combo_table[3]為 65536
            //  依此類推到 combo_table[11] 時會分別找到 combo_table[9] 的最小組成數及 comb_table[6]的最小組成數
            if (coins[j] <= the_amount)
            {
                combo_table[the_amount] = MIN( combo_table[the_amount], combo_table[ the_amount - coins[j] ] + 1 );
                // printf("amount --- >%d , coins[%d] --- >%d,  combo_table[ %d - %d ]+1 --- > combo_table[%d] gets %d \n", the_amount, j, coins[j], the_amount, coins[j], combo_table[the_amount], combo_table[ the_amount - coins[j] ] + 1);
                // print_array(combo_table, amount+1);
                // printf("\n");
            }
        }
    }
    return combo_table[amount] != 0xFFFF ? combo_table[amount] : -1;
}

int main(int argc, char const *argv[])
{
    // int coins[] = {1, 2, 5};
    int coins[] = {2, 5};
    // int coins[] = {5};
    // int coins[] = {1};
    // int coins[] = {186,419,83,408};
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    // int amount = 0;
    // int amount = 6249;
    int amount = 11;
    printf("coinChange --> [ %d ]\n", coinChange(coins, coinsSize, amount));
    return EXIT_SUCCESS;
}

void print_array(int *nums, int nums_size)
{
    int i;
    printf("[ ");
    for (i=0; i<nums_size; i++)
    {
        printf("%d", nums[i]);
        if (i < nums_size-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

/*

322. Coin Change
Medium

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4

*/

/* Time Limit Exceeded

void merge_sort(int *nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);
        int i, j, k, left_len = (mid-start+1), right_len = (end - mid), nums_left[left_len], nums_right[right_len];
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
            if (nums_left[i] >= nums_right[j])
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

int __coinChange(int *coins, int coinsSize, int amount, int start, int count, int *min)
{
    if (amount == 0)
    {
        (*min) = MIN((*min), count);
        return count;
    }

    if (amount < 0)
    {
        return count - 1;
    }

    int i;
    for (i=start; i<coinsSize; i++)
    {
        __coinChange(coins, coinsSize, amount-coins[i], i, count+1, min);
    }

    return count;
}

int coinChange(int* coins, int coinsSize, int amount)
{
    int min = 0xFFFFFFF;
    merge_sort(coins, 0, coinsSize-1);
    print_array(coins, coinsSize);
    __coinChange(coins, coinsSize, amount, 0, 0, &min);
    if (min == 0xFFFFFFF)
    {
        min = -1;
    }
    return min; 
}


*/

/* Online example

int coinChange(int* coins, int coinsSize, int amount)
{
    int i, j;
    int dp[amount + 1];
    for (i=0; i<amount + 1; i++)
    {
        dp[i] = 10001;
    }

    dp[0] = 0;
    for (i=0; i < amount+1; i++)
    {
        for (j=0; j<coinsSize; j++)
        {
            if (coins[j] <= i)
            {
                printf("i --- >%d , coins[%d] --- >%d,  dp[ %d - %d ]+1 --- >%d \n", i, j, coins[j], i, coins[j], dp[ i - coins[j] ] + 1);
                dp[i] = MIN( dp[i], dp[ i - coins[j] ] + 1 );
                print_array(dp, amount+1);
                printf("\n");
            }
        }
    }
    return dp[amount] == 10001 ? -1 : dp[amount];
}

*/