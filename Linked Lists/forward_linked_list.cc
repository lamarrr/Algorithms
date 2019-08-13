#include <cinttypes>

template<typename ListType, typename ValueType>
class Node {
};

template<typename ValueType>
class ForwardLinkedList;


template<ValueType>
class Node<ForwardLinkedList<ValueType>> {

public:
using value_type = ValueType;
using list_type = ForwardLinkedList<ValueType>;
using node_t = Node<ForwardLinkedList<ValueType>>;

node_t * next;
value_type value;
node_t(): next{nullptr} 
/* default inititalizable value_t? */
{}
node_t(const node_t&) = delete;
node_t(node_t && rv) = delete;
node_t& operator=(const node_t&) = delete;
node_t& operator=(node_t &&) = delete;

~node_t() = default;
};


template<typename ValueType>
class ForwardLinkedList {

public:
using node_t = Node<ForwardLinkedList<ValueType>>;

ForwardLinkedList(){}


};


int main(){
ForwardLinkedList<char> u;
}
