#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

int startScreen();
//Clears terminal window, then displays 1. New game, 2. Continue Last Game, 3. Rules, 4. Exit
//Continue last game will be unavailable if prevGame is false
//returns 1, 2, 3, 0
void rules();
//Clears terminal window and displays poker rules
//exits rule display on input of 1
Player playerCreation(const vector<Player>& players);
//Clears terminal window, ui for player creation. displays current players and input areas for a new player
int startSelection();

int main(){
    Game game;
    bool prevGame;

    cout << "\33[?1049h"; //enter alternate screen buffer window

    int ins = startSelection();

    while(ins != 0){

        char cont = 'Y';
        
        while(cont == 'Y' || cont == 'y'){
            Player newPlayer = playerCreation(game.getPlayers());
            game.addPlayer(newPlayer);
            cout << "Add another player? (Y/N)";
            cin >> cont;
        }
        
        game.start();
        game.bettingRound();
        game.showdown();

        prevGame = true;

        ins = startSelection();
    }
    
    cout << "\33[?1049h"; //exit alternate screen buffer window
    
    return 0;
}

int startSelection(){
    int ins = 0;

    while(ins != 1 && ins != 2 && ins != 0){
        ins = startScreen(); 

        if (ins == 3) {
            rules();
        } else if(ins != 1 && ins != 2 && ins != 0){               
            cout << "Invalid input: Select 1, 2, 3, or 0";
        }
    }

    return ins;
}