#include <iostream>
#include <string>

using namespace std;

int main(){ // Wha the hell

    float price = 0;
    cout << "Summary price : ";
    cin >> price;
    cout << "Food : " << price*100/107 << endl;
    cout << "Vat : " << price - (price*100/107) << endl;

}

