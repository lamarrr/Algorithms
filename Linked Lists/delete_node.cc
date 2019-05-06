#include <iostream>
#include "node.h"

// Remove elements containing [data] behind [node]
// Returns new [head] after removal
template <typename T>
BiDirectionalNode<T>* DeleteNode(BiDirectionalNode<T>* head, const T&& needle) {
  if (head->data == needle) return head;

  auto node = head->next;

  while (node != nullptr) {
    if (node->data == needle) {
      // certainly not empty [previous]
      node->previous->next = node->next;
      delete node;
      break;
    }

    node = node->next;
  }

  return head;
}

int main() {
  auto y = new LinkedList<int>{98};

  for (uint8_t i = 0; i < 25; i++) {
    y->PushBack(i);
  }

  PrintList(y);
  DeleteNode(y->head, 15);
  DeleteNode(y->head, 24);

  PrintList(y);
}