#pragma once

#include <vector>
#include <iterator>

#include "Warships.h"

using namespace std;

class Enemy {
    vector<Destroyer> destroyers;
    vector<Cruiser> cruisers;
    vector<Battleship> battleships;
    vector<AircraftCarrier> aircraftCarriers;
};