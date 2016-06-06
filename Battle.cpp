#include <iostream>

#include "Battle.h"

using namespace std;

const string sourceUSA = "USA.dat";
const string sourceJAPAN = "JAPAN.dat";


Battle::Battle() {
    unsigned int which;
    Parameters *wsk;

    for (int j = 0; j < 2; j++) {
        which = 0;

        if (j == 0) {
            wsk = new Parameters[15];
            read(sourceUSA, wsk);
            _site[j].siteName = "USA";
        } else {
            wsk = new Parameters[15];
            read(sourceJAPAN, wsk);
            _site[j].siteName = "Japonia";
        }

        for (unsigned int i = 0; i < 4; i++) {
            _site[j]._destroyers.push_back(Destroyer(wsk, which));
            which++;
        }

        for (unsigned int i = 0; i < 4; i++) {
            _site[j]._cruisers.push_back(Cruiser(wsk, which));
            which++;
        }

        for (unsigned int i = 0; i < 4; i++) {
            _site[j]._battleships.push_back(Battleship(wsk, which));
            which++;
        }

        for (unsigned int i = 0; i < 3; i++) {
            _site[j]._aircraftCarriers.push_back(AircraftCarrier(wsk, which));
            which++;
        }

        delete[] wsk;
    }
}