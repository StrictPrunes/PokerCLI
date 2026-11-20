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

    //combine hands and sort in descending order
    plrHand.insert(plrHand.end(),commHand.begin(), commHand.end());
    sort(plrHand.begin(), plrHand.end(), [](const Card &a, const Card &b) 
    { return a > b; });

    //check for 5 of the same suit
    int numSuit[4] = {0};
    int flushSuit = -1;
    int numRank[13] = {0};
    for(int i = 0; i<plrHand.size(); i++){    
        numSuit[plrHand[i].getSuit()]++;
        numRank[plrHand[i].getRank() - 1]++;

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

        } else {
            numStraight = 1;
            tempIndex = i+1;
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
                vector<Card> out(plrHand.begin(), plrHand.begin() + 5);
                Deck outs(out, {0, -1, -1});
                return outs;
            } else {    //hand contains straight flush
                vector<Card> out(plrHand.begin() + straightIndex, plrHand.begin() + straightIndex + 5);
                Deck outs(out, {1, plrHand[straightIndex].getRank()});
                return outs;
            }
        }
    }

    //check for four of a kind
    for(int i = 12; i >= 0; i--){
        if(numRank[i] == 4){
            vector<Card> out;
            copy_if(plrHand.begin(), plrHand.end(), back_inserter(out),
            [i](Card c) { return c.getRank() == i + 1; });
            for(Card c : plrHand){ 
                if(c.getRank() != i + 1){
                    out.push_back(c);
                    break;
                }    
            }
            Deck outs(out, {2, -1, -1});
            return outs;
        }
    }

    //check for full house
    int threeRank = -1;
    int pairRank1 = -1;
    int pairRank2 = -1;
    for(int i = 12; i >= 0; i--){
        if(threeRank == -1 && numRank[i] == 3){
            threeRank = i+1;
        } else if(pairRank1 == -1 && numRank[i] == 2){
            pairRank1 = i+1;
        } else if(pairRank2 == -1 && numRank[i] == 2 && pairRank1 != -1){
            pairRank2 = i+1;
        }

        if(threeRank != -1 && pairRank1 != -1){
            vector<Card> out;
            copy_if(plrHand.begin(), plrHand.end(), back_inserter(out),
            [threeRank](Card c) { return c.getRank() == threeRank; });

            copy_if(plrHand.begin(), plrHand.end(), back_inserter(out),
            [pairRank1](Card c) { return c.getRank() == pairRank1; });

            Deck outs(out, {3, threeRank, pairRank1});
            return outs;
        }
    }

    //next best is flush
    if(flushSuit != -1){
        vector<Card> out;
        copy_if(plrHand.begin(), plrHand.end(), back_inserter(out),
        [flushSuit, out](Card c) { if(out.size() >= 5){return false;} return c.getSuit() == flushSuit; });

        Deck outs(out, {4, out[0].getRank(), out[1].getRank()});
        return outs;
    }

    //next is straight
    if(straightIndex != -1){
        vector<Card> out(plrHand.begin() + straightIndex, plrHand.begin() + straightIndex + 5);

        Deck outs(out, {5, out[0].getRank()});
        return outs;
    }

    //three of a kind
    if(threeRank != -1){
        vector<Card> out;
        copy_if(plrHand.begin(), plrHand.end(), back_inserter(out),
        [threeRank](Card c) { return c.getRank() == threeRank; });
        
        for(Card c : plrHand){ 
            if(out.size() >= 5){
                break;
            } else if(c.getRank() != threeRank){
                out.push_back(c);
            }    
        }
        Deck outs(out, {6, threeRank});
        return outs;
    }
    
    //two pair
    if(pairRank1 != -1 && pairRank2 != -1){
        vector<Card> out;
        copy_if(plrHand.begin(), plrHand.end(), back_inserter(out),
        [pairRank1](Card c) { return c.getRank() == pairRank1; });
        
        copy_if(plrHand.begin(), plrHand.end(), back_inserter(out),
        [pairRank2](Card c) { return c.getRank() == pairRank2; });

        for(Card c : plrHand){ 
            if(c.getRank() != pairRank1 && c.getRank() != pairRank2){
                out.push_back(c);
                break;
            }    
        }
        Deck outs(out, {7, pairRank1, pairRank2});
        return outs;
    }

    //pair
    if(pairRank1 != -1){
        vector<Card> out;
        copy_if(plrHand.begin(), plrHand.end(), back_inserter(out),
        [pairRank1](Card c) { return c.getRank() == pairRank1; });

        for(Card c : plrHand){ 
            if(out.size() >= 5){
                break;
            } else if(c.getRank() != pairRank1){
                out.push_back(c);
            }    
        }
        Deck outs(out, {8, pairRank1, out[2].getRank()});
        return outs;
    }

    //high card
    vector<Card> out(plrHand.begin(), plrHand.begin() +5);
    return Deck(out, {9, out[0].getRank(), out[1].getRank()});
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