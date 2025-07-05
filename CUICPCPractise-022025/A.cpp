#include <iostream>
#include <cmath>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        k = k * ceil((double)n / k);
        int val = ceil((double)k / n);
        printf("%d\n", val);
    }
}
