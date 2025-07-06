#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

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

ll nCr(ll n, ll r, ll mod){
    // code here
    if (r > n){
        return 0;
    }

    ll numerator = 1;
    ll denominator = 1;

    for (int i = 0; i < r; i++){
        numerator = (numerator * (n - i)) % mod;
        denominator = (denominator * (i + 1)) % mod;
    }

    // Calculate modular inverse of denominator
    ll inverse = 1;
    ll base = denominator;
    ll power = mod - 2;
    while (power > 0){
        if (power & 1){
            inverse = (inverse * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }

    // Calculate nCr modulo mod
    ll result = (numerator * inverse) % mod;
    return result;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        ll N,x,y,k,p, total = 0;
        std::cin >> N >> x >> y >> k >> p;

        std::vector<ll> cache(N,-1);

        ll innerTotal = 0;
        for (int i = 1; i <= N; i++)
        {
            ll innerinnertotal = 0;
            for (int j = 1; j <= i; j++)
            {
                innerinnertotal += (((x%k + (2*x%k*y%k)%k)%k)*j%k)%k;
                innerinnertotal += (mod_pow(k,i-j,k) * mod_pow(x,i-j,k) * mod_pow(y,i-j,k)) % k;
                innerinnertotal += (y%k * j%k) %k;
                if (p != 0) innerinnertotal += (((i + j) % 2 == 0 ? 1%k : -1%k) * nCr(i, j, k) * ((j * j)%k)) % k;
            }
            innerTotal += innerinnertotal + (i%k * i%k * i%k)%k;
        }
        std::cout << innerTotal % k << '\n';
    }
}
