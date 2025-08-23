#include <iostream>
#include <stdexcept>

typedef long long ll;

std::string num2Eng[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
std::string mult10[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
std::string magnitude[] = {"hundred", "thousand", "million", "billion", "trillion"};

std::string ParseNum(ll num) // Num should be 3 digits or less also I think zero never occurs
{
    if (num > 999)
        throw std::runtime_error("yo logic is wrong little bro");

    if (num == 0)
        return ""; // Will check for this later

    if (num >= 100) return num2Eng[num / 100] + " hundred" + (num % 100 ? " " + ParseNum(num % 100): "");
    else if (num >= 20) return mult10[num / 10 - 2] + (num % 10 ? " " + ParseNum(num % 10): "");
    else return num2Eng[num];
}

int main()
{
    ll N;
    std::cin >> N;
    if (N <= 19)
    {
        std::cout << num2Eng[N] << std::endl;
        return 0;
    }

    ll mag = 1e12;
    ll magIndex = 4;
    while (mag >= 1000)
    {
        ll num = N / mag;
        ll leftOver = N % mag;
        if (num) std::cout << ParseNum(num) << ' ' << magnitude[magIndex] << (leftOver ? " " : "");

        N = leftOver;

        mag /= 1000;
        magIndex--;
    }

    std::cout << ParseNum(N);
    puts("");
}
