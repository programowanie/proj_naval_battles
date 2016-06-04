#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>

#include "Interface.h"
#include "Warships.h"
#include "Enemy.h"
#include "Battle.h"

void write(const string &file_name, DefenceParameters &defenceParametersStruct);

void write(const string &file_name, OffenceParameters &offenceParametersStruct);

void read(const string &file_name, DefenceParameters &defenceParametersStruct);

void read(const string &file_name, OffenceParameters &offenceParametersStruct);

int main(int argc, char *argv[]) {

    if (argc == 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    DefenceParameters TestDefenceParameters;
    TestDefenceParameters.baseHp = 68000.0;
    TestDefenceParameters.hp = TestDefenceParameters.baseHp;
    TestDefenceParameters.armor = 10;
    TestDefenceParameters.agility = 50;
    TestDefenceParameters.camouflage = 123.432;
    TestDefenceParameters.chanceForArson = 0.002;
    TestDefenceParameters.amountOfAntiAircraftCannons = 50;
    TestDefenceParameters.maxAntiAircraftCannonsDmg = 345;

    write("data.dat", TestDefenceParameters);

    Battle battle;
    return 0;
}

void write(const string &file_name, DefenceParameters &defenceParametersStruct) {
    ofstream out(file_name.c_str());
    out.write(reinterpret_cast<char *> (&defenceParametersStruct), sizeof(DefenceParameters));
}

void write(const string &file_name, OffenceParameters &offenceParametersStruct) {
    ofstream out(file_name.c_str());
    out.write(reinterpret_cast<char *> (&offenceParametersStruct), sizeof(OffenceParameters));
}

void read(const string &file_name, DefenceParameters &defenceParametersStruct) {
    ifstream in(file_name.c_str());
    in.read(reinterpret_cast<char *> (&defenceParametersStruct), sizeof(DefenceParameters));

}

void read(const string &file_name, OffenceParameters &offenceParametersStruct) {
    ifstream in(file_name.c_str());
    in.read(reinterpret_cast<char *> (&offenceParametersStruct), sizeof(OffenceParameters));

}