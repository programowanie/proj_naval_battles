#pragma once

#include <vector>

#include "Enemy.h"

class Battle {
    vector<Enemy> _site;

public:
    Battle();
    bool mainLoop();

    unsigned int round();

    void fight(whichShip ship1, whichShip ship2);
};