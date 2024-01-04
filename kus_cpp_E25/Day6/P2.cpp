#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int inp;
    int max = 0;
    while (inp != 0){
        cin >> inp;
        if (max < inp){
            max = inp;
        }
    }
    cout << max << endl;

}