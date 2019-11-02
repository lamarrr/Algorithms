
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include <fmt/format.h>

using namespace std;

template <typename T>
struct Stack : std::stack<int, std::vector<int>> {
  using base_t = std::stack<int, std::vector<int>>;

  Stack(const container_type& container) : base_t{container} {}
  auto begin() { return this->c.begin(); }
  auto end() { return this->c.end(); }
  
};

void Sort(Stack<int>* seq) {
  Stack<int> tmp({1, 2, 3, 4, 5, 6});
  auto print = [&]() {
    std::for_each(tmp.begin(), tmp.end(),
                  [](int value) -> void { fmt::print("{},", value); });
  };
  print();

  fmt::print("\n{}", tmp.top());
  tmp.pop();
  fmt::print("\n{}\n", tmp.top());

  
  print();

  (*seq) = std::move(tmp);
}

int main() {
  Stack<int>::container_type container{};
  Stack<int> stack(container);
  Sort(&stack);
}