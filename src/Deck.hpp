#pragma once

#include <iostream>
#include "Card.hpp"
#include <array>

using namespace std;

class Deck {
    public:
        Deck();
        //initializes an empty deck
        Deck(vector<Card> c, array<int,3> handType);

        Card drawTopCard();
        //draws the first card in the deck.
        //Precondition: Deck is not empty
        //Postcondition: returns the card at the end of the vector
        void addCard(Card c);
        //Adds card c to the deck
        void printDeck(ostream& outs);
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

        vector<Card> getCards() const;
        void setHandType(array<int,3> newVal);
        array<int,3> getHandType();

    private:
        vector<Card> cards;
        int numCards;
        array<int,3> handType; //first element is hand index (straight flush is 0), second is rank tiebreaker, third is secondary tiebreaker
};