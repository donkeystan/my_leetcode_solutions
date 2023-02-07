#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(a, b) (a > b ? a : b)

void check_substring(char *word, int *word_idx, char *standard, int std_idx, int *count)
{
    // 3.2 Base Condition #1 : When the word's char is not equal to standard's char
    //     that means the substring to check is not in aeiou order
    if (word[(*word_idx)] != standard[std_idx])
    {    
        (*count) = 0;
        return;
    }

    // 3.3 Base Condition #2 : Catching the last 'u' to not let it goes into the CORE loop.
    //     If we don't catch the last here, the result will never be recorded.
    if (std_idx == 4)
    {
        while (word[(*word_idx)] != '\0')
        {
            if (word[(*word_idx)] == 'u')
            {
                (*count) ++;
                (*word_idx)++;
            }
            else
            {
                return;
            }
        }
        return;
    }

    // 3.1 When calling the check_substring() function everytime,
    //     and not caught by Base condition #1, it will start count the lenght of substring consists of 'aeio', except 'u'
    for ((*word_idx); word[(*word_idx)] != '\0'; (*word_idx)++ )
    {
        if (word[(*word_idx)] == standard[std_idx])
        {
            (*count)++;
        }
        else
        {
            break;
        }
    }
    check_substring(word, word_idx, standard, std_idx+1, count);
}

int longestBeautifulSubstring(char * word)
{
    int i= 0;
    int count = 0;
    int max = 0;
    int tmp_max = 0;

    // 1. Prepare a basic standard for Sliding Window Comparison process
    char *standard = "aeiou";

    // Sliding Window Problem
    // 2. Start the main loop from the beginning of the string
    while (word[i] != '\0')
    {
        // 2.1 Find the starting 'a' char and begin the Window to check Substring
        if (word[i] == 'a')
        {
            // 3. Substring Check to find beautiful substring
            check_substring(word, &i, standard, 0, &count);
            tmp_max = count;
            count = 0;
            max = MAX(max, tmp_max);
            i--;
        }
        i++;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    // char *word = "aeiaaioaaaaeiiiiouuuooaauuaeiu";
    // char *word = "ui";
    // char *word = "aeiou"; aaaeeeiiioooou
    // char *word = "aaeeiouaaaeeeiiioooou";
    // char *word = "aeiouaeiouuaeiou";
    char *word = "aeiou";
    printf("The Longest Beautiful Substring length is [ %d ] \n", longestBeautifulSubstring(word));
    return EXIT_SUCCESS;
}


/*

1839. Longest Substring Of All Vowels in Order
Medium

A string is considered beautiful if it satisfies the following conditions:
Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.

Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.

A substring is a contiguous sequence of characters in a string.

Example 1:
Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
Output: 13
Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.

Example 2:
Input: word = "aeeeiiiioooauuuaeiou"
Output: 5
Explanation: The longest beautiful substring in word is "aeiou" of length 5.

Example 3:
Input: word = "a"
Output: 0
Explanation: There is no beautiful substring, so return 0.

Constraints:
1 <= word.length <= 5 * 10^5
word consists of characters 'a', 'e', 'i', 'o', and 'u'.

*/