#pragma once

#include <iostream>
#include "Deck.hpp"

using namespace std;

class Player {
    public:
        Player(Deck newHand, string newName, int newChips);
        Player(string newName, int newChips);
        Player();

        Deck highHand(const Deck& communityCards);
        //returns strongest hand player can make
        void resetHand();
        //removes all cards from hand, sets bet to 0
        int takeBet();
        //return bet amount and takes from players chips
        void addCard(Card c);
        //adds card to hand if there is room
        void makeBet(int newBet);
        //takes int from chips and adds to bet if there's enough
        void awardChips(int win);
        //adds win to chips
        void displayHand(ostream& outs);
        //outputs players hand
        void setActive(bool newVal);
        //sets active to newVal

        int getBet();
        //returns bet amount
        int getChips();
        //return chips
        string getName();
        //returns player name
        bool getActive();
        //returns true if player is active

    private:
        Deck hand;
        string name;
        int chips;
        int bet;
        bool active;    
};