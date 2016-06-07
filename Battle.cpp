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

        if (drawShip(0)) {
            cout << "Japonia wygrywa bitwe! Rozegrano " << turnNumber + 1 << " tur." << endl;
            break;
        }
        if (drawShip(1)) {
            cout << "USA wygrywaja bitwe! Rozegrano " << turnNumber + 1 << " tur." << endl;
            break;
        }

        cout << "TURA: " << turnNumber + 1 << endl;

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

int Battle::drawShip(unsigned int n) {
    Ship *wsk = NULL;

    int x = 15;

    int what, which;
    int drawn[4][4]{};

    for (int i = 0; i < 4; i++) {
        if (_site[n]._destroyers[i].isDead()) {
            drawn[0][i] = 1;
            x--;
        }

        if (_site[n]._cruisers[i].isDead()) {
            drawn[1][i] = 1;
            x--;
        }

        if (_site[n]._battleships[i].isDead()) {
            drawn[2][i] = 1;
            x--;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (_site[n]._aircraftCarriers[i].isDead()) {
            drawn[3][i] = 1;
            x--;
        }
    }

    if (x == 0) return 1;

    for (int i = 0; i < x; i++) {

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
                _qsite[n].push(wsk);
                break;
            case 1:
                if (_site[n]._cruisers[which].isAlive()) wsk = &_site[n]._cruisers[which];
                _qsite[n].push(wsk);
                break;
            case 2:
                if (_site[n]._battleships[which].isAlive()) wsk = &_site[n]._battleships[which];
                _qsite[n].push(wsk);
                break;
            case 3:
                if (_site[n]._aircraftCarriers[which].isAlive()) wsk = &_site[n]._aircraftCarriers[which];
                _qsite[n].push(wsk);
                break;
            default:
                cout << "Blad podczas losowania statku" << endl;
                break;
        }
    }

    wsk = NULL;
    return 0;
}

int war(Ship *wsk1, Ship *wsk2) {
    int x = 0;

    if (wsk1->isDead()) {
        cout << " " << wsk1->_name << " nie atakuje - zostal zniszczony w jednym z poprzednich atakow." << endl;
        return 0;
    }
    cout << wsk1->_name << " " << wsk1->_hp << "HP atakuje: " << wsk2->_name << " " << wsk2->_hp << "HP" << endl;
    cout << "   za pomoca";

    if (wsk1->_type == DESTROYER) {
        x = rand() % 3;
        if (x == 0) {
            cout << " pocisku AP zadajac ";
            cout << wsk1->_maxApShellDmg;
            wsk2->_hp -= wsk1->_maxApShellDmg;
        } else if (x == 1) {
            cout << " pocisku HE zadajac ";
            cout << wsk1->_maxHeShellDmg;
            wsk2->_hp -= wsk1->_maxHeShellDmg;
        } else {
            cout << " torpedy zadajac ";
            cout << wsk1->_maxTorpedoDmg;
            wsk2->_hp -= wsk1->_maxTorpedoDmg;
        }
    } else if (wsk1->_type == CRUISER || wsk1->_type == BATTLESHIP) {
        x = rand() % 2;
        if (x == 0) {
            cout << " pocisku AP zadajac ";
            cout << wsk1->_maxApShellDmg;
            wsk2->_hp -= wsk1->_maxApShellDmg;
        } else if (x == 1) {
            cout << " pocisku HE zadajac ";
            cout << wsk1->_maxHeShellDmg;
            wsk2->_hp -= wsk1->_maxHeShellDmg;
        }
    } else if (wsk1->_type == AIRCRAFTCARRIER) {
        cout << " eskadry zadajac ";
        cout << wsk1->_dmgPerSquadron;
        wsk2->_hp -= wsk1->_dmgPerSquadron;
    }

    cout << " obrazen." << endl;
    return 0;
}

int Battle::turn(int wf) {
    Ship *ship0 = NULL, *ship1 = NULL;
    int deadSite0 = 0, deadSite1 = 0, what = 0;

    for (int i = _qsite[0].size(), j = _qsite[1].size(), k = 0;
         !_qsite[0].empty() && !_qsite[1].empty(); i--, j--, k++) {
        Sleep(500);
        cout << k + 1 << ". ";
        switch (wf) {
            case 0:
                ship0 = _qsite[0].front();
                _qsite[0].pop();
                ship1 = _qsite[1].front();
                _qsite[1].pop();

                what = war(ship0, ship1);

                wf = 1;
                break;
            case 1:
                ship0 = _qsite[1].front();
                _qsite[1].pop();
                ship1 = _qsite[0].front();
                _qsite[0].pop();

                what = war(ship0, ship1);
                wf = 0;
                break;
            default:
                cout << "Blad podczas rozgrywania tury!" << endl;
                return 1;
        }
    }

    Sleep(500);
    return 0;
}