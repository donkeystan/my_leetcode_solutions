#include<stdlib.h>
#include<stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
void print_2d_array(int **nums, int row_size, int *col_sizes);
void print_array(int *nums, int nums_size);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
{
    // 若intervalSize 為 0 或  newInterval的最小小於intervals最小 且 newInterval的最大 大於intervals 最大，直接return newIntervals這組
    if (intervalsSize == 0 || (newInterval[0] <= intervals[0][0] && newInterval[1] >= intervals[intervalsSize-1][1]))
    {
        (*returnSize) = 1;
        (*returnColumnSizes) = (int *)malloc(sizeof(int) * 1);
        (*returnColumnSizes)[0] = 2;
        int **result = (int **)malloc(sizeof(int *) * (*returnSize));
        result[0] = (int *)malloc(sizeof(int) * 2);
        result[0][0] = newInterval[0];
        result[0][1] = newInterval[1];
        return result;
    }

    int i, j;
    
    // 條件為 將 newIntervals 插入頭組
    if (newInterval[1] < intervals[0][0])
    {
        (*returnSize) = intervalsSize + 1;
        (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
        int **result = (int **)malloc(sizeof(int *) * (*returnSize));
        result[0] = (int *)malloc(sizeof(int) * 2);

        result[0][0] = newInterval[0];
        result[0][1] = newInterval[1];
        (*returnColumnSizes)[0] = 2;

        for (i=1; i<(*returnSize); i++)
        {
            result[i] = (int *)malloc(sizeof(int) * 2);
            result[i][0] = intervals[i-1][0];
            result[i][1] = intervals[i-1][1];
            (*returnColumnSizes)[i] = 2;
        }
        return result;
    }
    
    // 條件為 將 newIntervals 插入最末組
    if (newInterval[0] > intervals[intervalsSize-1][1])
    {
        (*returnSize) = intervalsSize + 1;
        (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
        int **result = (int **)malloc(sizeof(int *) * (*returnSize));
        for (i=0; i<(*returnSize)-1; i++)
        {
            
            result[i] = (int *)malloc(sizeof(int) * 2);
            result[i][0] = intervals[i][0];
            result[i][1] = intervals[i][1];
            (*returnColumnSizes)[i] = 2;
        }
        result[i] = (int *)malloc(sizeof(int) * 2);
        result[i][0] = newInterval[0];
        result[i][1] = newInterval[1];
        (*returnColumnSizes)[i] = 2;
        return result;
    }


    // 排除完上述後，進行插入，將newIntervals 插入 intervals 中符合排序的位置
    int inserted_intervals[intervalsSize+1][2];
    int inserted = 0;
    for (i=0; i<intervalsSize; i++)
    {
        if (newInterval[0] <= intervals[i][0])
        {
            for (j=0; j<2; j++)
            {
                inserted_intervals[i][j] = newInterval[j];    
                inserted = 1;
            }

            for (i=i; i<intervalsSize; i++)
            {
                for (j=0; j<2; j++)
                {
                    inserted_intervals[i+1][j] = intervals[i][j];
                }
            }
            
            break;
        }

        for (j=0; j<2; j++)
        {
            inserted_intervals[i][j] = intervals[i][j];
        }    
    }

    // 檢查若無插入點，則該newInterval應做為最末組插入
    if (inserted == 0)
    {
        for (j=0; j<2; j++)
        {
            inserted_intervals[intervalsSize][j] = newInterval[j];
        }
    }

    // 進行雙 Pointer 處裡

    int seg_head;
    int seg_end;
    int **result = (int **)malloc(sizeof(int *) * (intervalsSize+1));
    int count = 0 ;

    // 先將 第一組資料存至 片段頭數 及 片段末數
    seg_head = inserted_intervals[0][0];
    seg_end = inserted_intervals[0][1];

    // 迴圈遍壢整個新 inserted_intervals 
    for (i=1; i<intervalsSize+1; i++)
    {

        // 當目前抓取的 片段末數 大於目前組的頭數 則 比較目前組的尾看是否併吞該組
        if (seg_end >= inserted_intervals[i][0])
        {
            // 比較 目前片段末數 與 目前組的尾數
            seg_end = max(inserted_intervals[i][1], seg_end);
        }
        else
        {
            // 若 目前片段末數 沒有大於 該組頭數，則將片段寫入結果組
            result[count] = (int *)malloc(sizeof(int) * 2);
            result[count][0] = seg_head;
            result[count][1] = seg_end;
            count ++;

            // 寫入完成後，更新 片段頭數 及 片段末數
            seg_head = inserted_intervals[i][0];
            seg_end = inserted_intervals[i][1];
        }
    }

    result[count] = (int *)malloc(sizeof(int) * 2);    
    result[count][0] = seg_head;
    result[count][1] = seg_end;
    count ++;
    
    (*returnSize) = count;
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    for (i=0; i<(*returnSize); i++)
    {
        (*returnColumnSizes)[i] = 2;
    }
    return result;
}

int main(int argc, char const *argv[])
{    
    // intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
    int temp[] = { 1,2,3,5,6,7,8,10,12,16,20,21 };
    // int temp[] = { 1, 3, 6, 9};
    
    // int temp[] = { 1,2,6,7,8,10,12,16,20,21 };
    // int temp[] ={};
    // int newInterval[] = {4, 8};
    // int newInterval[] = {3, 8};
    // int newInterval[] = {1, 15};
    // int newInterval[] = {0, 15};
    // int newInterval[] = {17, 18};
    // int newInterval[] = {22, 23};
    // int newInterval[] = {0, 0};
    // int newInterval[] = {3, 5};
    int newInterval[] = {1, 22};
    // int newInterval[] = {3, 22};
    
    // int temp[] = {1,5};
    // int newInterval[] = {2, 7};

    // int temp[] = {0,2,3,3,6,11};
    // int newInterval[] = {9, 15};

    int newIntervalSize = sizeof(newInterval) / sizeof(newInterval[0]);
    int intervalsColSize = 2;
    int intervalSize = (sizeof(temp)/sizeof(temp[0])) / intervalsColSize;
    int **intervals = (int **)malloc(sizeof(int *) * intervalSize);
    int i, j, k=0;
    for (i=0; i<intervalSize; i++)
    {
        intervals[i] = (int *)malloc(sizeof(int) * intervalsColSize);
        for (j=0; j<intervalsColSize; j++)
        {
            intervals[i][j] = temp[k++];
        }
    }
    int returnSize;
    int *returnColumnSizes = NULL;
    int **result = insert(intervals, intervalSize, &intervalsColSize, newInterval, newIntervalSize, &returnSize, &returnColumnSizes);
    print_2d_array(result, returnSize, returnColumnSizes);
    return EXIT_SUCCESS;
}

void print_2d_array(int **nums, int row_size, int *col_sizes)
{
    int i, j;
    printf("[\n");
    for (i=0; i<row_size; i++)
    {
        printf("[ ");
        for (j=0; j<col_sizes[i]; j++)
        {
            printf("%d", nums[i][j]);
            if (j < col_sizes[i]-1)
            {
                printf(", ");
            }
        }
        printf(" ]");
        if (i < row_size-1)
        {
            printf(", ");
        }
        printf("\n");
    }
    printf("]\n");
}

void print_array(int *nums, int nums_size)
{
    int i;
    printf("[ ");
    for (i=0; i<nums_size; i++)
    {
        printf("%d", nums[i]);
        if (i < nums_size-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}



/*

57. Insert Interval
Medium
8K
555
Companies
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^5
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 10^5

*/


/*

if (intervalsSize == 0 || (newInterval[0] < intervals[0][0] && newInterval[1] > intervals[intervalsSize-1][1]))
    {
        (*returnSize) = 1;
        (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
        result = (int **)malloc(sizeof(int *) * (*returnSize));
        result[0] = (int *)malloc(sizeof(int) * 2);
        for (i=0; i<2; i++)
        {
            result[0][i] = newInterval[i];
        }
        (*returnColumnSizes)[0] = 2;
        return result;
    }

    if (newInterval[1] < intervals[0][0])
    {
        head = append_list(head, &tail, newInterval, 2);
        (*returnSize) ++;

        for (i=0; i<intervalsSize; i++)
        {
            head = append_list(head, &tail, intervals[i], 2);
            (*returnSize) ++;
        }
        result = write_result(head, returnSize, returnColumnSizes);
        return result;
    }

    if (newInterval[0] > intervals[intervalsSize-1][1])
    {        
        for (i=0; i<intervalsSize; i++)
        {
            head = append_list(head, &tail, intervals[i], 2);
            (*returnSize) ++;
        }

        head = append_list(head, &tail, newInterval, 2);
        (*returnSize) ++;

        result = write_result(head, returnSize, returnColumnSizes);
        return result;
    }

    int merge_start_index = -1;
    int merge_end_index = -1;

    int tmp[2];
    for (i=0; i<intervalsSize; i++)
    {
        if (newInterval[0] <= intervals[i][1])
        {
            if (newInterval[0] <= intervals[i][0])
            {
                tmp[0] = newInterval[0];
            }
            else
            {
                tmp[0] = intervals[i][0];
            }
            
            
        }
    }

*/


/*

struct list_node *merge_lists(struct list_node *list1, struct list_node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    
    if (list2 == NULL)
    {
        return list1;
    }
    if (list1->nums[0] <= list2->nums[0])
    {
        list1->next = merge_lists(list1->next, list2);
        return list1;
    }

    else
    {
        list2->next = merge_lists(list2->next, list1);
        return list2;
    }
}

struct list_node *merge_sort_list(struct list_node *head)
{
    if (NULL == head || NULL == head->next)
    {
        return head;
    }
    struct list_node *mid = head;
    struct list_node *cut = head;
    struct list_node *tail = head;
    
    while (NULL != tail && NULL != tail->next)
    {
        cut = mid;
        mid = mid->next;
        tail = tail->next->next;
    } 
    cut->next = NULL;
    return merge_lists(merge_sort_list(head), merge_sort_list(mid));
}



*/

/*


struct list_node
{
    int *nums;
    int nums_size;
    struct list_node *next;
};

int print_list(struct list_node *head);
int print_list(struct list_node *head)
{
    int count = 0;
    while (NULL != head)
    {
        print_array(head->nums, head->nums_size);
        head = head->next;
        count ++;
    }
    return count;
}


struct list_node *get_node(int *nums, int nums_size)
{
    struct list_node *new_node = (struct list_node *)malloc(sizeof(struct list_node));
    new_node->nums = (int *)malloc(sizeof(int) * nums_size);
    new_node->nums_size = nums_size;
    int i;
    for (i=0; i<nums_size; i++)
    {
        new_node->nums[i] = nums[i];
    }
    new_node->next = NULL;
    return new_node;
}

struct list_node *append_list(struct list_node *head, struct list_node **tail, int *nums, int nums_size)
{
    if (NULL != head)
    {
        (*tail)->next = get_node(nums, nums_size);
        (*tail) = (*tail)->next;
    }
    else
    {
        head = get_node(nums, nums_size);
        (*tail) = head;
    }
    return head;
}

int **write_result(struct list_node *head, int *returnSize, int **returnColumnSizes)
{
    int **result = (int **)malloc(sizeof(int *) * (*returnSize));
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    int i;
    for (i=0; i<(*returnSize) && head != NULL; i++)
    {
        result[i] = head->nums;
        (*returnColumnSizes)[i] = head->nums_size;
        head = head->next;
    }
    return result;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
{
    int **result = NULL;
    (*returnSize) = 0;
    struct list_node *head = NULL;
    struct list_node *tail = NULL;
    int i, j;

    // exclude if intervalSize is 0 or the newIntreval set covers the whole intervals
    if (intervalsSize == 0 || (newInterval[0] < intervals[0][0] && newInterval[1] > intervals[intervalsSize-1][1]))
    {
        (*returnSize) = 1;
        (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
        result = (int **)malloc(sizeof(int *) * (*returnSize));
        result[0] = (int *)malloc(sizeof(int) * 2);
        for (i=0; i<2; i++)
        {
            result[0][i] = newInterval[i];
        }
        (*returnColumnSizes)[0] = 2;
        return result;
    }

    // exclude the newIntervals set smaller than the first set of intervals
    if (newInterval[1] < intervals[0][0])
    {
        head = append_list(head, &tail, newInterval, 2);
        (*returnSize) ++;

        for (i=0; i<intervalsSize; i++)
        {
            head = append_list(head, &tail, intervals[i], 2);
            (*returnSize) ++;
        }
        result = write_result(head, returnSize, returnColumnSizes);
        return result;
    }

    // exclude the newIntervals set larger than the last set of intervals
    if (newInterval[0] > intervals[intervalsSize-1][1])
    {        
        for (i=0; i<intervalsSize; i++)
        {
            head = append_list(head, &tail, intervals[i], 2);
            (*returnSize) ++;
        }

        head = append_list(head, &tail, newInterval, 2);
        (*returnSize) ++;

        result = write_result(head, returnSize, returnColumnSizes);
        return result;
    }

    int count;
    int seg_head;
    int seg_end;
    int insertion_index = -1;

    for (i=0; i<intervalsSize; i++)
    {
        if (newInterval[0] <= intervals[i][0])
        {
            insertion_index = i;
        }
    }

    if (insertion_index == 0)
    {
        seg_head = newInterval[0];
        seg_end = newInterval[1];
        
        for (i=0; i<intervalsSize; i++)
        {
            
        }


    }


   
    result = write_result(head, returnSize, returnColumnSizes);
    return result;
}


*/

/*

// 當 newIntervals[ 0 ]  比 intervals 第一組數字還小時，拿 newIntervals來當作s第一組egment head 並進行merge
    // if (newInterval[0] <= intervals[0][0])
    // {
    //     seg_head = newInterval[0];
    //     seg_end = newInterval[1];

    //     for (i=0; i<intervalsSize; i++)
    //     {
    //         if (seg_end >= intervals[i][0])
    //         {
    //             seg_end = max(intervals[i][1], seg_end);
    //         }
    //         else
    //         {
    //             result[count] = (int *)malloc(sizeof(int) * 2);
    //             result[count][0] = seg_head;
    //             result[count][1] = seg_end;
    //             count ++;
    //             seg_head = intervals[i][0];
    //             seg_end = intervals[i][1];
    //         }
    //     }
    // }
    // else
    // {
    //     seg_head = intervals[0][0];
    //     seg_end = intervals[0][1];

    //     for (i=1; i<intervalsSize; i++)
    //     {
    //         if (newInterval[0] <= intervals[i][0])
    //         {
    //             if (seg_end >= newInterval[0])
    //             {
    //                 seg_end = max(newInterval[1], seg_end);
    //             }
    //             else
    //             {
    //                 result[count] = (int *)malloc(sizeof(int) * 2);
    //                 result[count][0] = seg_head;
    //                 result[count][1] = seg_end;
    //                 count ++;
    //                 seg_head = newInterval[0];
    //                 seg_end = newInterval[1];
    //             }
    //         }

    //         if (seg_end >= intervals[i][0])
    //         {
    //             seg_end = max(intervals[i][1], seg_end);
    //         }
    //         else
    //         {

    //             result[count] = (int *)malloc(sizeof(int) * 2);
    //             result[count][0] = seg_head;
    //             result[count][1] = seg_end;
    //             count ++;
    //             seg_head = intervals[i][0];
    //             seg_end = intervals[i][1];
    //         }
    //     }
    // }


*/