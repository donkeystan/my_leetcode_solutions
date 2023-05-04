#include<stdio.h>
#include<stdlib.h>

// My solution is to use increment to do the sum since the constraints indicates both a and b within -1000~1000
int getSum(int a, int b)
{
    int i;
    if (b > 0)
    {
        for (i=0; i<b; i++)
        {
            a++;
        }    
    }
    else
    {
        b *= -1;
        for (i=0; i<b; i++)
        {
            a--;
        }    
    }
    return a;
}

int main(int argc, char const *argv[])
{
    printf("Sum --> [ %d ] \n", getSum(-1000, -1000));
    return EXIT_SUCCESS;
}

/*

371. Sum of Two Integers
Medium
Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = 2, b = 3
Output: 5

Constraints:
-1000 <= a, b <= 1000

*/
