#include "tile.h"
#include "../../consts/consts.h"
#include <string>

Tile::Tile(){};
Tile::~Tile(){};

void Tile::setType(std::string type){
    tileType = type;
}

std::string Tile::getType(){
    return tileType;
}


LakeTile::LakeTile() {
    setType(LAKE);
}

GroundTile::GroundTile() {
    setType(GROUND);
    building = nullptr;
}
void GroundTile::addBuilding(Template* buildingTemplate) {
    building = buildingTemplate;
}
bool GroundTile::isAvailable(){
        cout << &building << endl;
    return (building == NULL);
};

RoadTile::RoadTile() {
    setType(ROAD);
}