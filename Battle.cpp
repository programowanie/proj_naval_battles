#include <iostream>

#include "Battle.h"

using namespace std;

bool Battle::mainLoop() {
    show();
    cin.sync();
    cin.get();
    return 0;
}

void Battle::show() {
    _site1->showEnemy();
    _site2->showEnemy();
}

Battle::Battle() {
    _site1 = new Enemy(USA);
    _site2 = new Enemy(JAPAN);
}

Battle::~Battle() {
    delete _site1;
    delete _site2;
}