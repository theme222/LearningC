#include <bits/stdc++.h>

int main()
{
    int N, M;
    std::cin >> N >> M;
    
    int count = 0;
    for (int i = 0; i < N ; i++)
    {
        int j = i;
        while (j > M)
        {
            j = (j-1)/2;
        }
        if (j == M) continue;
        else count++;
    }
    std::cout << count << '\n';
    
    if (count == 0) return 0;
    
    for (int i = 0; i < N ; i++)
    {
        int j = i;
        while (j > M)
        {
            j = (j-1)/2;
        }
        if (j == M) continue;
        else
        {
            if (j != 0) std::cout << ' ';
            std::cout << i;
        }
    
    }
}