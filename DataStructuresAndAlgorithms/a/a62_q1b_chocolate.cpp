#include <iostream>
#include <vector>

typedef long long ll;

ll chocolateEatingDiary[69696];
const ll sneakyMod = 1000003;

int main()
{
    chocolateEatingDiary[0] = 1;
    ll n, k;
    std::cin >> n >> k;
    
    std::vector<ll> eatingTypes(k);
    for (auto &a: eatingTypes) std::cin >> a;
    
    for (ll i = 1; i <= n; i++)
    {
        int total = 0;
        for (ll size: eatingTypes)
        {
            if (i < size) continue;
            total += chocolateEatingDiary[i-size];
        }
        chocolateEatingDiary[i] = total % sneakyMod;
    }
    
    std::cout << chocolateEatingDiary[n] << '\n';
}