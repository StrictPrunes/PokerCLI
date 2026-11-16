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
    communityCards.printDeck();
}
        
void Game::start(){
    baseDeck.shuffle();
    
    for(Player p : players){
        p.addCard(baseDeck.drawTopCard());
        p.addCard(baseDeck.drawTopCard());
    }

}
        
void Game::bettingRound(){

}
        
void Game::showdown(){

}

vector<Player> Game::getPlayers(){
    return players;
}