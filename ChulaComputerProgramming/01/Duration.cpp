#include <iostream>


int main()
{
    int h1, m1, s1;
    int h2, m2, s2;
    int deltah, deltam, deltas;

    std::cin >> h1 >> m1 >> s1;
    std::cin >> h2 >> m2 >> s2;

    deltas = s2 - s1 + 60;

    if (deltas < 60) m1++;
    deltas %= 60;

    deltam = m2 - m1 + 60;

    if (deltam < 60) h1++;
    deltam %= 60;

    deltah = h2 - h1 + 24;

    deltah %=24;
    std::cout << deltah << ':' << deltam << ':' << deltas << '\n';

}
