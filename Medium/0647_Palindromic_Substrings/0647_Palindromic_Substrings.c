#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isPalindrome(char *s, int start, int end)
{
    int left_p = start, right_p = end;
    int str_len = (end - start) + 1; 
    int count = 0;
    while (left_p < right_p && s[left_p] == s[right_p])
    {
        count ++;
        left_p ++;
        right_p--;
    }
    if (count == str_len/2)
    {
        return 1;
    }
    return 0;
}

int countSubstrings(char * s)
{
    int count = strlen(s);
    int str_len = strlen(s);
    int start = 0;
    int end = 1;
    int end_ptr = 1;
    while (end < str_len)
    {
        start = 0;
        end_ptr = end;
        while (end_ptr < str_len)
        {
            if (isPalindrome(s, start, end_ptr))
            {
                count ++;
            }
            start ++;
            end_ptr ++;   
        }
        end ++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    printf("Count of Substring ---> %d\n", countSubstrings(s));
    return EXIT_FAILURE;
}


/*

647. Palindromic Substrings
Medium

Companies
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.

*/