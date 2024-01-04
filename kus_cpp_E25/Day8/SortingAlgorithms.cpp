#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void BubbleSort(int* arr, int size){
    int newNum,previousNum = -1,count = 1;
    int *ptr;
    while (count != 0){
        count = 0;
        previousNum = -1;
        for (int *ptr = arr;ptr != arr + size; ptr++){
            if (previousNum != -1){
                if (previousNum > *ptr){
                    count++;
                    int newNum = *ptr;
                    ptr[0] = previousNum;
                    ptr[-1] = newNum;
                     
                }
            } 
            
            previousNum = *ptr;
           
        }

        for (int *ptr = arr;ptr != arr + size; ptr++){
            cout << *ptr << " ";           
        }

        cout << "\n";
    }
    return;

}


int main(){
    int num,count = 0,total;
    cin >> total;
    vector<int> NumberVector;

    while (cin >> num){
        count += 1;
        NumberVector.push_back(num);
        if (count >= total){
            break; 
        }
    }


    int arr[NumberVector.size()];
    copy(NumberVector.begin(),NumberVector.end(),arr);
    BubbleSort(arr, total);
    return 0;
}







