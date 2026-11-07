#include <iostream>
#include "ui.hpp"
#include "Game.hpp"

using namespace std;

int startSelection(const UI& ui);

int main(){
    UI ui;
    Game game;
    
    int ins = startSelection(ui);

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

        ui.setPrevGame(true);

        ins = startSelection(ui);
    }

    return 0;
}

int startSelection(const UI& ui){
    int ins = 0;

    while(ins != 1 && ins != 2 && ins != 0){
        ins = ui.startScreen(); 

        if (ins == 3) {
            ui.rules();
        } else if(ins != 1 && ins != 2 && ins != 0){               
            cout << "Invalid input: Select 1, 2, 3, or 0";
        }
    }

    return ins;
}