#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int inp;
    int ssum = 0;
    while (inp != 0){
        cin >> inp;
        ssum += inp;
    }
    cout << ssum << endl;

}