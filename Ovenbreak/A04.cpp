#include <iostream>
#include <cmath>

int main()
{
    int totalX = 0, totalY = 0;
    int scale, speed;
    std::cin >> scale >> speed;

    int y1, x1, y2, x2;
    std::cin >> y1 >> x1 >> y2 >> x2;
    totalX += x1 + x2;
    totalY += y1 + y2;


    double dist = scale * sqrt((totalX * totalX) + (totalY * totalY));
    double time = dist * 1000 / (double)speed;
    double hour = floor(time / 3600.0);
    double minute = ceil((time - (hour * 3600)) / 60);
    printf("%d hr %d min\n", (int)hour, (int)minute);
}