#include<stdbool.h>
#include<stdio.h>

bool backspaceCompare(char * s, char * t)
{
/*
 *  s = "ab#c"  t = "ad#c"
 *  s = "ab##"  t = "c#d#"
 *  
 *  s = "ab##cd##ef"     t = "a#b#cd##ef"
 *  s = "abc###def##gh"  t = "a#bc##de#f#gh
 *  s = "b##cd##ef"      t = "#b#cd##ef"
 *  s = "b##c"           t = "#b#c"
 *  
 *  s = "a##c"           t = "#a#c"
 *  s = "a#c"            t = "b"
 *  s = "xywrrmp"        t = "xywrrmu#p"
 *  s = "bxj##tw"        t = "bxo#j##tw"
 *
 */

    int i=0;
    int j=0;
    int counter = 0;
    
    for(i=0; s[i] != '\0'; i++)
    {
        if(s[i] != '#')
        {
            s[counter++] = s[i];
        }
        else if(s[i] == '#' && counter>0 )
        {
            counter--;
        }
        
    }
    s[counter] = '\0';
    
    counter = 0;
    for(i=0; t[i] != '\0'; i++)
    {
        if(t[i] != '#')
        {
            t[counter++] = t[i];
        }
        else if(t[i] == '#' && counter>0 )
        {
            counter--;
        }
    }
    t[counter] = '\0';

    if(strcmp(s,t)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*

s[0] : b
counter = 0
s[0] = s[0]
counter++ ; counter = 1;


s[1] : x
counter = 1
s[1] = s[1]
counter++ ; counter = 2;


s[2] : j
counter = 2
s[2] = s[2]
counter++ ; counter = 3;


s[3] : #
counter = 3
counter-- ; counter = 2;


s[4] : #
counter = 2
counter-- ; counter = 1;


s[5] : t
counter = 1
s[1] = s[5]
counter++ ; counter = 2;


s[6] : w
counter = 2
s[2] = s[6]
counter++ ; counter = 3;

*/


/*

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a##c", t = "#a#c"
Output: true
Explanation: Both s and t become "c".

Example 4:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 
Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
*/

int main()
{
    char s[12] = "xywrrmp";     // btw
    char t[12] = "xywrrmu#p";   // bxtw
    int rc = 0;
    int i;

    printf("Before Backspacing Movement:\n");
    puts(s);
    puts(t);
    
    printf("\n");
    rc = backspaceCompare(s,t);
    
    printf("After Backspacing Movement:\n");
    puts(s);
    puts(t);
    
    printf("The return value is %d",rc);
    
    return 0;
}
