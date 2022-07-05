#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

bool isHappy(int n)
{
    int num;
    int i = 0;
    int sum;
    
    while(1)
    {   
        sum = 0;
        while(n!=0)
        {
            num = n%10;
            sum += (num*num);
            n /= 10;
        }        
        
        if(sum == 1)
        {
            return 1;
            break;
        }
        
        if(sum == 89)
        {
            return 0;
            break;
        }
        n = sum;
    }

}

/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, 
replace the number by the sum of the squares of its digits.

Repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1.

Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.


Example 1:

Input: n = 19
Output: true

Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1


Example 2:

Input: n = 2
Output: false
 
Constraints:

1 <= n <= 231 - 1
*/


int main()
{
    int n = 0;
    int rc = 0;
    int i;
    int happy = 0;
    int unhappy = 0;
    
    for(i=1; i<=100; i++)
    {
        rc = isHappy(i);
        if(rc ==1)
        {
            happy++;
            printf("We got a happy number! %d\n",i);
        }
        else
        {
            unhappy++;
            printf("Not a happy number! %d\n",i);
        }

    }
    
    printf("The result is : \n");
    printf("Happy Number      : %d\n",happy);
    printf("Non- Happy Number : %d\n",unhappy);
    
    system("pause");
    

    /*
    while(1)
    {
        printf("Please enter a number to see if it's happye number: \n");
        scanf("%d",&n);
        rc = isHappy(n);
        
        printf("rc gets %d\n",rc);
        
    }*/
   
    return 0;
}


