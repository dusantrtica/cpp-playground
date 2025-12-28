#include "code.hpp"
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

int largest_end_range_digits(const std::vector<std::pair<std::string, std::string>> &ranges) {
  auto end_ranges = ranges 
  | std::views::transform([](const auto &range) {
                      return range.second.length();
                    });                    

  return std::ranges::max(end_ranges);
}

void generate_invalid_ids(const int number_of_digits,
                          std::vector<std::string> &invalid_ids) {
  int total_number_of_ids = std::pow(10, number_of_digits / 2);
  invalid_ids.reserve(total_number_of_ids);
  for (int i = 1; i < total_number_of_ids; i++) {
    invalid_ids.push_back(std::to_string(i) + std::to_string(i));
  }
}

void parse_ranges(const std::string &input, std::vector<std::pair<std::string, std::string>> &ranges) {
    ranges.clear();
    auto dash_split_view = input 
        | std::views::split(',')
        | std::views::transform([](const auto& range) {
            // Convert comma-split range to string
            std::string item;
            for (auto c : range) item.push_back(c);
            
            // Split by dash and collect parts
            auto dash_split = item
                | std::views::split('-')
                | std::views::transform([](const auto& subrange) {
                    std::string part;
                    for (auto c : subrange) part.push_back(c);
                    return part;
                });
            std::vector<std::string> parts;
            for (auto&& part : dash_split) {
                parts.push_back(std::move(part));
            }
            return parts;
        });

    for (const auto& parts : dash_split_view) {
        if (parts.size() != 2) continue;
        ranges.emplace_back(parts[0], parts[1]);
    }
    return;
}


unsigned long sum_invalid_ids_in_ranges(const std::vector<std::pair<std::string, std::string>> &ranges) {
    auto number_of_digits = largest_end_range_digits(ranges);
    std::vector<std::string> invalid_ids;
    generate_invalid_ids(number_of_digits, invalid_ids);
    auto sum_of_invalid_ids = 0ul;    
    for (const auto& range : ranges) {
        const auto begin = std::stoul(range.first);
        const auto end = std::stoul(range.second);

        for(const auto& invalid_id : invalid_ids) {       
            auto n_invalid_id = std::stoul(invalid_id);     
            if(begin <= n_invalid_id && n_invalid_id <= end) {
                sum_of_invalid_ids += n_invalid_id;
            } 
        }
    }


    return sum_of_invalid_ids;
}