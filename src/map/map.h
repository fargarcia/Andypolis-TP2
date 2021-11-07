#ifndef	MAP_H
#define MAP_H

#include <string>
#include "./tile/tile.h"

class Map {
    private:
        Tile** tiles;

    public:
        Map();
        Map(int height, int width);

        void addTile(int xCoord, int yCoord, std::string tileType);

};  


#endif