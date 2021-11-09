#ifndef	MAP_H
#define MAP_H

#include <string>
#include "./tile/tile.h"

class Map {
    private:
        Tile** tiles;
        int roadTileAmount;

    public:
        Map();
        void createMap(int height, int width);
        void addTile(int xCoord, int yCoord, std::string tileType);
        Tile& getTile(int xCoord, int yCoord);
        void setRoadTileAmount(int amount);
        int countRoadTileAmount(int height, int width, std::string tileType);
        int getRoadTileAmount();

};  


#endif