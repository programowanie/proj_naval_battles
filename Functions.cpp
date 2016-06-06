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