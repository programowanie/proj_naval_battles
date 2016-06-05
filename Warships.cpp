#include <cstdlib>

#include "Warships.h"

using namespace std;

void Ship::Init(Parameters *parameters, unsigned int i) {
    _name = parameters[i].name;
    _type = parameters[i].type;
    baseHp = parameters[i].baseHp;
    _hp = baseHp;
    _armor = parameters[i].armor;
    _agility = parameters[i].agility;
    _camouflage = parameters[i].camouflage;
    _chanceForArson = parameters[i].chanceForArson;
}

void Warship::Init(Parameters *parameters, unsigned int i) {
    _amountOfCannons = parameters[i].amountOfCannons;
    _maxHeShellDmg = parameters[i].maxHeShellDmg;
    _maxApShellDmg = parameters[i].maxApShellDmg;
    _firingRange = parameters[i].firingRange;
    _chanceForArsonByHe = parameters[i].chanceForArsonByHe;
    _amountOfAntiAircraftCannons = parameters[i].amountOfAntiAircraftCannons;
    _maxAntiAircraftCannonsDmg = parameters[i].maxAntiAircraftCannonsDmg;
}

Destroyer::Destroyer(Parameters parameters[], unsigned int i) {
    _amountOfTorpedos = parameters[i].amountOfTorpedos;
    _maxTorpedoDmg = parameters[i].maxTorpedoDmg;
    _torpedoRange = parameters[i].torpedoRange;
    _amountOfCannons = parameters[i].amountOfCannons;
    _maxHeShellDmg = parameters[i].maxHeShellDmg;
    _maxApShellDmg = parameters[i].maxApShellDmg;
    _firingRange = parameters[i].firingRange;
    _chanceForArsonByHe = parameters[i].chanceForArsonByHe;
    _amountOfAntiAircraftCannons = parameters[i].amountOfAntiAircraftCannons;
    _maxAntiAircraftCannonsDmg = parameters[i].maxAntiAircraftCannonsDmg;

    Ship::Init(parameters, i);
    Warship::Init(parameters, i);
}

Cruiser::Cruiser(Parameters parameters[], unsigned int i) {
    Ship::Init(parameters, i);
    Warship::Init(parameters, i);
}


Battleship::Battleship(Parameters *parameters, unsigned int i) {
    Ship::Init(parameters, i);
    Warship::Init(parameters, i);
}

AircraftCarrier::AircraftCarrier(Parameters *parameters, unsigned int i) {
    _amountOfSquadrons = parameters[i].amountOfSquadrons;
    _aircraftInSquadron = parameters[i].aircraftInSquadron;
    _dmgPerSquadron = parameters[i].dmgPerSquadron;
    _baseHpPerSquadron = parameters[i].baseHpPerSquadron;

    Ship::Init(parameters, i);
}

string Ship::name() {
    return _name;
}

float Ship::hp() {
    return _hp;
}

