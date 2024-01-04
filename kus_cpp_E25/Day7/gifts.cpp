#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    
    // vector<int> IntVector;
    int itemCount,num = 0,count = 0,netWorth = 0;
    cout << "How many Items : ";
    cin >> itemCount;
    
    // IntVector.reserve(itemCount);

    
    while (cin >> num){
        count += 1;
        // IntVector.push_back(num);
        if (num > 0){
            netWorth += num;
        }
        if (count >= itemCount){
            break;
        }
    }
    cout << "Your net worth is now " << netWorth << endl;




    return 0;
}