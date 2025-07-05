#include <iostream>

int absurd[200000];
int runningCount[200000];
int main()
{
    int n, k;
    std::cin >> n >> k;

    for (int i = 0; i < n; i++)
        scanf("%d", absurd+i);

    // set runningCount 0
    for (int i = 0; i < k-1; i++)
        runningCount[0] += absurd[i];

    // Set other running count
    for (int i = 1; i < n-(k-1); i++)
        runningCount[i] = runningCount[i-1] - absurd[i-1] + absurd[i+k-1];

    // Yea i don't fuckin know how


}
