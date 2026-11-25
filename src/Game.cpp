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

}
        
void Game::showdown(){

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