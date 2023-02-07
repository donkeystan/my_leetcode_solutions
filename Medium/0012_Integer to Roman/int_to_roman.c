#include<stdio.h>
#include<stdlib.h>

/*
 *
 * This is a C program to Convert Numbers to Roman Numerals.
 *
 * Problem Description
 * This program takes a decimal number and converts it to roman number.
 * 
 * Problem Solution
 * 1. Take a decimal number as input.
 * 2. Check if the number is greater than 1000 or 900 or 500 or 400 or 100 or 90 or 50 or 40 or 10 or 9 or 5 or 4 or 1.
 * 3. If it is, then store its equivalent roman number in a array.
 * 4. Repeat the step 2-3 with the left over number.
 * 
 * Program/Source Code
 * Here is source code of the C program to Convert Numbers to Roman Numerals. 
 * The C program is successfully compiled and run on a Linux system. The program output is also shown below.
 */

/*
 * C Program to Convert Numbers to Roman Numerals
 */

 
void predigit(char num1, char num2);
void postdigit(char c, int n);
 
char romanval[1000];
int i = 0;
int main()
{
    int j;
    long number;
 
    printf("Enter the number: ");
    scanf("%d", &number);
    if (number <= 0)
    {
        printf("Invalid number");
        return 0;
    }
    while (number != 0)
    {
        if (number >= 1000)
        {
            postdigit('M', number / 1000);
            number = number - (number / 1000) * 1000;
        }
        else if (number >= 500)
        {
            if (number < (500 + 4 * 100))
            {
                postdigit('D', number / 500);
                number = number - (number / 500) * 500;
            }
            else
            {
                predigit('C','M');
                number = number - (1000-100);
            }
        }
        else if (number >= 100)
        {
            if (number < (100 + 3 * 100)) 
            {
                postdigit('C', number / 100);
                number = number - (number / 100) * 100;
            }
            else
            {
                predigit('L', 'D');
                number = number - (500 - 100);
            }
        }
        else if (number >= 50 )
        {
            if (number < (50 + 4 * 10))
            {
                postdigit('L', number / 50);
                number = number - (number / 50) * 50;
            }
            else
            {
                predigit('X','C');
                number = number - (100-10);
            }
        }
        else if (number >= 10)
        {
            if (number < (10 + 3 * 10))
            {
                postdigit('X', number / 10);
                number = number - (number / 10) * 10;
            }
            else
            {
                predigit('X','L');
                number = number - (50 - 10);
            }
        }
        else if (number >= 5)
        {
            if (number < (5 + 4 * 1))
            {
                postdigit('V', number / 5);
                number = number - (number / 5) * 5;
            }
            else
            {
                predigit('I', 'X');
                number = number - (10 - 1);
            }
        }
        else if (number >= 1)
        {
            if (number < 4)
            {
                postdigit('I', number / 1);
                number = number - (number / 1) * 1;
            }
            else
            {
                predigit('I', 'V');
                number = number - (5 - 1);
            }
        }
    }
    printf("Roman number is: ");
    for(j = 0; j < i; j++)
        printf("%c", romanval[j]);
    return 0;
}
 
void predigit(char num1, char num2)
{
    romanval[i++] = num1;
    romanval[i++] = num2;
}
 
void postdigit(char c, int n)
{
    int j;
    for (j = 0; j < n; j++)
        romanval[i++] = c;
}

/*
 * 
 * Program Explanation
 * 1. Take a decimal number as input and store it in the variable number.
 * 2. Check if the number is lesser than 0. If it is, then print the output as “Invalid number”.
 * 3. Check if the number is greater than 1000 or 500 or 100 or 50 or 10 or 5.
 * 4. If it is, then also check if the number is greater than 900 or 400 or 90 or 40 or 9 or4. If it is, then call the function predigit() and subtract the variable number by its equivalent number and override the variable number with this value.
 * 5. Otherwise call the function postdigit() and divide the variable number by its equivalent number and get the quotient. Multiply the quotient with its equivalent number and decrement the variable number with this value.
 * 6. In the function postdigit(), assign the equivalent roman number to the array romanval[].
 * 7. In the function predigit(), assign the array romanval[] with the parameters of function.
 * 8. Repeat the steps 3-5 until the variable number becomes zero.
 * 9. Print the array romanval[] as output.
 * 
 */