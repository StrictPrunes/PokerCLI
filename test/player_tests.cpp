#include "catch.hpp"
#include "Player.hpp"
#include "Card.hpp"

//to compile g++ test/player_tests.cpp src/Player.cpp src/card.cpp src/Deck.cpp tests_main.o -I src -o player_tests

TEST_CASE("highest hand is royal flush"){
    Player test;
    test.addCard(Card(13,1));
    test.addCard(Card(2,3));

    Deck commCards;
    commCards.addCard(Card(12,1));
    commCards.addCard(Card(11,1));
    commCards.addCard(Card(1,1));
    commCards.addCard(Card(10,1));
    commCards.addCard(Card(5,1));

    Deck output = test.highHand(commCards);

    REQUIRE(output.getHandType()[0] == 0);
}

TEST_CASE("duplicate cards high hand test"){
    Player test;
    test.addCard(Card(13,1));
    test.addCard(Card(2,3));

    Deck commCards;
    commCards.addCard(Card(12,1));
    commCards.addCard(Card(10,1));
    commCards.addCard(Card(1,1));
    commCards.addCard(Card(10,1));
    commCards.addCard(Card(5,1));

    Deck output = test.highHand(commCards);

    REQUIRE_FALSE(output.getHandType()[0] == 0);
}