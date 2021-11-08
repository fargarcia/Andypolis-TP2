#include "tile.h"
#include "../../consts/consts.h"
#include <string>

Tile::Tile(){};
Tile::~Tile(){};

void Tile::setType(std::string type){
    tileType = type;
}

std::string Tile::getType(){
    cout << "getType" << endl;
    return tileType;
}

LakeTile::LakeTile() {
    setType(LAKE);
}

GroundTile::GroundTile() {
    setType(GROUND);
}
void GroundTile::addBuilding(Template* buildingTemplate) {
    building = buildingTemplate;
}

RoadTile::RoadTile() {
    setType(ROAD);
}