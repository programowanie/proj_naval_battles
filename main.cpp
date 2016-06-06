#include <cstdlib>
#include <time.h>
#include <iostream>

#include "Battle.h"

int main(int argc, char *argv[]) {
    cout << "## Naval Battles Simulator ##\n\n";

    unsigned int seed;
    if (argc == 1) seed = (unsigned int) atoi(argv[1]);
    else seed = (unsigned int) time(NULL);
    srand(seed);

    Battle navalBattle;
    navalBattle.mainLoop();

    cin.sync();
    cin.get();

    return 0;
}

