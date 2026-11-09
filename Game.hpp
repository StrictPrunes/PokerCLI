#pragma once

#include <iostream>
#include "Player.hpp"
#include "Deck.hpp"
#include <vector>

using namespace std;

class Game {
    public:
        Game();
        
        void addPlayer();
        //add a new player
        void addChips(int chip);
        //adds given chips to pot
        void addCard(Card c);
        //adds card to community cards
        int emptyPot();
        //returns pot and sets it to 0
        void displayCommunityCards(ostream& outs);
        //displays
        void start();
        //deals cards to players, takes small and big blind, sets turn to player after big blind
        void bettingRound();
        //takes bets from players, sets turn to dealer
        void showdown();
        //determines which players has the best hand and awards pot to that player

    private:
        int pot;
        int currentPlayer;
        int currentDealer;
        int currentRound;
        vector<Player> players;
        Deck communityCards;
};