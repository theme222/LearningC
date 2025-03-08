#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void MergeSort(int *arr, int lStart, int rEnd)
{
    printf("Calling MergeSort with %d %d \n", lStart, rEnd);
    if (lStart == rEnd) return; // Size one don't do anything

    int lEnd = lStart + ((rEnd - lStart) / 2);
    int rStart = lEnd + 1;

    // Find the length of left and right
    int lSize = lEnd - lStart + 1;
    int rSize = rEnd - rStart + 1;
    
    MergeSort(arr, lStart, lEnd);
    MergeSort(arr, rStart, rEnd);

    int *lAuxArray = malloc(sizeof(int) * lSize);
    memcpy(lAuxArray, arr+lStart, sizeof(int) * lSize);
    int *rAuxArray = malloc(sizeof(int) * rSize);
    memcpy(rAuxArray, arr+rStart, sizeof(int) * rSize);
    int lIndex = 0, rIndex = 0;
    for (int i = lStart; i <= rEnd; i++)
    {
        if (lIndex == lSize) 
        {
            arr[i] = rAuxArray[rIndex];
            rIndex++;
        }
        else if (rIndex == rSize)
        {
            arr[i] = lAuxArray[lIndex];
            lIndex++;
        }
        else if (lAuxArray[lIndex] < rAuxArray[rIndex])
        {
            arr[i] = lAuxArray[lIndex];
            lIndex++;
        }
        else
        {
            arr[i] = rAuxArray[rIndex];
            rIndex++;
        }
    }
    free(lAuxArray);
    free(rAuxArray);
}

int arrLength;
int main()
{
    // Read from stdin
    scanf("%d", &arrLength);

    int *arr = calloc(arrLength, sizeof(int));
    for (int i = 0; i < arrLength; i++)
    {
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0, arrLength-1);

    // Output
    puts("\n");
    for (int i = 0; i < arrLength; i++)
    {
        printf("%d\n", arr[i]);
    }

    free(arr);
}
