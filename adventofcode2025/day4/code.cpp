#include "code.hpp"
#include <iostream>
#include <string>
#include <assert.h>

void parse_lines(const std::string &input,
                 std::vector<std::vector<char>> &parsed_input) {
  for (const char c : input) {
    if (parsed_input.empty() || c == '\n') {
      parsed_input.emplace_back(std::vector<char>());
      continue;
    }
    parsed_input.back().emplace_back(c);
  }
  parsed_input.pop_back();
}

int number_of_rolls_of_paper(std::vector<std::vector<char>> &input, std::function<void(int, int)> marker) {
  auto is_paper = [](const char c) -> bool { return c == '@'; };

  auto safe_check_is_paper = [&input, &is_paper](int i, int j) -> bool {
    if(i >= 0 && i < input[0].size()) {
        if(j >= 0 && j < input[i].size()) {
            return is_paper(input[i][j]);
        }
    }
    return false;
  };

  auto num_of_rolls_around = [&safe_check_is_paper](int i,
                                                            int j) -> int {
    int rolls_around = 0;
    if (safe_check_is_paper(i - 1, j - 1))
      rolls_around++;
    if (safe_check_is_paper(i - 1, j))
      rolls_around++;
    if (safe_check_is_paper(i - 1, j + 1))
      rolls_around++;
    if (safe_check_is_paper(i, j - 1))
      rolls_around++;
    if (safe_check_is_paper(i, j + 1))
      rolls_around++;
    if (safe_check_is_paper(i + 1, j - 1))
      rolls_around++;
    if (safe_check_is_paper(i + 1, j))
      rolls_around++;
    if (safe_check_is_paper(i + 1, j + 1))
      rolls_around++;

    return rolls_around;
  };

  int accessible_rolls_of_paper = 0;
  for (auto i = 0; i < input[0].size(); i++) {
    for (auto j = 0; j < input[i].size(); j++) {        
      if (is_paper(input[i][j]) && num_of_rolls_around(i, j) < 4) {
        marker(i, j);
        accessible_rolls_of_paper++;
      }
    }
  }
  return accessible_rolls_of_paper;
}

int number_of_rolls_accessible_with_removal(std::vector<std::vector<char>>& input) {
    int total_num_of_rolls = 0;
    while(true){
        std::vector<std::pair<int, int>> accessible_rolls_locations;
        auto num_of_rolls = number_of_rolls_of_paper(input, [&accessible_rolls_locations](int i, int j) {
            accessible_rolls_locations.push_back({i, j});            
        });
        if(!num_of_rolls) {
            break;
        }
        total_num_of_rolls += num_of_rolls;

        assert(num_of_rolls == accessible_rolls_locations.size());
        for(auto elem : accessible_rolls_locations) {            
            input[elem.first][elem.second] = 'x';
        }
    };

    return total_num_of_rolls;
};
