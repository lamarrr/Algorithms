#include <iostream>
#include <string>


#include "forward_linked_list.h"



int main(){

ForwardLinkedList<std::string>  fl_list{};
using node_t = ForwardLinkedList<std::string>;
std::cout << std::boolalpha << fl_list.Empty() << std::endl;

fl_list.PushFront("Hello");
fl_list.PushFront("World");

std::cout << fl_list.Front() << std::endl;

}
