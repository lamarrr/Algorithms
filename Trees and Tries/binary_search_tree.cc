#include <algorithm>
#include <iostream>


template <typename T>
struct BSTNode {
  T value_{};       // value
  BSTNode* left_;   // less than
  BSTNode* right_;  // greater than

  BSTNode(T value = {}, BSTNode* left = nullptr, BSTNode* right = nullptr)
      : value_{value}, left_{left}, right_{right} {}

  BSTNode* Find(T value) {
    if (value_ == value) {
      return this;
    } else if (value > value_ && right_ != nullptr) {
      return right_->Find(value);
    } else if (value <= value_ && left_ != nullptr) {
      return left_->Find(value);
    }

    return nullptr;
  }

  void Insert(T value) { auto node = new BSTNode;
  
  
   }

  // bool IsPresent(T value) {}
};

int main() {
  auto root = new BSTNode<int>{8};
  root->left_ = new BSTNode<int>{6};
  root->right_ = new BSTNode<int>{10};
  root->right_->right_ = new BSTNode<int>{11};

  std::cout << (root->Find(11) == root->right_->right_) << std::endl;
}

