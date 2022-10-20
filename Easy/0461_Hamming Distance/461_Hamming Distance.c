#include<stdio.h>
#include<stdlib.h>

int hammingDistance(int x, int y)
{
    int count = 0;

    while (x!=0 || y!=0)
    {
        if ((x%2) != (y%2))
        {
            count ++;
        }
        x/=2;
        y/=2;
    }

    return count;    
}


int main(int argc, char const *argv[])
{
    int x = 2147483647;
    int y = 67456;
    int rc = 0;

    rc = hammingDistance(x,y);

    printf("rc ---> %d\n",rc);

    return EXIT_SUCCESS;
}


/*

461. Hamming Distance
Easy
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, return the Hamming distance between them.

Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Example 2:
Input: x = 3, y = 1
Output: 1
 
Constraints:

0 <= x, y <= 2^31 - 1


*/