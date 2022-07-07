#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE_ASCII 256

int isRepeat(int *repeat, int idx);
void reset(int *repeat);

int lengthOfLongestSubstring(char * s)
{
    int repeat[SIZE_ASCII] = {0};
    
    int idx = 0;
    int check_idx = 0;
    int i = 0;
    int j = 0;
    int max = 0;
    int count = 0;

    while ( '\0' != s[i] )
    {
        j = i+1;
        // printf("%c",s[i]);

        idx = s[i++];
        repeat[idx] = 1;
        count = 1;
        
        while ( '\0' != s[j] )
        {
            check_idx = s[j];

            if ( isRepeat(repeat, check_idx) )
            {
                reset(repeat);
                // printf("\nfound repeat [ %c ] , break... count[ %d ]\n\n", s[j], count);
                count = 0;
                
                break;
            }
            else
            {
                // printf("%c",s[j]);
                repeat[check_idx] = 1;
                count ++;
                j++;
            }

            if (count > max)
            {
                max = count;
            }
        }
        // printf("\n");
    }

    if (count > max)
    {
        max = count;
    }

    return max;
}

int main()
{
    char *s = "abcabcbb";
    // char *s = "";
    // char *s = "pwwkew";
    // char *s = "bbbbb";
    // char *s = "axxxxxxbc";
    // char *s = "a";

    int rc;
    rc = lengthOfLongestSubstring(s);
    printf("%d",rc);

    return 0;
}


int isRepeat(int *repeat, int idx)
{
    if (repeat[idx] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void reset(int *repeat)
{
    int i;
    for (i=0; i<SIZE_ASCII; i++)
    {
        repeat[i] = 0;
    }
}

/*

3. Longest Substring Without Repeating Characters

Medium
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0
 

Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.

*/


/*
            check = s[i];

            if ( isRepeat(repeat, check) )
            {
                i++;
                printf("box[%d] exists\n", idx);

                if (count > max)
                {
                    max = count;
                }

                count = 0;

            }
            else
            {

                idx = s[i++];
                repeat[idx] = 1;
                count ++;       
            }


*/