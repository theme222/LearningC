#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PriorityQueue
{
    int *heap;
    int heapLength;
    int arenaLength; 
} PQ;

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

void Display(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d",arr[i]);
    }
}


void Swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void MinHeapify(int *arr, int index, int heapLength)
{
    int left = LeftChild(index);
    int right = RightChild(index);
    int smallest = index;
    if (left < heapLength && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < heapLength && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != index)
    {
        Swap(arr, index, smallest);
        MinHeapify(arr, smallest, heapLength);
    }
}

void BuildMinHeap(int *arr, int heapLength)
{
    for (int i = Parent(heapLength-1); i >= 0; i--) 
    {
        MinHeapify(arr, i, heapLength);
    }
}

void Push(PQ *pq, int val)
{
    if (pq->heapLength == pq->arenaLength)
    {
        pq->arenaLength *= 2;
        pq->heap = realloc(pq->heap, pq->arenaLength * sizeof(int));
    }
    pq->heap[pq->heapLength] = val;  // Set the last value to be the push
    pq->heapLength++;
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
    pq->heap[0] = pq->heap[pq->heapLength - 1];
    pq->heapLength--;
    MinHeapify(pq->heap, 0, pq->heapLength);
    return returnVal;
}

void InitializePriorityQueue(PQ *pq, int *arr, int arrSize)
{
    int arenaLength = 1;
    while (arenaLength < arrSize)
    {
        arenaLength *= 2;
    }

    pq->heapLength = arrSize;
    pq->arenaLength = arenaLength;
    pq->heap = (int*) malloc(arenaLength * sizeof(int));
    memcpy(pq->heap, arr, arrSize * sizeof(int));


    BuildMinHeap(pq->heap, pq->heapLength);
}

void DenitializePriorityQueue(PQ *pq) // Totally a word btw
{
    free(pq->heap);
    free(pq);
}

int main()
{
    PQ *pq = malloc(sizeof(PQ));
    int arr[8] = {4, 2, 4, 52, 78, 9, 0, 5};  // For initializing the priority queue (I don't think you can malloc a 0 size byte)
    InitializePriorityQueue(pq, arr, 8);
    puts("Push values into priority queue (Type a negative number to stop)");
    
    int input;
    scanf("%d", &input);

    while (input >= 0)
    {
        Push(pq, input);
        scanf("%d", &input);
    }

    puts("Popping all values from priority queue");
    int output = Pop(pq);
    while (output != -1)
    {
        printf("%d\n",output);
        output = Pop(pq);
    }
    DenitializePriorityQueue(pq);
}