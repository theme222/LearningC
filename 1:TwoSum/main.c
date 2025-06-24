#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *returnArr = malloc(sizeof(int) * 2);
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                returnArr[0] = i;
                returnArr[1] = j;
                return returnArr;
            }
        }
    }
    return returnArr;
}
