#include <stdlib.h>
#include <stdint.h>

int numRollsToTarget(int n, int k, int target) {
    // Initialize 2d array
    uint64_t **dp = calloc(sizeof(uint64_t*), n+1);
    for (int i = 0; i <= n; i++)
        dp[i] = calloc(sizeof(uint64_t), target+1);
    // Initialize 2d array

    for (int i = 1; i <= target; i++)
        if (i <= k) dp[1][i] = 1;

    for (int i = 2; i <= n ; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            for (int l = j-1; l >= j-k && l > 0; l--)
            {
                dp[i][j] += dp[i-1][l];
                dp[i][j] = dp[i][j] % 1000000007;
            }
        }
    }

    int total = dp[n][target];
    for (int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);

    return total;
}
