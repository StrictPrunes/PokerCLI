#pragma once

#include <iostream>

using namespace std;

class Card{
    public:
        Card(int newRank,int newSuit);
        //initializes the object with rank = newRank and suit = newSuit
        Card();
        //initializes the object with rank = 1 and suit = 0
        
        friend ostream& operator<<(ostream& outs, const Card& card1);
        //overloads the extraction operator to output the name of the card in the form Rank of Suit
        friend istream& operator>>(istream& ins, Card& card1);
        //overloads the insertion operator to accept input in the form Rank of Suit. 
        //sets rank and suit to corresponding integer values
        friend bool operator<(const Card& card1, const Card& card2);
        //overloads the less than operator to compare two cards. Compares rank first, then suit.
        //returns true if card 1 is less than card2.
        friend bool operator>(const Card& card1, const Card& card2);
        //overloads the greater than operator to compare two cards. Compares rank first, then suit.
        //returns true if card1 is greater than card2
        friend bool operator==(const Card& card1, const Card& card2);
        //overloads the equal to operator to compare two cards. 
        //returns true if card1 rank and suit are equal to card2 rank and suit

        bool isFaceCard();                          
        //returns true if card is a jack, queen, or king
        bool isValid();                             
        //returns true if rank is between 1 and 13 and suit is between 0 and 3
    private:
        int rank;
        int suit;
};