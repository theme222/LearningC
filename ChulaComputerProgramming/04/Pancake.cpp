#include <iostream>

int pancakeArr[10000];

int FindMaxIndex(int end)
{
    int maxIndex = 0;
    for (int i = 1; i < end; i++)
        if (pancakeArr[maxIndex] < pancakeArr[i])
            maxIndex = i;
    return maxIndex;
}

void Reverse(int start, int end)
{
    int* startptr = pancakeArr + start;
    int* endptr = pancakeArr + end;

    while (startptr < endptr)
    {
        int temp = *startptr;
        *startptr = *endptr;
        *endptr = temp;
        startptr++;
        endptr--;
    }
}

void PrintArr(int size)
{
    printf("%d", pancakeArr[0]);
    for (int i = 1; i < size; i++)
        printf(" %d", pancakeArr[i]);
    puts("");
}

int main()
{
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++)
        std::cin >> pancakeArr[i];

    PrintArr(size);
    int end = size;
    while (end > 0)
    {
        int maxIndex = FindMaxIndex(end);
        if (maxIndex == end - 1) { }
        else
        {
            if (maxIndex != 0)
            {
                Reverse(0, maxIndex);
                PrintArr(size);
            }
            Reverse(0, end-1);
            PrintArr(size);
        }

        end--;
    }
}
