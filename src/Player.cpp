#include <iostream>
#include "Player.hpp"
#include <algorithm>
#include <vector>

using namespace std;

Player::Player(Deck newHand, string newName, int newChips) : hand(newHand), name(newName), chips(newChips){

}

Player::Player(string newName, int newChips) : name(newName), chips(newChips){

}

Player::Player() : chips(0), bet(0), active(false){

}

Deck Player::highHand(const Deck& communityCards){
    vector<Card> plrHand = hand.getCards();
    vector<Card> commHand = communityCards.getCards();

    plrHand.insert(plrHand.end(),commHand.begin(), commHand.end());

    sort(plrHand.begin(), plrHand.end(), [](const Card &a, const Card &b) 
    { return a < b; });

    int numSameSuit;
    for(int i = 0; i<plrHand.size(); i++){
        if(plrHand[i].getSuit() != plrHand[i+1].getSuit()){
            numSameSuit++;
        }
    }

    if(numSameSuit >= 5){
        
    }
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
    hand.printDeck(cout);
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