#include <iostream>

int tiles[999];
int main()
{
    int size;
    std::cin >> size;

    int currIndex = 0;
    int rowZero;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> tiles[currIndex];
            if (tiles[currIndex] == 0)
            {
                rowZero = i;
                currIndex--;
            }
            currIndex++;
        }
    }

    // for (int i = 0; i < size*size-1; i++)
    //     std::cout << tiles[i] << ' ';
    //
    // puts("");

    int inversionCount = 0;
    for (int i = 0; i < size*size-1; i++)
        for (int j = i+1; j < size*size-1; j++)
            if (tiles[i] > tiles[j])
                inversionCount++;
                // printf("%d %d\n", tiles[i], tiles[j]);

    // printf("inversion: %d, row zero: %d, size: %d", inversionCount, rowZero, size);

    if (size % 2 == 1 && inversionCount % 2 == 0) puts("YES");
    else if (size % 2 == 0)
    {
        if (inversionCount % 2 == 1 && rowZero % 2 == 0)
            puts("YES");
        else if (inversionCount % 2 == 0 && rowZero % 2 == 1)
            puts("YES");
        else puts("NO");
    }
    else puts("NO");
}
