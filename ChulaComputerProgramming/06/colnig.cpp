#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

main()
{
    std::vector<int> vec;
    int n;
    std::cin >> n;
    while (n != 1)
    {
        vec.push_back(n);
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
    }

    vec.push_back(n);
    int startIndex = std::clamp((long)vec.size()-15, 0l, 99999999l);
    std::cout << vec[startIndex++];
    for (int i = startIndex; i < vec.size(); i++)
    {
        std::cout << "->"<<vec[i];
    }
}
