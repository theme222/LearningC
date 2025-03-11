#include <stdlib.h>
#include <stdio.h>

int arrLength;

void Swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int Partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int leftPartition = start-1;

    for (int i = start; i <= end-1; i++)
    {
        if (arr[i] <= pivot)
        {
            leftPartition++;
            Swap(arr, leftPartition, i);
        }
    }

    Swap(arr, leftPartition+1, end);
    return leftPartition+1;
}

void QuickSort(int *arr, int start, int end)
{
    if (start >= end) return;
    int center = Partition(arr, start, end);
    QuickSort(arr, start, center-1);
    QuickSort(arr, center+1, end);
}

int main()
{
    // Input the array values
    scanf("%d", &arrLength);
    int *arr = calloc(arrLength, sizeof(int));

    for (int i = 0; i < arrLength; i++)
    {
        scanf("%d", arr+i);
    }

    QuickSort(arr, 0, arrLength-1);

    puts("");

    for (int i = 0; i < arrLength; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
}