#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string line, char delimiter) {
    vector<string> vec;
    string currString = "";

    for (char a: line)
    {
        if (a == delimiter)
        {
            if (currString != "") {
                vec.push_back(currString);
            }
            currString = "";
        }
        else
        {
            currString += a;
        }
    }
    return vec;
}
int main() {
string line;
getline(cin, line);
string delim;
getline(cin, delim);
for (string e : split(line, delim[0])) {
cout << '(' << e << ')';
}
}
