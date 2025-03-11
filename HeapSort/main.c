#include <stdlib.h>
#include <stdio.h>

int heapLength;
int arrLength;

int Parent(int index) 
{
    return index/2;
}

int LeftChild(int index)
{
    return (index+1)*2-1;
}

int RightChild(int index)
{
    return (index+1)*2;
}

void Swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void MaxHeapify(int *arr, int index)
{
    if (index >= heapLength) return;
    if (LeftChild(index) < heapLength && arr[index] < arr[LeftChild(index)])
    {
        Swap(arr, index, LeftChild(index));
        MaxHeapify(arr, LeftChild(index));
    }
    else if (RightChild(index) < heapLength && arr[index] < arr[RightChild(index)])
    {
        Swap(arr, index, RightChild(index));
        MaxHeapify(arr, LeftChild(index));
    }
}

void BuildMaxHeap(int *arr)
{
    for (int i = Parent(heapLength-1); i >= 0; i--) // This is pretty inefficient but I don't really care
    {
        MaxHeapify(arr, i);
    }
}

void HeapSort(int *arr)
{
    BuildMaxHeap(arr);
    while (heapLength > 0)
    {
        Swap(arr, 0, heapLength-1);
        heapLength--;
        MaxHeapify(arr, 0);
    }
}

int main()
{
    // Input the array values
    scanf("%d", &heapLength);
    arrLength = heapLength;

    int *arr = calloc(arrLength, sizeof(int));

    for (int i = 0; i < arrLength; i++)
    {
        scanf("%d", arr+i);
    }

    HeapSort(arr);
    puts("");

    for (int i = 0; i < arrLength; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
}