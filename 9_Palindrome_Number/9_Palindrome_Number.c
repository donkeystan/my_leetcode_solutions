#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPalindrome(int x)
{
    int nums[10];
    int n = x;
    int numsSize;
    int loopSize;
    int i;
    int same_count = 0;

    if(x < 0)
    {
        return false;
    }
    else
    {
        i = 0;
        while(n>0)
        {
            nums[i] = n%10;
            n/=10;
            i++;
        }

        numsSize = i;
        loopSize = i/2;
        
        for(i=0; i<loopSize; i++)
        {
            printf("%d--->%d  <--check-->  ",i,nums[i]);
            printf("%d--->%d\n",(numsSize-1-i),nums[numsSize-1-i]);

            if(nums[i] == nums[numsSize-1-i])
            {
                same_count++;
            }
        }
        
        if(same_count == loopSize)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}



int main()
{
    int x = 123454321;
    bool return_bool = isPalindrome(x);
    printf("%d",return_bool);
    return 0;
}






//9. Palindrome Number

/*
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

Example 1:
Input: x = 121
Output: true

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Example 4:
Input: x = -101
Output: false

Constraints:
-2^31 <= x <= 2^31- 1
*/
