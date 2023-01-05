#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char *result_string_gen(char *s, int start, int end);
int isPalindrome(char *s, int start, int end);
void print_fragment(char *s, int start, int end);

char * longestPalindrome(char * s)
{
    // 1. Set (Left Fence, Righ Fence) for outer loop, and (Left P, Right P) for inner loop
    int start = 0;
    int end = strlen(s) - 1;
    char *result = NULL;
    int left_fence = start;
    int right_fence = end;
    int left_p = start;
    int right_p = end;
    int curr_len = 1;

    // 2. check the size in the fence and loop if its size is not zero
    int segment_len = right_fence - left_fence + 1;
    while (segment_len > 0)
    {
        // 3. set (left p, right p) same as the fence
        left_p = left_fence;
        right_p = right_fence;

        // 4. loop by moving both left_p and right_p towards right till any of them exceeds the right fence
        while (left_p <= end && right_p <= end)
        {
            // 5. search from large to small by (left_fence, right_fence)
            // 6. It is the answer if there's any returned palindrome length
            curr_len = isPalindrome(s, left_p, right_p);
            if (curr_len != 0)
            {
                // 7. Generate the returned malloc string and return immdiately
                result = result_string_gen(s, left_p, right_p);
                return result;
            }

            left_p++;
            right_p ++;
        }
        right_fence--;
        segment_len = right_fence - left_fence + 1;
    }
    return result;
}

// check palindrome from large to small by (start, end)
int isPalindrome(char *s, int start, int end)
{   
    int left_p = start, right_p = end;
    int segment_len = (end - start + 1);
    int count = 0;
    while ( left_p < right_p && s[left_p] == s[right_p])
    {
        left_p ++;
        right_p --;
    }

    if (0 != segment_len%2)
    {
        if (((left_p - start) * 2) + 1 == segment_len)
        {
            return segment_len;
        }
    }
    else
    {
        if (((left_p - start) * 2) == segment_len)
        {
            return segment_len;
        }
    }
    return 0;
}

char * result_string_gen(char *s, int start, int end)
{
    int string_size = end - start + 2;
    char *result = (char *)malloc(sizeof(char) * string_size);
    int i;
    for (i=0; i<string_size-1; i++)

    {
        result[i] = s[start+i];
    }
    result[i] = '\0';
    return result;
}

int main(int argc, char const *argv[])
{
    // char *s = "babad";
    // char *s = "cbbd";
    // char *s = "aaaa";
    // char *s = "aaaaa";
    char *s = "abcdfgflkkl";
    // char *s = "abcde";
    // char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    printf("Original String ------> ");
    puts(s);

    char *rs = longestPalindrome(s);

    printf("Longest Palindrome ---> ");
    puts(rs);

    // char *s = "abcddcba";
    // int rc = isPalindrome(s, 0, strlen(s)-1);
    // printf("palidrome len ---> %d\n", rc);

    return EXIT_SUCCESS;
}


void print_fragment(char *s, int start, int end)
{
    int i;

    for (i=start; i<=end; i++ )
    { 
        printf("%c", s[i]);
    }
    printf("\n");
}


/*
5. Longest Palindromic Substring
Medium

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/


/*
Time Limit Exceeded

char * result_string_gen(char *s, int start, int end);
int isPalindrome(char *s, int start, int end);

char * longestPalindrome(char * s)
{
    int strsSize = strlen(s);
    int start = 0;
    int end = 0;
    int max = 1;
    char *result = NULL;

    int i, j;
    for (i=0; i<strsSize; i++)
    {
        for (j=i+1; j<strsSize; j++)
        {
            if ( isPalindrome(s, i, j) )
            {
                if ( (j - i + 1 ) > max  )
                {
                    start = i;
                    end = j;
                    max = j - i + 1;
                }
            }
        }
    }

    if (max > 1)
    {
        result = result_string_gen(s, start, end);
    }
    else
    {
        result = result_string_gen(s, 0, 0);
    }
    
    return result;
}

int isPalindrome(char *s, int start, int end)
{
    int i,j;

    int strsSize = end - start + 1;
    int loopSize = strsSize / 2;
    int count = 0;

    i = 0;
    while ( s[start + i] == s[end-i] && i<loopSize)
    {
        count ++;
        i ++;
    }

    if (count == loopSize)
    {
        return 1;
    }

    return 0;
}

char * result_string_gen(char *s, int start, int end)
{
    int string_size = end - start + 2;
    char *result = (char *)malloc(sizeof(char) * string_size);
    int i;
    for (i=0; i<string_size-1; i++)
    {
        result[i] = s[start+i];
    }
    result[i] = '\0';
    return result;
}


*/