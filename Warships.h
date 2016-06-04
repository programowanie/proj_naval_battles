#pragma once

#include <string>

using namespace std;

enum typeOfWarship {
    DESTROYER, CRUISER, BATTLESHIP, AIRCRAFTCARRIER
};

struct DefenceParameters {
    double agility;
    double camouflage;
    double chanceForArson;
    unsigned int amountOfAntiAircraftCannons;
    unsigned int maxAntiAircraftCannonsDmg;
};

struct OffenceParameters {
    unsigned int amountOfCannons;
    unsigned int maxHeShellDmg;
    unsigned int maxApShellDmg;
    unsigned int firingRange;
    unsigned int chanceForArsonByHe;
    unsigned int amountOfTorpedos;
    unsigned int maxTorpedoDmg;
    unsigned int torpedoRange;
    unsigned int amountOfSquadrons;
    unsigned int aircraftInSquadron;
};

class Warship {
    string _name;
    typeOfWarship type;
    double _hp, baseHp;

public:
    Warship();

    string name();

    double hp();
};