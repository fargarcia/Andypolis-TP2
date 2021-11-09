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
    setBuildingAsNull();
}

Template GroundTile::getBuildingTemplate() {
    return *building;
}

void GroundTile::setBuildingAsNull() {
    building = NULL;
    cout << "building " << building << endl;
}

void GroundTile::addBuilding(Template* buildingTemplate) {
    building = buildingTemplate;
}
bool GroundTile::isAvailable() {
    cout << building << endl;
    if (building == nullptr)
        cout << "hola2" << endl;
    return (building == NULL);
};

RoadTile::RoadTile() {
    setType(ROAD);
}