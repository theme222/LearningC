#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct functionInput
{
    int *ptr;
    int size;
} funcin;

funcin* QuickSort(funcin *Array)
{
    int *arr = Array->ptr;
    int size = Array->size;
    if (size <= 1) 
    {
        int *newArr = (int *)malloc(sizeof(int) * size);
        if (size == 1) newArr[0] = arr[0];
        funcin *returnArr = (funcin*)malloc(sizeof(funcin));
        returnArr->size = size;
        returnArr->ptr = newArr;
        return returnArr;
    }

    int *lessArr, *moreArr;
    int moreCount = 0, lessCount= 0;
    lessArr = (int*)malloc((size) * sizeof(int));
    moreArr = (int*)malloc((size) * sizeof(int));
    int pivot = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] <= pivot)
        {
            lessArr[lessCount++] = arr[i];
        }
        else
        {
            moreArr[moreCount++] = arr[i];
        }
    }

    funcin *less = (funcin*)malloc(sizeof(funcin));
    funcin *more = (funcin*)malloc(sizeof(funcin));
    funcin *returnArr = (funcin*)malloc(sizeof(funcin));

    less->ptr = lessArr;
    less->size = lessCount;
    more->ptr = moreArr;
    more->size = moreCount;
    returnArr->size = lessCount + moreCount + 1;
    returnArr->ptr = (int*)malloc(sizeof(int) * size);

    funcin *srtLess = QuickSort(less);
    funcin *srtMore = QuickSort(more);

    memcpy(returnArr->ptr, srtLess->ptr, lessCount * sizeof(int));
    returnArr->ptr[lessCount] = pivot;
    memcpy(returnArr->ptr + lessCount + 1, srtMore->ptr, moreCount * sizeof(int));

    free(less->ptr);free(more->ptr);free(less);free(more);free(srtLess->ptr);free(srtLess);free(srtMore->ptr);free(srtMore);
    return returnArr;
}

int mainArray[1000];
int mainCount;

int main()
{
    while (1)
    {
        char str[100];
        scanf("%s",str);
        if (strcmp(str,"end") == 0) break;
        // append to main array
        mainArray[mainCount++] = atoi(str);
    }

    funcin *mainArr = (funcin *)malloc(sizeof(funcin));

    mainArr->ptr = (int*)malloc(mainCount * sizeof(int));
    memcpy(mainArr->ptr, mainArray, mainCount * sizeof(int));
    mainArr->size = mainCount;

    funcin *final = QuickSort(mainArr);

    for (int i = 0; i < final->size; i++)
    {
        printf("%d ", final->ptr[i]);
    }
    puts("\n");
    free(mainArr->ptr);
    free(mainArr);
    free(final->ptr);
    free(final);
    return 0;
}
