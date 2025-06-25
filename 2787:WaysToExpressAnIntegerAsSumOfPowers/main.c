#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int numberOfWays(int n, int x) {
    uint64_t fuck[301];
    for (int i = 0; i < 301; i++)
        fuck[i] = 0;
    fuck[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        uint64_t power = pow(i, x);
        for (int j = n; j >= power; j--)
            fuck[j] += fuck[j-power] % 1000000007;
    }
    return fuck[n] % 1000000007;
}
