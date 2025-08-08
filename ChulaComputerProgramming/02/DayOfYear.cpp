#include <iostream>
#include <cmath>

int TotalDaysAYear(int year)
{
    year -= 543;
    if (year % 400 == 0) return 366;
    if (year % 100 == 0) return 365;
    if (year % 4 == 0) return 366;
    return 365;
}

int GetDaysUntilEndMonth(int month, int fullYear)
{
    int days = 0;
    if (month == 1) days = 31;
    if (month == 2) days = 59;
    if (month == 3) days = 90;
    if (month == 4) days = 120;
    if (month == 5) days = 151;
    if (month == 6) days = 181;
    if (month == 7) days = 212;
    if (month == 8) days = 243;
    if (month == 9) days = 273;
    if (month == 10) days = 304;
    if (month == 11) days = 334;
    if (month == 12) days = 365;
    // std::cout << "dsafdsdsa" << (int)(fullYear == 366 && month > 1) << '\n';
    return days + (int)(fullYear == 366 && month > 1);
}

int GetDaysSinceStartYear(int day, int month, int fullYear)
{
    return GetDaysUntilEndMonth(month-1, fullYear) + day;
}

int main()
{
    int day, month, year;
    std::cin >> day >> month >> year;
    std::cout << GetDaysSinceStartYear(day, month, TotalDaysAYear(year)) << std::endl;
}
