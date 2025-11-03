#include <iostream>
#include <set>
#include <algorithm>
typedef long long ll;

int findCenter(int l, int r)
{
    return (l + r) / 2;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    ll n,m,k;
    std::set<ll> numbers;
    std::cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++)
    {
        int in;
        std::cin >> in;
        numbers.insert(in);
    }
    
    bool isFirst = true;
    for (int i = 0; i < m; i++)
    {
        ll input;
        std::cin >> input;
        if (!isFirst) std::cout << " ";
        
        ll min = input - k;
        ll max = input + k;
        
        auto minIter = numbers.lower_bound(min);
        auto maxIter = numbers.upper_bound(max);
        
        std::cout << << '\n';
        isFirst = false;
    }
    
}