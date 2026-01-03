#include "code.hpp"
#include <cstddef>
#include <fstream>
#include <memory>
#include <numeric>
#include <ranges>
#include <string>
#include <utility>
#include <charconv>
#include <vector>

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

    backup_intervals.push_back(make_pair(line.substr(0, pos), line.substr(pos+1)));
    tree.insert_interval(make_pair(line.substr(0, pos), line.substr(pos+1)));
  }


  int fresh_ingredients = 0;
  // Query the tree
  while (std::getline(input, line)) {
    auto interval = tree.find_interval(std::stoull(line));
    if(interval) {
        fresh_ingredients++;
    } else {        
        ull num_val = std::stoull(line);

        for(auto intrvl : backup_intervals) {
            if(intrvl.first <= num_val && num_val <= intrvl.second) {
                std::cout << line << " found by brute force in ";
                print_interval(intrvl);
                fresh_ingredients++;
            }   
        }
    }
  }

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
}

int main() { std::cout << count_fresh_ingredients_from_test_file() << std::endl; }