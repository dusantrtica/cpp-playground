#include "code.hpp"
#include "catch2/catch_test_macros.hpp" // Or "catch.hpp" for the single-header version
#include <fstream>
#include <iostream>

TEST_CASE("Day 2 test case") {
   SECTION("Largest end range digits test") {
    std::vector<std::pair<std::string, std::string>> ranges = {{"123", "12345"}, {"1234", "123456"}};
    REQUIRE(largest_end_range_digits(ranges) == 6);
   }

   SECTION("generate invalid ids test") {
    std::vector<std::string> invalid_ids;
    generate_invalid_ids(2, invalid_ids);
    REQUIRE(invalid_ids == std::vector<std::string>{"11", "22", "33", "44", "55", "66", "77", "88", "99"});
   }

   SECTION("parse ranges test") {
    std::vector<std::pair<std::string, std::string>> expected_ranges = {{"123", "12345"}, {"1234", "123456"}};
    std::vector<std::pair<std::string, std::string>> ranges;
    parse_ranges("123-12345,1234-123456", ranges);
    REQUIRE(ranges == expected_ranges);
   }
}
