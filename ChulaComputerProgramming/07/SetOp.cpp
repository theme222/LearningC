#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

int main() {
  std::string input;

  std::set<int> finalUnion;
  std::set<int> finalIntersect;
  std::set<int> finalDiff;

  bool isFirst = true;

  while (std::getline(std::cin, input)) {
    std::stringstream line(input);
    std::set<int> currSet;
    int num;

    // Input
    while (line >> num)
      currSet.insert(num);

    if (isFirst) {
      isFirst = false;
      finalUnion = currSet;
      finalIntersect = currSet;
      finalDiff = currSet;
      continue;
    }

    // Union
    for (auto n : currSet)
      finalUnion.insert(n);

    std::vector<int> toDelete;

    // Intersect
    for (auto n : finalIntersect)
      if (currSet.count(n) == 0)
          toDelete.push_back(n);

    for (auto n: toDelete)
        finalIntersect.erase(n);

    // Diff
    toDelete.clear();
    for (auto n : currSet)
      if (finalDiff.count(n) == 1)
        toDelete.push_back(n);

    for (auto n: toDelete)
        finalDiff.erase(n);
  }

  // Output
  std::cout << "U:";
  if (finalUnion.empty())
    std::cout << " empty set";
  else
    for (auto n : finalUnion)
      std::cout << " " << n;
  puts("");

  std::cout << "I:";
  if (finalIntersect.empty())
    std::cout << " empty set";
  else
    for (auto n : finalIntersect)
      std::cout << " " << n;
  puts("");

  std::cout << "D:";
  if (finalDiff.empty())
    std::cout << " empty set";
  else
    for (auto n : finalDiff)
      std::cout << " " << n;
  puts("");
}
