#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    ll n;
    const ll KKK = 1e8 + 7;
    
    std::cin >> n;
    ll typeA = 1; // 00 -> A, B, C
    ll typeB = 1; // 01 -> A, C
    ll typeC = 1; // 10 -> A, B
    
    while (--n)
    {
        ll newA, newB, newC;
        newA = (typeA + typeB + typeC) % KKK;
        newB = (typeA + typeC) % KKK;
        newC = (typeA + typeB) % KKK;
        
        typeA = newA;
        typeB = newB;
        typeC = newC;
    }
    
    std::cout << (typeA + typeB + typeC) % KKK << '\n';
}