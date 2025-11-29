#include <iostream>
#include <algorithm>

int degs[5005];

int main()
{
    std::ios_base::sync_with_stdio(0.); std::cin.tie(std::nullptr_t());
    
    int n;
    std::cin >> n;
    
    int max = -1;
    for (int i = 0; i < n ; i++)
    {
        int total = 0;
        for (int j = 0; j < n ; j++)
        {
            int num;
            std::cin >> num;
            total += num;
        }
        degs[total] += 1;
        max = std::max(max, total);
    }
    
    // output
    for (int i = 0; i <= max; i++)
    {
        if (i != 0) std::cout << ' ';
        std::cout << degs[i];
    }
    std::cout << '\n';
    
}

