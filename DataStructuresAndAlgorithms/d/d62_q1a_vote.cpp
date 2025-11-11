#include <iostream>
#include <queue>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int N, K;
    std::cin >> N >> K;
    
    std::map<std::string, int> ballot;
    
    while (N--)
    {
        std::string name;
        std::cin >> name;
        ballot[name]++;
    }
    
    std::priority_queue<std::pair<int, std::string>> topK;
    
    auto it = ballot.end();
    it--;
    
    while (true)
    {
        topK.push({it->second, it->first});
        if (it == ballot.begin()) break;
        it--;
    }
    
    
    std::pair<int, std::string> last;
    while (K--)
    {
        if (topK.empty()) break;
        last = topK.top();
        topK.pop();
    }
    
    std::cout << last.first << '\n';
    
}