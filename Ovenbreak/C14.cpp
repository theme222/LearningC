#include <iostream>
#include <cstdint>
#include <cmath>

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;
    while (true)
    {
        if (x % 2 > y % 4)
        {
            x += 2;
            y = x/2;
            if (z < y + 2)
                z += 3;
            continue;
        }
        else
        {
            y -= 2;
            if (y > 0) continue;
            y = z + 3;
            z = 5 + x;
            break;
        }
    }
    printf("%d %d %d\n", x, y, z);
}