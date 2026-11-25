#include "catch.hpp"
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

TEST_CASE("game start with two players"){
    Game g;
    g.addPlayer(Player("p1", 100));
    g.addPlayer(Player("p2", 100));

    g.start();

    vector<Player> p = g.getPlayers();

    REQUIRE(g.getPot() == 15);
    REQUIRE(g.getCurrentPlayer() == 1);
}