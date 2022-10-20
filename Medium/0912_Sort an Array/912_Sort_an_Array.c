#include<stdlib.h>
#include<stdio.h>
/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

void printArray(int *nums, int numsSize);
void merge_sort(int *nums, int start, int end);
void merge_process(int *nums, int start, int mid, int end);

int* sortArray(int* nums, int numsSize, int* returnSize)
{   
    int i;
    int *sorted_array = NULL;
    sorted_array = malloc(sizeof(int)*numsSize);
    merge_sort(nums, 0, numsSize-1);

    for (i=0; i<numsSize; i++)
    {
        sorted_array[i] = nums[i];
    }

    *returnSize = numsSize;
    return sorted_array;
}

int main(int argc, char const *argv[])
{
    int nums[] = {5,1,3,2,0,0};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int *return_array = NULL;
    int returnSize = 0;
    
    printf("<--- Before Sort --->\n");
    printArray(nums, numsSize);

    return_array = sortArray(nums, numsSize, &returnSize);

    printf("<--- After Sort --->\n");
    printArray(return_array, returnSize);

    return EXIT_SUCCESS;
}

void merge_sort(int *nums, int start, int end)
{    

    if(start < end)
    {
        int mid = ((end - start)/2) + start;
        printf("go left---> start:%d end:%d\n",start, mid);
        merge_sort(nums, start, mid);

        printf("go right---> start:%d end:%d\n",mid+1, end);
        merge_sort(nums, mid+1, end);

        printf("<--- Merging --->\n");
        merge_process(nums, start, mid, end);
    }
    printf("recursion returns...\n\n");
}

void merge_process(int *nums, int start, int mid, int end)
{
    int length_left = (mid - start + 1);
    int length_right = (end - mid);
    int array_left[length_left];
    int array_right[length_right];
    int i, j, k;

    for (i=0; i<length_left; i++)
    {
        array_left[i] = nums[start + i];
    }

    printf("left array--->");
    printArray(array_left, length_left);

    for (i=0; i<length_right; i++)
    {
        array_right[i] = nums[mid + 1 + i];
    }

    printf("right array--->");
    printArray(array_right, length_right);

    printf("array before merge ---> ");
    printArray(nums, 6);

    for (i=0, j=0, k=start; i<length_left && j<length_right; k++)
    {
        if (array_left[i] <= array_right[j])
        {
            nums[k] = array_left[i];
            i++;
        }
        else
        {
            nums[k] = array_right[j];
            j++;
        }
    }

    if (i < length_left)
    {   
        for (i=i; i<length_left; i++, k++)
        {
            nums[k] = array_left[i];
        }
    }

    if (j < length_right)
    {   
        for (j=j; i<length_right; j++, k++)
        {
            nums[k] = array_right[j];
        }
    }

    printf("array after merging ---> ");
    printArray(nums, 6);
}

void printArray(int *nums, int numsSize)
{
    int i;
    for (i=0; i<numsSize; i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
}


/*

912. Sort an Array
Medium

Given an array of integers nums, sort the array in ascending order.
Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
 
Constraints:
1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4


*/