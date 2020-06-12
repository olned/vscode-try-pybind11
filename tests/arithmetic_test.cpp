#include <arithmetic.hpp>
#include <catch.hpp>


TEST_CASE("2 + 3 == 5", "[add]")
{
    REQUIRE(add(2, 3) == 5);
}


TEST_CASE("5 - 3 == 2", "[subtrac]")
{
    REQUIRE(subtrac(5, 3) == 2);
}
