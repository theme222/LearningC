#include <iostream>
#include <map>
typedef long long ll;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::map<ll, ll> connect;
    ll N, M;
    std::cin >> N >> M;
    
    while (N--)
    {
        ll father, son;
        std::cin >> father >> son;
        connect[son] = father; // does the son have multiple father?
    }
    
    while (M--)
    {
        ll checkA, checkB;
        std::cin >> checkA >> checkB;
        
        ll aGrand = -1, bGrand = -2;
        if (connect.count(checkA) == 1)
            if (connect.count(connect[checkA]) == 1)
                aGrand = connect[connect[checkA]];
        
        if (connect.count(checkB) == 1)
            if (connect.count(connect[checkB]) == 1)
                bGrand = connect[connect[checkB]];
        
        std::cout << (aGrand == bGrand && checkA != checkB ? "YES": "NO") << '\n';
    }
}