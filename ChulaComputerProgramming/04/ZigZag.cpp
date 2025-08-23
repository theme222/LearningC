// I don't even think you need an array for this?
#include <iostream>

int main()
{
    int lineCount;
    std::cin >> lineCount;

    int minL = 1e9, maxL = -1e9, minR = 1e9, maxR = -1e9;

    bool flipflop = true; // if true L is left R is right
    while (lineCount--)
    {
        int L, R;
        std::cin >> L >> R;
        if (!flipflop) std::swap(L, R);

        minL = std::min(minL, L);
        maxL = std::max(maxL, L);
        minR = std::min(minR, R);
        maxR = std::max(maxR, R);

        flipflop = !flipflop;
    }

    std::string mode;
    std::cin >> mode;

    if (mode == "Zig-Zag")
        std::cout << minL << ' ' << maxR << '\n';
    else
        std::cout << minR << ' ' << maxL << '\n';

}
