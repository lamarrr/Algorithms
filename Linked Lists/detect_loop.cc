#include <iostream>

using namespace std;

template <typename T>
struct Node {
  using value_type = T;
  T val;
  Node* next{nullptr};
};

template <typename NodeT>
const NodeT* Advance(const NodeT* start, size_t len) {
  while (start != nullptr && len > 0) {
    len--;
    start = start->next;
  }
  return start;
}

template <typename NodeT>
bool HasLoop(const NodeT* slow_it) {
  auto fast_it = slow_it;

  while (true) {
    slow_it = slow_it->next;
    fast_it = fast_it->next;
    if (fast_it == nullptr) break;
    if (slow_it == nullptr) break;

    fast_it = fast_it->next;
    if (fast_it == nullptr) break;

    if (slow_it == fast_it) return true;
  }
  return false;
}

int main() {
  auto node = new Node<int>;
  node->next = new Node<int>;
  node->next->next = new Node<int>;
  node->next->next->next = new Node<int>;
  cout << boolalpha << HasLoop(node) << endl;
  node->next->next->next = node->next->next;
  cout << boolalpha << HasLoop(node) << endl;
}