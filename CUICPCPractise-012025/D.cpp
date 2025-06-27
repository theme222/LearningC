#include <algorithm>
#include <iostream>
#include <cmath>

int dp[4000];
int main()
{
    int n,a,b,c;
    std::cin >> n >> a >> b >> c;

    for (int i = 1; i <= n; i++)
    {
        int max = -1e6;
        if (i - a >= 0 && dp[i-a] + 1> max)
        {
            max = dp[i-a] + 1;
        }
        if (i - b >= 0 && dp[i-b] + 1 > max)
        {
            max = dp[i-b] + 1;
        }
        if (i - c >= 0 && dp[i-c] + 1 > max)
        {
            max = dp[i-c] + 1;
        }

        dp[i] = max;
    }

    printf("%d\n", dp[n]);
}
