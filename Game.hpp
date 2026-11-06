#ifndef GAME_H
#define GAME_H

#include <iostream>

using namespace std;

class Game {
    Public:
        Game();

        void addChips(int chip);
        //adds given int to pot
        void addCard(Card c);
        //adds card to community cards
        int emptyPot();
        //returns pot and sets it to 0
        void displayCommunityCards(ostream& outs);
        void start(Player (&players)[numPlayers], Deck (&deck)[n], int dealer, int &turn);
        //deals cards to players, takes small and big blind, sets turn to player after big blind
        void bettingRound(player (&players)[numPlayers], int &turn, int dealer);
        //takes bets from players, sets turn to dealer
        void showdown(player (&players)[numPlayers]);
        //determines which players has the best hand and awards pot to that player

    Private:
        int pot;
        int currentPlayer;
        int currentDealer;
        vector<Player> players;
        Deck communityCards;
}

#endif //GAME_H