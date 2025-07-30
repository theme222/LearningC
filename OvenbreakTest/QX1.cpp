#include <iostream>
#include <cmath>

void Option1()
{
    float a,b;
    std::cin >> a >> b;
    float total = a * b;
    std::cout << (int)(floor(total)) << '\n';
}

void printReturn(std::string str)
{
    std::cout << str << '\n';
    exit(0);
}

void Option2()
{
    int grade;
    std::cin >> grade;
    if (grade > 84) printReturn("A");
    else if (grade >= 80) printReturn("B+");
    else if (grade >= 75) printReturn("B");
    else if (grade >= 70) printReturn("C+");
    else if (grade >= 65) printReturn("C");
    else if (grade >= 60) printReturn("D+");
    else if (grade >= 50) printReturn("D");
    else printReturn("F");
}

void Option3()
{
    int height;
    std::cin >> height;
    std::string current = "";
    for (int i = 0; i < height; i++)
    {
        current += "*";
        std::cout << current;
        if ((i + 1) % 3 == 0|| (i + 1) % 11 == 0) std::cout << " Ti amo";
        std::cout << '\n';
    }
}

int arr[100000];
void Option4()
{
    int count;
    int index;
    std::cin >> count;
    for (int i = 0; i < count; i++)
    {
        int thing;
        std::cin >> thing;
        arr[thing]++;
    }
    std::cin >> index;

    std::cout << arr[index] << '\n';
}

int main()
{
    int option;
    std::cin >> option;
    switch(option)
    {
        case 1:
            Option1();
            break;
        case 2:
            Option2();
            break;
        case 3:
            Option3();
            break;
        case 4:
            Option4();
            break;

    }

}