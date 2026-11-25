#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include <iomanip>
#include <limits>

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
void topBanner(string page);

int main(){
    Game game;
    bool prevGame;

    cout << "\33[?1049h"; //enter alternate screen buffer window

    int ins = startSelection();

    /*while(ins != 4){

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
    }*/
    
    cout << "\33[?1049l"; //exit alternate screen buffer window
    
    return 0;
}

void topBanner(string page){
    string disp = "POKER CLI - " + page + "\n";

    cout << "\033[2J\033[1;1H";
    cout << "=================================================================================================================================================================================================================\n";
    cout << right << setw(105) << disp;
    cout << "=================================================================================================================================================================================================================\n";

}

int startScreen(){
    topBanner("WELCOME");
    cout << "WElCOME TO THE POKER CLI!\n\n";
    cout << "Please select one of the following options:\n";
    cout << "1. New Game\n2. Continue Game\n3. Rules\n4. Exit\n\n";
    int ins;
    cin >> ins;

    return ins;
}

void rules(){
    topBanner("RULES");
    cout << "Press enter to exit.\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

int startSelection(){
    int ins = -1;

    while(ins != 1 && ins != 2 && ins != 4){
        ins = startScreen(); 

        if (ins == 3) {
            rules();
        } else if(ins != 1 && ins != 2 && ins != 4){               
            cout << "Invalid input: Select 1, 2, 3, or 0";
        }
    }

    return ins;
}