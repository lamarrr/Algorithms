
#include <iostream>
#include <vector>

#include "recursive_binary_sum.h"

int main() {
  std::vector<int> u{1, 2, 3, 4, 5, 6, 7};
  std::cout << RecursiveBinarySum(u, 0, u.size()) << std::endl;
}