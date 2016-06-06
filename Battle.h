#pragma once

#include "Enemy.h"

class Battle {
    vector<Enemy> _site;

public:
    Battle();
    bool mainLoop();

    unsigned int round();

    void fight(unsigned int ship1, unsigned int ship2);
};