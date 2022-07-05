#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*

int range from 2147483647 to -2147483648
 2147483648 will be -2147483648
-2147483649 will be 2147483647

*/


int reverse(int x)
{
    int result = 0;
    bool neg = (x<0); //set neg as bool, true if x<0
    int loop = 1;

    while (x != 0)
    {
        if (neg &&  result < -0x7FFFFFFF/10)  //neg true and "result" is smaller than -2^31 /10
        {
            printf("Loop %d\n",loop);
            printf("neg &&  result < -0x7FFFFFFF/10 | x=%d, result=%d, neg is %d\n",x,result,neg);
            return 0;
        }

        if (!neg &&  result > 0x7FFFFFFF/10)  //neg not true and "result is larger than 2^31 /10
        {
            printf("Loop %d\n",loop);
            printf("!neg &&  result > 0x7FFFFFFF/10 | x=%d, result=%d, neg is %d\n",x,result,neg);
            return 0;
        }

        result *= 10;

        if (neg && x%10 < -0x7FFFFFFF-result)
        {
            printf("Loop %d\n",loop);
            printf("neg &&   x%10 < -0x7FFFFFFF-result | x=%d, result=%d, neg is %d\n",x,result,neg);
            return 0;
        }

        if (!neg && x%10 > 0x7FFFFFFF-result)
        {
            printf("Loop %d\n",loop);
            printf("!neg &&  x%10 > 0x7FFFFFFF-result | x=%d, result=%d, neg is %d\n",x,result,neg);
            return 0;
        }

        result += x%10;
        x /= 10;
        printf("Loop %d: %d %d\n",loop,x,result);
        loop++;

    }
    return result;
}

/* 
int reverse(int x)
{
    int result = 0;
    bool negativeValue = (x<10);

    while(x!=0)
    {
        if(negativeValue && result > 2147483647/10);
        {
            printf("negativeValue && result > 2147483647/10, found result is %d while x is %d\n",result, x);
            return 0;
        }
        
        if(!negativeValue && result < -2147483647/10);
        {
            printf("!negativeValue && result < -2147483647/10, found result is %d while x is %d\n",result, x);
            return 0;
        }
        
        result *=10;
        result += x%10;
        x/=10;
    }

    return result;
} */

/*

Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Example 4:
Input: x = 0
Output: 0

Constraints:
-2^31 <= x <= 2^31 - 1

*/


int main()
{
    int x = 0;
    int result = 0; 
    
    while(1)
    {
        printf("Enter a value:\n");
        scanf("%d",&x);

        result = reverse(x);

        printf("the result is %d\n",result);
    }
    
    return 0;
}


/*
int reverse(int x)
{
    int result = 0;
    bool neg = (x<0); //set neg as bool, true if x<0

    while (x != 0)
    {        
        
        if (neg &&  result < -0x7FFFFFFF/10)  //neg true and "result" is smaller than -2^31 /10
        {           
            printf("neg &&  result < -0x7FFFFFFF/10 | x=%d, result=%d, neg is %d\n",x,result,neg);
            return 0;
        }
        
        if (!neg &&  result > 0x7FFFFFFF/10)  //neg not true and "result is larger than 2^31 /10
        {
            printf("!neg &&  result > 0x7FFFFFFF/10 | x=%d, result=%d, neg is %d\n",x,result,neg);
            return 0;
        }
        
        result *= 10;
        
        if (neg &&   x%10 < -0x7FFFFFFF-result)
        {
            printf("neg &&   x%10 < -0x7FFFFFFF-result | x=%d, result=%d, neg is %d\n",x,result,neg);
            return 0;
        }
        
        if (!neg &&  x%10 > 0x7FFFFFFF-result)
        {
            printf("!neg &&  x%10 > 0x7FFFFFFF-result | x=%d, result=%d, neg is %d\n",x,result,neg);
            return 0;
        }
        
        result += x%10;
        x /= 10;
        printf("%d %d\n",x,result);
    }
    return result;
}
*/


/*
//This is my version 1

int reverse(int x)
{
    int n = x;
    int result = 0;
    int mag = 1;

    n/=10;
    while(n!=0)
    {
        n/=10;
        mag *= 10;
    }

    while(x!=0)
    {
        result += mag*(x%10);
        x/=10;
        mag/=10;
    }

    return result;
}

*/