#include <iostream>
#include <vector>
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
    std::vector<ll> numbers;
    std::cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        int in;
        std::cin >> in;
        numbers.push_back(in);
    }

    std::sort(numbers.begin(), numbers.end());

    bool isFirst = true;
    for (int i = 0; i < m; i++)
    {
        ll input;
        std::cin >> input;
        if (!isFirst) std::cout << " ";

        ll min = input - k;
        ll max = input + k;

        std::vector<ll>::iterator minIter = std::lower_bound(numbers.begin(), numbers.end(), min);
        std::vector<ll>::iterator maxIter = std::upper_bound(numbers.begin(), numbers.end(), max);

        std::cout << maxIter - minIter;
        isFirst = false;
    }

}
