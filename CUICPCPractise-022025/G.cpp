#include <iostream>
#include <cmath>

double numbers[100000];
int main()
{
    int n;
    std::cin >> n;

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
        total += numbers[i] >= 0 ? (int)ceil(numbers[i]): (int)floor(numbers[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (ceil(numbers[i]) == floor(numbers[i]))
            printf("%d\n", (int)numbers[i]);
        else if (total == 0)
            printf("%d\n", numbers[i] >= 0 ? (int)ceil(numbers[i]): (int)floor(numbers[i]));
        else if (total > 0)
        {
            if (numbers[i] > 0)
            {
                printf("%d\n", (int)floor(numbers[i]));
                total--;
            }
            else
                printf("%d\n", (int)floor(numbers[i]));
        }
        else if (total < 0)
        {
            if (numbers[i] > 0)
                printf("%d\n", (int)ceil(numbers[i]));
            else
            {
                printf("%d\n", (int)ceil(numbers[i]));
                total++;
            }
        }
    }


}
