#ifndef PROJ_NAVAL_BATTLES_BATTLE_H
#define PROJ_NAVAL_BATTLES_BATTLE_H

#include <vector>
#include <queue>
#include <iterator>
#include <iostream>

#include "Ship.h"

using namespace std;

//! Struktura opisująca stronę biorącą udział w bitwie
struct site {
    string siteName; ///< Nazwa strony biorącej udział w bitwie

    vector<Destroyer> _destroyers; ///< Wektor przechowujący niszczyciele danej strony
    vector<Cruiser> _cruisers; ///< Wektor przechowujący krążowniki danej strony
    vector<Battleship> _battleships; ///< Wektor przechowujący pancerniki danej strony
    vector<AircraftCarrier> _aircraftCarriers; ///< Wektor przechowujący lotniskowce danej strony
};

//! Klasa opisująca bitwę
class Battle {
    site _site[2]; ///< Tablica przechowująca strony w bitwie
    queue<Ship *> _qsite[2]; ///< Kolejka przechowująca statki w aktualnej turze

public:
	//! Konstruktr klasy
    Battle();

	//! Funkcja głównej pętli symulacji
    bool mainLoop();

	//! Funkcja losująca statki i dodająca je do kolejki
    int drawShip(unsigned int n);

	//! Funkcja pokazująca przeciwników w bitwie
    void showSites();

	//! Funkcja opisująca turę
    int turn(int wf);
};

#endif //PROJ_NAVAL_BATTLES_BATTLE_H