#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAP_SIZE 20000
void print_array(int *nums, int nums_size);

int mapping(int num)
{
    if (num >= 0)
    {
        return num;
    }
    return (num * -1) + 10000;
}

int extract(int num)
{
    if (num < 10001)
    {
        return num;
    }
    return (num - 10000) * -1;
}

void merge_sort_2d(int **nums, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort_2d(nums, start, mid);
        merge_sort_2d(nums, mid+1, end);
        int i, j, k, left_len = (mid-start+1), right_len = (end - mid);
        int **nums_left = (int **)malloc(sizeof(int *) * 2);
        int **nums_right = (int **)malloc(sizeof(int *) * 2);
        
        for (i=0; i<2; i++)
        {
            nums_left[i] = (int *)malloc(sizeof(int) * left_len);
            nums_right[i] = (int *)malloc(sizeof(int) * right_len);
        }

        for (i=0; i<left_len; i++)
        {
            nums_left[0][i] = nums[0][start + i];
            nums_left[1][i] = nums[1][start + i];
        }

        for (i=0; i<right_len; i++)
        {
            nums_right[0][i] = nums[0][mid +1 + i];
            nums_right[1][i] = nums[1][mid +1 + i];
        }

        for (i=0, j=0, k=start; i<left_len && j < right_len; k++)
        {
            if (nums_left[0][i] >= nums_right[0][j])
            {
                nums[0][k] = nums_left[0][i];
                nums[1][k] = nums_left[1][i++];
            }
            else
            {
                nums[0][k] = nums_right[0][j];
                nums[1][k] = nums_right[1][j++];
            }
        }

        while (i < left_len)
        {
            nums[0][k] = nums_left[0][i];
            nums[1][k++] = nums_left[1][i++];
        }

        while (j < right_len)
        {
            nums[0][k] = nums_right[0][j];
            nums[1][k++] = nums_right[1][j++];
        }
    }
}

    /*
        for num = [ 1, 1, 1, 2, 2, 3 ]

        write a table that looks like this
                +---+---+---+---+---+---+---+---+---+---+
    arr_index   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 
                +---+---+---+---+---+---+---+---+---+---+
        arr[0]  | 0 | 3 | 2 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |  then sort by this row of value (arr[1] must go with arr[0])
                +---+---+---+---+---+---+---+---+---+---+
        arr[1]  | 0 | 1 | 2 | 3 | 0 | 0 | 0 | 0 | 0 | 0 |  and extract the kth numbers from this row 
                +---+---+---+---+---+---+---+---+---+---+
    */

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    // 0. Prepare a map of 20000 int to store count of each number;
    int **map = (int **)malloc(sizeof(int *) * 2);
    int i, map_idx;
    for (i=0; i<2; i++)
    {
        map[i] = (int *)calloc(MAP_SIZE, sizeof(int));
    }

    // 1. Store the count of each element in the inputnums
    //    Save the maped number into its correspondent index and its value
    for (i=0; i<numsSize; i++)
    {
        map_idx = mapping(nums[i]);
        map[0][ map_idx ] ++; 
        map[1][ map_idx ] = map_idx; 
    }

    // 2. Do the merge_sort, compare count record in map[0]
    merge_sort_2d(map, 0, MAP_SIZE-1);

    (*returnSize) = k;
    int *result = (int *)malloc(sizeof(int) * k);

    // 3. Write the kth elements of map[1], which stores the original number of nums into the result array for return. 
    for (i=0; i<k; i++)
    {
        result[i] = extract(map[1][i]);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {1,1,1,2,2,3};
    int nums[] = {-9, 8, 2, 1,-9, 8, 8, 2, -9, -9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    int returnSize;
    int *result = topKFrequent(nums, numsSize, k, &returnSize);
    printf("< -- Top K:[%d] Elements are -->\n", k);
    print_array(result, returnSize);
    return EXIT_SUCCESS;
}

void print_array(int *nums, int nums_size)
{
    int i;
    printf("[ ");
    for (i=0; i<nums_size; i++)
    {
        printf("%d", nums[i]);
        if (i < nums_size -1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}


/*

347. Top K Frequent Elements
Medium
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1] 

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/