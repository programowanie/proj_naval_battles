#include <cstdlib>
#include <time.h>
#include <iostream>

#include "Interface.h"
#include "Warships.h"
#include "Enemy.h"
#include "Battle.h"

int main(int argc, char *argv[]) {
    cout << "## Naval Battles Simulator ##\n\n";

    if (argc == 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    //Battle battle;

    cin.sync();
    cin.get();

    return 0;
}

