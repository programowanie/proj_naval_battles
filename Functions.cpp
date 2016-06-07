#include <fstream>

#include "Functions.h"

using namespace std;

void read(const string &file_name, Parameters tab[]) {
    int typeOfWarship;
    ifstream file;
    file.open(file_name.c_str());
    if (!file.good()) exit(404);

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
}