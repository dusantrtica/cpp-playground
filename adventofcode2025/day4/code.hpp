#ifndef __DAY4_CODE_HPP__
#define __DAY4_CODE_HPP__

#include <string>
#include <vector>
#include <functional>

void parse_lines(const std::string& input, std::vector<std::vector<char>>& parsed_input);
int number_of_rolls_of_paper(std::vector<std::vector<char>>& input, std::function<void(int, int)> marker = [](int a, int b){});
int number_of_rolls_accessible_with_removal(std::vector<std::vector<char>>& input);
#endif
