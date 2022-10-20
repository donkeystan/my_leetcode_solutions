#include<stdio.h>

int firstUniqChar(char *s)
{
    int sizeMark = -1;
    int i = 0;
    int j = 0;
    
    //aebdacedb
    
    for(i=0; s[i] != '\0'; i++)
    {
        for(j=0; s[j] != '\0'; j++)
        {
            if(s[i] == s[j] && i != j)
            {
                //printf("Character %c Repeats at s[%d] and s[%d]\n",s[j],i,j);
                break;
            }
        }
        
        if(s[j] == '\0')
        {
            sizeMark = i;
            break;
        }
    }
   
    return sizeMark;
    
}

/*

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

Constraints:
1 <= s.length <= 10^5
s consists of only lowercase English letters.

*/


void main()
{
    char s[40] = "aebdaedb";
    int rc = 0;
    
    rc = firstUniqChar(s);
    printf("\nThe return output is %d",rc);
    
}
