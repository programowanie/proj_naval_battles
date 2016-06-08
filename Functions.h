#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//! Rodzaj okętu modelowany przez daną klasę
/*!
 * Wartości tego typu służą jako identyfikatory dostępnych rodzai okręów
 */
enum typeOfWarship {
    DESTROYER, ///< Okręt jest niszczycielem
    CRUISER, ///< Okręt jest krążownikiem
    BATTLESHIP, ///< Okręt jest pancernikiem
    AIRCRAFTCARRIER ///< Okręt jest lotniskowcem
};

//! Struktura przechowująca parametry okręów.
struct Parameters {
    string name; ///< Nazwa okrętu
    typeOfWarship type; ///< Rodzaj okrętu
    float baseHp; ///< Punkty życia
    unsigned int armor; ///< Pancerz okrętu
    double agility; ///< Zwrotność okrętu
    double camouflage; ///< Współczynnik kamuflażu
    double chanceForArson; ///< Szansa na wybuch pożaru
    unsigned int amountOfAntiAircraftCannons; ///< Liczba dział przeciwlotniczych
    unsigned int maxAntiAircraftCannonsDmg; ///< Maksymalne uszkodzenie zadawane przez działo przeciwlotnicze
    unsigned int amountOfCannons; ///< Liczba dział
    unsigned int maxHeShellDmg; ///< Obrażenia zadawane pociskiem odłamkowym
    unsigned int maxApShellDmg; ///< Obrażenia zadawane pociskiem przeciwpancernym
    unsigned int firingRange; ///< Zasięg strzału
    unsigned int chanceForArsonByHe; ///< Szansa na podpalenie pociskiem odłamkowym
    unsigned int amountOfTorpedos; ///< Liczba torped
    unsigned int maxTorpedoDmg; ///< Obrażenia zadawane przez torpedę
    unsigned int torpedoRange; ///< Zasięg torpedy
    unsigned int amountOfSquadrons; ///< Liczba eskadr
    unsigned int aircraftInSquadron; ///< Liczba samolotów w eskadrze
    unsigned int dmgPerSquadron; ///< Obrażenia zadawane przez eskadrę
    float baseHpPerSquadron; ///< Pukty życia eskadry
};

void read(const string &file_name, Parameters tab[]); //! Funkcja wczytująca parametry okrętów z pliku