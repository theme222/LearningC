#include <list>
#include <tuple>
#include <iostream>

typedef std::tuple<int, std::list<int>::iterator, std::list<int>::iterator> tupiII; // size

tupiII getChainSize(std::list<int>::iterator pos)
{
    int size = 1;
    int val = *pos;
    
    // Check left
    auto lpos = --pos; ++pos;
    auto rpos= ++pos; --pos;
    
    if (*lpos != val) return {0, lpos, rpos};
    
    while (*lpos == val)
    {
        size++;
        lpos--;
    }
    lpos++; // lpos is before first 
    
    // Check right
    while (*rpos == val)
    {
        size++;
        rpos++;
    }
    // rpos is after last (which is correct)
    return std::make_tuple(size, lpos, rpos);
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, K, V;
    std::cin >> N >> K >> V;
    
    std::list<int> balls;
    
    while (N--)
    {
        int val;
        std::cin >> val;
        balls.push_back(val);
    }
    
    auto pos = balls.begin();
    while (K--) pos++;
    
    pos = balls.insert(pos, V); // set it to the new pos
    tupiII chain = getChainSize(pos);
    
    while (std::get<0>(chain) >= 3)
    {
        // std::cout << std::get<0>(chain) << ' '<< *std::get<1>(chain) << ' '<< *std::get<2>(chain) << std::endl;
        pos = balls.erase(std::get<1>(chain), std::get<2>(chain));
        if (balls.size() < 3) break;
        chain = getChainSize(pos);
    }
    
    for (auto i = balls.begin(); i != balls.end(); i++)
    {
        if (i != balls.begin()) std::cout << ' ';
        std::cout << *i;
    }
}
