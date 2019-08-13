#include <cinttypes>

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

ForwardLinkedList(){}


};


