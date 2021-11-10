#ifndef	MAP_H
#define MAP_H

#include <string>
#include "./tile/tile.h"

class Map {
    private:
        Tile** tiles;
        int roadTileAmount;
        int height;
        int width;

    public:
        Map();
        void setHeight(int newHeight);
        void setWidth(int newWidth);
        int getHeight();
        int getWidth();
        void createMap(int height, int width);
        void addTile(int xCoord, int yCoord, std::string tileType);
        Tile* getTile(int xCoord, int yCoord);
        Tile** getTilesVector();
        Tile** getRoadTiles();
        void setRoadTileAmount(int amount);
        int countRoadTileAmount(int height, int width, std::string tileType);
        int getRoadTileAmount();
        void showMap();
        void printMap(int row, int col);

};  


#endif