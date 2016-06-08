#ifndef PROJ_NAVAL_BATTLES_SHIP_H
#define PROJ_NAVAL_BATTLES_SHIP_H

#include "Functions.h"

using namespace std;

//! Klasa bazowa okrętu
class Ship {
protected:
    string _name; ///< Nazwa okrętu
    typeOfWarship _type; ///< Rodzaj okrętu
    float baseHp; ///< Aktualne punkty życia
	float _hp; ///< Punkty życia
    unsigned int _armor; ///< Pancerz okrętu
    double _agility; ///< Zwrotność okrętu
    double _camouflage; ///< Współczynnik kamuflażu
    double _chanceForArson; ///< Szansa na wybuch pożaru
    unsigned int _amountOfCannons; ///< Liczba dział
    unsigned int _maxHeShellDmg; ///< Obrażenia zadawane pociskiem odłamkowym
    unsigned int _maxApShellDmg; ///< Obrażenia zadawane pociskiem przeciwpancernym
    unsigned int _firingRange; ///< Zasięg strzału
    unsigned int _chanceForArsonByHe; ///< Szansa na podpalenie pociskiem odłamkowym
    unsigned int _amountOfAntiAircraftCannons; ///< Liczba dział przeciwlotniczych
    unsigned int _maxAntiAircraftCannonsDmg; ///< Maksymalne uszkodzenie zadawane przez działo przeciwlotnicze
    unsigned int _amountOfTorpedos; ///< Liczba torped
    unsigned int _maxTorpedoDmg; ///< Obrażenia zadawane przez torpedę
    unsigned int _torpedoRange; ///< Zasięg torpedy
    unsigned int _amountOfSquadrons; ///< Liczba eskadr
    unsigned int _aircraftInSquadron; ///< Liczba samolotów w eskadrze
    unsigned int _dmgPerSquadron; ///< Obrażenia zadawane przez eskadrę
    float _baseHpPerSquadron; ///< Pukty życia eskadry
public:
	//! Konstruktor klasy bazowej
    void Init(Parameters parameters[], unsigned int i);
	
	//! Funkcja sprawdzająca czy okręt nie jest zniszczony
    bool isAlive();
	
	//! Funkcja sprawdzająca czy okręt jest zniszczony
    bool isDead();

	//! Funkcja przeprowadzająca atak
    virtual void attack() = 0;

	//! Funkcja zwracająca pozostałą liczbę eskadr
    virtual unsigned int numberOfSquadrons() = 0;

	//! Funkcja zwracająća typ okrętu
    typeOfWarship whatType() { return _type; };
	
	//! Funkcja niszczy okręt
    friend void makeDead(Ship *wsk);

	//! Funkcja przeprowadzająca walkę między dwoma okrętami
    friend int war(Ship *wsk1, Ship *wsk2);

	//! Funkcja opisująca okręt
    void description(Ship *wsk1, Ship *wsk2);
};

//! Klasa pochodna opisująca niszczyciela
class Destroyer : public Ship {
public:
	//! Konstruktor klasy Destroyer
    Destroyer(Parameters parameters[], unsigned int i); //! Konstruktor klasy

    unsigned int numberOfSquadrons() { return 0; };
    virtual void attack() { };
};

//! Klasa pochodna opisująca krążownik
class Cruiser : public Ship {
public:
	//! Konstruktor klasy Cruiser
    Cruiser(Parameters parameters[], unsigned int i);

    unsigned int numberOfSquadrons() { return 0; };
    virtual void attack() { };
};

//! Klasa pochodna opisująca pancernik
class Battleship : public Ship {
public:
	//! Konstruktor klasy Battleship
    Battleship(Parameters parameters[], unsigned int i);

    unsigned int numberOfSquadrons() { return 0; };
    virtual void attack() { };
};

//! Klasa pochodna opisująca lotniskowiec
class AircraftCarrier : public Ship {
public:
	//! Konstruktor klasy AircraftCarrier
    AircraftCarrier(Parameters parameters[], unsigned int i);

    virtual void attack() { };

    unsigned int numberOfSquadrons() { return _amountOfSquadrons; };
};

#endif //PROJ_NAVAL_BATTLES_SHIP_H