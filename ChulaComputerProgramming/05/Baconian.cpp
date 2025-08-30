#include <iostream>
#include <cctype>
#include <stdexcept>

inline bool isAlphabet(char c) { return isupper(c) || islower(c); }

// bool HasSameUpperness(std::string A, std::string B)
// {
//     if (A.size() != B.size()) throw std::runtime_error("A And B are not the same size");
//     for (int i = 0; i < A.size(); i++)
//         if (isupper(A[i]) != isupper(B[i]))
//             return false;
//     return true;
// }

char DecodeSegment(std::string str)
{
    int val = 0;
    for (int i = 3; i >= 0; i--)
    {
        val += (bool)islower(str[i]) * (1 << abs(3-i)); //
    }

    // std::cout << "Segment " << str << " translates to " << val << '\n';

    if (val <= 9) return val + '0';
    else if (val == 10) return '-';
    else if (val == 11) return ',';
    else throw std::runtime_error("Segment is more than 11");
}

std::string EncodeChar(char a)
{
    int val = ('0' <= a && a <= '9') ? a-'0': (a == '-' ? 10: 11);
    // std::cout << a << " becomes " << val;

    std::string retStr = "";
    int i = 3;
    while (i >= 0)
    {
        if (val >= 1 << i)
        {
            val -= 1 << i;
            retStr += 'l';
        }
        else
        {
            retStr += 'U';
        }
        i -= 1;
    }
    std::cout << '\n' << a << ' ' << retStr << '\n';
    return retStr;
}

std::string Encode(std::string& numbers, const std::string& fake)
{
    std::string outstr = "";
    int fakeIndex = 0;
    for (char n : numbers)
    {
        for (char a : EncodeChar(n))
        {
            while (!isAlphabet(fake[fakeIndex])) {
                outstr += fake[fakeIndex];
                fakeIndex++; if (fakeIndex >= fake.size()) fakeIndex = 0;
            }

            if (isupper(a)) outstr += toupper(fake[fakeIndex]);
            else outstr += tolower(fake[fakeIndex]);
            fakeIndex++; if (fakeIndex >= fake.size()) fakeIndex = 0;
        }
    }
    return outstr;
}

std::string Decode(std::string& str)
{
    std::string outstr = "";
    std::string instr = "";
    for (char c: str)
    {
        if (isAlphabet(c)) instr += c;
        if (instr.size() == 4)
        {
            outstr += DecodeSegment(instr);
            instr = "";
        }
    }
    return outstr;
}

int main()
{
    std::string fake;
    std::getline(std::cin, fake);

    while (true)
    {
        char mode;
        std::string str;
        std::getline(std::cin, str);
        if (str == "") break;
        mode = str[0];
        str = str.substr(2);
        if (mode == 'E') std::cout << Encode(str, fake) << '\n';
        else if (mode == 'D') std::cout << Decode(str) << '\n';
        else throw std::runtime_error("Invalid mode");
    }

}
