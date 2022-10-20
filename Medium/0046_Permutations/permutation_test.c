#include<stdlib.h>
#include<stdio.h>

void permutation(int  *nums, int *var, int level, int nums_size, int* combo);
int isContinue(int *var, int level);
int get_permutation_amount(int n);

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    int combo = 0;
    int size = get_permutation_amount(nums_size);
    int var[size];
    int level = 0;

    permutation(nums, var, level, nums_size, &combo);
    
    return 0;
}

void permutation(int *nums, int *var, int level, int nums_size, int* combo)
{
    if (level == nums_size)
    {
        (*combo) ++;
        printf("Combo [%d] --> ", (*combo));
        int i;
        for (i=0; i<nums_size; i++)
        {
            printf("%d ",nums[var[i]]);
        }
        printf("\n");
        return;
    }

    for (var[level]=0; var[level]<nums_size; var[level]++)
    {
        if (isContinue(var, level))
        {
            continue;
        }
        permutation(nums, var, level+1, nums_size, combo);
    }
}

int isContinue(int *var, int level)
{
    // ( i==j || i==k || i==l || j==k || j==l || k ==L )  <== it's a double loop structure to find continue condition

    int i;
    int j;

    for (i=0; i<=level; i++)
    {
        for (j=i+1; j<=level; j++)
        if (var[i] == var[j])
        {
            return 1;
        }
    }

    return 0;
}

int get_permutation_amount(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * get_permutation_amount(n-1);
}

/*
( level != 0 && var[level-1] == var[level] ) || ( level != 1 && var[level-2] == var[level] ) || ( level != 2 && var[level-3] == var[level])
*/

/*

int i,j,k;

    for (i=0; i<numsSize; i++)
    {
        for (j=0; j<numsSize; j++)
        {
            for (k=0; k<numsSize; k++)
            {
                if (i==j || i==k || j==k  )
                {
                    continue;
                }
                printf("i:%d, j:%d, k:%d ---> [%d, %d, %d]\n",i,j,k, nums[i], nums[j], nums[k]);
            }
        }
    }


*/
