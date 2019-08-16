
#include <cinttypes>

// inplace
// tail recursion
// complexity: O(n/2) => O(n)
// moving until partition point is reached?
template <typename ContainerType,
          typename ValueType = typename ContainerType::value_type>
void RecursiveReverse(ContainerType* container, size_t i, size_t j) {
  if (i < j
      // edge cases: i!=j - we are not swapping the same partition point
      //  i > j , we just crossed the partition point
  ) {
    std::swap(container->operator[](i), container->operator[](j));
    RecursiveReverse(container, i + 1, j - 1);
  }
}
