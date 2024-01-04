#include <iostream>
#include <typeinfo>
#include <string>


using namespace std;


// int* appendNum(int list[], int value){
//     int listSize = sizeof(list)/sizeof(int);
//     static int newList[9999999];
//     newList[listSize+1] = value;
//     for (int i; i < listSize+1 ; i++){
//         newList[i] = list[i];
//     }
//     return newList;
// }


int main(){ 
    int a[7] = {1,2,3,4,5,6,7};
    int *ptr = a;

    if (ptr[7] == '\0'){
        cout << "yay";
    } else{
        cout << "bruh";
        cout << typeid(ptr[10]).name();
    }




}

