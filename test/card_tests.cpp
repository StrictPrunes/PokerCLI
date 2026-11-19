#include "catch.hpp"
#include "Card.hpp"

TEST_CASE("isFaceCard with non face card"){
    Card test(1,0);

    REQUIRE(test.isFaceCard() == false);
}

TEST_CASE("isFaceCard with face card"){
    Card test(11,0);
    Card test2(12,1);
    Card test3(13,2);

    REQUIRE(test.isFaceCard() == true);
    REQUIRE(test2.isFaceCard() == true);
    REQUIRE(test3.isFaceCard() == true);
}

TEST_CASE("insertion operator with invalid input"){

}