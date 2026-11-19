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
    { return a > b; });

    int numSuit[4] = {0};
    int flushSuit = -1;
    //check for 5 of the same suit
    for(int i = 0; i<plrHand.size(); i++){    
        numSuit[plrHand[i].getSuit()]++;

        if(numSuit[plrHand[i].getSuit()] >= 5){
            flushSuit = plrHand[i].getSuit();
        }
    }

    //check for straights
    int straightIndex = -1;
    int numStraight = 1;
    int tempIndex = 0;
    for(int i = 0; i < plrHand.size() - 1; i++){
        //check for duplicates
        if(plrHand[i].getRank() == plrHand[i-1].getRank()){
            break;
        }

        if(plrHand[i].getRank() == 1 && plrHand.at(i+1).getRank() == 13){
            numStraight++;
        } else if(plrHand[i].getRank() == plrHand.at(i+1).getRank() + 1){
            numStraight++;
            
            if(i == plrHand.size() - 2){
                numStraight++;
            }
        } else {
            numStraight = 1;
            tempIndex = i;
        }

        //save index of highest card in straight
        if(numStraight >= 5){
            straightIndex = tempIndex;
        }
    }

    //if hand contains a flush and a straight, check for royal flush and straight flush
    if(flushSuit != -1 && straightIndex != -1){
        if(plrHand[straightIndex].getSuit() == flushSuit){
            if(plrHand[straightIndex].getRank() == 1){  //hand contains royal flush
                vector<Card> out(plrHand.begin(), plrHand.begin() + 4);
                Deck outs(out, {0,flushSuit,-1});
                return outs;
            } else {    //hand contains straight flush
                
            }
        }
    }

    return Deck();
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