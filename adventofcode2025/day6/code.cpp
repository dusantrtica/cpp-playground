#include "code.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

ull cephalopod_math(std::vector<std::vector<ull>> &input,
                    std::vector<std::string> &operators) {
  return 0;
};

auto is_space = [](unsigned char c) { return std::isspace(c); };

void trim(std::string &elem) {
  auto trimmed = elem | std::views::drop_while(is_space) | std::views::reverse |
                 std::views::drop_while(is_space) | std::views::reverse;

  elem.assign(trimmed.begin(), trimmed.end());
}

void parse_input(std::string &input, std::vector<std::vector<ull>> &operands,
                 std::vector<char> &operators) {
  
  operators.clear();
  operands.clear();
  
  auto lines_view = input
  | std::views::split('\n')
  | std::views::take(5)
  | std::views::filter([](auto line) { return !line.empty();});

  for (auto &&line : lines_view) {
    std::vector<ull> operands_in_line;
    auto operands_view =
        line        
        | std::views::split(' ')
        | std::views::filter([](auto elem) {
          std::string str_sub = std::ranges::to<std::string>(elem);
          trim(str_sub);
          return !str_sub.empty();
        })    
        | std::views::transform([](auto elem) {            
            auto str_sub = std::ranges::to<std::string>(elem);
            return std::stoull(str_sub);
        });

    for (auto operand : operands_view) {
      operands_in_line.push_back(operand);
    }
    operands.push_back(operands_in_line);
  }

  auto operators_lines_view = input 
  | std::views::reverse
  | std::views::split('\n')
  | std::views::take(2);

  for(auto operator_line_view : operators_lines_view) {
    auto operator_view = operator_line_view
    | std::views::reverse
    | std::views::split(' ')
    | std::views::filter([](auto elem) {
        std::string str_sub = std::ranges::to<std::string>(elem);
        trim(str_sub);
        return !str_sub.empty();
    })
    | std::views::transform([](auto elem) {            
        auto str_sub = std::ranges::to<std::string>(elem);
        return str_sub[0];
    });

    for(auto op : operator_view) {
        std::cout << "operator=" <<op<<'\n';
        operators.push_back(op);
    }
  }
}

int main() {
  std::string input = R"(
123 328  51 64 
 45 64  387 23 
  6 98  215 314
*   +   *   +  
)";

  std::vector<std::vector<ull>> operands;
  std::vector<char> operators;

  //parse_input(input, operands, operators);
  parse_input(input_from_assignment, operands, operators);

  ull total = 0;
  for(auto i = 0; i < operands[0].size(); i++) {
    ull accum = operators[i] == '+' ? 0 : 1;
    for(auto j = 0; j < operands.size(); j++) {
        std::cout << accum << operators[i] << operands[j][i] << std::endl;;
        if(operators[i] == '+') {            
            accum += operands[j][i];
        } else if (operators[i] == '*') {
            accum *= operands[j][i];
        } else {
            std::cout << "Uknown operator:";
        }
    }
    total += accum;
  }

  std::cout << "Total = " << total << std::endl;

  //   std::ifstream input("./in.txt");
  //   if (!input.is_open()) {
  //     std::cerr << "Cannot open file";
  //     return -1;
  //   }

  //   std::string line;
  //   while(std::getline(input, line)) {

  //   }
}