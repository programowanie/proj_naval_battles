#include <cstdlib>
#include <time.h>
#include <iostream>

#include "Battle.h"

int main(int argc, char *argv[]) {
    cout << "## Naval Battles Simulator ##\n\n";

    int seed;
    if (argc == 2) seed = atoi(argv[1]);
    else seed = time(NULL);

    Battle navalBattle;
    navalBattle.mainLoop();

    cin.sync();
    cin.get();

    return 0;
}

