#include <cstdlib>
#include <time.h>
#include <iostream>

#include "Battle.h"

int main(int argc, char *argv[]) {
    int seed;
    if (argc == 2) seed = atoi(argv[1]);
    else seed = time(NULL);
    srand((unsigned int) seed);

    Battle navalBattle;
    navalBattle.mainLoop();

    cout << endl;
    cout << "Wcisnij dowolny klawisz by zakonczyc: ";

    cin.sync();
    cin.get();

    return 0;
}

