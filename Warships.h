#pragma once

#include <string>

using namespace std;

enum typeOfWarship {
    DESTROYER, CRUISER, BATTLESHIP, AIRCRAFTCARRIER
};

struct DefenceParameters {
    float hp, baseHp;
    unsigned int armor;
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
    unsigned int dmgPerSquadron;
    float hpPerSquadron, baseHpPerSquadron;
};

class Warship {
    string _name;
    typeOfWarship _type;
    DefenceParameters _defence;
    OffenceParameters _offence;

public:
    Warship();

    Warship(string name, typeOfWarship type, DefenceParameters defence, OffenceParameters offence);

    string name();

    double hp();
};