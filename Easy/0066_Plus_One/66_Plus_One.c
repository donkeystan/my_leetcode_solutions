#include<stdio.h>
#include<stdlib.h>

void print_array(int *, int);

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i;
    int *result = NULL;
    int count = 0;

    result = (int *)malloc(sizeof(int) * (digitsSize+1));          // prepare a space of 1-int larger than original array space

    /*
        9 9 9

        1 9 9

        1 9 2 9 
    */
    
    for (i = digitsSize-1; i>=0; i--)
    {
        if (9 == digits[i])
        {
            digits[i] = 0;
            count ++;
        }
        else
        {
            digits[i] ++;
            break;
        }
    }

    if (count < digitsSize)
    {
        for (i=0; i<digitsSize; i++)
        {
            result[i] = digits[i];
        }
        *returnSize = digitsSize;
    }
    else
    {   
        result[0] = 1;
        for (i=1; i<=digitsSize; i++)
        {
            result[i] = digits[i-1];
        }
        *returnSize = (digitsSize + 1);
    }
    return result;
}


int main(int argc, char *argv[])
{
    int returnSize = 0;
    int digits[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    // int digits[] ={1,9,2,9};
    int digitsSize = sizeof(digits)/sizeof(digits[0]);
    int * result = NULL;

    print_array(digits,digitsSize);
    result = plusOne(digits, digitsSize, &returnSize);
    print_array(result, returnSize);
    free(result);

    return EXIT_SUCCESS;
}

void print_array(int *nums, int numsSize)
{
    int i;
    for(i=0; i<numsSize; i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
}

/*
66. Plus One
You are given a large integer represented as an integer array digits,
where each digits[i] is the ith digit of the integer.

The digits are ordered from most significant to least significant in left-to-right order.
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.


*/

/* Runtime Error  

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i;
    int count = 0;
    int *result = NULL;
    if (9 != digits[digitsSize-1])
    {
        int *result = (int *)malloc(sizeof(int) * digitsSize);
        *returnSize = digitsSize;
        digits[digitsSize-1]++;
        for (i=0; i<digitsSize; i++)
        {
            result[i] = digits[i];
        }
        return result;
    }

    i=digitsSize-1;
    count = 0;
    while (9 == digits[i])
    {
        digits[i] = 0;
        i--;
        count++;
    }
    
    if (count >= digitsSize)
    {
        digitsSize++;
        result = (int *)malloc(sizeof(int)*digitsSize);
        *returnSize = digitsSize;
        result[0] = 1;                                         // all 9 will get a 1 leading full 0
        for (i=1; i<digitsSize; i++)                            // copy sequence
        {
            result[i] = digits[i-1];
        }
        return result;
    }
    else
    {
        digits[i] ++;                                           // ith index is not 9, simply increment it
        int *result = (int *)malloc(sizeof(int) * digitsSize);  // allocate the same size of the array
        *returnSize = digitsSize;                               // overwrite the returnSize as the array size
        for (i=0; i<digitsSize; i++)                            // copy the array to new malloc space
        {
            result[i] = digits[i];
        }
        return result;
    }
    return NULL;
}

// Compiler Error Message

=================================================================
==31==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x60300000000c at pc 0x56540e7e6c7a bp 0x7ffcd7f38f90 sp 0x7ffcd7f38f80
READ of size 4 at 0x60300000000c thread T0
    #2 0x7ffad0e460b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x60300000000c is located 4 bytes to the left of 28-byte region [0x603000000010,0x60300000002c)
allocated by thread T0 here:
    #0 0x7ffad1a8bbc8 in malloc (/lib/x86_64-linux-gnu/libasan.so.5+0x10dbc8)
    #3 0x7ffad0e460b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
Shadow bytes around the buggy address:
  0x0c067fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c067fff8000: fa[fa]00 00 00 04 fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==31==ABORTING

*/


/*

if( count >= digitsSize)
    { 
        int new_len = digitsSize +1;
        int *result = (int *)malloc(sizeof(int)*new_len);
        *returnSize = new_len;
        result[0] = 1;                                         // all 9 will get a 1 leading full 0
        for(i=1; i<new_len; i++)                               // copy sequence
        {
            result[i] = digits[i-1];
        }
        return result;
    }
    else
    {
        digits[i] ++;                                           // ith index is not 9, simply increment it
        int *result = (int *)malloc(sizeof(int) * digitsSize);  // allocate the same size of the array
        *returnSize = digitsSize;                               // overwrite the returnSize as the array size
        for(i=0; i<digitsSize; i++)                             // copy the array to new malloc space
        {
            result[i] = digits[i];
        }
        return result;
    }
    return NULL;

    Above code gets result as following when we pass [9] or more [9,9...,9]



=================================================================
==32==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x60200000000c at pc 0x558bd929cc7a bp 0x7ffc6dfa1530 sp 0x7ffc6dfa1520
READ of size 4 at 0x60200000000c thread T0
    #2 0x7fac1e3d90b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x60200000000c is located 4 bytes to the left of 4-byte region [0x602000000010,0x602000000014)
allocated by thread T0 here:
    #0 0x7fac1f01ebc8 in malloc (/lib/x86_64-linux-gnu/libasan.so.5+0x10dbc8)
    #3 0x7fac1e3d90b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
Shadow bytes around the buggy address:
  0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c047fff8000: fa[fa]04 fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==32==ABORTING


*/