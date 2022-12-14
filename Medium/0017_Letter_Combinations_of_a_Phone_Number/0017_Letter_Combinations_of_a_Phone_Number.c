#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char *KEY[] =
{
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

int ptr_to_char_count(char *digits)
{
    int i;
    int count = 1;
    for (i=0; digits[i] != '\0'; i++)
    {
        // printf("len of key %c ---> %d \n ", digits[i] ,strlen( KEY[ digits[i] - 50 ] ) );
        count *= strlen( KEY[ digits[i] - 50 ] );
    }

    // printf("count ---> %d\n", count);
    return count;
}

void combinations(char *digits, char **keys, int *path, int level, char **result, int *combo)
{
    // 6. Base Condition of Recursion
    if ( level == strlen(digits) )
    {
        // 7. set memory space to store the string combination, each pointer gets a pointer to string of size char times digit count  
        // 8. add 1 extra char space for NULL character
        result[(*combo)] = (char *)malloc( sizeof(char) * (strlen(digits) + 1) ); 
        
        // 9. store the char in the malloc space
        int i;
        for (i=0; i<strlen(digits); i++)
        {
            // 10. pointer to the key[0] = "abc", key[1]="def", key[2] = "ghi"
            // 11. path[i] holds the index where each level of loop is at
            result[(*combo)][i] = keys[i][path[i]];
        }

        // 12. remember to set the NULL char in each string and increment combo count.
        result[(*combo)][i] = '\0';
        (*combo) ++;
        return;
    }

    // 5. Recursion act as nested loops, level defines i, j, k... loop, each loop goes from 0 to each string length in KEY[]
    for (path[level]=0; path[level] < strlen( KEY[ digits[level]-50 ] ); path[level]++ )
    {
        combinations(digits, keys, path, level+1, result, combo);
    }
}

char ** letterCombinations(char *digits, int *returnSize)
{
    // 1. If string length is 0, simply pass the malloc 0 space to caller
    if (strlen(digits) == 0)
    {
        *returnSize = 0;
        char **result = (char **) malloc(sizeof(char *) * (*returnSize) );
        return result;
    }

    // 2. set the memory space to result pointer sets
    int combo_count = ptr_to_char_count(digits);
    char **result = (char **) malloc( sizeof(char *) * combo_count );
    
    // set another pointer arrays to get the string in KEY[]
    char *keys[strlen(digits)];
    int i;
    for (i=0; i<strlen(digits); i++)
    {
        keys[i] = KEY[ digits[i]-50 ];
    }


    // 3. set a path array to act as an i, j, k ...  loop for nested looping through recursions 
    int path[strlen(digits)];
    *returnSize = combo_count;
    int level = 0;
    int combo = 0;

    // 4. sequence starts
    combinations(digits, keys, path, level, result, &combo);
    return result;
}



void print_strings(char **result, int returnSize);
void concept(char *digits);

int main(int argc, char const *argv[])
{
    // char *digits = "2379";
    char *digits = "";
    int returnSize = 0;
    char **result = letterCombinations(digits, &returnSize);
    print_strings(result, returnSize);
    // concept(digits);
    return 0;
}

void concept(char *digits)
{

/*
'2' - 48 = 2
'2' - 50 = 0  <=== better use -50 to extract the strings in KEY[] 

50 2
51 3
52 4
53 5
54 6
55 7
56 8
57 9

*/

    // pointer to get strings stored in KEY[]
    char *key2 = KEY[digits[0] -50];
    char *key7 = KEY[digits[1] -50];
    char *key9 = KEY[digits[2] -50];

    int count = 0;

    // nested looping through each string to get the combintaions
    int i, j, k;
    for (i=0; key2[i] != '\0';  i++)
    {
        for (j=0; key7[j] != '\0'; j++)
        {
            for (k=0; key9[k] != '\0'; k++)
            {
                printf("%c%c%c\n", key2[i], key7[j], key9[k]);
                count ++;            
            }
        }
    }
    printf("Count --> %d \n", count);
}



void print_strings(char **result, int returnSize)
{
    int i;
    for (i=0; i<returnSize; i++)
    {
        printf("Combo [ %d ] ---> ", i+1);
        puts(result[i]);
    }
}


/*

17. Letter Combinations of a Phone Number
Medium

Companies
Given a string containing digits from 2-9 inclusive,
return all possible letter combinations that the number could represent.
Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/
