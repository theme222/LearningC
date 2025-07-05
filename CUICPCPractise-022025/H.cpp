#include <iostream>
#include <cstdint>
#include <iterator>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

std::map<int, int> numOfNums;
bool numHasBeenUsed[2000];
int nums[2000];
int main()
{
    int numCount;
    std::cin >> numCount;

    for (int i = 0; i < numCount; i++)
    {
        scanf("%d",nums+i);
        if (numOfNums.contains(nums[i])) numOfNums[i]++;
        else numOfNums[i] = 1;
    }

    std::sort(nums, nums+numCount);

    // for (int i =0; i < numCount; i++)
    //     printf("%d ", nums[i]);
    // puts("");

    int shortI1 = -1, shortI2 = -1;
    for (int i = 0; i < numCount; i++)
        for (int j = i+1; j < numCount; j++)
        {
            if (abs(nums[shortI1] - nums[shortI2]) > abs(nums[i] - nums[j]) || (shortI1 == -1 && shortI2 == -1))
            {
                shortI1 = i;
                shortI2 = j;
            }
        }

    uint64_t total = 0;
    numHasBeenUsed[shortI1] = true;

    // printf("I1 %d I2 %d\n", shortI1, shortI2);
    int currentMin = nums[shortI1], currentMax = nums[shortI1];
    int indexToCheck = shortI2;
    for (int i = 0; i < numCount-1; i++)
    {
        numHasBeenUsed[indexToCheck] = true;
        numOfNums[nums[indexToCheck]]--;
        int lowestDiff = (int)1e16;
        int nextIndex = -1;
        int nextCount = 0;

        for (int j = indexToCheck-1; j >= 0; j--)
        {
            if (numHasBeenUsed[j]) continue;
            lowestDiff = abs(nums[indexToCheck] - nums[j]);
            nextIndex = j;
            nextCount = 0;
            break;
        }

        for (int j = indexToCheck+1; j < numCount; j++)
        {
            if (numHasBeenUsed[j]) continue;
            if (nextIndex == -1 || nums[j] == nums[indexToCheck])
            {
                lowestDiff = abs(nums[indexToCheck] - nums[j]);
                nextIndex = j;
                break;
            }

            int totalDiffHigh = abs(nums[indexToCheck] - nums[j]) * numOfNums[nums[j]] + (abs(nums[j] - nums[nextIndex]) * numOfNums[nextIndex]);
            int totalDiffLow = (lowestDiff * numOfNums[nextIndex]) + (abs(nums[j] - nums[nextIndex]) * numOfNums[j]);

            if (totalDiffHigh < totalDiffLow)
            {
                lowestDiff = abs(nums[indexToCheck] - nums[j]);
                nextIndex = j;
            }
            break;
        }

        if (nums[indexToCheck] < currentMin) currentMin = nums[indexToCheck];
        if (nums[indexToCheck] > currentMax) currentMax = nums[indexToCheck];


        // printf("%d %d %d\n", indexToCheck, currentMin, currentMax);
        indexToCheck = nextIndex;
        total += currentMax - currentMin;
    }
    printf("%lu\n", total);
}
