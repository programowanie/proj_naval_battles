#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>

#include "Interface.h"
#include "Warships.h"
#include "Enemy.h"
#include "Battle.h"

bool read(const string &file_name, Parameters tab[]);

void showParameters(Parameters tab[], int n);

int main(int argc, char *argv[]) {
    cout << "## Naval Battles Simulator ##\n\n";

    if (argc == 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    Parameters *parametersUSA = new Parameters[15];
    Parameters *parametersJAPAN = new Parameters[15];

    if (read("USA.dat", parametersUSA) && read("JAPAN.dat", parametersJAPAN))
        cout << "\nPoprawnie wczytano parametry statkow\nWyswietlic wczytane parametry? [t/n]: ";
    char whatToDo;
    cin >> whatToDo;
    if (whatToDo == 't') {
        showParameters(parametersUSA, 15);
        showParameters(parametersJAPAN, 15);
    }

    Battle battle;

    delete[] parametersUSA;
    delete[] parametersJAPAN;

    cin.sync();
    cin.get();

    return 0;
}

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

