#include <iostream>
#include <cctype>

int main()
{
    std::string a;
    std::cin >> a;

    bool isfirst = true;

    std::string currentSplit = a.substr(0,1);

    bool isNumber = isdigit(currentSplit[0]);

    for (int i = 1; i < a.size(); i++)
    {
        if (isupper(a[i]) || (!isNumber && isdigit(a[i])) || (isNumber && !isdigit(a[i])))
        {
            if (!isfirst) std::cout << ", ";
            std::cout << currentSplit;
            isfirst = false;
            currentSplit = "";
        }

        currentSplit += a[i];
        isNumber = isdigit(a[i]);
    }
    if (!isfirst) std::cout << ", ";
    std::cout << currentSplit;
    puts("");

}
