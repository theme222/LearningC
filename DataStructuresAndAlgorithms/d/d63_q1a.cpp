#include <iostream>
#include <vector>
using namespace std;

void multiple_add(vector<int> &v, int value, int position, int count) {
    int originalSize = v.size();
    v.resize(v.size() + count, value);
    for (int i = originalSize-1; i >= position; i--)
    {
        v[i+count] = v[i];
        v[i] = value;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,value,position,count;
    cin >> n >> value >> position >> count;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    multiple_add(v,value,position,count);
    cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
    for (auto &x : v) cout << x << " ";
    cout << endl;

    int *test1 = new int[20];
    int *test2 = new int[20]();
}
