#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int, int);
int partialAdd(char *, char*, char*, char*);

int max(int a, int b)
{
    int result = (a>b)?a:b;
    return result;
}

int partialAdd(char *shorter, char *longer, char *tmp, char *mem)   // len a < len b
{
    int i;
    int j;
    int k;
    int len_shorter = strlen(shorter);
    int len_longer = strlen(longer);
    *mem = '0';
    j = len_longer-1;
    k = 0;

    for (i=len_shorter-1; i>=0; i--)
    {
        printf("\n<----- Loop %d ----->\n",k);
        if ('1'==shorter[i] && '1'== longer[j])
        {
            if ('0' == *mem)
            {
                printf("shorter[%d]--->%c  &&  longer[%d]--->%c  &&  mem--->0\n",i,shorter[i],j,longer[j]);
                tmp[k] = '0';
                *mem = '1';
                printf("    tmp[%d]--->0  &&   mem--->1\n",k);
            }
            else
            {
                printf("shorter[%d]--->%c  &&  longer[%d]--->%c  &&  mem--->1\n",i,shorter[i],j,longer[j]);
                tmp[k] = '1';
                *mem = '1';
                printf("    tmp[%d]--->1  &&   mem--->1\n",k);
            }
        }

        if ( '0'==shorter[i] && '0'== longer[j] )
        {
            if ('0' == *mem)
            {
                printf("shorter[%d]--->%c  &&  longer[%d]--->%c  &&  mem--->0\n",i,shorter[i],j,longer[j]);
                tmp[k] = '0';
                *mem = '0';
                printf("    tmp[%d]--->0  &&   mem--->0\n",k);
            }
            else
            {
                printf("shorter[%d]--->%c  &&  longer[%d]--->%c  &&  mem--->1\n",i,shorter[i],j,longer[j]);
                tmp[k] = '1';
                *mem = '0';
                printf("    tmp[%d]--->1  &&   mem--->0\n",k);
            }
        }

        if ( ('0'==shorter[i] && '1'== longer[j]) || ('1'==shorter[i] && '0'== longer[j]) )
        {
            if ('0' == *mem)
            {
                printf("shorter[%d]--->%c  &&  longer[%d]--->%c  &&  mem--->0\n",i,shorter[i],j,longer[j]);
                tmp[k] = '1';
                *mem = '0';
                printf("    tmp[%d]--->1  &&   mem--->0\n",k);
            }
            else
            {
                printf("shorter[%d]--->%c  &&  longer[%d]--->%c  &&  mem--->1\n",i,shorter[i],j,longer[j]);
                tmp[k] = '0';
                *mem = '1';
                printf("    tmp[%d]--->0  &&   mem--->1\n",k);
            }
        }
        j--;
        k++;
    }
    return k;
}

char * addBinary(char * a, char * b)
{
    int i;
    int j;
    int k;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int size = max(len_a,len_b);
    char tmp[size+1];
    char *result = (char*)malloc(sizeof(char)*(size+2));
    char mem = '0';
    char *p_mem = &mem;
    int rem;

    printf("len a ---> %d\n",len_a);
    printf("len b ---> %d\n",len_b);

    if ( 0 == (len_a - len_b) )
    {
        k = partialAdd(a, b, tmp, p_mem); 
        if ('1' == mem)
        {
            tmp[k] = '1';
        }
        else
        {
            tmp[k] = 'N';
        }
    }

    if (len_a < len_b)
    {
        k = partialAdd(a, b, tmp, p_mem);  // passing shorter array as a and longer as b
        rem = len_b - len_a;

        printf("\n<----- rest of the array ----->\n");

        for (i=rem-1; i>=0; i--)
        {
            if ('1' == b[i])
            {
                if('1' == mem)
                {
                    printf("  b[%d]--->%c  &&  mem--->1\n",i,b[i]);
                    tmp[k] = '0';
                    mem ='1';
                    printf("tmp[%d]--->0  &&   mem--->1\n",k);
                }
                else
                {
                    printf("  b[%d]--->%c\n  &&  mem--->0",i,b[i]);
                    tmp[k] = '1';
                    mem ='0';
                    printf("tmp[%d]--->1  &&   mem--->0\n",k);
                }
            }

            if ('0' == b[i])
            {
                if('1' == mem)
                {
                    printf("  b[%d]--->%c  &&  mem--->1\n",i,b[i]);
                    tmp[k] = '1';
                    mem ='0';
                    printf("tmp[%d]--->1  &&   mem--->0\n",k);
                }
                else
                {
                    printf("  b[%d]--->%c  &&  mem--->0\n",i,b[i]);
                    tmp[k] = '0';
                    mem ='0';
                    printf("tmp[%d]--->0  &&   mem--->0\n",k);
                }
            }
            k++;
        }

        if ('1' == mem)
        {
            tmp[k] = '1';
        }
        else
        {
            tmp[k] = 'N';
        }
    }

    if (len_b < len_a)
    {
        k = partialAdd(b, a, tmp, p_mem);  // passing shorter array as a and longer as b
        rem = len_a - len_b;

        printf("\n<----- rest of the array ----->\n");

        for (i=rem-1; i>=0; i--)
        {
            if ('1' == a[i])
            {
                if('1' == mem)
                {
                    printf("  a[%d]--->%c  &&  mem--->1\n",i,a[i]);
                    tmp[k] = '0';
                    mem ='1';
                    printf("tmp[%d]--->0  &&   mem--->1\n",k);
                }
                else
                {
                    printf("  a[%d]--->%c  &&  mem--->0\n",i,a[i]);
                    tmp[k] = '1';
                    mem ='0';
                    printf("tmp[%d]--->0  &&   mem--->0\n",k);
                }
            }

            if ('0' == a[i])
            {
                if('1' == mem)
                {
                    printf("  a[%d]--->%c  &&  mem--->1\n",i,a[i]);
                    tmp[k] = '1';
                    mem ='0';
                    printf("tmp[%d]--->0  &&   mem--->0\n",k);
                }
                else
                {
                    printf("  a[%d]--->%c  &&  mem--->0\n",i,a[i]);
                    tmp[k] = '0';
                    mem ='0';
                    printf("tmp[%d]--->0  &&   mem--->0\n",k);
                }
            }
            k++;
        }

        if ('1' == mem)
        {
            tmp[k] = '1';
        }
        else
        {
            tmp[k] = 'N';
        }
    }

    printf("\n<----- Result [%d]----->\n",k);
    for (i=0; i<size+1; i++)
    {
        printf("tmp[%d]--->%c\n",i,tmp[i]);
    }

    i=0;
    for (k=k; k>=0; k--)
    {
        if ('1'==tmp[k] || '0'==tmp[k])
        {
            result[i] = tmp[k];
            i++;
        }
    }
    result[i] = '\0';

    return result;
}

int main(int argc, char *argv[])
{
    char *rc = NULL;
    char *a = "10";
    char *b = "1";

    rc = addBinary(a,b);

    puts(rc);

    return EXIT_SUCCESS;
}


/*

0 0 => 0
0 1 => 1
1 0 => 1
1 1 => 1 0

*/


/*
67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
1 <= a.length, b.length <= 10^4
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

*/




/*

    printf("<---- a ---->\n");
    for (i=len_a-1; i>=0; i--)
    {
        printf("%d ---> %c\n",i,a[i]);
    }

    printf("\n<---- b ---->\n");
    for (i=len_b-1; i>=0; i--)
    {
        printf("%d ---> %c\n",i,b[i]);
    }


printf("<--- a --->\n");
for (i=0; '\0' != a[i]; i++)
{
    printf("%c ",a[i]);
}
printf("\n");

printf("<--- b --->\n");
for (i=0; '\0' != b[i]; i++)
{
    printf("%c ",b[i]);
}
printf("\n");

*/
