#include<stdio.h>
#include<stdlib.h>

int mySqrt(int x)
{
    int i = 1;
    int q;

    if ( 1 == x )
    {
        return 1;
    }
    else
    {   
        q = x/i;
        while ( ( 0 != i-q) || ( 1 != i-q) || ( 1 != q-i ))
        {
            if ( 0 == i-q )
            {
                return i;
            }

            if ( 1 == i-q )
            {
                return q;
            }

            if ( 1 == q-i )
            {
                return i;
            }
            i++;
            q = x/i;
        }
    }

    return 0;
}


int main(int argc, char *argv[])
{
    int exit = 1;
    int rc;
    int n=1;

    while ( 1 == exit )
    {
        printf("Enter a num: ");
        exit = scanf("%d",&n);
        rc = mySqrt(n);
        printf("rc ---> %d\n\n",rc);
        // n++;
    }


    // while ( n<5000 )
    // {
    //     // printf("Enter a num: ");
    //     // exit = scanf("%d",&n);
    //     rc = mySqrt(n);
    //     printf("%d\n",rc);
    //     n++;
    // }

    return EXIT_SUCCESS;
}

/*

69. Sqrt(x)

Share
Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Example 1:
Input: x = 4
Output: 2

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 
Constraints:
0 <= x <= 2^31 - 1

*/