#include <iostream>
typedef long long unsigned llu;

int main()
{
    std::string in;
    std::cin >> in;

    llu num;
    std::cin >> num;

    in[0] += num / 676000;
    num %= 676000;

    in[1] += num / 26000;
    num %= 26000;

    in[2] += num / 1000;
    num %= 1000;

    in[4] += num / 100;
    num %= 100;

    in[5] += num / 10;
    num %= 10;

    in[6] += num;

    if (in[6] >= 10)
    {
        in[5] += (in[6] - '0') / 10;
        in[6] = '0' + (in[6] - '0') % 10;
    }

    if (in[5] >= 10)
    {
        in[4] += (in[5] - '0') / 10;
        in[5] = '0' + (in[5] - '0') % 10;
    }

    if (in[4] >= 10)
    {
        in[2] += (in[4] - '0') / 10;
        in[4] = '0' + (in[4] - '0') % 10;
    }

    if (in[2] >= 26)
    {
        in[1] += (in[2] - 'A') / 26;
        in[2] = 'A' + (in[2] - 'A') % 26;
    }

    if (in[1] >= 26)
    {
        in[0] += (in[1] - 'A') / 26;
        in[1] = 'A' + (in[1] - 'A') % 26;
    }

    std::cout << in << std::endl;
}
