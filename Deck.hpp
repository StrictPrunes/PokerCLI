#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "card.hpp"

using namespace std;

struct Node  {  
    Card card;  
    Node* next;  
}; 

class Deck {
    public:
    Deck();
    //initializes an empty deck

    Card drawTopCard();
    //draws the first card in the deck. Deck is a stack following LIFO.
    
    //Precondition: Deck is not empty
    //Postcondition: returns the card at the head of the deck
    bool addCard(Card c);
    //Adds card c to the head of the deck
    void printDeck();
    //prints the whole deck in an easy to understand format
    bool isEmpty();
    //returns true if deck is empty; else returns false
    Card findHighCard() const;
    //Precondition: Deck is not empty
    //Postcondition: returns the card with the highest rank, using suit as a tiebreaker

    void shuffle();
    //fill deck and shuffle
    Card draw();
    //return top card and discard it from deck
    void burn();
    //discard top card


    private:
        vector<Card> cards;
};

#endif //DECK_H