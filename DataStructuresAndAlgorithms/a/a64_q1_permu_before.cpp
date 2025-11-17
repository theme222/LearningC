#include <bits/stdc++.h>

int n, m;
std::map<int, int> constraint;

void permute(int length, std::vector<int>& vec, std::vector<bool> &used)
{
    if (length == n) // print that boi
    {
        bool isFirst = true;
        for (auto a: vec)
        {
            if (!isFirst) std::cout << ' ';
            std::cout << a;
            isFirst = false;
        }
        std::cout << '\n';
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            if (used[i]) continue;
            if (constraint.count(i) && !used[constraint[i]]) continue;
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
        int before, after;
        std::cin >> before >> after;
        constraint[after] = before;
    }
    
    std::vector<int> vec(n, -1);
    std::vector<bool> used(n);
    
    permute(0, vec, used);
}