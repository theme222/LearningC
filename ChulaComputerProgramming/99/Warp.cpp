#include <bits/stdc++.h>

typedef std::pair<int, int> ipair;

int warpCount, start, end;
std::map<int, std::vector<int>> warpList;

bool traverse(int source)
{
    if (source == end) return true;
    if (source > end) return false;
    if (warpList.count(source) == 0) return false;

    bool found = false;
    for (auto dest: warpList[source])
    {
        found = found || traverse(dest);
    }
    return found;
}

int main()
{
    std::cin >> warpCount >> start >> end;

    for (int i = 0; i < warpCount; i++)
    {
        int source, dest;
        std::cin >> source >> dest;

        if (warpList.count(source) == 0)
            warpList[source] = std::vector<int> {dest};
        else
            warpList[source].push_back(dest);
    }

    bool found = traverse(start);
    puts(found ? "yes": "no");
}
