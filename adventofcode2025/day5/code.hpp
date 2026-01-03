#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

typedef unsigned long long ull;

class interval_tree {
public:
  interval_tree() {};
  void insert_interval(std::pair<ull, ull> interval);
  std::shared_ptr<std::pair<ull, ull>> find_interval(ull point);

  void print_tree() { print_tree_(this->root); }

private:
  struct element {
    std::pair<ull, ull> interval;
    unsigned long long max;
    std::unique_ptr<element> left = nullptr, right = nullptr;
  };

  std::unique_ptr<element> insert_element(std::unique_ptr<element> &root,
                                          std::pair<ull, ull> interval) {
    if (root == nullptr) {
      root = std::make_unique<interval_tree::element>();
      root->interval = interval;
      root->max = interval.second;
    } else if (interval.first < root->interval.first) {
      root->left = insert_element(root->left, interval);
    } else {
      root->right = insert_element(root->right, interval);
    }

    return std::move(root);
  }

  std::shared_ptr<std::pair<ull, ull>>
  find_element(std::unique_ptr<element> &root, ull point) {
    if (!root) {
      return nullptr;
    }
    if (root->interval.first <= point && point <= root->interval.second) {
      return std::make_shared<std::pair<ull, ull>>(root->interval.first,
                                                   root->interval.second);
    } else if (point < root->interval.first && root->left) {
      return find_element(root->left, point);
    } else {
      return find_element(root->right, point);
    }
  }

  std::unique_ptr<element> root = nullptr;

  // Function to print the tree in a 2D format
  void print_tree_(std::unique_ptr<element>&root, int space = 0, int space_increment = 4) {
    // Base case
    if (root == nullptr)
      return;

    // Increase distance between levels
    space += space_increment;

    // Process right child first
    print_tree_(root->right, space, space_increment);

    // Print current node after space
    std::cout << std::endl;
    for (int i = space_increment; i < space; i++)
      std::cout << " ";
    std::cout << root->interval.first << " " << root->interval.second << "\n";

    // Process left child
    print_tree_(root->left, space, space_increment);
  }
};