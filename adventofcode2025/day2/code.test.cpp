#include "code.hpp"
#include "catch2/catch_test_macros.hpp" // Or "catch.hpp" for the single-header version
#include <fstream>
#include <iostream>

TEST_CASE("Day 2 test case") {
    SECTION("Invalid ID test") {
        REQUIRE(is_invalid_id(1234567890) == false);
    }

    SECTION("Invalid ID test, for 2 digits") {
        REQUIRE(is_invalid_id(22) == true);
        REQUIRE(is_invalid_id(44) == true);
        REQUIRE(is_invalid_id(66) == true);

        REQUIRE(is_invalid_id(23) == false);
        REQUIRE(is_invalid_id(40) == false);
        REQUIRE(is_invalid_id(57) == false);
        REQUIRE(is_invalid_id(74) == false);
        REQUIRE(is_invalid_id(91) == false);
    }

    SECTION("Invalid ID test, for 3 digits") {
        REQUIRE(is_invalid_id(111) == false);
        REQUIRE(is_invalid_id(321) == false);
        REQUIRE(is_invalid_id(543) == false);
    }

    SECTION("Invalid ID test, for 4 digits") {
        REQUIRE(is_invalid_id(1234) == false);
        REQUIRE(is_invalid_id(3210) == false);
        REQUIRE(is_invalid_id(5432) == false);

        REQUIRE(is_invalid_id(1212) == true);
        REQUIRE(is_invalid_id(3030) == true);
        REQUIRE(is_invalid_id(5757) == true);
    }

    SECTION("Invalid ID test, for 5 digits") {
        REQUIRE(is_invalid_id(12345) == false);
        REQUIRE(is_invalid_id(32105) == false);
        REQUIRE(is_invalid_id(54321) == false);   
    }

    SECTION("Invalid ID test, for 6 digits") {
        REQUIRE(is_invalid_id(123456) == false);
        REQUIRE(is_invalid_id(321056) == false);
        REQUIRE(is_invalid_id(543210) == false);

        REQUIRE(is_invalid_id(123123) == true);
        REQUIRE(is_invalid_id(300300) == true);
        REQUIRE(is_invalid_id(577577) == true);
    }
}
