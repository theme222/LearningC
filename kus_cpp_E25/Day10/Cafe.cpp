#include <iostream>
#include <string>

using namespace std;

int totalPay = 0,totalSale = 0;
string customerName = " ",receiptString = "";
string salesString = "";

// bruh moment

void print_menu(){
    cout << "Coffee Menu" << endl;
    cout << "0. Finish \n1. Latte = 40 \n2. Espresso = 45 \n3. Americano = 50 \n4. Mocca = 55 \n5. Cappuccino = 60" << endl;
}

bool order_coffee(){
    bool orderFinished = false;
    int intCoffeeType,price,amount;
    string stringCoffeeType;
    cout << "Customer Name : ";
    cin.sync();
    getline(cin, customerName);
    if (customerName == "end day"){
        return false;
    }

    while (!orderFinished){
        cout << "Coffee type : ";
        cin >> intCoffeeType;

        switch (intCoffeeType)
        {
        default:
            cout << "Total price : " << totalPay << endl;
            return true;
        case 1:
            stringCoffeeType = "Latte";
            price = 40;
            break;
        case 2:
            stringCoffeeType = "Espresso";
            price = 45;
            break;
        case 3:
            stringCoffeeType = "Americano";
            price = 50;
            break;
        case 4:
            stringCoffeeType = "Mocca";
            price = 55;
            break;
        case 5:
            stringCoffeeType = "Cappuccino";
            price = 60;
            break;
        }

        cout << "Amount of " << stringCoffeeType<<": ";
        cin >> amount;
        totalPay += price * amount;
        receiptString += (stringCoffeeType + " " + to_string(amount) + ", " + to_string(price * amount) + " baht\n");

    }
    return true;
}

void change(){
    int customerPay,changeToCalc;
    cout << "Payment : ";
    cin >> customerPay;
    changeToCalc = customerPay - totalPay;
    cout << "Customer's change : " << changeToCalc << endl;

    int changeTypes[] = {1000,500,100,50,20,10,5,1};
    for (int changeType : changeTypes){
        int count = 0;
        while (true){
            if (changeToCalc - changeType >= 0){
                count += 1;
                changeToCalc -= changeType;
            } else {
                if (count > 0){
                    cout << "Change " << changeType << " : " << count << endl;
                }
                
                break;
            }
        }
    }
}

void print_receipt(){
    cout << "--------- receipt --------- \nCPE36 COFFEE SHOP\n";
    cout << "Customer name : "<<customerName << endl;
    cout << receiptString;
    cout << "Thank you\n---------------------------" << endl;
}

void print_report(){
    cout << "---- Daily Sale Report ----" << endl;
    cout << salesString;
    cout << "Total sale : " << totalSale << " baht" << endl;
    cout << "---------------------------" << endl;
}

int main(){
    while (true)
    {
        totalPay = 0;
        receiptString = "";
        customerName = "";
        print_menu();
        if (!order_coffee()){break;}
        change();
        print_receipt();
        totalSale += totalPay;
        salesString += customerName + " " + to_string(totalPay) + " baht\n";
    }
    print_report();
    return 0;
}