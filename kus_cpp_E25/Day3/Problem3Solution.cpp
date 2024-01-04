#include <iostream>
#include <string>

using namespace std;

int main(){ // Wha the hell

    int people;
    cin >> people;
    int total = 0;
    for (int i = people; i > 0; i--){
        total += i-1;
    }
    cout << total;

}

