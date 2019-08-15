#include <iostream>

#include "circularly_linked_list.h"

int main() {
  CircularlyLinkedList<int> clist{};
  clist.PushFront(3);
  clist.PushFront(2);
  clist.PushFront(1);

  std::cout << clist.front()->value << ",";
  clist.PopFront();
  std::cout << clist.front()->value << ",";
  clist.PopFront();
  std::cout << clist.front()->value << std::endl;
  clist.PopFront();
  // empty

  clist.PushFront(3);
  clist.PushFront(2);
  clist.PushFront(1);

  std::cout << "Cloning" << std::endl;
  CircularlyLinkedList<int> tclist = clist.ReverseClone();
  std::cout << "Cloned" << std::endl;

  std::cout << tclist.front()->value << ",";
  tclist.PopFront();

  std::cout << tclist.front()->value << ",";
  tclist.PopFront();
  std::cout << tclist.front()->value << std::endl;
  tclist.PopFront();
}
