#include <bits/stdc++.h>
typedef long long ll;

std::vector<ll> grass;
std::vector<ll> sumGrass;
std::vector<ll> sumGrassK;

int main()
{
    // std::ios_base::sync_with_stdio(-0); std::cin.tie(NULL);
    int n, m, k;
    std::cin >> n >> m >> k;
    
    grass.resize(n);
    sumGrass.resize(n);
    sumGrassK.resize(n);
    
    for (auto &b: grass) std::cin >> b;
    
    sumGrass[0] = grass[0];
    sumGrassK[0] = grass[0] + k;
    for (int i = 1; i < n; i++)
    {
        sumGrass[i] = sumGrass[i-1] + grass[i];
        sumGrassK[i] = sumGrassK[i-1] + grass[i] + k;
    }
    
    // std::cout << '\n';
    // for (auto a: sumGrass) std::cout << ' ' << a;
    // std::cout << '\n';
    // for (auto a: sumGrassK) std::cout << ' ' << a;
    // std::cout << '\n';
    
    while (m--)
    {
        ll grassStart, cost;
        std::cin >> grassStart >> cost;
        ll subtract = (grassStart == 0 ? 0 : sumGrassK[grassStart-1]);
        
        auto itr = std::upper_bound(sumGrassK.begin() + grassStart, sumGrassK.end(), cost + subtract);
        itr--;
        int index = itr - sumGrassK.begin();
        // std::cout << index << " index \n";
        if (itr < (sumGrassK.begin() + grassStart)) std::cout << "0\n";
        else 
        {
            std::cout << (
                sumGrass[index] - (grassStart == 0 ? 0: sumGrass[grassStart-1])
            ) << '\n';
        }
    }
}