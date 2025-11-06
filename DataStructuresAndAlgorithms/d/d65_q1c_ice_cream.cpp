#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll, ll> llpair;

ll sumMoney[100002];
std::vector<llpair> changeDays; // day money

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    ll n, m, start;
    std::cin >> n >> m >> start;
    
    while (n--)
    {
        ll day, money;
        std::cin >> day >> money;
        changeDays.push_back({day, money});
    }
    
    std::sort(changeDays.begin(), changeDays.end());
    
    int currentChangeIndex = 0;
    int currentIncome = start;
    sumMoney[0] = start;
    for (int i = 1; i <= 100000; i++)
    {
        if (currentChangeIndex < changeDays.size() && i == changeDays[currentChangeIndex].first) 
        {
            currentIncome = changeDays[currentChangeIndex].second;
            currentChangeIndex++;
        }
        sumMoney[i] = sumMoney[i-1] + currentIncome;
    }
    
    bool isFirst = true;
    while (m--)
    {
        if (!isFirst) std::cout << ' ';
        ll icecream, dayOfScam;
        std::cin >> icecream >> dayOfScam;
        
        auto buyBefore = std::lower_bound(sumMoney, sumMoney+dayOfScam+1, icecream);
        if (buyBefore == sumMoney+dayOfScam+1) // scam before
        {
            ll newPrice = icecream + *(sumMoney+dayOfScam);
            auto buyAfter = std::lower_bound(sumMoney+dayOfScam+1, sumMoney+100001, newPrice);
            std::cout << buyAfter - sumMoney;
        }
        else
            std::cout << buyBefore - sumMoney;
        isFirst = false;
    }
}