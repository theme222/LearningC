#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
#define UPPERLIMITOFB 1000

uint64_t x;
int n, d;
int a[100000], b[100000];
int aToIndex[100001]; // bucket sort or something idk
int bbbbbbbb[100001];
int bIncrement = 0;

void swap(int &pos1, int &pos2)
{
    int temp = pos1;
    pos1 = pos2;
    pos2 = temp;
}

uint64_t getNextX() { // this is a hash function bruh
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        if (i < d) b[i] = 1;
    }

    for(int i = 0; i < n; i++)
        swap(a[i], a[getNextX() % (i + 1)]);
    for(int i = 0; i < n; i++)
        swap(b[i], b[getNextX() % (i + 1)]);
}

int DumbFourierier(int i)
{
    int max = 0;
    for (int j = 0; j <= n; j++)
        if (b[i-j] && a[j] > max) max = a[j];
    return max;
}

int DumberFouriererer(int i)
{
    int max = 0;
    for (int j = n; j >= 0; j--)
    {
        int index = aToIndex[j];
        if (i >= index && b[i - index] == 1)
        {
            max = j;
            break;
        }
    }
    return max;
}

int DumbestFourierueiurier(int i)
{
    int max = 0;
    for (int j = 0; j < bIncrement; j++)
    {
        if (bbbbbbbb[j] > i) break;
        int aIndex = i - bbbbbbbb[j];
        if (max < a[aIndex]) max = a[aIndex];
    }
    return max;
}

int main()
{
    std::cin >> n >> d >> x;
    initAB();
    for (int i = 0; i < n; i++)
    {
        aToIndex[a[i]] = i;
        if (b[i])
        {
            bbbbbbbb[bIncrement] = i;
            bIncrement++;
        }
    }

    for (int i =0 ; i < n; i++)
        printf("%d ", a[i]);
    puts("");
    for (int i =0 ; i < n; i++)
        printf("%d ", b[i]);
    puts("");
    for (int i =0 ; i < n; i++)
        printf("%d ", bbbbbbbb[i]);
    puts("");


    if (d > UPPERLIMITOFB)
    {
        for (int i = 0; i < n && i < 320; i++)
            printf("%d\n", DumbFourierier(i));
        for (int i = 320; i < n; i++)
            printf("%d\n", DumberFouriererer(i));
    }
    else
    {
        for (int i = 0; i < n && i < 320; i++)
            printf("%d\n", DumbFourierier(i));
        for (int i = 320; i < n; i++)
            printf("%d\n", DumbestFourierueiurier(i));
    }
}
