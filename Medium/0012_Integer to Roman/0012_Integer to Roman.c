#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * intToRoman(int num)
{
    // 1. Prepare a set of Roman Numbers to store how many roman letters we need to transfer from keys[]
    int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // 2. Prepare keys[] as sets of strings of roman letter for transfer process
    char *keys[13] =
    {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };

    // 3. Process to get how many of the letters in each key we need and store the amount in original nums
    char tmp_result[20];
    int i, j, k, l=0, tmp, key_len;
    for (i=0; i<numsSize; i++)
    {
        tmp = num / nums[i];
        num %= nums[i];
        nums[i] = tmp;
    }

    // 4. After above process, we can start the transfer and store each char in the tmp_result array
    for (i=0; i<numsSize; i++)
    {
        key_len = strlen(keys[i]);
        for (j=0; j<nums[i]; j++)
        {
            for (k=0; k<key_len; k++)
            {
                tmp_result[l++] = keys[i][k];
            }
        }
    }

    // 5. Store the result string for return
    char *result = (char *)malloc(sizeof(char) * (l+1));
    for (i=0; i<l; i++)
    {
        result[i] = tmp_result[i];
    }
    result[l] = '\0';

    return result;
}

int main(int argc, char const *argv[])
{
    // int num = 1994;
    int num = 3999;
    char *result = intToRoman(num);
    puts(result);
    return EXIT_SUCCESS;
}

/*

12. Integer to Roman
Medium

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

CM            900
CD            400
XC            90
XL            40
IX            9
IV            4            

For example, 2 is written as II in Roman numeral, just two one's added together.
12 is written as XII, which is simply X + II.
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Example 1:
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.

Example 2:
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 
Constraints:
1 <= num <= 3999

*/

