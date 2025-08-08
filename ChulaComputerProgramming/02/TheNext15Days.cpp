#include <exception>
#include <iostream>
#include <stdexcept>

int GetMonthSize(int month, int year)
{
    switch (month)
    {
        case 1: return 31;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        case 2:
            year -= 543;
            if (year % 400 == 0) return 29;
            if (year % 100 == 0) return 28;
            if (year % 4 == 0) return 29;
            return 28;
        default: throw std::invalid_argument("invalid month");
    }
}

int main()
{
    int d,m,y;
    std::cin >> d >> m >> y;
    int n = GetMonthSize(m, y);
    d += 15;
    if (d > n)
    {
        d -= n;
        m++;
    }
    if (m > 12)
    {
        m -= 12;
        y++;
    }
    printf("%d/%d/%d\n", d,m,y);
}
