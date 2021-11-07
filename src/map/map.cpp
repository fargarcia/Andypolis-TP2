#include "map.h"
#include "./tile/tile.h"
#include "../consts/consts.h"

Map::Map(){};
Map::Map(int height, int width){
    tiles = new Tile*[height];
    for (int i = 0; i < height; ++i)
        tiles[i] = new Tile[width];
    return;
}

void Map::addTile(int xCoord, int yCoord, std::string tileType){
    if (tileType == ROAD) {
        tiles[xCoord][yCoord] = RoadTile();
    } else if (tileType == GROUND) {
        tiles[xCoord][yCoord] = GroundTile();
    } else {
        tiles[xCoord][yCoord] = LakeTile();
    } 
    return;
}