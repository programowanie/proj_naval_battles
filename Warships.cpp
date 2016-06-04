#include <cstdlib>

#include "Warships.h"

using namespace std;

Warship::Warship() {
    exit(0);
}

Warship::Warship(string name, typeOfWarship type, DefenceParameters defence, OffenceParameters offence) {
    _name = name;
    _type = type;

    _defence.baseHp = defence.baseHp;
    _defence.hp = _defence.baseHp;
    _defence.armor = defence.armor;
    _defence.agility = defence.agility;
    _defence.camouflage = defence.camouflage;
    _defence.chanceForArson = defence.chanceForArson;
    _defence.amountOfAntiAircraftCannons = defence.amountOfAntiAircraftCannons;
    _defence.maxAntiAircraftCannonsDmg = defence.maxAntiAircraftCannonsDmg;

    _offence.amountOfCannons = offence.amountOfCannons;
    _offence.maxHeShellDmg = offence.maxHeShellDmg;
    _offence.maxApShellDmg = offence.maxApShellDmg;
    _offence.firingRange = offence.firingRange;
    _offence.chanceForArsonByHe = offence.chanceForArsonByHe;
    _offence.amountOfTorpedos = offence.amountOfTorpedos;
    _offence.maxTorpedoDmg = offence.maxTorpedoDmg;
    _offence.torpedoRange = offence.torpedoRange;
    _offence.amountOfSquadrons = offence.amountOfSquadrons;
    _offence.aircraftInSquadron = offence.aircraftInSquadron;
    _offence.dmgPerSquadron = offence.dmgPerSquadron;
    _offence.baseHpPerSquadron = offence.baseHpPerSquadron;
    _offence.hpPerSquadron = _offence.baseHpPerSquadron;
}

string Warship::name() {
    return _name;
}

double Warship::hp() {
    return _defence.hp;
}