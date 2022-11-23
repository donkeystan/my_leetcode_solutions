#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int longestCommonSubsequence(char * text1, char * text2)
{
    int text1_len = strlen(text1) + 1;
    int text2_len = strlen(text2) + 1;

    printf("text1_len ---> %d \n", text1_len);
    printf("text2_len ---> %d \n", text2_len);

    int dp_table[text1_len][text2_len];
    int i, j;
    for (i=0; i<text1_len; i++)
    {
        dp_table[i][0] = 0;
    }

    for (j=0; j<text2_len; j++)
    {
        dp_table[0][j] = 0;
    }

    for (i=1; i<text1_len; i++)
    {
        for (j=1; j<text2_len; j++)
        {
            if (text1[i-1] == text2[j-1])
            {
                dp_table[i][j] = dp_table[i-1][j-1] + 1;
            }
            else if (dp_table[i-1][j] >= dp_table[i][j-1])
            {
                dp_table[i][j] = dp_table[i-1][j];
            }
            else
            {
                dp_table[i][j] = dp_table[i][j-1];
            }
        }
    }

    return dp_table[i-1][j-1];
}

/*

Solution:
Use dp_table to record the reulst in each stage of comparison

text1 = ac
text2 = badc

let's create a dp table of size ( text1.len + 1 ) x  ( text2.len + 1 )

int dp_table[3][5]
       
idx:  j    0     1     2     3     4       
i
                 b     a     d     c
        +-----+-----+-----+-----+-----+
0       |  0  |  0  |  0  |  0  |  0  |
        +-----+-----+-----+-----+-----+
1   a   |  0  |  0  |  1  |  1  |  1  |
        +-----+-----+-----+-----+-----+
2   c   |  0  |  0  |  1  |  1  |  2  |
        +-----+-----+-----+-----+-----+

default dp_table[i][0] and dp_table[0][j] as 0s

1. set a nested for loop within text1.len as i and text2.len as j
2. compare text1[0..n] with text2[0..n] by setting if (text1[i-1] == text2[j-1]), which does the job 
3. if text1[i-1] matches text2[j-1], record it to dp_tanlep[i][j] by incrementing it's top-left record by 1,
    dp_table[i][j] = dp_tablep[i-1][j-1] + 1;  
4. if not the text1[i-1] == text2[j-1] match case, we take the larger top or left record from current poition
    to put in current poition
    if (dp_table[i][j-1] >= dp_table[i-1][j] )
        dp_table[i][j] = dp_table[i][j-1]
    else 
        dp_table[i][j] = dp_table[i-1][j]
5. when all the comparison and record is done, 
    the final answer will be in the bottom left corner

*/

int main(int argc, char const *argv[])
{
    // char *text1 = "apque";
    // char *text2 = "bbbbaqu";
    char *text1 = "ac";
    char *text2 = "badc";

    int rc = longestCommonSubsequence(text1, text2);
    printf("rc ---> %d\n", rc);
    return EXIT_SUCCESS;
}

/*

1143. Longest Common Subsequence
Medium

Given two strings text1 and text2,
return the length of their longest common subsequence.

If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with 
some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:
1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/

/*

int get_lcs_length(char *text1, char *text2, int text1_len, int text2_len)
{
    if (text1_len == 0 || text2_len == 0)
    {
        return 0;
    }
    else if ( text1[text1_len-1] == text2[text1_len-1] )
    {
        return ( 1 + get_lcs_length(text1, text2, text1_len-1, text2_len-1));
    }
    else
    {
        return MAX(get_lcs_length(text1, text2, text1_len-1, text2_len), get_lcs_length(text1, text2, text1_len, text2_len-1));
    }
}

*/