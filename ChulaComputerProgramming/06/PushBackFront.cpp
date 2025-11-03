#include <deque>
#include <iostream>

std::deque<int> dq;
int main() {
    int n;
    std::cin >> n;

    bool flip = true;
    std::cin >> n;
    while (n != -1) {
      if (flip) dq.push_back(n);
      else dq.push_front(n);

      flip = ! flip;
      std::cin >> n;
    }

    std::cout << '[' << dq[0];
    for (int i = 1; i < dq.size(); i++)
    {
      std::cout << ' ' << dq[i];
    }
    std::cout << ']';

}
