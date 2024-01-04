#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int input1;
    int input2;

    cin >> input1;
    cin >> input2;

    for (int i = 0; i < input2; i++){
        string bruh = "";
        for (int j = 0; j < input1; j++){
            bruh += "#";
        }
        cout << bruh << endl;
    }
    
    
}