#include <iostream>
#include <string>
typedef long long ll;

int main()
{
    std::string id;
    std::cin >> id;
    ll checknum = 0;
    ll sum = 0;
    ll digit = 0;
    ll mult = 13;

    while (digit <= 11)
    {
        checknum += (id[digit] - '0') * mult;
        mult--;
        digit++;
    }

    checknum %= 11;
    checknum = (11 - checknum) % 10;
    std::cout << id[0] << '-' << id.substr(1,4) << '-' << id.substr(5,5) << '-' << id.substr(10,2) << '-' << checknum << '\n';
}
