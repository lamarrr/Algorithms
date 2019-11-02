#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

template <typename ContainerT>
void BubbleSort(ContainerT& container) {
  assert(container.size() > 1);
  bool is_sorted = false;
  while (!is_sorted) {
    is_sorted = true;
    for (auto left = container.begin(), right = container.begin() + 1;
         right < container.end(); left++, right++) {
      if (*left > *right) {
        is_sorted = false;
        std::swap(*left, *right);
      }
    }
  }
}

int main(int argc, char** argv) {
  std::vector<int> vec{6, 7, 8, 3, 4, 2, 1, 9, 10};

  BubbleSort(vec);
  for (auto i : vec) {
    std::cout << i << std::endl;
  }
}
