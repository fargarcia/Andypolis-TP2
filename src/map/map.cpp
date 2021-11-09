#include "map.h"
#include "./tile/tile.h"
#include "../consts/consts.h"
#include "../consts/colors.h"

Map::Map(){};

void Map::setHeight(int newHeight) {
    height = newHeight;
}

void Map::setWidth(int newWidth) {
    width = newWidth;
}

void Map::createMap(int newHeight, int newWidth){
    setHeight(newHeight);
    setWidth(newWidth);
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

void Map::setRoadTileAmount(int amount) {
    roadTileAmount = amount;
}

int Map::getRoadTileAmount() {
    return roadTileAmount;
}

// Funcion para saber cuantos casilleros transitables existen en el mapa
int Map::countRoadTileAmount(int height, int width, std::string tileType) {
    int roadTileAmount = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(tileType == ROAD)
            roadTileAmount++;
        }
    }
    return roadTileAmount;
}

void Map::printMap(int row, int col) {
    if(tiles[row][col].getType() == GROUND) {
    /*
    ** ESTA COMENTADO PORQUE isAvailable() NO FUNCIONA Y SE ROMPE
    if(!(static_cast<GroundTile*>(&tiles[i][j])->isAvailable())) {
        string name = static_cast<GroundTile*>(&tiles[i][j]) -> getBuildingTemplate().getName();
        // IMPRIMIR LA INICIAL DEL EDIFICIO
    }*/
    // MOSTRAR EL CASILLERO EN VERDE
    cout << BGND_DARK_GREEN_22 << "   " << END_COLOR;
    cout << BGND_DARK_GREEN_22 << "   " << END_COLOR;
    cout << BGND_DARK_GREEN_22 << "   " << END_COLOR;
    }
    else if(tiles[row][col].getType() == LAKE) {
        cout << BGND_BLUE_20 << "   " << END_COLOR;
        cout << BGND_BLUE_20 << "   " << END_COLOR;
        cout << BGND_BLUE_20 << "   " << END_COLOR;
    }
    else if(tiles[row][col].getType() == ROAD) {
        cout << BGND_DARK_GRAY_237 << "   " << END_COLOR;
        cout << BGND_DARK_GRAY_237 << "   " << END_COLOR;
        cout << BGND_DARK_GRAY_237 << "   " << END_COLOR;
    }
}

void Map::showMap() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < width; k++) {
                printMap(i, k);
            }
            cout << endl;
        }
        //cout << endl;
    }
}