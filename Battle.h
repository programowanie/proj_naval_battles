#pragma once

#include "Enemy.h"

class Battle {
    Enemy *_site1;
    Enemy *_site2;
public:
    Battle();

    ~Battle();

    bool mainLoop();

    void show();
};