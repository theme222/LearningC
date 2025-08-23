#include <iostream>

int rainColumn[60];
int main()
{
    int columnCount;
    std::cin >> columnCount;

    int maxRow = -1;
    for (int i = 0; i < columnCount; i++)
    {
        std::cin >> rainColumn[i];
        maxRow = std::max(rainColumn[i], maxRow);
    }

    int totalWater = 0;

    for (int row = 0; row < maxRow; row++)
    {
        bool isWalled = false;
        int currentWater = 0;
        for (int col = 0; col < columnCount; col++)
        {
            if (rainColumn[col] > row)
            {
                isWalled = true;
                totalWater += currentWater;
                currentWater = 0;
            }
            if (isWalled && rainColumn[col] <= row)
                currentWater++;
        }
        // We ignore the currentwater here because it means it isn't walled off
    }

    std::cout << totalWater << std::endl;
}
