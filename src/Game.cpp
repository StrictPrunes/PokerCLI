#include <iostream>
#include "Game.hpp"

using namespace std;

Game::Game() : pot(0), currentRound(1){

}

void Game::addPlayer(Player newPlayer){
    players.push_back(newPlayer);
}
        
void Game::addChips(int chip){
    pot += chip;
}
        
void Game::addCard(Card c){
    communityCards.addCard(c);
}
        
int Game::emptyPot(){
    int tempPot;
    pot = 0;
    return pot;
}
        
void Game::displayCommunityCards(ostream& outs){
    communityCards.printDeck(cout);
}
        
void Game::start(){
    baseDeck.shuffle();

    for(Player p : players){
        p.addCard(baseDeck.drawTopCard());
        p.addCard(baseDeck.drawTopCard());
    }

    currentDealer = 0;
    players[(currentDealer+1) % players.size()].makeBet(5);
    players[(currentDealer+2) % players.size()].makeBet(10);
    pot += players[(currentDealer+1) % players.size()].takeBet();
    pot += players[(currentDealer+2) % players.size()].takeBet();

    currentPlayer = (currentDealer + 3) % players.size();
}
        
void Game::bettingRound(){

    bool check = false;
    int highBet = 0;
    int lastBet = 0;
    int prevBet[players.size()];
    
    for(int i = 0; i < players.size(); i++){
        prevBet[i] = players[i].getBet();
    }

    do{

        for(int i = currentDealer + 1; i  <= currentDealer; i = (i+1) % players.size()){
            if(players[i].getActive()){
            bool check2 = false;

            while(!check2){
            cout << "1. Check/Call\n2. Raise\n3. Fold\n4. View Table\n\n";
            int ins;
            cin >> ins;

            if(ins == 1){
                if(players[i].getBet() - prevBet[i] == highBet){
                    check = true;
                }else if(highBet >  players[i].getBet() - prevBet[i]){
                    int bet = highBet - players[i].getBet() - prevBet[i];
                    if(bet <= players[i].getChips() - players[i].getBet()){
                        players[i].makeBet(bet);
                        cout << "Matched highest Bet: " << highBet << endl;
                        check = true;
                    } else {
                        players[i].makeBet(players[i].getChips() - players[i].getBet());
                        cout << "Bet max amount player can bet: " << players[i].getBet() - prevBet[i] << endl;
                        check = true;
                        players[i].setActive(false);
                    }
                }
            }else if(ins == 2){
                int bet;
                cin >> bet;

                if(bet > highBet && bet > lastBet && bet <= players[i].getChips() - players[i].getBet()){
                    players[i].makeBet(bet);
                    highBet = highBet + bet;
                    lastBet = bet;
                    cout << "New highest Bet: " << highBet << endl;
                    check = true;
                } else{
                    cout << "Bet is too high, or not >= the last raise" << endl;
                }

            }else if(ins == 3){
                players[i].setActive(false);
                check = true;

            }else if(ins == 4){
                cout << "Available Chips: " << players[i].getChips() - players[i].getBet() << endl;
                cout << "Players Cards: " << endl;
                players[i].displayHand(cout);
                cout << "Community Cards: " << endl;
                communityCards.printDeck(cout);
            }

            }
            }

        }

        check = false;
        for(Player p : players){

            if(p.getBet() != highBet && p.getActive()){
                check = true;
            }
        }


    } while(check);
    baseDeck.burn();

    if(currentRound == 1){
        addCard(baseDeck.drawTopCard());
        addCard(baseDeck.drawTopCard());
        addCard(baseDeck.drawTopCard());
    } else if(currentRound != 4){
        addCard(baseDeck.drawTopCard());
    }

}

        
void Game::showdown(){

    int winner = 0;

    for(int i = 1; i < players.size(); i++){{

        if(players[i].highHand() > players[winner].highHand()){
            winner = i;
        }

    }

    for(int i = 0; i < players.size(); i++){

        players[winner].awardChips(players[i].takeBet());

    }

}

vector<Player> Game::getPlayers(){
    return players;
}

int Game::getPot(){
    return pot;
}
int Game::getCurrentPlayer(){
    return currentPlayer;
}