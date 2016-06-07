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
    unsigned int _amountOfCannons;
    unsigned int _maxHeShellDmg;
    unsigned int _maxApShellDmg;
    unsigned int _firingRange;
    unsigned int _chanceForArsonByHe;
    unsigned int _amountOfAntiAircraftCannons;
    unsigned int _maxAntiAircraftCannonsDmg;
    unsigned int _amountOfTorpedos;
    unsigned int _maxTorpedoDmg;
    unsigned int _torpedoRange;
    unsigned int _amountOfSquadrons;
    unsigned int _aircraftInSquadron;
    unsigned int _dmgPerSquadron;
    float _baseHpPerSquadron;
public:
    void Init(Parameters parameters[], unsigned int i);

    bool isAlive();

    virtual void attack() = 0;

    virtual unsigned int numberOfSquadrons() = 0;

    typeOfWarship whatType() { return _type; };

    friend void makeDead(Ship *wsk);

    friend int war(Ship *wsk1, Ship *wsk2);
};

class Destroyer : public Ship {
public:
    Destroyer(Parameters parameters[], unsigned int i);

    unsigned int numberOfSquadrons() { return 0; };
    virtual void attack() { };
};

class Cruiser : public Ship {
public:
    Cruiser(Parameters parameters[], unsigned int i);

    unsigned int numberOfSquadrons() { return 0; };
    virtual void attack() { };
};

class Battleship : public Ship {
public:
    Battleship(Parameters parameters[], unsigned int i);

    unsigned int numberOfSquadrons() { return 0; };
    virtual void attack() { };
};

class AircraftCarrier : public Ship {
public:
    AircraftCarrier(Parameters parameters[], unsigned int i);

    virtual void attack() { };

    unsigned int numberOfSquadrons() { return _amountOfSquadrons; };
};

#endif //PROJ_NAVAL_BATTLES_SHIP_H