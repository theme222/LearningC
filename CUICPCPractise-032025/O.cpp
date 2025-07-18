#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

typedef long long ll;
typedef std::pair<ll,int> ipair;

bool sortByCount(const ipair& a, const ipair& b)
{
    return a.second > b.second;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);

        std::map<ll, int> count;
        ll num;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &num);
            count[num]++;
        }

        std::vector<ipair> increasingList;
        increasingList.reserve(n);
        for (auto m: count)
            increasingList.push_back(m);

        std::sort(increasingList.begin(), increasingList.end(), sortByCount);
        for (int i = 0; i < increasingList.size(); i++)
        {
            int& total = increasingList[i].second;
            int delCount = 0;
            int delSize = ceil((double)total / (double)(increasingList.size()-1));
            for (int j = increasingList.size()-1; j > i; j--)
            {
                int delAmount = std::clamp(delSize, 0, std::min(total, increasingList[j].second));
                increasingList[j].second -= delAmount;
                total -= delAmount;
                if (increasingList[j].second == 0) delCount++;
                if (total <= 0) break;
            }
            while (delCount--) increasingList.pop_back();
        }

        int sum = 0;
        for (auto a: increasingList)
            sum += a.second;
        printf("%d\n",sum);
    }

}
