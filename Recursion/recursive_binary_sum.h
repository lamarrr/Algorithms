
#include <cinttypes>

template <typename ContainerType,
          typename ValueType = typename ContainerType::value_type>
ValueType RecursiveBinarySum(const ContainerType& container, size_t i,
                             size_t n) {
  if (n == 1) return container[i];

  // this forms a binary tree (visual)
  ValueType res = RecursiveBinarySum(container, i, n / 2) +
                  RecursiveBinarySum(container, i + (n / 2), n - (n / 2));
  return res;
}
