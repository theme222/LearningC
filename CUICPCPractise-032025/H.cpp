#include <iostream>

char feild[501][501];
int dp[501][501];
int runningSum[505][505];

int main()
{
    int height, width;
    scanf("%d %d", &height, &width);
    for (int i = 1; i <= height; i++)
        scanf("%s", feild[i]+1);

    for (int h = 1; h <= height; h++)
    {
        for (int w = 1; w <= width; w++)
        {
            if (feild[h][w] == '#') continue;
            int total = 0;
            // check right
            if (feild[h][w+1] == '.')
                total++;

            // check down
            if (feild[h+1][w] == '.')
                total++;

            dp[h][w] = total;
        }
    }

    for (int h = height; h >= 1; h--)
        for (int w = width; w >= 1; w--)
            runningSum[h][w] = dp[h][w] + runningSum[h][w+1];

    // for (int i = 1; i <= height; i++)
    // {
    //     for (int j = 1; j <= width; j++)
    //     {
    //         printf("%c", feild[i][j]);
    //     }
    //     puts("");
    // }

    // for (int i = 1; i <= height; i++)
    // {
    //     for (int j = 1; j <= width; j++)
    //     {
    //         printf("%d", dp[i][j]);
    //     }
    //     puts("");
    // }


    int queries;
    scanf("%d", &queries);
    while (queries--)
    {
        int r1,c1,r2,c2;
        scanf("%d %d %d %d", &r1,&c1,&r2,&c2);

        int sumTotal = 0;
        for (int i = r1; i <= r2; i++)
            sumTotal += runningSum[i][c1] - runningSum[i][c2+1];

        // right side
        for (int i = r1; i <= r2; i++)
            if (feild[i][c2] == '.' && feild[i][c2+1] == '.' ) sumTotal--;

        // bottom side
        for (int i = c1; i <= c2; i++)
            if (feild[r2][i] == '.' && feild[r2+1][i] == '.') sumTotal--;

        printf("%d\n", sumTotal);
    }

}
