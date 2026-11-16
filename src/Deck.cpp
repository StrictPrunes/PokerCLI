#include "Deck.hpp"

using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>

Deck::Deck() {
    numCards = 0;
}

Card Deck::drawTopCard(){
    Card top = cards[numCards - 1];

    numCards--;
    return top;
}

void Deck::shuffle(){

    numCards = 52;
     for (int i = 0; i < 4; i++){
        for (int n = 1; n < 14; n++){
            cards[numCards] = Card(n, i);
        }
    }

    srand(time(nullptr));
    for (int i  = 0; i < numCards; i ++){

        int r = rand() % 52;
        Card temp = cards[0];

        cards[0] = cards[r];
        cards[r] = temp;

    }

}