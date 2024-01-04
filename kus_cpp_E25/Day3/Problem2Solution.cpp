#include <iostream>
#include <string>

using namespace std;

int main(){ // Wha the hell

    int second = 0;
    cout << "Sheep : ";
    cin >> second;

    int hour = second/3600;
    int minute = (second-hour*3600)/60;
    second = second-(hour*3600)-(minute*60);


    cout << "Time : Hour(s) " << hour << " Minutes(s) " << minute << " Second(s) " << second;

}

