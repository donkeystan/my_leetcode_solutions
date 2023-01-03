#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *create_return_string(int *nums, int numsSize)
{
    // prepare a space for returing string
    char *result = (char *)malloc(sizeof(char) * (numsSize + 1));
    int i, j;

    // check if leading zero found
    i = (nums[0] != 0) ? 0 : 1;
    j = 0;

    // string making process
    for (i=i; i<numsSize; i++)
    {
        result[j++] = nums[i] + 48;
    }
    result[j] = '\0';
    return result;
}

int multiply_and_save(int num2, int num1, int *nums, int *curr_index, int carry)
{
    // temporarily save the result by addition from multiplication of two nums, current carry value, and current element
    int result = (num2 * num1) + carry + nums[(*curr_index)];

    // split and save the carr
    carry = result / 10;

    // save and write current element at curr_index
    nums[(*curr_index)] = (result%10);

    // remember to decrement the curr_index
    (*curr_index) --;
    return carry;
}

char * multiply(char * num1, char * num2)
{
    // 1. Get each string's length and check if any single zero found to return "0" directly.
    int len_1 = strlen(num1), len_2 = strlen(num2);
    char *result = NULL;
    if ( (len_1 == 1 && num1[0] == '0') || (len_2 == 1 && num2[0] == '0'))
    {
        return "0";
    }
    
    // 2. alloc a space with initialized 0's
    int *nums = (int *)calloc((len_1 + len_2), sizeof(int));

    // 3. Set carry, curr_index and count to track the process of carry and num storage
    int i, j, carry = 0, curr_index = (len_1 + len_2) - 1, count = 0;
    
    // 4. loop through each char and have the char deducte 48 to become int value
    for (i=len_2-1; i >= 0; i--)
    {
        for (j=len_1-1; j>=0; j--)
        {
            // 5. get the carry value, and current index position for next round after multiply and save
            carry = multiply_and_save((num2[i]-48), (num1[j]-48), nums, &curr_index, carry);
        }

        if (carry != 0)
        {
            // 6. if carry is not 0 after every round of multiplication, its number has to be saved in the very beginning
            nums[curr_index] = carry;
            carry = 0;
        }

        // 7. Important, every round the initial curr_index has to move forward by decrement
        count ++;
        curr_index = (len_1 + len_2 - 1) - count;
    }

    // 8. Final string making process and memory freeing
    result = create_return_string(nums, (len_1 + len_2));
    free(nums);
    return result;
}

int main(int argc, char const *argv[])
{
    // char *num1 = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
    // char *num2 = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";

    // char *num1 = "9123";
    // char *num2 = "0";

    char *num1 = "123456789";
    char *num2 = "999985";

    char *result = multiply(num1, num2);
    puts(result);
    return 0;
}


/*

43. Multiply Strings
Medium

Given two non-negative integers num1 and num2 represented as strings,
return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Constraints:
1 <= num1.length, num2.length <= 200

num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.

*/