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

    vector<Card> expCards = {Card(1,1), Card(13,1), Card(12,1), Card(11,1), Card(10,1)};
    array<int,3> expHandType = {0,-1,-1};

    REQUIRE(output.getHandType() == expHandType);
    REQUIRE(output.getCards() == expCards);
}

TEST_CASE("highest hand is straight flush"){
    Player test;
    test.addCard(Card(13,1));
    test.addCard(Card(2,3));

    Deck commCards;
    commCards.addCard(Card(12,1));
    commCards.addCard(Card(11,1));
    commCards.addCard(Card(9,1));
    commCards.addCard(Card(10,1));
    commCards.addCard(Card(5,1));

    Deck output = test.highHand(commCards);

    vector<Card> expCards = {Card(13,1), Card(12,1), Card(11,1), Card(10,1), Card(9,1)};
    array<int,3> expHandType = {1,13};

    REQUIRE(output.getHandType() == expHandType);
    REQUIRE(output.getCards() == expCards);
}

TEST_CASE("highest hand is four of a kind"){
    Player test;
    test.addCard(Card(13,1));
    test.addCard(Card(2,3));

    Deck commCards;
    commCards.addCard(Card(13,3));
    commCards.addCard(Card(11,1));
    commCards.addCard(Card(9,1));
    commCards.addCard(Card(13,2));
    commCards.addCard(Card(13,0));

    Deck output = test.highHand(commCards);

    vector<Card> expCards = {Card(13,3), Card(13,2), Card(13,1), Card(13,0), Card(11,1)};
    array<int,3> expHandType = {2,-1,-1};

    REQUIRE(output.getHandType() == expHandType);
    REQUIRE(output.getCards() == expCards);
}

TEST_CASE("highest hand is full house"){
    Player test;
    test.addCard(Card(13,1));
    test.addCard(Card(2,3));

    Deck commCards;
    commCards.addCard(Card(13,3));
    commCards.addCard(Card(11,1));
    commCards.addCard(Card(9,1));
    commCards.addCard(Card(13,2));
    commCards.addCard(Card(9,0));

    Deck output = test.highHand(commCards);

    vector<Card> expCards = {Card(13,3), Card(13,2), Card(13,1), Card(9,1), Card(9,0)};
    array<int,3> expHandType = {3, 13, 9};

    REQUIRE(output.getHandType() == expHandType);
    REQUIRE(output.getCards() == expCards);
}

TEST_CASE("highest hand is flush"){
    Player test;
    test.addCard(Card(13,2));
    test.addCard(Card(2,2));

    Deck commCards;
    commCards.addCard(Card(10,2));
    commCards.addCard(Card(11,1));
    commCards.addCard(Card(9,1));
    commCards.addCard(Card(1,2));
    commCards.addCard(Card(3,2));

    Deck output = test.highHand(commCards);

    vector<Card> expCards = {Card(1,2), Card(13,2), Card(10,2), Card(3,2), Card(2,2)};
    array<int,3> expHandType = {4, 1, 13};

    REQUIRE(output.getHandType() == expHandType);
    REQUIRE(output.getCards() == expCards);
}

TEST_CASE("highest hand is straight"){
    Player test;
    test.addCard(Card(9,2));
    test.addCard(Card(2,2));

    Deck commCards;
    commCards.addCard(Card(7,3));
    commCards.addCard(Card(8,1));
    commCards.addCard(Card(6,1));
    commCards.addCard(Card(5,0));
    commCards.addCard(Card(3,2));

    Deck output = test.highHand(commCards);

    vector<Card> expCards = {Card(9,2), Card(8,1), Card(7,3), Card(6,1), Card(5,0)};
    array<int,3> expHandType = {5, 9};

    REQUIRE(output.getHandType() == expHandType);
    REQUIRE(output.getCards() == expCards);
}

TEST_CASE("ace low straight"){
    Player test;
    test.addCard(Card(5,2));
    test.addCard(Card(2,2));

    Deck commCards;
    commCards.addCard(Card(13,3));
    commCards.addCard(Card(4,1));
    commCards.addCard(Card(10,1));
    commCards.addCard(Card(1,0));
    commCards.addCard(Card(3,2));

    Deck output = test.highHand(commCards);

    vector<Card> expCards = {Card(5,2), Card(4,1), Card(3,2), Card(2,2), Card(1,0)};
    array<int,3> expHandType = {5, 5};

    
    REQUIRE(output.getHandType() == expHandType);
    REQUIRE(output.getCards() == expCards);
}

TEST_CASE("highest hand is three of a kind"){
    Player test;
    test.addCard(Card(4,2));
    test.addCard(Card(2,2));

    Deck commCards;
    commCards.addCard(Card(7,3));
    commCards.addCard(Card(4,1));
    commCards.addCard(Card(1,1));
    commCards.addCard(Card(4,0));
    commCards.addCard(Card(3,2));

    Deck output = test.highHand(commCards);

    vector<Card> expCards = {Card(4,2), Card(4,1), Card(4,0), Card(1,1), Card(7,3)};
    array<int,3> expHandType = {6, 4};

    REQUIRE(output.getHandType() == expHandType);
    REQUIRE(output.getCards() == expCards);
}

TEST_CASE("highest hand is two pair"){
    Player test;
    test.addCard(Card(4,2));
    test.addCard(Card(2,2));

    Deck commCards;
    commCards.addCard(Card(7,3));
    commCards.addCard(Card(4,1));
    commCards.addCard(Card(1,1));
    commCards.addCard(Card(7,0));
    commCards.addCard(Card(3,2));

    Deck output = test.highHand(commCards);

    vector<Card> expCards = {Card(7,3), Card(7,0), Card(4,2), Card(4,1), Card(1,1)};
    array<int,3> expHandType = {7, 7, 4};

    REQUIRE(output.getHandType() == expHandType);
    REQUIRE(output.getCards() == expCards);
}

TEST_CASE("highest hand is pair"){
    Player test;
    test.addCard(Card(4,2));
    test.addCard(Card(2,2));

    Deck commCards;
    commCards.addCard(Card(13,3));
    commCards.addCard(Card(4,1));
    commCards.addCard(Card(1,1));
    commCards.addCard(Card(7,0));
    commCards.addCard(Card(3,2));

    Deck output = test.highHand(commCards);

    vector<Card> expCards = {Card(4,2), Card(4,1), Card(1,1), Card(13,3), Card(7,0)};
    array<int,3> expHandType = {8, 4, 1};

    REQUIRE(output.getHandType() == expHandType);
    REQUIRE(output.getCards() == expCards);
}

TEST_CASE("highest hand is high card"){
    Player test;
    test.addCard(Card(5,2));
    test.addCard(Card(2,2));

    Deck commCards;
    commCards.addCard(Card(13,3));
    commCards.addCard(Card(4,1));
    commCards.addCard(Card(9,1));
    commCards.addCard(Card(8,0));
    commCards.addCard(Card(3,2));

    Deck output = test.highHand(commCards);

    vector<Card> expCards = {Card(13,3), Card(9,1), Card(8,0), Card(5,2), Card(4,1)};
    array<int,3> expHandType = {9, 13, 9};

    REQUIRE(output.getCards() == expCards);
    REQUIRE(output.getHandType() == expHandType);
}