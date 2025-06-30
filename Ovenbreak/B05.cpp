#include <iostream>

bool has21(std::string &str)
{
    return str[str.size() - 1] == '1' && str[str.size() - 2] == '2';
}

std::string compStr(std::string str1, std::string str2)
{
    if (str1[0] == str2[0] && str1[1] == str2[1]) return "No one.";
    if (str1[0] > str2[0]) return str1;
    if (str1[0] < str2[0]) return str2;
    if (str1[1] > str2[1]) return str1;
    if (str1[1] < str2[1]) return str2;
}

void printWin(std::string str)
{
    if (str == "No one.") 
    {
        puts("No one.");
        return;
    }
    printf("Win: %s\n", str.c_str());
}

int main()
{
    std::string name1, name2;
    int a1,d1,s1;
    int a2,d2,s2;
    std::cin >> name1 >> name2;
    std::cin >> a1 >> d1 >> s1;
    std::cin >> a2 >> d2 >> s2;

    int total1 = a1+d1+s1;
    int total2 = a2+d2+s2;
    if (total1 > total2)
    {
        printWin(name1);
        return 0;
    }
    else if (total2 < total1)
    {
        printWin(name2);
        return 0;
    }
    if (a1 > a2)   
    {
        printWin(name1);
        return 0;
    }
    else if (a2 > a1)
    {
        printWin(name2);
        return 0;
    }
    if (s1 > s2)   
    {
        printWin(name1);
        return 0;
    }
    else if (s2 > s1)
    {
        printWin(name2);
        return 0;
    }
    if (name1[0] == '3' ^ name2[0] == '3')
    {
        printWin(name1[0] == '3' ? name1 : name2);
        return 0;
    }
    printWin(compStr(name1, name2));

}