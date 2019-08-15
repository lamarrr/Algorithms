#include <cassert>
#include <cinttypes>

#include "node.h"

template <typename ValueType>
class CircularlyLinkedList;

template <typename ValueType>
class Node<CircularlyLinkedList<ValueType>, ValueType> {
 public:
  using list_type = CircularlyLinkedList<ValueType>;
  using value_type = ValueType;
  using node_type = Node<list_type, ValueType>;

  node_type* next;
  value_type value;
};

template <typename ValueType>
class CircularlyLinkedList {
 public:
  using node_type = Node<CircularlyLinkedList<ValueType>, ValueType>;
  using value_type = typename node_type::value_type;

 private:
  node_type* cursor_;
  node_type* front_;
  node_type* back_;

 public:
  CircularlyLinkedList() : cursor_{nullptr}, front_{nullptr}, back_{nullptr} {}
  CircularlyLinkedList(const CircularlyLinkedList&) = delete;
  CircularlyLinkedList(CircularlyLinkedList&&) = delete;
  CircularlyLinkedList& operator=(const CircularlyLinkedList&&) = delete;
  CircularlyLinkedList& operator=(CircularlyLinkedList&&) = delete;
  ~CircularlyLinkedList() {
    while (front_ != nullptr) {
      node_type* cur = front_;

      front_ = cur->next;
      delete cur;
    }
  }

  node_type* front() { return front_; }
  node_type* back() { return back_; }
  const node_type* front() const { return front_; }
  const node_type* back() const { return back_; }

  bool Empty() { return (front_ == nullptr); }

  // O(1) complexity
  // Pop Back is O(n) complexity
  void PopFront() {
    // normaly to return using std::move, but just for demo purpose and not yet
    // implemented
    assert(!Empty());

    node_type* next = front_->next;

    delete front_;
    // even nullptr
    front_ = next;

    return;
  }

  void PushFront(const value_type& v) {
    node_type* old = front_;
    front_ = new node_type;

    front_->next = old;
    front_->value = v;

    return;
  }
};
