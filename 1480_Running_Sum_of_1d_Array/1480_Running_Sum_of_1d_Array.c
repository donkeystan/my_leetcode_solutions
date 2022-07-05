#include<stdio.h>
#include<stdlib.h>

//Only this function part is submitted (required by leetcode).
int* runningSum(int* nums, int numsSize, int* returnSize)
{
    int i;
    int *numsOut=0;                                    //declare a pointer in the function with null initialization
    
    numsOut = malloc(sizeof(int)*numsSize);            // assign a malloc space to numsOut
    
    *numsOut = *nums;                                  // numsOut get the value passed from 'nums' of main

    for(i=1; i<numsSize; i++)                          //loop from 1 to the array size
    {
        *(numsOut+i) = *(numsOut+(i-1)) + *(nums+i);   //numsOut[1] will get numsOut[0] + nums[1]
    }                                                  //since numsOut[0] already copied nums[0]
    
    *returnSize = numsSize;                            //pointer retrunSize received address of RC
    return numsOut;
}

//main is only an simulation which may differ from what leetcode makes.
int main()
{
    int i;
    int size=0;
    int rcvdSize=0;
    int *nums=0;
    int *ptr;

    printf("\nEnter how many numbers in the series:  ");
    scanf("%d",&size);

    nums = malloc(sizeof(int)*size);
    for(i=0; i<size; i++)
    {
        scanf("%d",(nums+i));
    }

    for(i=1; i<=size; i++)
    {
        ptr = runningSum(nums,i,&rcvdSize);
        printf("Series %d is %d\n",i,*(ptr+(i-1)));
    }
    
    free(ptr);
    free(nums);
    
    return 0;
}

/* 
// The complete program with main.
int* runningSum(int* nums, int numsSize)
{
    int i;
    
    for(i=0; i<numsSize; i++)
    {
        if(i==0)
        {
            *(nums+i) = *(nums+i);
        }
        else
        {
            *(nums+i) += *(nums+(i-1));
        }
    }

    return 0;
}


int main()
{
    int *numsArray=0;
    int size=0;
    int count;
    
    while(1)
    {
        printf("\nEnter how many numbers in the series:  ");
        scanf("%d",&size);
        
        if(size>1000)break;
        
        numsArray = malloc(sizeof(int)*(size+1));
        
        printf("\nEnter values:  \n");
        for(count=0; count<size; count++)
        {
            scanf("%d",(numsArray+count));
        }

        runningSum(numsArray,size);

        for(count=0; count<size; count++)
        {
            printf("Running Sum #%d is %d\n",count+1,*(numsArray+count));
        }
        free(numsArray);
    }
    return 0;
}
*/

/*
nums[3] = {1,2,3};

nums[0] = mums[0]
nums[1] = nums[0] + nums[1]
nums[2] = nums[2] + nums[1] + nums[2]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 
int* runningSum(int* nums, int numsSize, int* returnSize){

}
*/

/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]

Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
*/


/*

int main()
{
    int length;
    int inputSeries[length];
    int tempSum[length];
    int runningSum[length];
    int count;
    
    do
    {  
        printf("\nEnter how many numbers in the series:  ");
        scanf("%d",&length);
        
        if(length<1||length>1000)
        {
            printf("Amount must be 1 and no larger than 1000!\n");
        }
        else
        {
            printf("Enter a series of value to get running sum...\n");
                                
            for(count=0;count<length;count++)
            {
                printf("give me number of # %d : ",count+1);
                scanf(" %d",&inputSeries[count]);
            }
            printf("\n");
            
            if(inputSeries<1000000||inputSeries>(-1000000))
            {
                printf("The input value must be within -10^6 ~ 10^6\n\n");
            }
            else
            {
                for(count=0;count<length;count++)
                {
                    if(count==0)
                    {
                        tempSum[count]=inputSeries[count];
                        runningSum[count]=tempSum[count];
                    }
                    else
                    {
                        tempSum[count]=tempSum[count-1]+inputSeries[count];
                        runningSum[count]=tempSum[count];
                    }
                }
                
                for(count=0;count<length;count++)
                {
                    printf("%d,",runningSum[count]);
                }
                printf("\n");
            }
        }
    }
    while(1);
    
    return 0; 
}
*/


// High Level Answer

/*

int* runningSum(int* nums, int numsSize, int* returnSize)
{
    for(int i=1;i<numsSize;i++)
    {
        nums[i] = nums[i] + nums[i-1];
    }
    
    *returnSize = numsSize;
    
    return nums;
}

*/