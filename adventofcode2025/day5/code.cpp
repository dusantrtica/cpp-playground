#include "code.hpp"
#include <cstddef>
#include <memory>
#include <utility>

void interval_tree::insert_interval(std::pair<ull, ull> interval) {
    root = insert_element(root, interval);
}

std::shared_ptr<std::pair<ull, ull>> interval_tree::find_interval(ull point) {
    return find_element(root, point);
}

auto make_pair(ull start, ull end) {
    return std::pair<ull, ull>{start, end};
}

int main() {
    interval_tree tree;
    tree.insert_interval(make_pair(3, 5));
    tree.insert_interval(make_pair(10, 14));
    tree.insert_interval(make_pair(16, 20));
    tree.insert_interval(make_pair(12, 18));

    std::cout<<tree.find_interval(10);
}