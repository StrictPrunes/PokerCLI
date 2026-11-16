#include <iostream>
#include "Card.hpp"

using namespace std;


const string rankName[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "Ten", "Jack", "Queen", "King"};
const string suitName[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};


//Card class implementation

Card::Card(int new_rank, int new_suit){
    rank = new_rank;
    suit = new_suit;

    if(!isValid()){
        cout << "Invalid Card. Exiting...";
        exit(1);
    }
}

Card::Card(){
    rank = 1;
    suit = 0;
}

bool Card::isFaceCard(){
    if(rank == 11 || rank == 12 || rank == 13){
        return true;
    } else {
        return false;
    }
}

bool Card::isValid(){
    if(rank < 1 || rank > 13 || suit < 0 || suit > 3){
        std::cout << "Invalid input.";
        return false;
    } else {
        return true;
    }
}

ostream& operator<<(ostream& outs, const Card& card1){
    outs << rankName[card1.rank-1];
    outs << " of ";
    outs << suitName[card1.suit];

    return outs;
}

istream& operator>>(istream& ins, Card& card1){
    string of;
    string rank, suit;

    ins >> rank >> of >> suit;
    bool foundRank, foundSuit;
    for(int i = 0; i < 13; i++){
        if(rank == rankName[i]){
            card1.rank = i+1;
            foundRank = true;
            break;
        }
    }

    for(int i = 0; i<4; i++){
        if(suit == suitName[i]){
            card1.suit = i;
            foundSuit = true;
            break;
        }
    }
    
    if(!foundRank || !foundSuit){
        cout << "No matching rank or suit found. Exiting...\n";
        exit(1);
    }
    return ins;
}

bool operator<(const Card& card1, const Card& card2){    
    int rank1 = card1.rank;
    int rank2 = card2.rank;
    
    #ifdef ACE_HIGH
    if(rank1 == 1){
        rank1 = 14;
    }
    if(rank2 == 1){
        rank2 = 14;
    }
    #endif
    
    if(card1.rank != card2.rank){
        return rank1 < rank2;
    }

    return card1.suit < card2.suit;
}

bool operator>(const Card& card1, const Card& card2){
    int rank1 = card1.rank;
    int rank2 = card2.rank;
    
    #ifdef ACE_HIGH
    if(rank1 == 1){
        rank1 = 14;
    }
    if(rank2 == 1){
        rank2 = 14;
    }
    #endif
    
    if(card1.rank != card2.rank){
        return rank1 > rank2;
    }

    return card1.suit > card2.suit;
}

bool operator==(const Card& card1, const Card& card2){
    return(card1.suit == card2.suit && card1.rank == card2.rank);
}

