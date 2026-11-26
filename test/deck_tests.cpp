#include "catch.hpp"
#include "Deck.hpp"
#include "Card.hpp"

using namespace std;

TEST_CASE("shuffle test"){
    Deck d;
    d.shuffle();
    d.printDeck(cout);
}