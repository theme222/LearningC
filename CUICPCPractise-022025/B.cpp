#include <iostream>
#include <cmath>
#include <cstdint>


int main()
{
    uint32_t players[1001];
    uint32_t fedor;

    int n, m, k;
    std::cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
        scanf("%u", players+i);

    scanf("%u", &fedor);

    int friends = 0;
    for (int i = 0; i < m; i++)
    {
        int count = 0;
        players[i] ^= fedor;
        for (int j = 0; j < 32; j++)
            if (players[i] & 1<<j) count++;
        if (count <= k) friends++;
    }
    printf("%d\n", friends);
}
