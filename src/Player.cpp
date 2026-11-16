#include <iostream>
#include "Player.hpp"

using namespace std;

Player::Player(Deck newHand, string newName, int newChips) : hand(newHand), name(newName), chips(newChips){

}

Player::Player(string newName, int newChips) : name(newName), chips(newChips){

}

Player::Player() : chips(0), bet(0), active(false){

}

Deck Player::highHand(const Deck& communityCards){
    
}

void Player::resetHand(){
    bet = 0;
    hand.burn();
    hand.burn();
}

int Player::takeBet(){
    chips -= bet;
    return bet;
}

void Player::addCard(Card c){
    hand.addCard(c);
}

bool Player::makeBet(int newBet){
    if(newBet < chips){
        bet += newBet;
        return true;
    }

    return false;
}

void Player::awardChips(int win){
    chips += win;
}

void Player::displayHand(ostream& outs){
    hand.printDeck();
}

void Player::setActive(bool newVal){
    active = newVal;
}

int Player::getBet(){
    return bet;
}

int Player::getChips(){
    return chips;
}

string Player::getName(){
    return name;
}

bool Player::getActive(){
    return active;
}