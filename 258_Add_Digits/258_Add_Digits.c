#include<stdio.h>
#include<stdlib.h>

int addDigits(int num)
{   
    if(num<10)
    {
        return num;
    }
    else
    {
        int sum = 0;

        while(num != 0)
        {
            sum+=num%10;
            num/=10;
        }
        return addDigits(sum);
    }    
}


int main()
{
    int n = 38;
    int rc;
    rc = addDigits(n);
    printf("%d",rc);

    return 0;
}

/*
Given an integer num,
repeatedly add all its digits until the result has only one digit, and return it.

Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Example 2:
Input: num = 0
Output: 0
 
Constraints:

0 <= num <= 2^31 - 1

*/