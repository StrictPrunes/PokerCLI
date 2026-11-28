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

    while(ins != 4){

        char cont = 'Y';
        
        while(cont == 'Y' || cont == 'y'){
            Player newPlayer = playerCreation(game.getPlayers());
            game.addPlayer(newPlayer);
            do {
                if(cont != 'Y' && cont != 'y' && cont != 'N' && cont != 'n'){
                    cout << "\nPlease select Y/N\n";
                }
                cout << "Add another player? (Y/N) ";
                cin >> cont;
            } while (cont != 'Y' && cont != 'y' && cont != 'N' && cont != 'n');
        }

        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        //game.start();
        for(int i = 0; i < 4; i++){
            topBanner("Round " + to_string(i + 1));
            game.bettingRound();
        }
        //game.showdown();

        prevGame = true;

        ins = startSelection();
    }
    
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
    topBanner("POKER RULES");

    cout << "======================= HOW TO PLAY =======================\n\n";

    cout << "1. Check:\n";
    cout << "   Pass the action to the next player without betting.\n";
    cout << "   Only allowed when no bet has been made in the current round.\n\n";

    cout << "2. Bet:\n";
    cout << "   Put chips into the pot to start the betting for the round.\n\n";

    cout << "3. Call:\n";
    cout << "   Match the current highest bet by putting in enough chips.\n\n";

    cout << "4. Raise:\n";
    cout << "   Increase the current bet, forcing other players to either\n";
    cout << "   match the new amount, raise again, or fold.\n\n";

    cout << "5. Fold:\n";
    cout << "   Give up your hand and leave the current round.\n";
    cout << "   Any chips already contributed to the pot are forfeited.\n\n";

    cout << "======================= GAME TERMS ========================\n\n";

    cout << "6. Blinds:\n";
    cout << "   Forced bets made before the cards are dealt.\n";
    cout << "   The player left of the dealer posts the Small Blind,\n";
    cout << "   and the next player posts the Big Blind.\n\n";

    cout << "7. Pot:\n";
    cout << "   The total amount of chips bet by all players during a hand.\n\n";

    cout << "8. Dealer Button:\n";
    cout << "   Indicates the dealer position and moves clockwise after\n";
    cout << "   each hand. It determines who posts the blinds.\n\n";

    cout << "9. Community Cards:\n";
    cout << "   Five shared cards placed face-up in the middle of the table.\n";
    cout << "   All remaining players can use these cards to make their hand.\n\n";

    cout << "======================= HAND RANKINGS =====================\n\n";

    cout << "From strongest to weakest:\n";
    cout << "1. Royal Flush       - A, K, Q, J, 10 of the same suit.\n";
    cout << "2. Straight Flush    - Five consecutive cards of the same suit.\n";
    cout << "3. Four of a Kind    - Four cards of the same rank.\n";
    cout << "4. Full House        - Three of a kind and a pair.\n";
    cout << "5. Flush             - Five cards of the same suit.\n";
    cout << "6. Straight          - Five consecutive cards.\n";
    cout << "7. Three of a Kind   - Three cards of the same rank.\n";
    cout << "8. Two Pair          - Two different pairs.\n";
    cout << "9. One Pair          - Two cards of the same rank.\n";
    cout << "10. High Card        - No combination; highest card wins.\n\n";

    cout << "============================================================\n";
    cout << "Press ENTER to return to the main menu...\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

Player playerCreation(const vector<Player>& players){
    topBanner("PLAYER CREATION");
    cout << "WELCOME TO PLAYER CREATION\n\nCurrent Players\n";
    for(Player p : players){
        cout << p.getName() << ": " << p.getChips() << " Chips\n";
    }

    string name;
    int chips;
    cout << "\nCreate a new player...\nEnter name: ";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, name);
    cout << "Enter chips: ";
    cin >> chips;

    return Player(name, chips);
}
