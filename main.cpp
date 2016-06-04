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

int main(int argc, char *argv[]) {
    if (argc == 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    Parameters *parametersUSA = new Parameters[1];
    //Parameters *parametersJAPAN = new Parameters[15];
    if (read("USA.dat", parametersUSA))
        cout << "\nPoprawnie wczytano parametry statkow\nWyswietlic wczytane parametry? [t/n]: " << endl;

    //read("JAPAN.dat", parametersJAPAN);



    Battle battle;

    delete[] parametersUSA;
    //delete [] parametersJAPAN;

    return 0;
}

bool read(string file_name, Parameters tab[]) {
    ifstream file;
    file.open(file_name.c_str());
    if (!file.good()) return false;

    for (int i = 0; i < 1; i++) {
        file >> tab[i].name;
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
}