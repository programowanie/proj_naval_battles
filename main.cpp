#include <cstdlib>
#include <time.h>

#include "Interface.h"
#include "Warships.h"
#include "Enemy.h"
#include "Battle.h"

int main(int argc, char *argv[]) {

    if (argc == 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    Battle battle;
    return 0;
}