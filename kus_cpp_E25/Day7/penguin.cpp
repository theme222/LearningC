#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    
    vector<int> IntVector;
    int penguinCount,num,count = 0;

    cout << "How many penguins : ";
    cin >> penguinCount;
    IntVector.reserve(penguinCount);

    
    while (cin >> num){
        count += 1;
        IntVector.push_back(num);
        if (count >= penguinCount){
            break; 
        }
    }

    int angle;
    int totalCross = 0;
    int size = IntVector.size();
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (IntVector[i] < IntVector[j]){
                totalCross += 1;
            }
        }
    }




    cout << "Hits each other : " << totalCross << endl;


    return 0;
}