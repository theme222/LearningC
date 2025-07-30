#include <iostream>
#include <cmath>

int x,y,z;

void output()
{
    printf("%d %d %d\n", x, y, z);
    exit(0);
}

int main()
{
    std::cin >> x >> y >> z;
    if (x < 50)
    {
        while (true)
        {
            if (y > z)
            {
                if (y %2 == 0)
                {
                    x += pow(y,2) + pow(z,2);
                    if (x % 10 == 4)
                    {
                        output();
                    }
                    else
                    {
                        if (x % 3 == 0)
                        {
                            y--;
                        }
                        else
                        {
                            z++;
                        }
                        if (x / (y + z) > 15) output();
                        else continue;
                    }

                }
                else
                {
                    x = x - (y-z);
                    y++;
                    continue;

                }

            }
            else 
            {
                break;
            }

        }

    }
    else
    {
        if (x > y)
        {
            if (x % 2 == 0)
            {
                x *= 2;
                y = x + 4;
                z = (y-x) * 3;
                output();
            }
            else
            {
                if (y < z)
                {
                    x = x + y;
                    y = x * 3;
                    z += y;
                }
                else
                {
                    x /= 2;
                    y *= 2;
                    z = x - y;
                }
                output();
            }
        }
        else
        {
            if (z % 3 == 2)
            {
                x = y * 5;
                y = x / 2;
                z = y + 7;
                output();
            }
            else 
            {
                if (y > z)
                {
                    x = x + z;
                    y = y - 3;
                    z = x * 2;
                    output();
                } 
                else
                {
                    x--;
                    y += z;
                    z = y - 4;
                    output();
                }
            }

        }
    }
    output();
}