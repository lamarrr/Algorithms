#include <iostream>
#include <vector>

#include "recursive_reverse.h"

int main() {
  std::vector<int> u{1, 2, 3, 4, 5, 6, 7};

  RecursiveReverse(&u, 0, u.size() - 1);

  for (auto v : u) std::cout << v;

  std::cout << std::endl;
}