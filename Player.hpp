#pragma once

#include <iostream>
#include "Deck.hpp"

using namespace std;

class Player {
    public:
        Player(Deck newHand, string newName, int newChips);
        Player(string newName, int newChips);
        Player();

        Deck highHand(Deck communityCards);
        //returns strongest hand player can make
        void resetHand();
        //removes all cards from hand, sets bet to 0
        int takeBet();
        //return bet amount and takes from players chips
        void AddCard(Card c);
        //adds card to hand if there is room
        void makeBet(int newBet);
        //takes int from chips and adds to bet if there's enough
        void awardChips(int win);
        //adds win to chips
        void displayHand(ostream& outs);
        //outputs players hand
        
        int getBet();
        //returns bet amount
        int getChips();
        //return chips
        string getName();
        bool getActive();

    private:
        Deck hand;
        string name;
        int chips;
        int bet;
        bool active;    
};