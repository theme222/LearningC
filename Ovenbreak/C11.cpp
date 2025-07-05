#include <iostream>
#include <cstdint>
#include <cmath>

std::string reverse(const std::string &str)
{
    std::string out = "";
    for (int i = str.size()-1; i >= 0; i--)
        out += str[i];
    return out;
}

std::string operator*(const std::string& str, int num) 
{
    std::string outString = "";
    for (int i = 0; i < num;i++)
        outString += str;
    return outString;
}

void PrintOuterbox(int size)
{

    std::string inner;
    bool flipflop = true;
    for (int i = 0; i < size; i++)
    {
        inner += flipflop ? "^#^" : "*#*";
        flipflop = ! flipflop;
    }
    
    std::string inner2 = reverse(inner);

    std::cout << "  ###" << inner << "###"
        << "||" << "###" << inner2 << "###\n"
    ;
}

void PrintKindaOuterbox(int size)
{
    std::string inner;

    bool flipflop = true;
    inner += flipflop ? "*" : "^";
    for (int i = 0; i < size-1; i++)
    {
        inner += flipflop ? "##^" : "##*";
        flipflop = ! flipflop;
    }
    
    std::string inner2 = reverse(inner);

    std::cout << " ####" << inner << "####"
        << " || " << "####" << inner2 << "####\n" ;
}

void PrintInnerBorderbox(int size)
{
    std::cout << "###" << (std::string)"-" * (size*3)
        << "###  ||  ###" << (std::string)"-" * (size*3)
        << "###\n";
}

void PrintTextInnerThinghikjfdskjfdsjfds(int size, std::string &text)
{
    std::string w_h_i_t_e_s_p_a_c_e = (std::string)" " * size;
    std::cout << "###" << w_h_i_t_e_s_p_a_c_e 
        << text << w_h_i_t_e_s_p_a_c_e << "###  ||"
        << "  ###" << w_h_i_t_e_s_p_a_c_e << text
        << w_h_i_t_e_s_p_a_c_e << "###\n";

}


int main()
{
    std::string text;
    std::cin >> text;
    int len = text.size();
    PrintOuterbox(len);
    PrintKindaOuterbox(len);
    PrintInnerBorderbox(len);
    PrintTextInnerThinghikjfdskjfdsjfds(len, text);
    PrintInnerBorderbox(len);
    PrintKindaOuterbox(len);
    PrintOuterbox(len);
}