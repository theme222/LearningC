#include <bits/stdc++.h>

typedef std::pair<int, int> ipair;

int warpCount, start, end;
std::map<int, std::vector<int>> warpList;

std::vector<int> currentPath;
std::set<std::vector<int>> paths;

std::string ConstructPath(const std::vector<int>& vec)
{
    std::string out = std::to_string(vec[0]);

    for (int i = 1; i < vec.size(); i++)
        out += " -> " + std::to_string(vec[i]);

    return out;
}

bool Traverse(int source)
{
    if (source == end)
    {
        paths.insert(currentPath);
        return true;
    }

    if (source > end) return false;
    if (warpList.count(source) == 0) return false;

    bool found = false;
    for (auto dest: warpList[source])
    {
        currentPath.push_back(dest);
        bool res = Traverse(dest);
        found = found || res;
        currentPath.pop_back();
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

    currentPath.push_back(start);
    bool found = Traverse(start);
    if (found)
    {
        for (auto& s: paths)
            std::cout << ConstructPath(s) << '\n';
    }
    else puts("no");
}
