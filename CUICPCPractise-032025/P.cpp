#include <iostream>
#include <cmath>

typedef long long ll;

ll thing(ll n)
{
    if (n == 0) return 0;
    return (n*n) - n + 1;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while (t--)
    {
        ll n, l, r;
        scanf("%lld %lld %lld", &n, &l, &r);
        // n^2 - n + 1
        ll startNum = -1;
        for (int i = 1; i <= n+1; i++)
        {
            if (thing(i-1) < l && l <= thing(i))
            {
                startNum = i;
                break;
            }
        }

        if (startNum == -1) exit(1);
        ll currentNum = startNum;
        ll currentIndex = thing(currentNum-1)+1;
        ll count = 2 + ((l-currentIndex)/2);
        bool printNum = true && ((l-currentIndex) % 2 == 0);
        // std::cout << currentNum << " " << currentIndex << " " << count << std::endl;
        // std::cout << printNum << " asdfjklasdfjklasdfjkljklsdfjklfjklsd\n";
        currentIndex = l;
        do {
            // printf("||%lld||", currentIndex);
            if (currentIndex == 1)
            {
                printf("1 ");
                currentNum++;
                count = 2;
                continue;
            }
            if (currentIndex > r) break;
            if (count > currentNum)
            {
                currentNum++;
                count = 2;
            }
            if (printNum)
                printf("%lld ", currentNum);
            else if (count == currentNum)
                printf("1 ");
            else
                printf("%lld ", count);
            if (!printNum) count++;
            printNum = !printNum;
        } while (currentIndex++);
        puts("");
    }
}
