#include <iostream>

#include "Battle.h"

using namespace std;

bool Battle::mainLoop() {
    unsigned int game = 1;

    while (game) {
        game = round();
    }

    return 0;
}

Battle::Battle() {
    _site.push_back(Enemy(USA));
    _site.push_back(Enemy(JAPAN));
}

unsigned int Battle::round() {
    fight(_site[0].drawShip(), _site[1].drawShip());
    return 0;
}

void Battle::fight(whichShip ship1, whichShip ship2) {
    //_site[0].showShip(ship1);
    //_site[1].showShip(ship2);
}





