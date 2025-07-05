#include <iostream>


int main()
{
    int asdf[1000];
    int max = -100000000;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = i; j < 1000; j++)
        {
            if (asdf[j] + asdf[i] > max) max = asdf[j] + asdf[i];
        }
    }
    std::cout << max << std::endl;
}
