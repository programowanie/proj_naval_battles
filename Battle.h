#ifndef PROJ_NAVAL_BATTLES_BATTLE_H
#define PROJ_NAVAL_BATTLES_BATTLE_H

#include <vector>
#include <queue>
#include <iterator>
#include <string>

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
    Battle();

    bool mainLoop();

    void drawShip(unsigned int n);
    void showSites();

    int turn(int wf);
};

#endif //PROJ_NAVAL_BATTLES_BATTLE_H