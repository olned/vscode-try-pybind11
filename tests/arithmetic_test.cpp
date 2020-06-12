#include <arithmetic.hpp>
#include <catch.hpp>


TEST_CASE("2 + 3 == 5", "[add]")
{
    REQUIRE(add(2, 3) == 5);
}
