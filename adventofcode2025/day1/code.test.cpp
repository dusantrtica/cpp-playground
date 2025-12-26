#include "code.hpp"
#include "catch2/catch_test_macros.hpp" // Or "catch.hpp" for the single-header version
#include <fstream>
#include <iostream>

TEST_CASE("Example test case") {
  // Your assertions here
  REQUIRE(1 + 1 == 2);

  SECTION("Password simple test") {
    std::vector<std::string> input = {"L5", "R5", "L5", "L3"};
    REQUIRE(password(input) == 0);
  }

  SECTION("Password test from example") {
    std::vector<std::string> input = {"L68", "L30", "R48", "L5",  "R60",
                                      "L55", "L1",  "L99", "R14", "L82"};
    REQUIRE(password(input) == 3);
  }

  SECTION("Password test from input.txt") {
    std::filesystem::current_path("/Users/dusantrtica/projects/cpp-playground/adventofcode2025/day1");

    std::ifstream file("input.txt");
    std::vector<std::string> input;
    std::string line;

    while (std::getline(file, line)) {
      input.push_back(line);
    }
    
    REQUIRE(password(input) == 1154);
  }

  SECTION("Password with crossing zero test from example") {
    std::vector<std::string> input = {"L68", "L30", "R48", "L5",  "R60",
        "L55", "L1",  "L99", "R14", "L82"};
    REQUIRE(password_with_crossing_zero(input) == 6);
  }

  SECTION("Password with crossing zero test from input.txt") {
    std::filesystem::current_path("/Users/dusantrtica/projects/cpp-playground/adventofcode2025/day1");

    std::ifstream file("input.txt");
    std::vector<std::string> input;
    std::string line;

    while (std::getline(file, line)) {
      input.push_back(line);
    }
    
    REQUIRE(password_with_crossing_zero(input) == 6819);
  }
}
