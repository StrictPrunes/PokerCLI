#include "Deck.hpp"

using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

Deck::Deck() {
    numCards = 0;
    handType = {-1};
}

Deck::Deck(vector<Card> c, int handType) : cards(c), handType(handType){

}

Card Deck::drawTopCard(){
    Card top = cards[numCards - 1];
    cards.pop_back();

    numCards--;
    return top;
}

void Deck::addCard(Card c){
    
    cards.push_back(c);
    numCards++;

}

void Deck::printDeck(ostream& outs){
    for(int i = 0; i < numCards; i ++){
        outs << cards[i] << endl;
    }

}

bool Deck::isEmpty(){
    return numCards == 0;

}

Card Deck::findHighCard() const {

    if(numCards != 0){
        Card high = cards[0];

        for(int i  = 1; i < numCards; i ++){
            if (cards[i] > high){
                high = cards[i];
            }
        }
        return high;
    }else{
        return Card();
    }
    
}

void Deck::shuffle(){
    numCards = 52;
    for (int i = 0; i < 4; i++){
        for (int n = 1; n < 14; n++){
            cards.push_back(Card(n, i));
        }
    }

    srand(time(nullptr));
    for (int i  = 0; i < numCards; i++){
        int r = rand() % 52;
        Card temp = cards[i];

        cards[i] = cards[r-1];
        cards[r-1] = temp;

    }

}

void Deck::burn(){
    cards.pop_back();
}

vector<Card> Deck::getCards() const{
    return cards;
}

void Deck::setHandType(int newVal){
    handType = newVal;
}

int Deck::getHandType(){
    return handType;
}
