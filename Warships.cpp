#include <cstdlib>

#include "Warships.h"

using namespace std;

Destroyer::Destroyer(Parameters parameters[], unsigned int i) {
    _name = parameters[i].name;
    _type = parameters[i].type;
    baseHp = parameters[i].baseHp;
    _hp = baseHp;
    _armor = parameters[i].armor;
    _agility = parameters[i].agility;
    _camouflage = parameters[i].camouflage;
    _chanceForArson = parameters[i].chanceForArson;
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
}

