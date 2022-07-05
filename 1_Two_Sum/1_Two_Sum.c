#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int *returnPos = (int*)malloc(sizeof(int)*2);
    int i =0, j=0;
    int diff;
            
    for(i=0; i<numsSize; i++)
    {
        diff = target - nums[i];
        for(j=i+1; j<numsSize; j++)
        {
            if(diff == nums[j]) 
            {
                returnPos[0] = i;
                returnPos[1] = j;
                return returnPos;
            }
        }
    }
    return returnPos;
}

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.
*/


void main(void)
{
    /*
    int nums[10] = {0};
    int target = 0;
    int numsSize = 10;
    int *returnSize = NULL;
    int i;
    
    while(1)
    {
        printf("Enter number series: \n");
        for(i<0; i<numsSize; i++)
        {
            scanf("%d",nums+i);
        }
        
        for(i=0; i<numsSize; i++) 
        {
            printf("%d ",*(nums+i));
        }
        
        printf("\nGive it a sum target:\n");
        scanf("%d",&target);        
        printf("Sum target is %d\n",target);
        
        returnSize = twoSum(nums, numsSize, target, returnSize);
        
        printf("\nreturnSize receives the malloc address from twoSum at %p\n",returnSize);
        
        
        printf("\ntwoSum at :\n");
        for(i=0; i<2; i++) 
        {
            printf("%d ",*(returnSize+i));
        }

        free(returnSize);
        printf("\n\n");
    }
    */
 
    
    int nums[] = {1,3,5,7,9,11,13,15,17,19};
    int target = 34;
    int numsSize = (sizeof(nums)/sizeof(nums[0]));
    int n;
    int *returnSize = &n;
    int *ptr =NULL;
    int i;
    
    ptr = twoSum(nums, numsSize, target, returnSize);

    for(i=0; i<n; i++) 
    {
        printf("%d ",*(ptr+i));
    }

    free(ptr);
    
    
}


// High-Level Answers//
/*

#define MAXN ((uint32_t)1000000000)
#define MAXABSN (MAXN*2+2)

#define MAXBITN (MAXABSN/32+1)

#define SETBIT(arr, nr) arr[(MAXN+(uint32_t)(nr))/32] |= (uint32_t)(1)<<((MAXN+(uint32_t)(nr))%32)
#define ISBIT(arr, nr) (arr[(MAXN+(uint32_t)(nr))/32] & ((uint32_t)(1)<<(MAXN+(uint32_t)(nr))%32))
#define CLEARBIT(arr, nr) arr[(MAXN+(uint32_t)(nr))/32] &= ~(uint32_t)(1)<<((MAXN+(uint32_t)(nr))%32)


// * Note: The returned array must be malloced, assume caller calls free().
 

uint32_t b[MAXBITN] = {0};

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *ret = (int *)malloc(sizeof(int)*2), i;
    *returnSize=2;
    
    for(i = 0; i < numsSize; i++)
    {
        if (ISBIT(b, target-nums[i]))
        {
            break;
        }
        else
        {
            SETBIT(b, nums[i]);
        }
    }

    ret[0] = i;
    
    for(--i;i>-1;i--)
    {
        if ((target - nums[ret[0]]) == nums[i])
        {
            break;
        }
        else
        {
            CLEARBIT(b, nums[i]);
        }
    }

    ret[1] = i;
    
    for (;i>-1;i--)
    {
        CLEARBIT(b,nums[i]);
    }
    
    return ret;
}
*/