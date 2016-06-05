#pragma once

#include <string>

using namespace std;

enum typeOfWarship {
    DESTROYER, CRUISER, BATTLESHIP, AIRCRAFTCARRIER
};

struct Parameters {
    string name;
    typeOfWarship type;
    float baseHp;
    unsigned int armor;
    double agility;
    double camouflage;
    double chanceForArson;
    unsigned int amountOfAntiAircraftCannons;
    unsigned int maxAntiAircraftCannonsDmg;
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
    float baseHpPerSquadron;
};

class Ship {
protected:
    string _name;
    typeOfWarship _type;

    float baseHp, _hp;
    unsigned int _armor;
    double _agility;
    double _camouflage;
    double _chanceForArson;

public:
    void Init(Parameters parameters[], unsigned int i);

    string name();
};

class Warship {
protected:
    unsigned int _amountOfCannons;
    unsigned int _maxHeShellDmg;
    unsigned int _maxApShellDmg;
    unsigned int _firingRange;
    unsigned int _chanceForArsonByHe;
    unsigned int _amountOfAntiAircraftCannons;
    unsigned int _maxAntiAircraftCannonsDmg;
public:
    void Init(Parameters parameters[], unsigned int i);
};

class Destroyer : Ship, Warship {
    unsigned int _amountOfTorpedos;
    unsigned int _maxTorpedoDmg;
    unsigned int _torpedoRange;

public:
    Destroyer(Parameters parameters[], unsigned int i);
};

class Cruiser : Ship, Warship {
public:
    Cruiser(Parameters parameters[], unsigned int i);
};

class Battleship : Ship, Warship {
public:
    Battleship(Parameters parameters[], unsigned int i);
};

class AircraftCarrier : Ship {
    unsigned int _amountOfSquadrons;
    unsigned int _aircraftInSquadron;
    unsigned int _dmgPerSquadron;
    float _baseHpPerSquadron;
    float *_hp;
public:
    AircraftCarrier(Parameters parameters[], unsigned int i);
};