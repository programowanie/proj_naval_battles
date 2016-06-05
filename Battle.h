#pragma once

#include "Enemy.h"

class Battle {
    Enemy *_site1 = new Enemy(USA);
    Enemy *_site2 = new Enemy(JAPAN);
public:
    void mainLoop();
};