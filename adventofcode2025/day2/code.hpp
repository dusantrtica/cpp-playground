#ifndef __DAY2_CODE_HPP__
#define __DAY2_CODE_HPP__

#include <string>
#include <vector>

int largest_end_range_digits(const std::vector<std::pair<std::string, std::string>>& ranges);
void generate_invalid_ids(const int number_of_digits, std::vector<std::string>& invalid_ids);
void parse_ranges(const std::string& input, std::vector<std::pair<std::string, std::string>>& ranges);
unsigned long sum_invalid_ids_in_ranges(const std::vector<std::pair<std::string, std::string>> &ranges);
#endif
