#include <iostream>
#include <string>

using namespace std;

void Head(int num){
    string Head = " ";
    string sideHead = " O";
    for(int i = 0; i != num; i++){
        Head += "O";
        if (i < num-2){
            sideHead += " ";
        }
    }
    sideHead += "O";
    cout << Head << endl; // Make the top of the head
    for(int i = 0; i < (num-2)/2; i++){ // Make the side of the head
        cout << sideHead << endl;
    }
    cout << Head << endl; // Make the bottom of the head
}
void Body(int num){
    string neck = "";
    string neckAndArms = "";
    for(int i = 0; i < num/2; i++){
            neck += " ";
            neckAndArms += "-";
    }
    neck += "||";
    neckAndArms = neckAndArms + "||" + neckAndArms;
    for(int i = 0; i < (num-2)/2; i++){
        cout << neck << endl;
    } 
    cout << neckAndArms << endl;
    for(int i = 0; i < (num-2)/2; i++){
        cout << neck << endl;
    } 
}
void Leg(int num){
    string leg = "";
    for(int j = num/2; j != 0 ; j--){
        for(int i = 0; i < j; i++){
            leg += " ";
        }
        leg += "/";
        for(int i = 0; i < num/2-j; i++){
            leg += "  ";
        }
        leg += "\\";
        cout << leg << endl;
        leg = "";
    }


}

int main(){
    int num;
    cin >> num;
    Head(num);
    Body(num);
    Leg(num);
    return 0;
}