#include <iostream>

std::string real[] = {"Robert","William","James","John","Margaret","Edward","Sarah","Andrew","Anthony","Deborah"};
std::string fake[] = {"Dick","Bill","Jim","Jack","Peggy","Ed","Sally","Andy","Tony","Debbie"};

int index(std::string& thing, std::string *list)
{
    int i;
    for (i = 0; i < 10; i++)
        if (list[i] == thing)
            break;
    // printf("%d\n", i);
    return i;
}

int main()
{
    int count;
    std::cin >> count;
    while (count--)
    {
        std::string name;
        std::cin >> name;

        if (index(name, real) != 10) std::cout << fake[index(name, real)] << '\n';
        else if (index(name, fake) != 10) std::cout << real[index(name, fake)] << '\n';
        else puts("Not found");
    }
}
