#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int num1, int num2)
{
    if(num1>num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

int lcs(char *text1, char*text2, int len_t1, int len_t2)
{
    
    if(len_t1 == 0 || len_t2 ==0)
    {
        printf("Goes into base condition\n");
        return 0;
    }
    else if( text1[len_t1-1] == text2[len_t2-1] )
    {
        printf("text1[%d] is %c, text2 [%d] is %c\n", len_t1, len_t2, text1[len_t1], text2[len_t2]);
        printf("Same char found, goes into recursion\n");
        return ( 1 + lcs( text1, text2, len_t1-1, len_t2-1));
    }
    else
    {
        printf("Different char found, goes into recursion\n");
        return max(lcs( text1, text2, len_t1, len_t2-1 ), lcs( text1, text2, len_t1-1,len_t2 ) );
    }
}



int longestCommonSubsequence(char * text1, char * text2)
{
    int len_t1 = strlen(text1);
    int len_t2 = strlen(text2);

    return lcs(text1,text2,len_t1,len_t2);
}

int main()
{
    // char *text1 = "hofubmnylkra";
    // char *text2 = "pqhgxgdofcvmr";
    char *text1 = "apque";
    char *text2 = "bbbbaqu";
    int rc;

    rc = longestCommonSubsequence(text1,text2);
    printf("%d",rc);

    return 0;
}