// Doesn't work with all negative values

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arrayLength;
int maximumSum = -1e9;
int maxStartIndex;
int maxEndIndex;


int main()
{
    // Input the array
    scanf("%d", &arrayLength);
    int* arr = calloc(arrayLength, sizeof(int));
    
    for (int i = 0; i< arrayLength; i++)
    {
        scanf("%d", arr+i);
    }

    int i=0;
    while (arr[i] < 0 && i < arrayLength) i++;
    int currentStartIndex = i, currentEndIndex = i;
    int currentSum = arr[i], currentMaxSum = arr[i];

    // Dynamic Programming 
    for (i = i+1; i < arrayLength; i++)
    {
        currentSum += arr[i];
        if (currentSum > currentMaxSum)
        {
            currentEndIndex = i;
            currentMaxSum = currentSum;
        }
        if (currentSum <= 0)
        {
            maximumSum = currentMaxSum;
            maxStartIndex = currentStartIndex;
            maxEndIndex = currentEndIndex;
            currentStartIndex = i+1;
            currentEndIndex = i+1;
            currentSum = 0;
            currentMaxSum = 0;
        }
    }
    if (currentMaxSum > maximumSum) 
    {
        maxStartIndex = currentStartIndex;
        maxEndIndex = currentEndIndex;
        maximumSum = currentMaxSum;
    }
    if (currentSum > maximumSum) 
    {
        maxStartIndex = currentStartIndex;
        maxEndIndex = i; 
        maximumSum = currentSum;
    }

    printf("Maximum sum : %d \n", maximumSum);
    printf("Index %d %d \n", maxStartIndex, maxEndIndex);
    free(arr);
}