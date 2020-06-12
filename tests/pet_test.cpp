#include <pet/dog.hpp>
#include <catch.hpp>


TEST_CASE("The dog barks 3 times", "[barks-3]")
{
    Dog dog{};
    REQUIRE(dog.go(3) == "woof! woof! woof! ");
}

