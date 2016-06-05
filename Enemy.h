#pragma once

#include <vector>
#include <iterator>
#include <string>
#include <fstream>

#include "Warships.h"

#define SOURCE_USA "USA.dat"
#define SOURCE_JAPAN "JAPAN.dat"

bool read(const string &file_name, Parameters tab[]);

void showParameters(Parameters tab[], int n);

using namespace std;

enum site {
    USA, JAPAN
};

class Enemy {
    site _site;
    vector<Destroyer> _destroyers;
    vector<Cruiser> _cruisers;
    vector<Battleship> _battleships;
    vector<AircraftCarrier> _aircraftCarriers;
public:
    Enemy(site s);

    void showEnemy();
};