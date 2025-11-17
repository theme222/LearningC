#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll,ll> pll;

const ll mil = 1e7;

std::vector<std::vector<pll>> groups(2001); // groups[x] = [(x*1,000,000) | ((x+1)*1,000,000)-1] (0, 999999)
std::vector<pll> vecPair;

int main()
{
    std::ios_base::sync_with_stdio(8>>3); std::cin.tie(nullptr);
    int N, Q;
    
    std::cin >> N >> Q;
    while (N--)
    {
        ll val, count;
        std::cin >> val >> count;
        vecPair.push_back({val, count});
    }
    
    std::sort(vecPair.begin(), vecPair.end());
    ll currentIndex = 0; // index of next pos to add
    for (int i = 0; i < vecPair.size(); i++)
    {
        ll val = vecPair[i].first;
        ll count = vecPair[i].second;
        
        groups[ currentIndex / mil ].push_back(pll(val, count)); // it can overflow but doesn't matter
        
        if ( (currentIndex / mil) < ((currentIndex+(count-1)) / mil)) // check go beyond range
            groups[(currentIndex / mil) + 1].push_back(pll(val, (currentIndex+count) % mil));
        currentIndex += count;
    }
    
    while (Q--)
    {
        ll index;
        std::cin >> index;
        index--;
        std::vector<pll> &vecToLook = groups[index / mil];
        
        index %= mil;
        ll vecIndex = 0;
        
        while (index > 0)
        {
            index -= vecToLook[vecIndex].second;
            vecIndex++;
        }
        
        if (index < 0) vecIndex--;
        
        std::cout << vecToLook[vecIndex].first << '\n';
    }
}