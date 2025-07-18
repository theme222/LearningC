#include <iostream>
#include <cmath>
#include <string>
typedef long long ll;

ll Fac(ll n)
{
    ll res = 1;
    while (n--)
        res *= n+1;
    return res;
}

ll Cnr(ll n, ll r)
{
    if (n < r) exit(1);
    if (r < 0) return 0;
    if (n == r) return 1;
    return Fac(n) / (Fac(n-r) * Fac(r));
}

ll FindClassy(std::string str, ll maxSize) // str is max
{
    if (maxSize == 0) return 1;
    ll size = str.size();
    if (size <= maxSize) return std::stoll(str)+1;

    // Digits up to last assuming last is non zero
    ll comboespre = 0;
    ll comboeslastiszero = 0;
    for (ll currentMax = maxSize; currentMax >= 0; currentMax--)
    {
        comboespre += Cnr(size-1, currentMax-1) * pow(9, currentMax-1) * (str[0] - '0' - 1);
        comboeslastiszero += Cnr(size-1, currentMax) * pow(9, currentMax);
    }

    // Find next non zero digit
    ll nextResult = 1;
    for (int i = 1; i < size; i++)
    {
        if (str[i] != '0')
        {
            nextResult = FindClassy(str.substr(i), maxSize-1);
            break;
        }
    }
    return comboespre + comboeslastiszero + nextResult;
}

ll FindClassyPre(std::string str)
{
    ll thing = std::stoll(str);
    if (thing <= 999) return thing+1;
    return FindClassy(str, 3);
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        std::string min, max;
        ll minnum, maxnum;
        std::cin >> min >> max;
        minnum = std::stoll(min);
        minnum--;
        std::cout << FindClassyPre(max) - FindClassyPre(std::to_string(minnum)) << std::endl;
    }
}
