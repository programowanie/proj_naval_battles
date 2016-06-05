#pragma once

#include "Enemy.h"

class Battle {
    vector<Enemy> _site;

public:
    Battle();
    bool mainLoop();
    void show();
};