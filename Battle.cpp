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

}

Battle::Battle() {
    _site.push_back(Enemy(USA));
    _site.push_back(Enemy(JAPAN));
}