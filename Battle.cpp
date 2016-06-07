#include <iostream>

#include "Battle.h"
#include <windows.h>

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

bool Battle::mainLoop() {
    int turnNumber = 0;
    int whoFirst;
    int end = 0;

    while (!end) {
        system("cls");
        cout << "                           ## Naval Battles ##" << endl;
        cout << "                        Symulator bitwy morskiej." << endl << endl;
        showSites();

        cout << "TURA: " << turnNumber + 1 << endl;

        drawShip(0);
        drawShip(1);

        whoFirst = rand() % 2;
        cout << "Rozpoczyna: ";

        if (whoFirst == 0) cout << _site[0].siteName << endl;
        else cout << _site[1].siteName << endl;
        cout << endl;

        end = turn(whoFirst);
        if (end == 0) turnNumber++;
    }
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
    cout << "niszczyciel       " << destroyers[0][0] << "               " << destroyers[1][1] << endl;
    cout << "krazownik         " << cruisers[0][0] << "               " << cruisers[1][1] << endl;
    cout << "pancernik         " << battleships[0][0] << "               " << battleships[1][1] << endl;
    cout << "lotniskowiec      " << aircraftCarriers[0][0] << "               " << aircraftCarriers[1][1] << endl <<
    endl;
}

void Battle::drawShip(unsigned int n) {
    Ship *wsk = NULL;

    int what, which;
    int drawn[4][4]{};

    for (int i = 0; i < 15; i++) {

        while (true) {
            what = rand() % 4;
            if (what == 3) which = rand() % 3;
            else which = rand() % 4;

            if (drawn[what][which] == 0) {
                drawn[what][which] = 1;
                break;
            }
        }

        switch (what) {
            case 0:
                if (_site[n]._destroyers[which].isAlive()) wsk = &_site[n]._destroyers[which];
                else wsk = NULL;
                _qsite[n].push(wsk);
                break;
            case 1:
                if (_site[n]._cruisers[which].isAlive()) wsk = &_site[n]._cruisers[which];
                else wsk = NULL;
                _qsite[n].push(wsk);
                break;
            case 2:
                if (_site[n]._battleships[which].isAlive()) wsk = &_site[n]._battleships[which];
                else wsk = NULL;
                _qsite[n].push(wsk);
                break;
            case 3:
                if (_site[n]._aircraftCarriers[which].isAlive()) wsk = &_site[n]._aircraftCarriers[which];
                else wsk = NULL;
                _qsite[n].push(wsk);
                break;
            default:
                cout << "Blad podczas losowania statku" << endl;
                break;
        }
    }

    wsk = NULL;
}

int war(Ship *wsk1, Ship *wsk2) {
    Sleep(300);

    cout << wsk1->whatType();


    return 0;
}

int Battle::turn(int wf) {
    Ship *ship0 = NULL, *ship1 = NULL;

    switch (wf) {
        case 0:
            for (int i = 0; i < 15; i++) {
                ship0 = _qsite[0].front();
                _qsite[0].pop();
                ship1 = _qsite[1].front();
                _qsite[1].pop();

                war(ship0, ship1);
            }
            break;
        case 1:
            for (int i = 0; i < 15; i++) {
                ship0 = _qsite[1].front();
                _qsite[1].pop();
                ship1 = _qsite[0].front();
                _qsite[0].pop();

                war(ship0, ship1);
            }
            break;
        default:
            cout << "Blad podczas rozzgrywania tury!" << endl;
            return 1;
    }
    return 0;
}