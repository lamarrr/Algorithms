#include <iostream>

#include "circularly_linked_list.h"

int main() {
  CircularlyLinkedList<int> clist{};
  clist.PushFront(8);
  clist.PushFront(9);
  clist.PushFront(10);

  std::cout << clist.front()->value << ",";
  clist.PopFront();
  std::cout << clist.front()->value << ",";
  clist.PopFront();
  std::cout << clist.front()->value << std::endl;
  clist.PopFront();
}
