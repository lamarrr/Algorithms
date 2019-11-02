#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <type_traits>
#include <typeinfo>

using namespace std;

template <typename T>
struct Node {
  using value_type = T;
  T val;
  Node* next{nullptr};
};

template <typename NodeT>
const NodeT* FindIntersectionBrute1(const NodeT* it_a, const NodeT* b) {
  while (it_a != nullptr) {
    auto it_b = b;
    while (it_b != nullptr) {
      if (it_a == it_b) return it_a;
      it_b = it_b->next;
    }
    it_a = it_a->next;
  }
  return nullptr;
}

template <typename NodeT>
size_t GetElementCount(const NodeT* head) {
  size_t count = 0;

  while (head != nullptr) {
    count++;
    head = head->next;
  }
  return count;
}

template <typename NodeT>
const NodeT* Advance(const NodeT* start, size_t len) {
  while (start != nullptr && len > 0) {
    len--;
    start = start->next;
  }
  return start;
}

template <typename NodeT>
const NodeT* FindIntersectionBrute2(const NodeT* x, const NodeT* y) {
  if (x == nullptr || y == nullptr) return nullptr;
  auto x_count = GetElementCount(x);
  auto y_count = GetElementCount(y);

  if (x_count > y_count) {
    auto diff = x_count - y_count;
    x = Advance(x, diff);
  }
  {
    auto diff = y_count - x_count;
    y = Advance(y, diff);
  }

  while (x != nullptr && y != nullptr) {
    x = x->next;
    y = y->next;
    if (x == y) return x;
  }
  return nullptr;
}

int main() {
  Node<int> n1;
  n1.next = new Node<int>;
  n1.next->next = new Node<int>;
  n1.next->next->next = new Node<int>;
  n1.next->next->next->next = new Node<int>;

  Node<int> m1;
  m1.next = new Node<int>;
  m1.next->next = new Node<int>;
  m1.next->next->next = new Node<int>;
  m1.next->next->next->next = new Node<int>;

  cout << boolalpha << (FindIntersectionBrute1(&n1, &m1) == nullptr) << endl;
  cout << boolalpha << (FindIntersectionBrute2(&n1, &m1) == nullptr) << endl;

  m1.next->next = n1.next->next;

  cout << (FindIntersectionBrute1(&n1, &m1) == m1.next->next) << endl;
  cout << (FindIntersectionBrute2(&n1, &m1) == m1.next->next) << endl;
}
