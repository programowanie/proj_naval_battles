#ifndef PROJ_NAVAL_BATTLES_SHIP_H
#define PROJ_NAVAL_BATTLES_SHIP_H

#include "Functions.h"

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
    bool isAlive();

    virtual void attack() = 0;
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

class Destroyer : public Ship, public Warship {
    unsigned int _amountOfTorpedos;
    unsigned int _maxTorpedoDmg;
    unsigned int _torpedoRange;

public:
    Destroyer(Parameters parameters[], unsigned int i);

    virtual void attack() { };
};

class Cruiser : public Ship, public Warship {
public:
    Cruiser(Parameters parameters[], unsigned int i);

    virtual void attack() { };
};

class Battleship : public Ship, public Warship {
public:
    Battleship(Parameters parameters[], unsigned int i);

    virtual void attack() { };
};

class AircraftCarrier : public Ship {
    unsigned int _amountOfSquadrons;
    unsigned int _aircraftInSquadron;
    unsigned int _dmgPerSquadron;
    float _baseHpPerSquadron;
public:
    AircraftCarrier(Parameters parameters[], unsigned int i);

    virtual void attack() { };
};

#endif //PROJ_NAVAL_BATTLES_SHIP_H