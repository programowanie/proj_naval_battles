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

void Battle::mainLoop() {
    system("cls");
    cout << "                           ## Naval Battles ##" << endl;
    cout << "                        Symulator bitwy morskiej." << endl << endl;
    showSites();
}

void Battle::showSites() {
    unsigned int destroyers[2][2]{}, cruisers[2][2]{}, battleships[2][2]{}, aircraftCarriers[2][2]{};

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 4; i++) {
            if (_site[j]._destroyers[i].isAlive()) destroyers[j][j]++;
            if (_site[j]._cruisers[i].isAlive()) cruisers[j][j]++;
            if (_site[j]._battleships[i].isAlive()) battleships[j][j]++;
        }

        for (int i = 0; i < 3; i++)
            if (_site[j]._aircraftCarriers[i].isAlive()) aircraftCarriers[j][j]++;
    }


    cout << "STATYSTYKI" << endl << endl;
    cout << "                  " << _site[0].siteName << "             " << _site[1].siteName << endl;
    cout << "Typ statku:       Ilosc:          Ilosc:" << endl << endl;
    cout << "niszczyciele      " << destroyers[0][0] << "               " << destroyers[1][1] << endl;
    cout << "krazowniki        " << cruisers[0][0] << "               " << cruisers[1][1] << endl;
    cout << "pancerniki        " << battleships[0][0] << "               " << battleships[1][1] << endl;
    cout << "lotniskowce       " << aircraftCarriers[0][0] << "               " << aircraftCarriers[1][1] << endl;
}





