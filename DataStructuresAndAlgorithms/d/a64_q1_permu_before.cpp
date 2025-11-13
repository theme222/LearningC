#include <bits/stdc++.h>

int n, m;

void permute(int length, std::vector<int>& vec, std::vector<bool> &used)
{
    if (length == n) // print that boi
    {
        bool isFirst = true;
        for (auto a: vec)
        {
            std::cout << a;
            if (isFirst) std::cout << ' ';
            isFirst = false;
        }
        std::cout << '\n';
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            if (used[i]) continue;
            used[i] = true;
            vec[length] = i;
            permute(length+1, vec, used);
            vec[length] = -1;
            used[i] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    std::cin >> n >> m;
    
    while (m--)
    {
        
    }
    
    std::vector<int> vec(n, -1);
    std::vector<bool> used(n);
    
    permute(0, vec, used);
}