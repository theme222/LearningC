#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arrayLength;
int maximumSum = -1e9;
int maxStartIndex;
int maxEndIndex;

typedef struct Trip
{
    int startIndex;
    int endIndex;
    int totalSum;
} Trip;

Trip CenterMaxSubArray(int* arr, int start, int end)
{
    int mid = start + ((end - start) / 2);
    Trip returnVal = (Trip) {.startIndex = mid, .endIndex = mid, .totalSum = arr[mid]} ;
    
    // Loop mid to start
    for (int i = mid-1; i >= start; i--)
    {
        if (arr[i] >= 0)
        {
            returnVal.totalSum += arr[i];
            returnVal.startIndex = i;
        } 
        else break;
    }

    // Loop mid+1 to end
    for (int i = mid+1; i <= end; i++)
    {
        if (arr[i] >= 0)
        {
            returnVal.totalSum += arr[i];
            returnVal.endIndex = i;
        }
        else break;
    }
    return returnVal;

}

Trip FindMaxSubArray(int* arr, int startIndex, int endIndex)
{
    printf("Calling with %d %d \n", startIndex, endIndex);
    if (startIndex >= endIndex) // Base case (1)
    {
        return (Trip) {.startIndex = startIndex, .endIndex = endIndex, .totalSum = arr[startIndex]};
    }

    int mid = startIndex + ((endIndex - startIndex) / 2);
    Trip leftTrip = FindMaxSubArray(arr, startIndex, mid);
    Trip rightTrip = FindMaxSubArray(arr, mid + 1, endIndex);
    Trip midTrip = CenterMaxSubArray(arr, startIndex, endIndex);

    printf("%d %d %d\n", leftTrip.totalSum, midTrip.totalSum, rightTrip.totalSum);
    if (leftTrip.totalSum >= rightTrip.totalSum && leftTrip.totalSum >= midTrip.totalSum)
    {
        return leftTrip;
    }
    else if (rightTrip.totalSum >= leftTrip.totalSum && rightTrip.totalSum >= midTrip.totalSum)
    {
        return rightTrip;
    }
    else
    {
        return midTrip;
    }
}

int main()
{
    // Input the array
    scanf("%d", &arrayLength);
    int* arr = calloc(arrayLength, sizeof(int));
    
    for (int i = 0; i< arrayLength; i++)
    {
        scanf("%d", arr+i);
    }

    // Devide and conquer

    Trip trip = FindMaxSubArray(arr, 0, arrayLength-1);
    
    printf("Maximum sum : %d \n", trip.totalSum);
    printf("Index %d %d \n", trip.startIndex, trip.endIndex);
    free(arr);
}