#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define SIZE_S 100
#define SIZE_M 500
#define SIZE_L 5000



void swap(int *, int *);
int input(char*, int);
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */




int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{   
    int i;
    // for(i=0; i<numsSize; i++)
    // {
    //     printf("%d--->%c\n",i,nums[i]);
    // }
    return *returnSize;
}

int multi_input(int, char** );

int main(int argc, char *argv[])
{
    int numsSize = 3;
    int nums[3] = { 1, 2, 3 };
    int *columnSizes[] = { nums, nums+1, nums+2 };
    char *col[SIZE_S];
    int **p = columnSizes;
    char temp[100] ;
    int rc;
    int i;

    while(1)
    {
        puts("Input Your Stuff Here:");
        multi_input(SIZE_S, col);
    }
    

    return 0;
}

int multi_input( int n, char **ptr_ )
{
    char raw_data[SIZE_L];
    char tmp[SIZE_M];
    char *ptr[SIZE_S];
    int ptr_count = 0;
    int offset = 0 ;
    int i;

    while(1)
    {  
        input(tmp, SIZE_M);
        if( strcmp(tmp,"exit") == 0)
        {
            break;
        }
        ptr[ptr_count] = &raw_data[offset];
        strcpy(ptr[ptr_count],tmp);
        ptr_count++;
        offset += (strlen(tmp)+1);
    }

    printf("ptr_count---->%d, offset--->%d\n",ptr_count,offset);

    for(i=0; i<ptr_count; i++)
    {
        puts(ptr[i]);
    }
}

int input(char* arr, int strSize)
{
    int i = 0;
    char ch;
    while( ( ch = getchar() ) != '\n')
    {
        if(i<strSize)
        {
            arr[i] = ch;
            i++;
        }
    }
    arr[i] = '\0';
    return i;
}

void swap(int *num, int *num2)
{
    *num ^= *num2;
    *num2 ^= *num;
    *num ^= *num2;
}

/*

46. Permutations
Medium

Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/