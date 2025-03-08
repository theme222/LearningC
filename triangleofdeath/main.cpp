#include <bits/stdc++.h>
using namespace std;

int holyhell[3] = {100000, 100000, 100000};
int totalSticks,stick,_max = -1;
int main()
{
    cin >> totalSticks;
    while (totalSticks--)
    {
        scanf("%d",&stick);
        holyhell[2] = stick;
        sort(holyhell, holyhell + 3);
        if (stick > _max) _max = stick;
    }

    if (holyhell[0] + holyhell[1] > _max) cout << "no" << endl;
    else cout << "yes" << endl;

    return 0;
}
