#ifndef PROJ_NAVAL_BATTLES_BATTLE_H
#define PROJ_NAVAL_BATTLES_BATTLE_H

#include <vector>
#include <queue>
#include <iterator>
#include <iostream>

#include "Ship.h"

using namespace std;

struct site {
    string siteName;

    vector<Destroyer> _destroyers;
    vector<Cruiser> _cruisers;
    vector<Battleship> _battleships;
    vector<AircraftCarrier> _aircraftCarriers;
};

class Battle {
    site _site[2];
    queue<Ship *> _qsite[2];

public:

    Battle(); /// Create a Battle

    bool mainLoop(); /// \fn mainLoopMain simulation loop

    int drawShip(unsigned int n); /// \fn drawShip Function draws ships, adding them to the queue.

    void showSites(); /// \fn Function shows opponents in battle.

    int turn(int wf);
};

#endif //PROJ_NAVAL_BATTLES_BATTLE_H