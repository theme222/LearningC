#include <iostream>

char idk[99999];

std::string operator*(const std::string& str, int nbum)
{
    std::string outstr = "";
    for (int i = 0; i < nbum; i++)
    {
        outstr += str;
    }
    return outstr;
}


int main()
{
    int n, angular_velocity = 1;
    std::cin >> n;
    while (n--)
    {
        std::string tihng;
        std::cin >> tihng;
        if (tihng != "oii") 
        {
            int count = 0;
            while (count < 3)
            {
                char a;
                std::cin >> a;
                switch(a)
                {
                    case 'i':
                    count++;
                    break;
                    case 'a':
                    angular_velocity += 1;
                    break;
                    case 'o':
                    angular_velocity -= 1;
                    if (angular_velocity == 0) angular_velocity = 1;
                    break;
                }

            }
            continue;
        }
        else
        {
            std::string buffer = "";
            int count = 0;
            while (count < 3)
            {
                char newChar;
                std::cin >> newChar;
                if (newChar == 'i') 
                {
                    buffer += ((std::string)" i") * angular_velocity;
                    count++;
                }
                else
                {
                    std::string tihngggg = "  ";
                    tihngggg[1] = newChar;
                    std::cout << buffer << tihngggg * angular_velocity;
                    buffer = "";
                    count = 0;
                }
            }
        }
    }
}