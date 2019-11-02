#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node {
  vector<Node*> children;
  T value;
};

int main();

template <typename ValueT, typename NodeAllocatorT = allocator<Node<ValueT>>,
          typename VectorAllocatorT = allocator<Node<ValueT>*>>
struct Graph {
  using vector_allocator_type = VectorAllocatorT;
  using node_type = Node<ValueT>;
  using node_allocator_type = NodeAllocatorT;

  Graph() : node_allocator_{}, nodes_{vector_allocator_type{}} {}

  ~Graph() noexcept {
    for (auto node : nodes_) {
      node_allocator_.deallocate(node, 1);
    }
  }

  friend int main();

 protected:
  node_allocator_type node_allocator_;
  vector<node_type*, vector_allocator_type> nodes_;
};

int main() {
  Graph<int> graph;
  auto& alloca = graph.node_allocator_;
  graph.nodes_.push_back(alloca.allocate(1));
  (graph.nodes_[0]->children).push_back(nullptr);
}