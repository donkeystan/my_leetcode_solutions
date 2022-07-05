#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

bool isPowerOfTwo(int n)
{
    if (n<=0)
    {
        return false;
    }
    
    int count = 0;

    while(n != 0)
    {
        if (n%2 == 1)
        {
            count ++;
        }
        
        if (count > 1)
        {
            return false;
        }
        n /= 2;
    }

    return true;
}

bool isPowerOfTwo_2(int n)
{
    int i;
    for (i=0; i<=31; i++)
    {
        if (( ( (1 << i) & n) != 0) && ( ((1 << i) ^ n) == 0 ) )
        {
            return true;
        }
    }
    return false;
}


int main(int argc, char const *argv[])
{
    int num = 32;
    bool rc;

    rc = isPowerOfTwo(num);
    printf("rc--->%d\n",rc);

    rc = isPowerOfTwo_2(num);
    printf("rc--->%d\n",rc);

    return EXIT_SUCCESS;
}


/*
231. Power of Two



Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 2^0 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 2^4 = 16

Example 3:
Input: n = 3
Output: false

Constraints:

-2^31 <= n <= 2^31 - 1

*/