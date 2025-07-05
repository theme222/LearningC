#include <iostream>
#include <cstdint>

namespace Const
{
    const double e = 2.71828182;
    const double pi = 3.1415926;
}


typedef long long ll;
ll mod_pow(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    uint64_t testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        uint64_t N,x,y,k,p;
        std::cin >> N >> x >> y >> k >> p;


        for (int i = 0; i < N; i++)
        {

        }

    }
}