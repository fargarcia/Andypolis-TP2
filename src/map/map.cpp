#include "map.h"
#include "./tile/tile.h"
#include "../consts/consts.h"

Map::Map(){};

void Map::createMap(int height, int width){
    tiles = new Tile*[height];
    for (int i = 0; i < height; ++i)
        tiles[i] = new Tile[width];
    return;
}

void Map::addTile(int xCoord, int yCoord, std::string tileType)
{
    if (tileType == ROAD) {
        tiles[xCoord][yCoord] = RoadTile();
    } else if (tileType == GROUND) {
        tiles[xCoord][yCoord] = GroundTile();
    } else {
        tiles[xCoord][yCoord] = LakeTile();
    }
    return;
}

Tile& Map::getTile(int xCoord, int yCoord){
    return tiles[xCoord][yCoord];
}