#include <iostream>
#include <algorithm>

void CustomResize(std::string& str, int size)
{
    if (str.size() >= size) return;
    for (int i = 0;  i < size - str.size(); i++)
        str += '0';
}

int main()
{
    std::string total = "0";
    total.reserve(100);

    std::string in;

    while (std::cin >> in)
    {
        if (in == "END") break;

        int mag = 0;
        int carry = 0;

        for (int i = in.size() - 1; i >= 0; i--)
        {

            CustomResize(total, mag+1);
            // Add
            int currentTotal = total[mag] - '0';
            int currentIn = in[i] - '0';

            if (currentIn + currentTotal + carry > 9)
            {
                total[mag] = ((currentIn + currentTotal + carry) % 10) + '0';
                carry = 1;
            }
            else
            {
                total[mag] += currentIn + carry;
                carry = 0;
            }
            mag++;
        }

        if (carry > 0)
        {
            CustomResize(total, mag+1);
            while (total[mag] == '9')
            {
                total[mag] = '0';
                mag++;
                CustomResize(total, mag+1);
            }
            total[mag] += carry;
        }
        // std::cout << total << '\n';
    }

    std::reverse(total.begin(), total.end());
    std::cout << total << std::endl;
}
