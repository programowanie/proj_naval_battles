#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//! Rodzaj okętu modelowany przez daną klasę.
/*!
 * Wartości tego typu służą jako identyfikatory dostępnych rodzai okręów.
 */
enum typeOfWarship {
    DESTROYER /*! Okręt jest niszczycielem */,
    CRUISER /*! Okręt jest krążownikiem */,
    BATTLESHIP /*! Okręt jest pancernikiem */,
    AIRCRAFTCARRIER /*! Okręt jest lotniskowcem */
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

void read(const string &file_name, Parameters tab[]);
