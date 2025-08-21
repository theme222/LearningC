#include <iostream>

int main()
{
    float p;
    std::cin >> p;
    float k = 1, t =1;
    while (true)
    {
        t = (t * (365-(k-1)))/365;
        if (1-t >= p) break;
        else k++;
    }
    std::cout << k << std::endl;
}
