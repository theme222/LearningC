#include <iostream>
#include <cmath>
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    ll num;
    std::string notrepeat, repeat;
    std::cin >> num >> notrepeat >> repeat;


    ll divisor = 0, top = 0;
    ll magRep = repeat.size();
    while (magRep--)
    {
        divisor *= 10;
        divisor += 9;
    }

    top += (std::stoll(notrepeat) * divisor) + (std::stoll(repeat));
    divisor *= pow(10, notrepeat.size());
    top += num * divisor;
    ll change = gcd(top, divisor);
    top /= change;
    divisor /= change;
    std::cout << top << " / " << divisor << std::endl;
}
