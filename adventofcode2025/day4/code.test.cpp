#include "code.hpp"
#include "catch2/catch_test_macros.hpp" // Or "catch.hpp" for the single-header version
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric> // Required for std::ranges::fold_left
#include <ranges>
#include <set>
#include <string>
#include <string_view>

TEST_CASE("") {
  SECTION("largest number in string 1") {
    std::string input = R"(
..@@.@@@@.
@@@.@.@.@@
@@@@@.@.@@
@.@@@@..@.
@@.@@@@.@@
.@@@@@@@.@
.@.@.@.@@@
@.@@@.@@@@
.@@@@@@@@.
@.@.@@@.@.
    )";
    REQUIRE(number_of_rolls_of_paper(input) == 13);
  }
}
