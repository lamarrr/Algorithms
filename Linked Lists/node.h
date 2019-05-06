#include <cinttypes>
#include <iostream>

template <typename T>
struct BiDirectionalNode;

template <typename T, typename NodeType>
struct LinkedList;

template <typename T>
struct BiDirectionalNode {
  BiDirectionalNode* previous{nullptr};
  BiDirectionalNode* next{nullptr};
  T data;

  BiDirectionalNode() : previous{nullptr}, next{nullptr}, data{} {}

  // Not implemented Yet, can cause problems when not deleted
  BiDirectionalNode(const BiDirectionalNode& node) = delete;
  BiDirectionalNode(BiDirectionalNode&&) = delete;
  BiDirectionalNode& operator=(const BiDirectionalNode&) = delete;
  BiDirectionalNode& operator=(BiDirectionalNode&&) = delete;
  // Purely pointer

  friend class LinkedList<T, BiDirectionalNode<T>>;

 private:
  // Push elements to last linked Node
  void PushBack(const T&& value) {
    BiDirectionalNode* i = this;
    while (i->next != nullptr) {
      i = i->next;
    }
    BiDirectionalNode* n = new BiDirectionalNode{};
    i->next = n;
    n->previous = i;
    n->data = value;
  }

  // Push elements to last linked Node
  void PushFront(const T&& value) {
    BiDirectionalNode* i = previous;
    while (i != nullptr) {
      i = i->previous;
    }
    BiDirectionalNode* n = new BiDirectionalNode{};
    i->previous = n;
    n->data = value;
    n->next = i;
  }

  // Pop all elements at back of Node
  void PopBack() {
    BiDirectionalNode* curr = next;

    while (curr != nullptr) {
      auto inext = curr->next;
      delete curr;
      curr = inext;
    }
    next = nullptr;
  }
  void PopFront() {
    BiDirectionalNode* curr = previous;

    while (curr != nullptr) {
      auto inext = curr->previous;
      delete curr;
      curr = inext;
    }
    previous = nullptr;
  }
};

template <typename T, typename NodeType = BiDirectionalNode<T>>
struct LinkedList {};

#include <utility>
// Memory Manager
template <typename T>
struct LinkedList<T, BiDirectionalNode<T>> {
  using node_t = BiDirectionalNode<T>;

  node_t* head{nullptr};

  LinkedList(const T&& data) {
    head = new BiDirectionalNode<T>{};
    head->data = data;
  }

  void PushBack(const T&& data) { head->PushBack(std::forward<const T>(data)); }
  void PushFront(const T&& data) {
    head->PushFront(data);
    head = head->previous;
  }
  void PopBack() { head->PopBack(); }
};

template <typename T>
void PrintList(LinkedList<T>* l) {
  auto node = l->head;
  while (node != nullptr) {
    std::cout << node->data << ", ";
    node = node->next;
  }
  std::cout << std::endl;
}