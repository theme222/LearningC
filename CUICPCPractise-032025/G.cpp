#include <iostream>
#include <stdexcept>
#include <vector>

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        std::vector<int> currentWeights(n+1,0);

        for (int i =0; i < n; i++)
        {
            int w;
            scanf("%d",&w);
            currentWeights[w]++;
        }

        if (n <= 3)
        {
            printf("%d\n",n/2);
            continue;
        }

        int bestGroupCount = 0;
        for (int targetSize = 2; targetSize <= 2*n; targetSize++)
        {
            int start, end;
            if (targetSize > n)
            {
                start = targetSize - n;
                end = n;
            }
            else
            {
                start = 1;
                end = targetSize - 1;
            }

            int currentGroupCount = 0;
            while (start <= end)
            {
                if (start == end) currentGroupCount += currentWeights[start]/2;
                else currentGroupCount += std::min(currentWeights[start], currentWeights[end]);
                start++;
                end--;
            }
            if (currentGroupCount > bestGroupCount) bestGroupCount = currentGroupCount;
        }
        printf("%d\n", bestGroupCount);
    }
}
