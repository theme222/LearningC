#include <iostream>

class Thing {
public:
    static int count;
};

int Thing::count = 2;

int main()
{
    std::cout << (++Thing::count << 3) << std::endl;
    std::cout << (23 * 5 % 2 + 1 == 1) << std::endl;
    std::cout << (++Thing::count)++ << std::endl;
}
