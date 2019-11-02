#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

// ASCII only
template <typename T>
struct TrieNode {
  T value_{};  // value
  std::array<TrieNode, 128> children_;

  bool IsEmpty() { return value_ == static_cast<T>(0); }

  TrieNode(T value = static_cast<T>(0),
           const std::array<TrieNode, 128>& children = {})
      : value_{value}, children_{children} {}

};

int main() { using trie_t = TrieNode<char>; }
