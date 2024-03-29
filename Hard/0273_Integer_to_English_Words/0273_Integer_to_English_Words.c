#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int word_copying(char *words, char *final_words, int curr_idx)
{
    int i, word_length = strlen(words);
    for (i=0; i<word_length; i++)
    {
        final_words[curr_idx++] = words[i];
    }
    return curr_idx;
}

char * numberToWords(int num)
{
    // 1. Return "Zero" if num is 0
    if (0 == num)
    {
        return "Zero";
    }

    // 2. Prepare Primary Units for further calculating and memorizing the numbers of Billion to Hundred and Below
    int primary_units[] = {1000000000, 1000000, 1000, 100, 1};
    int primary_size = sizeof(primary_units) / sizeof(primary_units[0]);

    // 3. Preare Secondary Units for calculating and memorizing the numbers of Hundred, Ninety to Ten and below.
    int secondary_units[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int secondary_size = sizeof(secondary_units) / sizeof(secondary_units[0]);

    // 4. Prepare String Sets by array of pointers to char
    char *primary_words[] =
    {
        "Billion ", "Million ", "Thousand ", "Hundred ", ""
    };

    char *secondary_words[] =
    {
        "Hundred ", "Ninety ", "Eighty ", "Seventy ", "Sixty ", "Fifty ", "Forty ", "Thirty ", "Twenty ",
                    "Nineteen ", "Eighteen ", "Seventeen ", "Sixteen ", "Fifteen ", "Fourteen ", "Thirteen ", "Twelve ",
                    "Eleven ", "Ten "
    };

    char *numbers[] =
    {
        "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "
    };


    // 5. Prepare an equal size copy of primary units to store the number of Billion, Million to Hundred and below.
    int i, j, tmp;
    int primary_units_copy[] = {0, 0, 0, 0, 0};

    // 6. Start calculating the amount of each primary unit
    //      6.1 store the temp count in a tmp by division
    //      6.2 Split the by moding the num, and save the temp count to the <primary_units_array[]> for later process
    for (i=0; i<primary_size; i++)
    {
        tmp = num / primary_units[i];
        num %= primary_units[i];
        primary_units[i] = tmp;
        primary_units_copy[i] = primary_units[i];
    }

    // 7. After receiving the amount of each primary unit in the <primary_units_array[]>,
    //    prepare a 2D array to calculate and memorize the amount of each secondary units from Hundred, Ninety to Ten and below.
    int **units_of_primary_units = (int **)malloc(sizeof(int *) * 5);
    for (i=0; i<primary_size; i++)
    {
        // 7.1 Prepare a 28-int size array in every row
        // 7.2 Loop through each secondary units and get the amount of each secondary unit
        // 7.3 save the amount of each secondary unit in the newly created 2D array <units_of_primary_units[][]>
        units_of_primary_units[i] = (int *)calloc(28, sizeof(int));
        for (j=0; j<secondary_size; j++)
        {
            tmp = primary_units_copy[i] / secondary_units[j];
            primary_units_copy[i] %= secondary_units[j];
            units_of_primary_units[i][j] = tmp;
        }
    }
    
    // 8. Final Process to create English words by readin the records stored in the 2D array
    //      8.1 use <word_size> to record current length of the English words
    char final_words[150];
    int words_size = 0;

    // 9. Main Loop for processing primay units, Billion, Million to Hundred and below.
    for (i=0; i<primary_size; i++)
    {
        // 10. Check if each primary unit requires process
        if (primary_units[i] != 0)
        {
            // 11. Check first element in the secondary units where it should indicates how many sub-"Hundred" inside each Primary Unit
            if (units_of_primary_units[i][0] != 0)
            {
                // 11.1 Copy the word of number by applying the first sub-"Hundred" of current primary unit as key to number[]
                // 11.2 Once sub-"Hundred" is done, copy the "Hundred" word to <final_words[]>
                words_size = word_copying(numbers[units_of_primary_units[i][0]], final_words, words_size);
                words_size = word_copying(secondary_words[0], final_words, words_size);
            }

            // 12. Check from 1st to 19th element of secondary units of each primary unit to see if 90-10 is required to put in
            for (j=1; j<19; j++)
            {
                if (units_of_primary_units[i][j] != 0)
                {
                    // 12.1 Applying simple secondary words in the same position to <final_words[]>
                    words_size = word_copying(secondary_words[j], final_words, words_size);
                }
            }

            // 13. Check from 19th to 28th element to see if numbers below hundred is required to put it
            for (j=19; j<28; j++)
            {
                if (units_of_primary_units[i][j] != 0)
                {
                    // 13.1 apply current unit of secondary units to numbers[] as key and copy the words to <final_words[]>
                    words_size = word_copying(numbers[secondary_units[j]], final_words, words_size);
                }
            }

            // 14. Copy the primary words Billion, Million, ... to Hundred and below to <final_words[]>
            words_size = word_copying(primary_words[i], final_words, words_size);
        }
    }

    // 15. Final process to copy the <final_words[]> to string for returing the result.
    char *result = (char *)malloc(sizeof(char) * words_size);
    for (i=0; i<words_size; i++)
    {
        result[i] = final_words[i];
    }
    result[words_size - 1] = '\0';
    return result;
}

int main(int argc, char const *argv[])
{
    // int num = 0;
    // int num = 2147483647;
    int num = 999;
    char *words = numberToWords(num);
    puts(words);
    return EXIT_SUCCESS;
}

/*

273. Integer to English Words
Hard

Convert a non-negative integer num to its English words representation.

Example 1:
Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Constraints:


*/


/* Without extra word copying function

char * numberToWords(int num)
{
    if (0 == num)
    {
        return "Zero";
    }

    int primary_units[] = {1000000000, 1000000, 1000, 100, 1};
    int primary_size = sizeof(primary_units) / sizeof(primary_units[0]);
    int secondary_units[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int secondary_size = sizeof(secondary_units) / sizeof(secondary_units[0]);

    char *primary_words[] =
    {
        "Billion ", "Million ", "Thousand ", "Hundred ", ""
    };

    char *secondary_words[] =
    {
        "Hundred ", "Ninety ", "Eighty ", "Seventy ", "Sixty ", "Fifty ", "Forty ", "Thirty ", "Twenty ",
                    "Nineteen ", "Eighteen ", "Seventeen ", "Sixteen ", "Fifteen ", "Fourteen ", "Thirteen ", "Twelve ",
                    "Eleven ", "Ten "
    };

    char *numbers[] =
    {
        "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "
    };

    int i, j, tmp;

    int primary_units_copy[] = {0, 0, 0, 0, 0};
    for (i=0; i<primary_size; i++)
    {
        tmp = num / primary_units[i];
        num %= primary_units[i];
        primary_units[i] = tmp;
        primary_units_copy[i] = primary_units[i];
    }

    int **units_of_primary_units = (int **)malloc(sizeof(int *) * 5);
    for (i=0; i<primary_size; i++)
    {
        units_of_primary_units[i] = (int *)calloc(28, sizeof(int));
        for (j=0; j<secondary_size; j++)
        {
            tmp = primary_units_copy[i] / secondary_units[j];
            primary_units_copy[i] %= secondary_units[j];
            units_of_primary_units[i][j] = tmp;
        }
    }
    
    char final_words[255];
    int word_length = 0, k, l = 0;

    for (i=0; i<primary_size; i++)
    {
        if (primary_units[i] != 0)
        {
            if (units_of_primary_units[i][0] != 0)
            {
                word_length = strlen(numbers[units_of_primary_units[i][0]]);
                for (k=0; k<word_length; k++)
                {
                    final_words[l++] = numbers[units_of_primary_units[i][0]][k];
                }

                word_length = strlen(secondary_words[0]);
                for (k=0; k<word_length; k++)
                {
                    final_words[l++] = secondary_words[0][k];
                }
            }

            for (j=1; j<19; j++)
            {
                if (units_of_primary_units[i][j] != 0)
                {
                    word_length = strlen(secondary_words[j]);
                    for (k=0; k<word_length; k++)
                    {
                        final_words[l++] = secondary_words[j][k];
                    }
                }
            }

            for (j=19; j<28; j++)
            {
                if (units_of_primary_units[i][j] != 0)
                {
                    word_length = strlen( numbers[secondary_units[j]]);
                    for (k=0; k<word_length; k++)
                    {
                        final_words[l++] = numbers[secondary_units[j]][k];
                    }
                }
            }

            word_length = strlen( primary_words[i] );
            for (k=0; k<word_length; k++)
            {
                final_words[l++] = primary_words[i][k];
            }
        }
    }

    char *result = (char *)malloc(sizeof(char) * l);
    for (i=0; i<l; i++)
    {
        // printf("%c", final_words[i]);
        result[i] = final_words[i];
    }
    result[l-1] = '\0';

    return result;
}

*/