#include<stdio.h>

//Reverse String
void reverseString(char* s, int sSize)
{
    int i =0;
    
    for(i=0; i<sSize/2; i++)
    {
        s[i]^= s[(sSize-(i+1))];
        s[(sSize-(i+1))] ^= s[i];
        s[i]^=s[(sSize-(i+1))];
    }        
}


/*

Write a function that reverses a string. The input string is given as an array of characters s.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Constraints:
1 <= s.length <= 105
s[i] is a printable ascii character.
 
Follow up: Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

*/

int main()
{
    int i=0;
    char s[]= {'h','e','l','l','o'};
    int sSize = (sizeof(s)/sizeof(s[0]));
    printf("Size of the string is %d\n",sSize);
    
    reverseString(s,sSize);
    
    for(i=0; i<sSize; i++)
    {
        printf("%c, ",s[i]);
    }
    printf("\n");
    
    
    
    return 0;
}


/*  
        
        //odd size should -1, even size no -1 needed
        
        // "abcde" -> 5 char in string size 5   5/2 = 2.5 = 2
        
        s[0] = s[sSize-1]; //s[0] h swap a[4] e 
        s[1] = s[sSize-2]; //s[1] e swap a[3] d  //procedure ends here
        s[2] = s[sSize-3]; //s[2] l swap a[2] c 
        s[3] = s[sSize-4]; //s[3] l swap a[1] b
        s[4] = s[sSize-5]; //s[4] o swap a[0] a

        // "abcdef" ->  6 char in string size 6   6/2 = 3 
        
        s[0] = s[sSize-2]; //s[0] a swap a[5] f 
        s[1] = s[sSize-3]; //s[1] b swap a[4] e 
        s[2] = s[sSize-4]; //s[2] c swap a[3] d  //procedure ends here 
        s[3] = s[sSize-5]; //s[3] d swap a[2] c
        s[4] = s[sSize-6]; //s[4] e swap a[1] b
        s[5] = s[sSize-6]; //s[5] e swap a[0] a

        */