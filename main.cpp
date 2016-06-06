#include <cstdlib>
#include <time.h>
#include <iostream>

#include "Battle.h"

int main(int argc, char *argv[]) {
    int seed;
    if (argc == 2) seed = atoi(argv[1]);
    else seed = time(NULL);
    srand(seed);

    Battle navalBattle;

    cin.sync();
    cin.get();

    return 0;
}

