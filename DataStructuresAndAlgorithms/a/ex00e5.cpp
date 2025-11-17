#include <bits/stdc++.h>

int n, k;

void combi(int length, int consec, std::vector<int> &vec, bool isGood)
{
    // if (k - consec > n - length) return;
    if (consec == k) isGood = true;
    
    if (length == n)
    {
        if (isGood)
        {
            for (auto a: vec)
                std::cout << a;
            std::cout << '\n';
        }
    }
    else 
    {
        // Choose 0
        vec[length] = 0;
        combi(length+1, 0, vec, isGood);
        
        // Choose 1
        vec[length] = 1;
        combi(length+1, consec+1, vec, isGood);
    }
    
}

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    
    std::cin >> n >> k;
    std::vector<int> vec(n);
    combi(0, 0, vec, false);
}