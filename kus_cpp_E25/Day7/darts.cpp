#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){

    int totalPoints = 0;
    int dartCount;

    // take the amount of darts
    cout << "How many darts to fire : ";
    cin >> dartCount;

    for(int i = 0; i < dartCount; i++){
        int X,Y;
        cout << "Get X Y : ";
        cin >> X >> Y;
        // Calculate Hypotenuse idk how to spell

        float radius = sqrt(pow(X,2) + pow(Y,2));
        if (radius <= 2){
            totalPoints += 5;
        } else if (radius <= 4){
            totalPoints += 4;
        }else if (radius <= 6){
            totalPoints += 3;
        }else if (radius <= 8){
            totalPoints += 2;
        }else if (radius <= 10){
            totalPoints += 1;
        }
    }
    cout << "You got " << totalPoints << " Point(s)!" << endl;
    return 0;
}