#pragma once

#include <iostream>
#include "Card.hpp"

using namespace std;

class Deck {
    public:
        Deck();
        //initializes an empty deck

        Card drawTopCard();
        //draws the first card in the deck.
        //Precondition: Deck is not empty
        //Postcondition: returns the card at the end of the vector
        bool addCard(Card c);
        //Adds card c to the deck
        void printDeck();
        //prints the whole deck in an easy to understand format
        bool isEmpty();
        //returns true if deck is empty; else returns false
        Card findHighCard() const;
        //Precondition: Deck is not empty
        //Postcondition: returns the card with the highest rank, using suit as a tiebreaker
        void shuffle();
        //fill deck and shuffle
        void burn();
        //discard top card

    private:
        vector<Card> cards;
};