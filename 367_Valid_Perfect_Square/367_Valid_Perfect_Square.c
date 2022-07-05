#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

bool isPerfectSquare(int num)
{
    int i=1;
    int q;
  
    if ( 1 == num )
    {
        return 1;
    }
    else
    {
        q = num/i;
        while ( ( 0 != i-q ) || ( 1 != i-q ) || ( 1 != q-i ) )
        {
            if ( 0 == i-q )
            {
                if ( 0 == (num%i) )
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }

            if ( 1 == i-q )
            {
                return 0;
            }

            if ( 1 == q-i )
            {
                return 0;
            }
            i++;
            q = num/i;
        }
    }
    return 0;
}


int main(int argc, char *argv[])
{
    int exit = 1;
    int rc;
    int n=1;
    int i;

    // while ( 1 == exit )
    // {
    //     printf("Enter a num: ");
    //     exit = scanf("%d",&n);
    //     fflush(stdin);
    //     rc = isPerfectSquare(n);
    //     printf("rc ---> %d\n\n",rc);
    // }

    FILE *fptr;
    fptr = fopen("out.txt","w+");
    for ( i=1; i<=10000000; i++)
    {
        rc = isPerfectSquare(i);
        if ( 1 == rc)
        {
            // printf("rc ---> %d\n\n",rc);
            printf("Perfect Square Number found ---> [ %d ]  ---> [ 0x00%X ] \n",i, &i+i);
            fprintf(fptr, "%d\n", i);
        }
    }
    fclose(fptr);


    return EXIT_SUCCESS;
}

/*

367. Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt.

Example 1:
Input: num = 16
Output: true

Example 2:
Input: num = 14
Output: false

Constraints:
1 <= num <= 2^31 - 1

*/