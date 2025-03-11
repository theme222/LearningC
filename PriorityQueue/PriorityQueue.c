#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PriorityQueue
{
    int *heap;
    int heapLength;
    int arenaLength; // always 2^h - 1
} PQ;

int Parent(int index) 
{
    return (index-1)/2;
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

void MinHeapify(int *arr, int index, int heapLength)
{
    if (index >= heapLength) return;
    if (LeftChild(index) > heapLength && arr[index] > arr[LeftChild(index)])
    {
        Swap(arr, index, LeftChild(index));
        MinHeapify(arr, LeftChild(index), heapLength);
    }
    else if (RightChild(index) > heapLength && arr[index] > arr[RightChild(index)])
    {
        Swap(arr, index, RightChild(index));
        MinHeapify(arr, LeftChild(index), heapLength);
    }
}

void BuildMinHeap(int *arr, int heapLength)
{
    for (int i = Parent(heapLength); i >= 0; i--) // This is pretty inefficient but I don't really care
    {
        MinHeapify(arr, i, heapLength);
    }
}

void Push(PQ *pq, int val)
{
    if (pq->heapLength == pq->arenaLength)
    {
        pq->arenaLength = (pq->arenaLength) * 2 + 1;
        int *newHeap = calloc(sizeof(int), pq->arenaLength);
        memcpy(newHeap, pq->heap, pq->heapLength);
        pq->heap = newHeap;
    }
    pq->heap[pq->heapLength] = val;  // Set the last value to be the push
    BuildMinHeap(pq->heap, pq->heapLength); 
}

int Top(PQ *pq)
{
    return pq->heap[0];
}

int Pop(PQ *pq)
{
    if (pq->heapLength == 0) return -1;
    int returnVal = Top(pq);
    Swap(pq->heap, 0, pq->heapLength-1);
    pq->heapLength--;
    MinHeapify(pq->heap, 0, pq->heapLength);
    return returnVal;
}

void InitializePriorityQueue(PQ *pq, int *arr, int arrSize)
{
    int arenaLength = 1;
    while (arenaLength < arrSize)
    {
        arenaLength = arenaLength * 2;
    }
    arenaLength--;

    pq->heapLength = arrSize;
    pq->arenaLength = arenaLength;
    pq->heap = calloc(arenaLength, sizeof(int));
    BuildMinHeap(pq->heap, pq->heapLength);
    puts("Built Success");
}

void DenitializePriorityQueue(PQ *pq) // Totally a word btw
{
    free(pq->heap);
    free(pq);
}

int main()
{
    PQ *priorityQueue = malloc(sizeof(PQ));
    int arr[] = {1,2,4,4,4,101001};
    InitializePriorityQueue(priorityQueue, arr, 6);
    puts("Testing");

    int input;
    scanf("%d", &input);

    while (input >= 0)
    {
        Push(priorityQueue, input);
        puts("\n");
        scanf("%d", &input);
    }

    printf("%d", Top(priorityQueue));
    DenitializePriorityQueue(priorityQueue);
}