#include <iostream>
#include <set>

std::set<int> orderedSet;

int main()
{
    int K;
    std::cin >> K;

    int n;
    while (std::cin >> n)
        orderedSet.insert(n);

    int count = 0;

    std::set<int>::iterator itStart = orderedSet.begin();
    std::set<int>::iterator itEnd = orderedSet.end();
    itEnd--; // Get the actual value

    while(*itStart < *itEnd)
    {
        if (*itStart + *itEnd < K)
            itStart++;
        else if (*itStart + *itEnd > K)
            itEnd--;
        else
        {
            count++;
            itEnd--;
        }
    }
    std::cout << count;
}
