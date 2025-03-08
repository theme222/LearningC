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

    // Bruteforce the array
    for (int i = 0; i < arrayLength; i++)
    {
        int sum = 0;
        for (int j = i; j < arrayLength; j++)
        {
            sum += arr[j];
            if (sum > maximumSum)
            {
                maxStartIndex = i;
                maxEndIndex = j;
                maximumSum = sum;
            }
        }
    }

    printf("Maximum sum : %d \n", maximumSum);
    printf("Index %d %d \n", maxStartIndex, maxEndIndex);
    free(arr);
}