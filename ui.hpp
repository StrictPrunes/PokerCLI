#pragma once

#include <iostream>
#include "Game.hpp"

using namespace std;

class UI {
    public:
        UI();

        int startScreen() const;
        //Clears terminal window, then displays 1. New game, 2. Continue Last Game, 3. Rules, 4. Exit
        //Continue last game will be unavailable if prevGame is false
        //returns 1, 2, 3, 0
        void rules() const;
        //clears terminal window and displays poker rules
        //exits rule display on input of 1
        void playerCreation();
        //Clears terminal window, ui for player creation. displays current players and input areas for a new player
        void betRound(const Game& gameData);
        //displays current player, current round, community cards, and active bets
        void endScreen(const Game& gameData);
        //Clears terminal window, then displays round statistics
        
        void setPrevGame(bool newVal);
        //sets value of prevGame to newVal
        //used to check if a previous game has been played for the start screen
    private:
        bool prevGame;
};