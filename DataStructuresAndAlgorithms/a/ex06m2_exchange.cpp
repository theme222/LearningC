#include <bits/stdc++.h>

typedef std::vector<std::vector<float>> vector2d;

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int N;
        std::cin >> N;
        
        vector2d dist(N, std::vector<float>(N));
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                float val;
                std::cin >> val;
                dist[i][j] = val;
            }
        }
        
        // floyd may whethershall
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (dist[i][j] < dist[i][k] * dist[k][j])
                        dist[i][j] = dist[i][k] * dist[k][j];
        
        bool isOk = true;
        for (int a = 0; a < N; a++)
            if (dist[a][a] > 1) isOk = false;
        
        // std::cout << '\n';
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < N; j++)
        //     {
        //         std::cout << ' ' << dist[i][j];
        //     }
        //     std::cout << '\n';
        // }
        std::cout << (isOk ? "NO\n": "YES\n");
    }
}