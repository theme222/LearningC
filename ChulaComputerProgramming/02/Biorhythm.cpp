// Using if else only pains me :(
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

double customRound(double num)
{
    return round(100 * num) / 100;
}

double CalcBioRythmThing(int totalDays, int divider)
{
    return customRound(sin(2.0 * M_PI * (double)totalDays / (double)divider));
}

int main()
{
    int day1, month1, year1;
    int day2, month2, year2;

    std::cin >> day1 >> month1 >> year1;
    std::cin >> day2 >> month2 >> year2;

    int fullYear1 = TotalDaysAYear(year1);
    int fullYear2 = TotalDaysAYear(year2);
    // printf("fullyear %d %d", fullYear1, fullYear2);
    int daysUntilEnd = fullYear1 - GetDaysSinceStartYear(day1, month1, fullYear1) + 1;
    int daysSinceStart = GetDaysSinceStartYear(day2, month2, fullYear2) - 1;
    // printf("dayss %d %d \n", daysUntilEnd, daysSinceStart);

    int daysInMiddleYears = (year2 - year1 - 1) * 365;
    int totalDays = daysUntilEnd + daysSinceStart + daysInMiddleYears;

    std::cout << totalDays << " "
        << CalcBioRythmThing(totalDays, 23) << " "
        << CalcBioRythmThing(totalDays, 28) << " "
        << CalcBioRythmThing(totalDays, 33) << '\n';
}
