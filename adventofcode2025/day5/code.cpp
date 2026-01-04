#include "code.hpp"
#include <charconv>
#include <cstddef>
#include <fstream>
#include <memory>
#include <numeric>
#include <ranges>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <utility>

void interval_tree::insert_interval(std::pair<ull, ull> interval) {
  root = insert_element(root, interval);
}

std::shared_ptr<std::pair<ull, ull>> interval_tree::find_interval(ull point) {
  return find_element(root, point);
}

auto make_pair(ull start, ull end) { return std::pair<ull, ull>{start, end}; }
auto make_pair(std::string start, std::string end) {
  return make_pair(std::stoull(start), std::stoull(end));
}

void print_interval(std::pair<ull, ull> interval) {
  std::cout << interval.first << " " << interval.second << std::endl;
}

std::vector<std::pair<ull, ull>>
merge_intervals(std::vector<std::pair<ull, ull>> &intervals) {
  std::sort(intervals.begin(), intervals.end());

  std::vector<std::pair<ull, ull>> merged_intervals;

  for (auto interval : intervals) {
    if (merged_intervals.empty()) {
      merged_intervals.push_back(interval);
      continue;
    }
    auto lastly_added_interval = merged_intervals.back();
    if (lastly_added_interval.second >= interval.first) {
      merged_intervals.back().second =
          std::max(interval.second, lastly_added_interval.second);
    } else {
      merged_intervals.push_back(interval);
    }
  }

  return merged_intervals;
}

ull count_fresh_ingredients(std::vector<std::pair<ull, ull>> merged_intervals) {
    unsigned long long num_fresh_ingredients = 0;
    for(auto interval : merged_intervals) {
        ull diff = interval.second - interval.first;
        num_fresh_ingredients += diff + 1;
        std::cout << "num of fresh ingredients is " << num_fresh_ingredients << std::endl;
    }

    return num_fresh_ingredients;
}

int count_fresh_ingredients_from_test_file() {
  std::ifstream input("./in.txt");
  if (!input.is_open()) {
    std::cerr << "Cannot open file";
    return -1;
  }

  interval_tree tree;
  std::string line;
  std::vector<std::pair<ull, ull>> backup_intervals;

  while (std::getline(input, line)) {
    if (line == "") {
      break;
    }

    int pos = line.find('-');

    backup_intervals.push_back(
        make_pair(line.substr(0, pos), line.substr(pos + 1)));
    tree.insert_interval(make_pair(line.substr(0, pos), line.substr(pos + 1)));
  }

  int fresh_ingredients = 0;
  // Query the tree
  while (std::getline(input, line)) {
    auto interval = tree.find_interval(std::stoull(line));
    if (interval) {
      fresh_ingredients++;
    } else {
      ull num_val = std::stoull(line);

      for (auto intrvl : backup_intervals) {
        if (intrvl.first <= num_val && num_val <= intrvl.second) {
          std::cout << line << " found by brute force in ";
          print_interval(intrvl);
          fresh_ingredients++;
        }
      }
    }
  }

  std::cout << "total fresh = " << count_fresh_ingredients(merge_intervals(backup_intervals));
  return fresh_ingredients;
}

void sanity_tests() {
  interval_tree tree;
  tree.insert_interval(make_pair(3, 5));
  tree.insert_interval(make_pair(10, 14));
  tree.insert_interval(make_pair(16, 20));
  tree.insert_interval(make_pair(12, 18));

  std::cout << tree.find_interval(1) << std::endl;
  std::cout << tree.find_interval(5) << std::endl;
  std::cout << tree.find_interval(8) << std::endl;
  std::cout << tree.find_interval(11) << std::endl;
  std::cout << tree.find_interval(17) << std::endl;
  std::cout << tree.find_interval(32) << std::endl;

  std::vector<std::pair<ull, ull>> intervals = {
    make_pair(3, 5),
    make_pair(10, 14),
    make_pair(16, 20),
    make_pair(12, 18)
  };

  std::cout<<count_fresh_ingredients(merge_intervals(intervals));
}

int main() {
    sanity_tests();
    std::cout << count_fresh_ingredients_from_test_file() << std::endl;
}