#include <cinttypes>
#include <functional>


template<typename ContainerType, typename ValueType = typename ContainerType::value_type>
const ValueType& RecursiveMax(const ContainerType& container,
size_t n) {

if(n == 2) return container[n-1] >
container[n-2] ? container[n-1] : container[n-2];



const ValueType& lmax =
RecursiveMax(container, n-1);

return container[n-1] > lmax? container[n-1]: lmax;
}
