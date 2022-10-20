#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strStr(char * haystack, char * needle)
{
    int i;
    int j;
    int mark;
    int count;
    int sizeHaystack = strlen(haystack);
    int sizeNeedle = strlen(needle);
    
    printf("sizeHaystack--->%d,\n",sizeHaystack);
    printf("sizeNeedle--->%d,\n",sizeNeedle);

    if(sizeNeedle == 0)
    {
        return 0;
    }
    if(sizeNeedle > sizeHaystack)
    {
        return -1;
    }

    for(i=0; i<sizeHaystack; i++)
    {   
        printf("sizeHaystack %d-%d --->%d , sizeNeedle--->%d,\n",sizeHaystack,i,sizeHaystack-i,sizeNeedle );
        if( (sizeHaystack-i) < sizeNeedle)                              // if left size of haystack is smaller than needle, break the loop
        {
            printf("break occured\n");
            break;
        }      

        if( needle[0] == haystack[i] )
        {
            // printf("needle[0]--->%c found to meet haystack[%d]--->%c\n",needle[0],i,haystack[i]);
            mark = i;                                                    // mark the index when first char of each string mmet
            count = 0;                                                   // set counter to record the length comparison
            for(j=0; j<sizeNeedle; j++)                                  // loop through the entire needle
            {                                                            // make sure not exceeding the size of needle and haystack
                if( needle[j] == haystack[i+j] )                         // compare needle with haystack
                {
                    // printf("needle[%d]--->%c == haystack[%d]--->%c\n",j,needle[j],i+j,haystack[i+j]);
                    count++;                          // count the amount of needle and haystack 
                    // printf("count++ --> %d\n",count);
                }
            }
            if(count == sizeNeedle)
            {
                // printf("found the mark of strStr --> %d\n",mark);                
                return mark;
            }
            // printf("No strStr found after comparison\n");
        }    
    }
    return -1;
}

int main(int argc, char *argv[])
{
    char *haystack = "mississippi";
    char *needle = "issip";
    int rc = strStr(haystack,needle);
    printf("rc--->%d\n",rc);

    return EXIT_SUCCESS;
}

int print_char(char *str)
{
    int i;
    int strsSize = strlen(str);
    for(i=0; i<strsSize; i++)
    {
        printf("%c ",str[i]);
    }
    printf("\n");
    return 0;
}



int is_empty(char *str)
{
    if(strlen(str) != 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}

int int_array_print(int *arr, int numsSize)
{
    int i;
    for(i=0; i<numsSize; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

/*
28. Implement strStr()
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Example 3:
Input: haystack = "", needle = ""
Output: 0

Constraints:
0 <= haystack.length, needle.length <= 5 * 10^4
haystack and needle consist of only lower-case English characters.
*/


/*
// Result : Wrong Anser at "mississippi" vs "issip", expected 4, but get -1

int strStr(char * haystack, char * needle)
{
    int i;
    int count = 0;
    int sizeHaystack = strlen(haystack);
    int sizeNeedle = strlen(needle);
    
    printf("sizeHaystack--->%d,\n",sizeHaystack);
    printf("sizeNeedle--->%d,\n",sizeNeedle);

    if(sizeNeedle == 0)
    {
        return 0;
    }

    if(sizeNeedle > sizeHaystack)
    {
        return -1;
    }

    for(i=0; i<sizeHaystack; i++)
    {   
        if( haystack[i] != needle[count] )
        {
            printf("haystack[%d]--->%c diff needle[%d]--->%c\n",i,haystack[i],count,needle[count]);
            count = 0;
        }

        if( haystack[i] == needle[count] )
        {
            printf("haystack[%d]--->%c meet needle[%d]--->%c\n",i,haystack[i],count,needle[count]);
            count++;
            if(count == sizeNeedle)
            {
                return i-(count-1);
            }
        }
    }
    return -1;
}


// Result : LTE --> 2.134 sec


int strStr(char * haystack, char * needle)
{
    int i;
    int j;
    int mark;
    int count;
    int sizeHaystack = strlen(haystack);
    int sizeNeedle = strlen(needle);
    
    printf("sizeHaystack--->%d,\n",sizeHaystack);
    printf("sizeNeedle--->%d,\n",sizeNeedle);

    if(sizeNeedle == 0)
    {
        return 0;
    }

    if(sizeNeedle > sizeHaystack)
    {
        return -1;
    }

    for(i=0; i<sizeHaystack; i++)
    {
        if( needle[0] == haystack[i] )
        {
            // printf("needle[0]--->%c found to meet haystack[%d]--->%c\n",needle[0],i,haystack[i]);
            mark = i;                                                    // mark the index when first char of each string mmet
            count = 0;                                                   // set counter to record the length comparison
            for(j=0; j<sizeNeedle && i+j<sizeHaystack; j++)              // loop through the entire needle
            {                                                            // make sure not exceeding the size of needle and haystack
                if( needle[j] == haystack[i+j] )                         // compare needle with haystack
                {
                    // printf("needle[%d]--->%c == haystack[%d]--->%c\n",j,needle[j],i+j,haystack[i+j]);
                    count++;                          // count the amount of needle and haystack 
                    // printf("count++ --> %d\n",count);
                }
            }
            if(count == sizeNeedle)
            {
                // printf("found the mark of strStr --> %d\n",mark);                
                return mark;
            }
            // printf("No strStr found after comparison\n");
        }
    }
    return -1;
}


// Tricky solution with built-in strstr function
int strStr(char * haystack, char * needle)
{
    char *  ptr = strstr( haystack , needle );

    if (ptr == NULL) return -1;
    
    return (ptr - haystack);
}


*/