#include <iostream>
#include <algorithm>

int puzzles[1000];
int main()
{
    int n,m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
        std::cin >> puzzles[i];

    std::sort(puzzles, puzzles+m);
    int start = 0, end = start+n-1;
    int lowest = 1e9;
    for (;end < m;)
    {
        if (puzzles[end]-puzzles[start] < lowest) lowest = puzzles[end]-puzzles[start];
        start++;
        end++;
    }

    std::cout << lowest << std::endl;

}
