#include <iostream>
#include <string>
#include <fstream>

#include "Enemy.h"

using namespace std;

bool read(const string &file_name, Parameters tab[]) {
    int typeOfWarship;
    ifstream file;
    file.open(file_name.c_str());
    if (!file.good()) return false;

    for (int i = 0; i < 15; i++) {
        file >> tab[i].name;

        file >> typeOfWarship;
        if (typeOfWarship == 0) tab[i].type = DESTROYER;
        else if (typeOfWarship == 1) tab[i].type = CRUISER;
        else if (typeOfWarship == 2) tab[i].type = BATTLESHIP;
        else if (typeOfWarship == 3) tab[i].type = AIRCRAFTCARRIER;


        file >> tab[i].baseHp;
        file >> tab[i].armor;
        file >> tab[i].agility;
        file >> tab[i].camouflage;
        file >> tab[i].chanceForArson;
        file >> tab[i].amountOfAntiAircraftCannons;
        file >> tab[i].maxAntiAircraftCannonsDmg;
        file >> tab[i].amountOfCannons;
        file >> tab[i].maxHeShellDmg;
        file >> tab[i].maxApShellDmg;
        file >> tab[i].firingRange;
        file >> tab[i].chanceForArsonByHe;
        file >> tab[i].amountOfTorpedos;
        file >> tab[i].maxTorpedoDmg;
        file >> tab[i].torpedoRange;
        file >> tab[i].amountOfSquadrons;
        file >> tab[i].aircraftInSquadron;
        file >> tab[i].dmgPerSquadron;
        file >> tab[i].baseHpPerSquadron;
    }

    return true;
}

void showParameters(Parameters *tab, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n#### Numer statku: " << i + 1 << endl;
        cout << "\nNazwa: " << tab[i].name << endl;

        cout << "Typ: ";
        if (tab[i].type == DESTROYER) cout << "niszczyciel" << endl;
        else if (tab[i].type == CRUISER) cout << "krazownik" << endl;
        else if (tab[i].type == BATTLESHIP) cout << "pancernik" << endl;
        else cout << "lotniskowiec" << endl;

        cout << "HP: " << tab[i].baseHp << endl;
        cout << "Pancerz: " << tab[i].armor << endl;
        cout << "Zwrotnosc: " << tab[i].agility << endl;
        cout << "Kamuflaz: " << tab[i].camouflage << endl;
        cout << "Szansa na podpalenie: " << tab[i].chanceForArson << endl;

        cout << "\n## Obrona \n" << endl;

        cout << "Liczba dzial przeciwlotniczych: " << tab[i].amountOfAntiAircraftCannons << endl;
        cout << "Max. dmg na dzialo: " << tab[i].maxAntiAircraftCannonsDmg << endl;

        cout << "\n## Atak \n" << endl;

        cout << "Liczba dzial: " << tab[i].amountOfCannons << endl;
        cout << "Dmg pocisku HE: " << tab[i].maxHeShellDmg << endl;
        cout << "Dmg pocisku AP: " << tab[i].maxApShellDmg << endl;
        cout << "Zasieg ostrzalu: " << tab[i].firingRange << endl;
        cout << "Szansa na podpalenie pociskiem HE: " << tab[i].chanceForArsonByHe << endl;
        cout << "Liczba torped: " << tab[i].amountOfTorpedos << endl;
        cout << "Dmg torpedy: " << tab[i].maxTorpedoDmg << endl;
        cout << "Zasieg torpedy: " << tab[i].torpedoRange << endl;
        cout << "Liczba eskadr: " << tab[i].amountOfSquadrons << endl;
        cout << "Liczba samolotow w eskadrze: " << tab[i].aircraftInSquadron << endl;
        cout << "Dmg zadawany przez eskadre: " << tab[i].dmgPerSquadron << endl;
        cout << "HP eskadry: " << tab[i].baseHpPerSquadron << endl;

        cout << "\n\n#################\n#################\n\n";
    }
}

Enemy::Enemy(site enemy) {
    Parameters *parameters = new Parameters[15];
    unsigned int which = 0;

    switch (enemy) {
        case USA:
            read(SOURCE_USA, parameters);
            break;
        case JAPAN:
            read(SOURCE_JAPAN, parameters);
            break;
    }

    cout << "Poprawnie wczytano parametry!\n";

    _site = enemy;

    for (int i = 0; i < 4; i++) {
        _destroyers.push_back(Destroyer(parameters, which));
        which++;
    }


    for (int i = 0; i < 4; i++) {
        _cruisers.push_back(Cruiser(parameters, which));
        which++;
    }


    for (int k = 0; k < 4; k++) {
        _battleships.push_back(Battleship(parameters, which));
        which++;
    }


    for (int l = 0; l < 3; l++) {
        _aircraftCarriers.push_back(AircraftCarrier(parameters, which));
        which++;
    }


    delete[] parameters;
}

void Enemy::showEnemy() {
    cin.sync();
    unsigned int which = 0;
    cout << "\nStrona: ";
    switch (_site) {
        case USA:
            cout << "USA" << endl;
            break;
        case JAPAN:
            cout << "JAPONIA" << endl;
            break;
    }

    cout << "\nNISZCZYCIELE\n";
    cout << "NR " << "Nazwa" << "    HP" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "\n" << i + 1 << ". " << _destroyers[i].name() << " " << _destroyers[i].hp();
        which++;
    }
    cout << "\n\nKRAZOWNIKI:";
    for (int i = 0; i < 4; i++) {
        cout << "\n" << i + 1 << ". " << _cruisers[i].name() << " " << _cruisers[i].hp();
        which++;
    }
    cout << "\n\nPANCERNIKI:";
    for (int i = 0; i < 4; i++) {
        cout << "\n" << i + 1 << ". " << _battleships[i].name() << " " << _battleships[i].hp();
        which++;
    }
    cout << "\n\nLOTNISKOWCE:";
    for (int i = 0; i < 3; i++) {
        cout << "\n" << i + 1 << ". " << _aircraftCarriers[i].name() << " " << _aircraftCarriers[i].hp();
        which++;
    }
    cout << endl << endl;
    cin.sync();
}



