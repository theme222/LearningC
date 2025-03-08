#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arrLength;
int main()
{
    // Read from stdin
    scanf("%d", &arrLength);

    int* arr = calloc(arrLength, sizeof(int));
    for (int i = 0; i < arrLength; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Insertion sort
    for (int i = 0; i < arrLength; i++)
    {
        if (i == 0) continue;
        int currentValue = arr[i];
        for (int j = i-1; j >= 0; j--)
        {
            if (currentValue < arr[j])
            {
                arr[j+1] = arr[j];
                if (j == 0) arr[0] = currentValue;
            }
            else 
            {
                arr[j+1] = currentValue;
                break;
            }
        }
    }

    // Output
    puts("\n");
    for (int i =0; i< arrLength; i++)
    {
        printf("%d\n", arr[i]);
    }

    free(arr);
}


