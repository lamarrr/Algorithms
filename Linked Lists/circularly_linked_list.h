#include <cinttypes>


template<typename ValueType>
class CircularlyLinkedList;


template<typename ValueType>
class Node<CircularlyLinkedList, ValueType> {

public:
using list_type = CircularlyLinkedList;
using value_type = ValueType;
using node_type = Node<CircularlyLinkedList, ValueType>;

node_type * next;
value_type value;
};


class CircularlyLinkedList {

public:
using node_type = Node<CircularlyLinkedList, ValueType>;
using value_type = node_type::value_type;

private:
node_type * handle_;

public:


};
