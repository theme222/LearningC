#include <iostream>

typedef long long ll;

ll GetMagnitude(ll a)
{
    ll mag = 0;
    do
    {
        a /= 10;
        mag++;
    } while (a);
    return mag;
}

ll CustomPow(ll a, ll n)
{
    ll res = 1;
    while (n--)
        res *= a;
    return res;
}

int main()
{
    ll a,b;
    std::cin >> a >> b;

    ll totalLength = 0;
    while (true)
    {
        ll magA = GetMagnitude(a);
        ll magB = GetMagnitude(b);

        if (magA < magB)
        {
            ll goal = CustomPow(10, magA)-1;
            totalLength += ((goal - a) + 1) * magA;
            a = goal + 1;
        }
        else
        {
            totalLength += (b - a + 1) * magB;
            break;
        }
    }
    std::cout << totalLength << std::endl;
}
