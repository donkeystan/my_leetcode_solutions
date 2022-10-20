#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * longestCommonPrefix(char ** strs, int strsSize)
{
    char prefix[200];
    char *result ="";
    char *tmp_ptr;
    int i,j;
    int max_str_size = 0;
    int mark;

    for(i=0; i<strsSize; i++)
    {
        if( strlen(strs[i]) > max_str_size )
        {
            max_str_size = strlen(strs[i]);
        }
        // printf("strs[%d]---> %s\n", i, strs[i] );
        // printf("size_set[%d] len ---> %d\n",i,size_set[i]);
    }
    // printf("max_str_size ---> %d\n",max_str_size);

    for(j=0; j<max_str_size; j++)
    {
        mark = 1;
        for(i=1; i<strsSize; i++)
        {
            // printf("strs[%d][%d]-----> %c\n",i,j,strs[i][j]);

            if( strs[i][j] == strs[0][j] )
            {
               mark ++; 
            }
            else
            {
                break;                            // no need to compare if elements are different
            }
        }

        if(mark == strsSize)
        {
            prefix[j] = strs[0][j];
        }
        else
        {
            break;                               // if same char count is different form strsSize, break the process, no prefix should be returned
        }
        // printf("<--  string end  -->\n");
    }
    prefix[j] = '\0';                           // put NULL char into the array

    tmp_ptr = (char *)malloc(sizeof(char)*(strlen(prefix)+1));

    // printf("strlen(prefix) ---> %d\n",strlen(prefix));
    for(i=0; i<=strlen(prefix); i++)
    {
        tmp_ptr[i] = prefix[i];
    }
    result = tmp_ptr;
    

    return result;
}

int main()
{
    char *strs[3] = {"flllower", "flllow", "flllight"};
    int strsSize = 3;
    char *ptr;
    int len;
    int i;
    int count = 0;

    ptr = longestCommonPrefix(strs,strsSize);

    printf("ptr---> %s\n",ptr);

    return 0;
}



/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/