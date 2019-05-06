#include <cassert>
#include <iostream>
#include "node.h"

template <typename T>
void RemoveDuplicates(BiDirectionalNode<T>* node) {
  assert(node != nullptr);

  while (node->next != nullptr) {
    BiDirectionalNode<T>* curr = node->next;
    while (curr != nullptr) {
      auto next = curr->next;
      if (node->data == curr->data) {
        // TODO(lamarrr): check against nullptrs and edge cases
        auto nnext = curr->next;
        auto nprev = curr->previous;

        curr->previous->next = nnext;
        if (curr->next) curr->next->previous = nprev;

        delete curr;
      }
      curr = next;
    }
    node = node->next;
  }
}

int main() {
  LinkedList<int>* list = new LinkedList<int>{8};
  list->PushBack(20);
  list->PushBack(23);
  list->PushBack(23);
  list->PushBack(21);
  list->PushBack(20);
  list->PushBack(22);
  list->PushBack(23);
  list->PushBack(23);
  list->PushBack(5);
  list->PushBack(5);
  list->PushBack(4);
  list->PushBack(5);

  std::cout << list->head->data << std::endl;

  PrintList(list);
  RemoveDuplicates(list->head);
  PrintList(list);
  


  delete list;
}