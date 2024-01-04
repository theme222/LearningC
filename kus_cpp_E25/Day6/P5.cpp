#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int input;
    string direction;

    cin >> input;
    cin >> direction;

    if (direction == "right"){
        for (int i = 1; i < input+1; i++){
            string bruh = "";
            for (int j = 0; j < i; j++){
                bruh += "#";
            }
            cout << bruh << endl;
        }
    }
    else{
        for (int i = input-1;  i >= 0; i--){
            string bruh = "";

            for (int j = 0; j < i; j++){
                bruh += " ";
            }
            
            for (int k = 0; k < input - i; k++){
                bruh += "#";
            }
            cout << bruh << endl;
        }
    }

    
    
}