#include<stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct list_node
{
    float quotient;
    int num1;
    int num2;
    struct list_node *next;
};

struct list_node *get_node(float quotient, int num1, int num2);
struct list_node *append(struct list_node *head, struct list_node **tail, float quotient, int num1, int num2);
int print_list(struct list_node *head, int count);
struct list_node *merge_sort_list(struct list_node *head);
struct list_node *merge_lists(struct list_node *list1, struct list_node *list2);

void write_result(struct list_node *head, int k, int *result)
{
    int i;
    for (i=1; i<k && NULL!=head; i++)
    {
        head = head->next;
    }
    result[0] = head->num1;
    result[1] = head->num2;
}

void combinations(int *arr, int arrSize, struct list_node **head, struct list_node **tail)
{
    int i, j;
    for (i=0; i<arrSize; i++)
    {
        for (j=i+1; j<arrSize; j++)
        {
            (*head) = append((*head), tail, (float)arr[i]/(float)arr[j], arr[i], arr[j]);
        }
    }
    (*head) = merge_sort_list((*head));
}

/*
    My solution is pretty simple and brutal.
    First use combination C-size K-2, so no recursion is required.
    Just a 2 for loop can get all C-size K-2 combinations.
    Use Linked-list data structure that holds a float, and two int to store the [ quotient of the fraction in decimals ], [prime 1 'numerator'] and [prime 2 'denominator']
    than use merge_sort_list to sort by each node's [quotient of fraction] from small to large
    then use a for loop to take the kthSmallest fraction set and return the result;
*/

int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize)
{
    (*returnSize) = 2;
    int *result = (int *)malloc(sizeof(int) * (*returnSize));
    struct list_node *head = NULL;
    struct list_node *tail = NULL;
    combinations(arr, arrSize, &head, &tail);
    print_list(head, 0);
    write_result(head, k, result);
    return result;
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

struct list_node *merge_lists(struct list_node *list1, struct list_node *list2)
{
    if (NULL == list1)
    {
        return list2;
    }
    if (NULL == list2)
    {
        return list1;
    }
    if (list1->quotient <= list2->quotient)
    {
        list1->next = merge_lists(list1->next, list2);
        return list1;
    }
    if (list2->quotient < list1->quotient)
    {
        list2->next = merge_lists(list2->next, list1);
        return list2;
    }
    return list1;
}

struct list_node *get_node(float quotient, int num1, int num2)
{
    struct list_node *new_node = (struct list_node *)malloc(sizeof(struct list_node));
    new_node -> quotient = quotient;
    new_node -> num1 = num1;
    new_node -> num2 = num2;
    new_node -> next = NULL;
    return new_node;
}

struct list_node *append(struct list_node *head, struct list_node **tail, float quotient, int num1, int num2)
{
    if (NULL != head)
    {
        (*tail)->next = get_node(quotient, num1, num2);
        (*tail) = (*tail)->next;
        return head;
    }
    head = get_node(quotient, num1, num2);
    (*tail) = head;
    return head;
}

int print_list(struct list_node *head, int count)
{
    if (NULL != head)
    {
        printf("[%.16f, %d, %d ]\n", head->quotient, head->num1, head->num2);
        count = print_list(head->next, count+1);
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979};
    int k = 1;
    // int arr[] = {1, 2, 3, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    // int k = 3;
    int returnSize;
    int *result = kthSmallestPrimeFraction(arr, arrSize, k, &returnSize);
    printf("kthSmallestPrimeFraction --> [ %d, %d ]\n", result[0], result[1]);
    return EXIT_SUCCESS;
}

/*

786. K-th Smallest Prime Fraction
Medium
You are given a sorted integer array arr containing 1 and prime numbers,
where all the integers of arr are unique. You are also given an integer k.
For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

Example 1:
Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.

Example 2:
Input: arr = [1,7], k = 1
Output: [1,7]

Constraints:
2 <= arr.length <= 1000
1 <= arr[i] <= 3 * 10^4
arr[0] == 1
arr[i] is a prime number for i > 0.
All the numbers of arr are unique and sorted in strictly increasing order.
1 <= k <= arr.length * (arr.length - 1) / 2

Follow up: Can you solve the problem with better than O(n^2) complexity?

*/