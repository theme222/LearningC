#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll, ll> pll;

std::set<pll> line;

bool merge(pll a, pll b, pll &out)
{
    if (a > b) std::swap(a,b);
    bool isOverlap = (b.first <= a.first && a.first <= b.second) || 
                    (a.first <= b.first &&  b.first <= a.second) || 
                    (a.second+1 == b.first); // connected
    out = pll(std::min(a.first, b.first), std::max(a.second, b.second));
    return isOverlap;
}

std::ostream& operator<<(std::ostream& os, pll other)
{
    return os << other.first << '-' << other.second;
}

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    ll N;
    std::cin >> N;
    
    while (N--)
    {
        ll mode;
        std::cin >> mode;
        if (mode == 1)
        {
            ll a, b;
            std::cin >> a >> b;
            
            pll current = std::make_pair(a,b);
            pll out;
            
            if (!line.empty())
            {
                while (true)
                {
                    auto higher = line.lower_bound(current);
                    auto lower = line.end();
                    if (higher != line.begin()) {lower = --higher; higher++;}
                    bool changed = false;
                    // std::cout << "higher: " << *higher << " end:" << *line.end() << " size:" << line.size() << '\n';
                    
                    if (higher != line.end() && merge(current, *higher, out))
                    {
                        line.erase(higher);
                        current = out;
                        changed = true;
                    }
                    
                    // std::cout << "lower: " << *lower << " end:" << *line.end() << " size:" << line.size() << '\n';
                    
                    if (lower != line.end() && merge(current, *lower, out))
                    {
                        line.erase(lower);
                        current = out;
                        changed = true;
                    }
                    
                    // std::cout << "new current: " << current << '\n';
                    if (!changed) break;
                }
            }
            
            line.insert(current);
        }
        else if (mode == 2) std::cout << line.size() << '\n';
    }
}