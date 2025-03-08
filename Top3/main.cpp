#include <bits/stdc++.h>
using namespace std;

vector<pair<float,string>> thing;
int nameCount;


int main()
{
    cin >> nameCount;

    string name;
    float score;
    while (nameCount--)
    {
        cin >> score >> name;
        thing.push_back(pair<float,string>(score,name));
        sort(thing.begin(),thing.end(),greater());
        if (thing.size() > 3) thing.erase(thing.end() - 1);
        
    }

    cout << thing[0].second << endl;
    cout << thing[1].second << endl;
    cout << thing[2].second << endl;

    return 0;
}

