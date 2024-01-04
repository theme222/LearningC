#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int inp;
    int total = 1;
    cin >> inp;
    if (inp == 0){
        cout << total;
    }
    else if(inp < 0){
        cout << "undefined";
    }
    else{
        for(int i = inp; i > 0; i--){
            total *= i;
        }
        cout << total;
    }
    
}