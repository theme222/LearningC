#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int totalCount;

void printNums(int *nums)
{
    for (int i = 0; i < 5; i++)
        printf("%d ", nums[i]);
    puts("");
}

void merge(int *nums, int start, int mid, int end)
{
    int *temp = malloc(sizeof(int) * (end-start + 1));
    int tempSize = 0;
    int count = 0, checkPos = mid+1, rightPos = mid+1;
    for (int l = start; l <= mid; l++)
    {
        while (checkPos <= end)
        {
            if ((int64_t)nums[l] <= (int64_t)nums[checkPos] * 2) break;
            count++;
            checkPos++;
        }

        totalCount += count;

        while (rightPos <= end && (int64_t)nums[rightPos] < nums[l])
        {
            temp[tempSize] = nums[rightPos];
            tempSize++;
            rightPos++;
        }

        temp[tempSize] = nums[l];
        tempSize++;
    }

    for (int r = rightPos; r <= end; r++)
    {
        temp[tempSize] = nums[r];
        tempSize++;
    }

    for (int i = 0; i < end-start+1; i++)
        nums[start + i] = temp[i];

    free(temp);
}

void divide(int *nums, int start, int end)
{
    if (start >= end) return;
    int mid = (end-start) / 2 + start;
    divide(nums, start, mid);
    divide(nums, mid+1, end);
    merge(nums, start, mid, end);
}

int reversePairs(int* nums, int numsSize)
{
    totalCount = 0;
    divide(nums, 0, numsSize-1);

    return totalCount;
}

int main()
{
    int nums[] = {1,3,2,3,1};
    reversePairs(nums, 5);
}
