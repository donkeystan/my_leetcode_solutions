#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool checkPerfectNumber(int num)
{
    int sq;
    int i;
    int sum;
    sq = sqrt(num) + 1;
    // printf("sq--->%d\n",sq);

    if( num == 1 )
    {
        return false;
    }

    sum = 1;
    for(i=2; i<sq; i++)
    {
        if( num%i == 0 )
        {
            sum += ( i + (num/i) );                 // if(28%2==0), 28//2==24, sum+= (2+14),.....
            // printf("loop--->%d, num/%d--->%d, sum--->%d\n",i,i,num/i,sum);
        }
    }

    if( sum == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}



int main()
{
    int num=33550336;
    int rc;
    int i;
    rc = checkPerfectNumber(num);
    printf("rc--->%d, perfect num--->%d\n",rc,num);

    // for(i=0; i<100000000; i++)
    // {
    //     rc = checkPerfectNumber(i);
    //     if(rc==1)
    //     {
    //         printf("rc--->%d, perfect num--->%d\n",rc,i);
    //     }
    // }
    

    return 0;
}


/*

A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

 

Example 1:
Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.

Example 2:
Input: num = 6
Output: true

Example 3:
Input: num = 496
Output: true

Example 4:
Input: num = 8128
Output: true

Example 5:
Input: num = 2
Output: false

Constraints:

1 <= num <= 108
*/