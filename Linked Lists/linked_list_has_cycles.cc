#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <vector>

template <typename T>
struct Node {
  Node* next_;
  T value_;
};

using node_t = Node<int>;
bool HasCycle(node_t* root) {
  std::vector<node_t*> nodes;
  while (root != nullptr) {
    if (std::find(nodes.begin(), nodes.end(), root) != nodes.end()) return true;
    nodes.push_back(root);
    root = root->next_;
  }
  return false;
}

enum Status { kError = -1, kOk = 0 };

int main() {
  // intentional memory leak
  node_t* root_a = new node_t;
  root_a->value_ = 10;
  root_a->next_ = new node_t;
  root_a->next_->next_ = root_a;

  node_t* root_b = new node_t;
  root_b->value_ = 10;
  root_b->next_ = new node_t;
  root_b->next_->next_ = nullptr;

  std::cout << std::boolalpha << "root_a: " << HasCycle(root_a) << "\n"
            << "root_b: " << HasCycle(root_b) << std::endl;
  return kOk;
}
