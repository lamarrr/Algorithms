#include <cinttypes>
#include <cassert>

template<typename ListType, typename ValueType>
class Node {
};

template<typename ValueType>
class ForwardLinkedList;


template<typename ValueType>
class Node<ForwardLinkedList<ValueType>, ValueType> {

public:
using value_type = ValueType;
using list_type = ForwardLinkedList<ValueType>;
using node_t = Node<ForwardLinkedList<ValueType>, ValueType>;

node_t * next;
value_type value;
Node(): next{nullptr} 
/* default inititalizable value_t? */
{}
Node(const Node<list_type,ValueType>&) = delete;
Node(Node<list_type,ValueType> && rv) = delete;
Node& operator=(const Node<list_type,ValueType>&) = delete;
Node& operator=(Node<list_type,ValueType> &&) = delete;

~Node() = default;
};


template<typename ValueType>
class ForwardLinkedList {
public:
using node_type = Node<ForwardLinkedList<ValueType>, ValueType>;
using value_type = typename node_type::value_type;

private:
node_type * head_;

public:
ForwardLinkedList(): head_{nullptr} {}

inline bool Empty() const noexcept {
return head_ == nullptr;
}

inline const value_type& Front() const noexcept {
assert(!Empty());
return head_->value;
}

inline value_type& Front() {
assert(!Empty());
return head_->value;
}

// O(1) complexity
inline void PushFront(const value_type & v) noexcept {
node_type * curr = new node_type{};

curr->value = v;
curr->next = head_;
head_ = curr;
}

};


