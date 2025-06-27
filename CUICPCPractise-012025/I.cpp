#include <iostream>
#include <cmath>
#include <cstdint>
#include <vector>


uint32_t values[150000][20];
int main()
{
    int n, m;
    std::cin >> n >> m;

    int totalNums = 1 << n; // 2 ^ n

    for (int i = 0; i < totalNums; i++)
        scanf("%u", values[i]);


    bool isOrringLol = true;
    for (int i = 1; i <= n; i++)
    {
        int level = 1 << i;
        for (int j = 0; j < totalNums; j += level)
        {
            if (isOrringLol) values[j][i] = values[j][i-1] | values[j + (level>>1)][i-1];
            else values[j][i] = values[j][i-1] ^ values[j + (level>>1)][i-1];
        }
        isOrringLol = !isOrringLol;
    }


    while (m--)
    {
        uint32_t pos, change;
        scanf("%u %u", &pos, &change);

        pos--;
        values[pos][0] = change;

        bool isOrringLol = true;
        for (int i = 1; i <= n; i++)
        {
            int level = 1<<i;
            int posA = (pos / level) * level;
            int posB = posA + (level >> 1);

            if (isOrringLol) values[posA][i] = values[posA][i-1] | values[posB][i-1];
            else values[posA][i] = values[posA][i-1] ^ values[posB][i-1];
            printf("Doing %d %d getting %d",  values[posA][i-1] , values[posB][i-1], values[posA][i]);
            pos = posA;
            isOrringLol = ! isOrringLol;
        }

        printf("%u\n", values[0][n]);

        for (int j = 0; j <= n; j++)
        {
            for (int i = 0; i < totalNums; i++)
                printf("%d ", values[i][j]);
            puts("");
        }
    }
}
