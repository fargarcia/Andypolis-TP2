#ifndef ERRORS_H
#define PATHS_H

#include <iostream>

using namespace std;


enum errors
{
    OK                  = 0,
	NOT_ENOUGH_WOOD     = 1,
    NOT_ENOUGH_ROCK     = 2,
    NOT_ENOUGH_METAL    = 3,
    NOT_AVAILABLE       = 4,
    TERRAIN_NOT_SUITALBE= 5,
    OCUPIED_TILE        = 6,
    TYPE_NOT_FOUND      = 7
};

#endif