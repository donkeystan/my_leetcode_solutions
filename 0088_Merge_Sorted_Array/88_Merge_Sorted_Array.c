#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void print(int *, int nums1Size);
void array_copy(int *, int *, int numsSize);

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int tmp_nums[m+n];
    int i;
    int j;
    int k;

    if( n == 0 )                             // do nothing if second array got nothing
    {
        return;
    }
    else if( m==0 )                          // copy second array to first array if first array got nothing
    {
        array_copy(nums1,nums2,m+n);
        return;
    }
    else
    {
        j = 0;
        k = 0;
        for(i=0; i<m+n; i++ )                              // commpare array 1 and array 2's elements and copy it to tmp array
        {                                                  // if not exceeding the length of first array while the element of first array is smaller or equal to second array
            if( nums1[j] <= nums2[k] && j<m)               // copy nums1's current element to tmp array
            {
                tmp_nums[i] = nums1[j];
                printf("nums1[%d] <= nums2[%d] ---> tmp_nums[%d] = nums1[%d],  tmp_nums[%d] ---> %d", j, k, i, j, i, nums1[j]);
                j++;
                printf("  j--->%d\n",j);
            }
            else if( nums2[k] < nums1[j] && k<n )          // if not exceeding the length of second array while the element of second array is smaller or equal to first array
            {                                              // copy nums2's current element to tmp array
                tmp_nums[i] = nums2[k];
                printf("nums2[%d] <  nums1[%d] ---> tmp_nums[%d] = nums2[%d],  tmp_nums[%d] ---> %d", k, j, i, k, i, nums2[k]);
                k++;
                printf("  k--->%d\n",k);
            }

            if(j==m)                                      // break the loop when reaching the length limit of array 1
            {
                printf("j==m : \ni ---> %d\nj ---> %d\nm ---> %d\nk ---> %d\nn ---> %d\nm+n ---> %d\n",i,j,m,k,n,m+n);
                break;
            }
            if(k==n)                                     // break the loop when reaching the length limit of array 1
            {
                printf("k==n : \ni ---> %d\nj ---> %d\nm ---> %d\nk ---> %d\nn ---> %d\nm+n ---> %d\n",i,j,m,k,n,m+n);
                break;
            }
        }

        if( j==m )                                    // break the loop when reaching the length limit of array 1
        {                                             // copy rest of array 2's elements into tmp array from i+1's column
            for(i++; i<m+n; i++)                     
            {
                tmp_nums[i] = nums2[k];
                printf("tmp_nums[%d] = nums2[%d],  tmp_nums[%d] ---> %d", i, k, i, nums2[k]);
                k++;
                printf("  k--->%d\n",k);
            }
        }
        
        if( k==n )                                   // break the loop when reaching the length limit of array 2
        {                                            // copy rest of array 1's elements into tmp array from i+1's column
            for(i++; i<m+n; i++)
            {
                tmp_nums[i] = nums1[j];
                printf("tmp_nums[%d] = nums1[%d],  tmp_nums[%d] ---> %d", i, j, i, nums1[j]);
                j++;
                printf("   j--->%d\n",j);
            }
        }
        array_copy(nums1, tmp_nums, nums1Size);     // upon completion of merging, copy the tmp array to overwrite array 1 as resultant array
    }
    
    // print(tmp_nums, nums1Size);
}

int main(int argc, char *argv[])
{
    int nums1Size = 6;
    int m = 3;
    int nums2Size = 5;
    int n = 3;
    int nums1[] = {4,5,6,0,0,0};
    int nums2[] = {-7,0,0};
    int i;

    print(nums1, nums1Size);
    print(nums2, nums2Size);
    merge(nums1, nums1Size, m, nums2, nums2Size, n );
    print(nums1, nums1Size);

    return 0;
}


void array_copy(int *dest_nums, int *source_nums, int numsSize)
{
    int i;

    for(i=0; i<numsSize; i++)
    {
        dest_nums[i] = source_nums[i];
    }
}


void print(int *nums, int nums1Size)
{
    int i;
    printf("[");

    for(i=0; i<nums1Size; i++)
    {
        printf("%d", nums[i]);
        if(i<nums1Size-1)
        {
            printf(",");
        }
    }
    printf("]\n");
}


/*

nums1Size ---> 6
m ---> 3
nums2Size ---> 3
n ---> 3

88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, 
but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, 
where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/