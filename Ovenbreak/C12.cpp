#include <iostream>
#include <cstdint>
#include <cmath>

std::string Level1(char thing)
{
    switch(thing)
    {
        case '0':
        case '2':
        case '3':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'A':
        case 'P':
            return "###";
        case '1':
            return "  #";
        case '4':
        case 'M':
            return "# #";
    }
            return "!";
}

std::string Level2(char thing)
{
    switch(thing)
    {
case '5':
case '6':
return "#  ";
case '2':
case '1':
case '3':
case '7':
return "  #";
case '0':
case 'A':
case 'P':
case '9':
case '4':
case '8':
return "# #";
case 'M':
return"###";
    }
            return "!";
}


std::string Level3(char thing)
{
    switch(thing)
    {
        case '2':
        case '3':
        case '5':
        case '6':
        case '8':
        case '9':
        case 'A':
        case 'P':
        case '4':
        return "###";
        case '1':
        case '7':
        return "  #";
        case '0':
        case 'M':
            return "# #";
    }
            return "!";
}


std::string Level4(char thing)
{
    switch(thing)
    {
        case '2':
        case 'P':
        return "#  ";
        case '9':
        case '5':
        case '7':
        case '4':
        case '1':
        case '3':
        return "  #";
        case '6':
        case 'A':
        case 'M':
        case '8':
        case '0':
            return "# #";
    }
            return "!";
}

std::string Level5(char thing)
{
    switch(thing)
    {
        case 'P':
        return "#  ";
        case '7':
        case '4':
        case '1':
        return "  #";
        case 'A':
        case 'M':
        return "# #";
        case '5':
        case '9':
        case '8':
        case '6':
        case '3':
        case '2':
        case '0':
        return "###";
    }
            return "!";
}

void doFunction(int level, char thing)
{
    switch(level)
    {
        case 1:
            std::cout << Level1(thing);
            return;
        case 2:
            std::cout << Level2(thing);
            return;
        case 3:
            std::cout << Level3(thing);
            return;
        case 4:
            std::cout << Level4(thing);
            return;
        case 5:
            std::cout << Level5(thing);
            return;
    }

}


int main()
{
    bool isAm = true;
    std::string first, second;
    std::cin >> first >> second;
    if (first[0] == '2' || first[0] == '1' && first[1] >= '2')
        isAm = false;

    if (!isAm)
    {
        int num = std::stoi(first);
        num -= 12;
        first[0] = num/10 + '0';
        first[1] = num%10 + '0';
    }

    

    std::string mString = isAm ? "AM" : "PM";
    for (int i = 1; i <= 5; i++)
    {
        doFunction(i, first[0]);
        printf(" ");
        doFunction(i, first[1]);
        printf(i%2==0?" : ":"   ");
        doFunction(i, second[0]);
        printf(" ");
        doFunction(i, second[1]);
        printf("   ");
        doFunction(i, mString[0]);
        printf(" ");
        doFunction(i, mString[1]);
        puts("");
    }
}