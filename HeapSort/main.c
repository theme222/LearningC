// This actually contains pretty well writen code except for the Parent LeftChild RightChild Swap MaxHeapify BuildMaxHeap HeapSort display main functions 👍
#include <stdlib.h>
#include <stdio.h>

int heapLength;
int arrLength;

int Parent(int index) 
{
    return (index+1)/2-1;
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
    int left = LeftChild(index);
    int right = RightChild(index);
    int highest = index;
    if (left < heapLength && arr[highest] < arr[left])
    {
        highest = left;
    }
    if (right < heapLength && arr[highest] < arr[right])
    {
        highest = right;
    }
    if (highest != index)
    {
        Swap(arr, index, highest);
        MaxHeapify(arr, highest);
    }
}

void BuildMaxHeap(int *arr)
{
    for (int i = Parent(heapLength-1); i >= 0; i--) 
    {
        MaxHeapify(arr, i);
    }
}

void display(int *arr)
{
    for (int i = 0; i < arrLength; i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
}


void HeapSort(int *arr)
{
    puts("");
    BuildMaxHeap(arr);
    while (heapLength > 0)
    {
        display(arr);
        Swap(arr, 0, heapLength-1);
        heapLength--;
        MaxHeapify(arr, 0);
    }
}

int main()
{
    scanf("%d", &arrLength);
    heapLength = arrLength;

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
