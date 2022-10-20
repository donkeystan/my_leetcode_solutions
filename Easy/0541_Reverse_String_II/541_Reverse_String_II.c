#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *dest, char *src, int start, int end);

char * reverseStr(char * s, int k)
{
    int i;
    int start;
    int end;
    int count;
    int rev;

    // oversize handling
    if (k > strlen(s))
    {
        k = strlen(s);
    }

    char *dest = (char *)malloc(sizeof(char) * (strlen(s) + 1));

    i = 0;
    rev = 1;
    count = 0;

    while (s[i] != '\0')
    {

        dest[i++] = s[i];
        count++;

        if (count == k && rev == 0)
        {
            count = 0;
            rev = 1;
        }

        if (count == k && rev == 1)
        {
            start = i - k;
            end = i - 1;

            reverse(dest, s, start, end);

            count = 0;
            rev = 0;
        }

        if (s[i] == '\0' && rev == 1)
        {
            start = i - count;
            end = i - 1;
            reverse(dest, s, start, end);
        }
    }

    dest[i] = '\0';

    return dest;
}

void reverse(char *dest, char *src, int start, int end)
{
    int i = start;
    int j = end;
    
    while ( i <= end)
    {   
        dest[i++] = src[j--];
    }
}

int main(int argc, char const *argv[])
{
    char *s = "abcdefghijklmn";
    char *rc = reverseStr(s, 2);

    puts(rc);

    return EXIT_SUCCESS;
}


/*

Given a string s and an integer k,
reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them.

If there are less than 2k but greater than or equal to k characters,
then reverse the first k characters and left the other as original.

Example 1:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Example 2:
Input: s = "abcd", k = 2
Output: "bacd"

Constraints:
1 <= s.length <= 10^4
s consists of only lowercase English letters.
1 <= k <= 10^4

*/

/*

   i = 0;
    j = 0;
    count = 0;

    while (s[i] != '\0')
    {
        dest[i] = s[i++];
        count ++;
        
        // when count meets the k group, start the reverse
        if (count == k)
        {
            start = i - k;
            end = i - 1;

            // reverse the part
            reverse(dest, s, start, end);
            rev ++;

            // reset the count for regular copy
            count = -k;
        }
    }

*/
