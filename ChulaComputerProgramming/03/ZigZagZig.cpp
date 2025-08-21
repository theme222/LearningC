#include <iostream>

int main()
{
    int minA = 1e9, maxA = -1e9, minB = 1e9, maxB = -1e9;
    bool isA = true;
    bool mode;


    int currNum = 0;
    int count = 0;
    while (std::cin >> currNum)
    {
        if (currNum == -998)
        {
            mode = true;
            break;
        }
        else if (currNum == -999)
        {
            mode = false;
            break;
        }

        if (isA)
        {
            maxA = std::max(maxA, currNum);
            minA = std::min(minA, currNum);
        }
        else
        {
            maxB = std::max(maxB, currNum);
            minB = std::min(minB, currNum);
        }

        if (count % 2 == 0) isA = !isA;
        count++;
    }

    if (mode) // A min B max
    {
        std::cout << minA << ' ' << maxB << '\n';
    }
    else // B min A max
    {
        std::cout << minB << ' ' << maxA << '\n';
    }
}
