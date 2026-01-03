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

private:
  struct element {
    std::pair<ull, ull> interval;
    unsigned long long max;
    std::unique_ptr<element> left = nullptr, right = nullptr;
  };

  std::unique_ptr<element> insert_element(std::unique_ptr<element>& root,
                                          std::pair<ull, ull> interval) {
    if (root == nullptr) {
      root = std::make_unique<interval_tree::element>();
      root->interval = interval;
      root->max = interval.second;
    } else if (interval.first <= root->interval.first) {
        root->left = insert_element(root->left, interval);
    } else {
        root->right = insert_element(root->right, interval);
    }

    return std::move(root);
  }

  std::shared_ptr<std::pair<ull, ull>> find_element(std::unique_ptr<element>& root, ull point) {
    if(!root) {
        return nullptr;
    }
    if(root->interval.first <= point && point <= root->interval.second) {
        return std::make_shared<std::pair<ull, ull>>(root->interval.first, root->interval.second);
    } else if (point < root->interval.first) {
        return find_element(root->left, point);
    } else {
        return find_element(root->right, point);
    }
  }

  std::unique_ptr<element> root = nullptr;
};