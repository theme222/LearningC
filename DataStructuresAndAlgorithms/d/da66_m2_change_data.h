#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    typedef std::queue<int> qi;
    typedef std::vector<qi> vqi;
    typedef std::stack<vqi> svqi;
    svqi newStack;
    
    while (!a.empty())
    {
        vqi vec = a.top();
        a.pop();
        
        for (qi &que: vec)
        {
            for (int i = 0; i < que.size(); i++)
            {
                int val = que.front();
                if (val == from) val = to;
                que.pop();
                que.push(val); // queue stays the same size
            }
        }
        newStack.push(vec);
    }
    
    while (!newStack.empty())
    {
        a.push(newStack.top());
        newStack.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    typedef std::priority_queue<int> pqi;
    typedef std::pair<pqi, int> ppqii;
    typedef std::map<string, ppqii> mppqii;
    
    for (auto& keyvalue: a)
    {
        ppqii &pair = keyvalue.second;
        if (pair.second == from) pair.second = to;
        
        pqi &pq = pair.first;
        
        std::vector<int> temp;
        temp.reserve(pq.size());
        while (!pq.empty())
        {
            temp.push_back(pq.top() == from ? to : pq.top());
            pq.pop();
        }
        
        for (int a: temp)
            pq.push(a);
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // what the fuck
    typedef std::pair<int, string> pis;
    typedef std::map<int, pis> mpis;
    typedef std::pair<std::list<int>, mpis> plmpis;
    typedef std::set<plmpis> splmpis;
    
    splmpis outSet;
    
    for (plmpis pairListMap : a)
    {
        // List change
        std::list<int> &ls = pairListMap.first;
        for (auto &val: ls)
            if (val == from) val = to;
            
        mpis &mp = pairListMap.second;
        // Map change
        
        // check key
        if (mp.count(from) == 1) 
        {
            mp[to] = mp[from];
            mp.erase(from);
        }
        
        // Check value
        for (auto &keyvalue: mp)
        {
            pis &pairIntString = keyvalue.second;
            if (pairIntString.first == from) pairIntString.first = to;
        }
        outSet.insert(pairListMap);
    }
    std::swap(a, outSet);
}

#endif
