#include <iostream>
#include "ui.hpp"
#include "Game.hpp"

using namespace std;

int startSelection(const UI& ui);

int main(){
    Game game;
    
    cout << "\33[?1049h"; //enter alternate screen buffer window

    int ins = startSelection();

    while(ins != 0){

        char cont = 'Y';
        
        while(cont == 'Y' || cont == 'y'){
            game.addPlayer();
            cout << "Add another player? (Y/N)";
            cin >> cont;
        }
        
        game.start();
        game.bettingRound();
        game.showdown();

        UI::setPrevGame(true);

        ins = startSelection();
    }
    
    cout << "\33[?1049h"; //exit alternate screen buffer window
    
    return 0;
}

int startSelection(){
    int ins = 0;

    while(ins != 1 && ins != 2 && ins != 0){
        ins = UI::startScreen(); 

        if (ins == 3) {
            UI::rules();
        } else if(ins != 1 && ins != 2 && ins != 0){               
            cout << "Invalid input: Select 1, 2, 3, or 0";
        }
    }

    return ins;
}