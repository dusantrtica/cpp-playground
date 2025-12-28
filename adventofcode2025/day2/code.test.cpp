#include "code.hpp"
#include "catch2/catch_test_macros.hpp" // Or "catch.hpp" for the single-header version
#include <fstream>
#include <iostream>
#include <set>
#include <string>

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

   SECTION("sum_invalid_ids_in_ranges case 1") {
    REQUIRE(sum_invalid_ids_in_ranges({{"11", "22"}}) == 33);
   }

   SECTION("sum_invalid_ids_in_ranges case 2") {
    REQUIRE(sum_invalid_ids_in_ranges({{"95", "115"}}) == 99);
   }

   SECTION("sum_invalid_ids_in_ranges case 3") {
    REQUIRE(sum_invalid_ids_in_ranges({{"998", "1020"}}) == 1010);
   }

   SECTION("sum_invalid_ids_in_ranges case 4") {
    REQUIRE(sum_invalid_ids_in_ranges({{"1698522", "1698528"}}) == 0);
   }

   SECTION("assignment input") {
    auto ranges_input = "26803-38596,161-351,37-56,9945663-10044587,350019-413817,5252508299-5252534634,38145069-38162596,1747127-1881019,609816-640411,207466-230638,18904-25781,131637-190261,438347308-438525264,5124157617-5124298820,68670991-68710448,8282798062-8282867198,2942-5251,659813-676399,57-99,5857600742-5857691960,9898925025-9899040061,745821-835116,2056-2782,686588904-686792094,5487438-5622255,325224-347154,352-630,244657-315699,459409-500499,639-918,78943-106934,3260856-3442902,3-20,887467-1022885,975-1863,5897-13354,43667065-43786338";
    std::vector<std::pair<std::string, std::string>> ranges;
    parse_ranges(ranges_input, ranges);
    std::cout << "sum of all invalid ids " << sum_invalid_ids_in_ranges(ranges);
   };

   SECTION("invalid ids part 2 ") {
    std::set<unsigned long> invalid_ids;
    generate_invalid_ids_pt2(10000, invalid_ids);
    std::println("Set contents: {}", invalid_ids);
   }
}
